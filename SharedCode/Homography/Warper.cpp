//
//  Warper.cpp
//  HomographyExample
//
//  Created by Seb Lee-Delisle on 08/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "Warper.h"


Warper :: Warper() { 
	
	srcImage = NULL; 
	
	guiVisible = false; 
	changed = false; 
	
	ofAddListener(ofEvents().mousePressed, this, &Warper::mousePressed);
	ofAddListener(ofEvents().mouseDragged, this, &Warper::mouseDragged);
	ofAddListener(ofEvents().mouseReleased, this, &Warper::mouseReleased);
	settingsFileLabel = "defaultWarp"; 
	
	
	// create defaults if there is no saved setting yet. 
	if(!loadSettings()){
		for(int i = 0; i<4;i++) { 
			
			if(srcVecs.size()==i) srcVecs.push_back(ofVec2f()); 
			
			srcVecs[i].set( (i%2)*ofGetWidth(), floor(i/2)*ofGetHeight());
			
		}
		for(int i = 0; i<4;i++) { 
			
			if(dstVecs.size()==i) dstVecs.push_back(ofVec2f()); 
			dstVecs[i].set( (i%2)*ofGetWidth(), floor(i/2)*ofGetHeight());
			
		}		
	}
	
	warpedImage.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR); 
	autoSave =true; 
	
};

bool Warper :: update() { 
	if(!srcImage) return false; 
	
	if(changed) { 
		// update points
		
		vector<Point2f> srcPoints, dstPoints;
		for(int i = 0; i < srcVecs.size(); i++) {
			srcPoints.push_back(Point2f(srcVecs[i].x, srcVecs[i].y));
			dstPoints.push_back(Point2f(dstVecs[i].x, dstVecs[i].y));
		}			
		
		homography = findHomography(Mat(srcPoints), Mat(dstPoints));
		inverseHomography = findHomography(Mat(dstPoints), Mat(srcPoints));
		
		changed = false; 
	
		
		warpPerspective(*srcImage, warpedImage, homography, CV_INTER_LINEAR);
		warpedImage.update();
		
		return true; 
	}
	
	
		
	//perspectiveTransform(srcVecs, srcVecs, homography);
		
		
	//warpedImage.update();
		
	return false; 
	
};

void Warper :: drawPoints(vector<ofVec2f>& points, ofColor colour) {
	
	
	ofPushStyle();
	ofNoFill();
	ofPushMatrix(); 

	ofEnableSmoothing(); 
	//ofScale(1024, 768); 
	for(int i = 0; i < points.size(); i++) {
		ofSetColor(ofColor::black); 
		ofSetLineWidth(6);
		
		ofCircle(points[i], 1);
		ofSetColor(colour); 
		ofSetLineWidth(2);
		ofCircle(points[i], 10);
		ofCircle(points[i], 1);
		
		
		
	}
	ofPopMatrix(); 
	ofPopStyle();

}



void Warper :: draw() { 
	if((!srcImage)||(!guiVisible)) return; 
	
	// draw GUI
	
	ofSetColor(255);
	
	warpedImage.draw(0,0);
	ofPushMatrix(); 
	
	ofTranslate((ofGetWidth()/2) - (srcImage->width/4), (ofGetHeight()/2) - (srcImage->height/4));
	ofScale(0.5,0.5); 
	srcImage->draw(0,0); 
	drawPoints(srcVecs, ofColor::cyan);

	ofPopMatrix(); 
	drawPoints(srcVecs, ofColor::cyan);
	
	drawPoints(dstVecs); 
	
	
};

void Warper :: setSourceImage(ofImage& img) { 
	srcImage = &img;
	
	changed = true; 
	
	if(srcVecs.size()==0) { 
		
		for(int i = 0; i<4; i++) { 
			srcVecs.push_back(ofVec2f((i%2)*img.width,floor(i/2)*img.height )); 
			dstVecs.push_back(ofVec2f((i%2)*img.width,floor(i/2)*img.height ));
			
		}	
		
	}
	
	
};

