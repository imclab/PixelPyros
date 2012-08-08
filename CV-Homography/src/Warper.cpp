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
	
	loadSettings();
	
};

void Warper :: update() { 
	if(!srcImage) return; 
	
	if(changed) { 
		// update points
		
		vector<Point2f> srcPoints, dstPoints;
		for(int i = 0; i < srcVecs.size(); i++) {
			srcPoints.push_back(Point2f(srcVecs[i].x, srcVecs[i].y));
			dstPoints.push_back(Point2f(dstVecs[i].x, dstVecs[i].y));
		}			
		
		homography = findHomography(Mat(srcPoints), Mat(dstPoints));
		
		warpPerspective(*srcImage, warpedImage, homography, CV_INTER_LINEAR);
		warpedImage.update();
		changed = false; 
		
	}
	
};

void Warper :: drawPoints(vector<ofVec2f>& points) {
	
	
	
	ofNoFill();
	ofPushMatrix(); 
	//ofScale(1024, 768); 
	for(int i = 0; i < points.size(); i++) {
		ofCircle(points[i], 10);
		ofCircle(points[i], 1);
	}
	ofPopMatrix(); 
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
	ofSetColor(ofColor::green);
	drawPoints(srcVecs);

	ofPopMatrix(); 
	ofSetColor(ofColor::green);
	drawPoints(srcVecs);
	
	ofSetColor(ofColor::red);
	drawPoints(dstVecs); 
	
	
};

void Warper :: setSourceImage(ofImage& img) { 
	srcImage = &img;
	if(warpedImage.isAllocated()) warpedImage.clear(); 
	imitate(warpedImage, img); 
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
	settings.loadFile("warpdata/"+settingsFileLabel+".xml");
	if(settings.getNumTags("srcvec")!=4) return false; 
	if(settings.getNumTags("dstvec")!=4) return false; 
	
	
	for(int i = 0; i<4;i++) { 

		if(srcVecs.size()==i) srcVecs.push_back(ofVec2f()); 

		
		settings.pushTag("srcvec", i); 
		srcVecs[i].set(settings.getValue("x", 0),
						 settings.getValue("y", 0));

		settings.popTag();
	}
	for(int i = 0; i<4;i++) { 
		
		
		if(dstVecs.size()==i) dstVecs.push_back(ofVec2f()); 
		
		settings.pushTag("dstvec", i); 
		
		dstVecs[i].set(settings.getValue("x", 0),
					   settings.getValue("y", 0));
		
		settings.popTag();
	}	
		
}


bool Warper:: saveSettings() {
	
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




void Warper :: mousePressed(ofMouseEventArgs &e) {

	if(!guiVisible) return; 
	
	ofVec2f cur(e.x, e.y);
	
	// pretty nasty : because it's an or operation, the second call 
	// only happens if the first is false; 
	(hitTestPoints(srcVecs, cur) || hitTestPoints(dstVecs, cur)); 
		
	//srcVecs[0].set(ofGetMouseX(), ofGetMouseY()); 
	//changed = true;
	
	
	
	
	
	cout << "MousePressed" << endl; 
};


void Warper :: mouseDragged(ofMouseEventArgs &e) {
	if(!guiVisible) return; 
	
	
	if(movingPoint) { 

		curPoint->set(e.x, e.y); 
	
		changed = true;
	
	}
	cout << "MouseDragged" << endl; 
};



void Warper :: mouseReleased(ofMouseEventArgs &e) {
	if(!guiVisible) return; 
	
	if(movingPoint) {
		movingPoint = false; 
		changed = true; 
	}
	cout << "MouseDragged" << endl; 
	
	saveSettings(); 
	//loadSettings(); 
};