bool Warper:: loadSettings() { 
	
	ofxXmlSettings settings;
	if(!settings.loadFile("warpdata/"+settingsFileLabel+".xml")) return false;
	if(settings.getNumTags("srcvec")!=4) return false; 
	if(settings.getNumTags("dstvec")!=4) return false; 
	
	
	for(int i = 0; i<4;i++) { 

		if(srcVecs.size()==i) srcVecs.push_back(ofVec2f()); 

		
		settings.pushTag("srcvec", i); 
		srcVecs[i].set(settings.getValue("x", (i%2)*ofGetWidth()),
						 settings.getValue("y", floor(i/2)*ofGetHeight()));

		settings.popTag();
	}
	for(int i = 0; i<4;i++) { 
		
		
		if(dstVecs.size()==i) dstVecs.push_back(ofVec2f()); 
		
		settings.pushTag("dstvec", i); 
		
		dstVecs[i].set(settings.getValue("x", (i%2)*ofGetWidth()),
					   settings.getValue("y", floor(i/2)*ofGetHeight()	));
		
		settings.popTag();
	}	
		
}


bool Warper:: saveSettings() {
	
	ofDirectory dir("warpdata"); 
	if(!dir.exists()) dir.create();
	
	ofxXmlSettings positions; 

	//positions.addTag("settings"); 
	//positions.pushTag("settings"); 
	
	for(int i = 0; i < srcVecs.size(); i++){
		positions.addTag("srcvec"); 
		positions.pushTag("srcvec", i); 
		//so set the three values in the file
		//positions.addTag("x", ); 
		positions.addValue("x", srcVecs[i].x); 
		positions.addValue("y", srcVecs[i].y); 
		
		
		positions.popTag(); 
		//	
	}

	//positions.popTag(); 

	for(int i = 0; i < dstVecs.size(); i++){
		
		positions.addTag("dstvec"); 
		positions.pushTag("dstvec", i); 
		
		//so set the three values in the file
		positions.addValue("x", dstVecs[i].x);
		positions.addValue("y", dstVecs[i].y);
		positions.popTag(); 
		
		
	}

	positions.addValue("srcWidth", srcImage->width); 
	positions.addValue("srcHeight", srcImage->height); 

	positions.addValue("dstWidth", warpedImage.width); 
	positions.addValue("dstHeight", warpedImage.height); 	
	
	positions.saveFile("warpdata/"+settingsFileLabel+".xml");	
	
	
}

bool Warper :: hitTestPoints ( vector<ofVec2f>& points, ofVec2f& point) {
	
	for(int i = 0; i < points.size(); i++) {
		if(points[i].distance(point) < 20) {
			movingPoint = true;
			curPoint = &points[i];
			return true;
		}
	}
	
}

void Warper :: showGui() { 
	if(!guiVisible) { 
		guiVisible = true; 
		changed = true;
	}
	
}

void Warper :: hideGui() { 
	if(guiVisible) { 
		guiVisible = false;
		
		if(autoSave) saveSettings(); 
		
	}
	
}

void Warper :: toggleGui() {
	
	if(!guiVisible) showGui(); 
	else hideGui(); 

}


void Warper :: mousePressed(ofMouseEventArgs &e) {

	if(!guiVisible) return; 
	
	ofVec2f cur(e.x, e.y);
	
	hitTestPoints(dstVecs, cur); 
	hitTestPoints(srcVecs, cur); 
	
};


void Warper :: mouseDragged(ofMouseEventArgs &e) {
	if(!guiVisible) return; 
	
	
	if(movingPoint) { 

		curPoint->set(e.x, e.y); 
	
		changed = true;
	
	}
	
};



void Warper :: mouseReleased(ofMouseEventArgs &e) {
	if(!guiVisible) return; 
	
	if(movingPoint) {
		movingPoint = false; 
		changed = true; 
	}
	
	
	saveSettings(); 
	//loadSettings(); 
};






