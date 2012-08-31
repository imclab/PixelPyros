//
//  QuadWarp.cpp
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 30/08/2012.
//
//

#include "QuadWarp.h"

#include "matrix_funcs.h"

QuadWarp :: QuadWarp (string saveLabel) {
	
	ofAddListener(ofEvents().mousePressed, this, &QuadWarp::mousePressed);
	ofAddListener(ofEvents().mouseDragged, this, &QuadWarp::mouseDragged);
	ofAddListener(ofEvents().mouseReleased, this, &QuadWarp::mouseReleased);


	pointColour = ofColor :: white;
	dstPoints.resize(4);
	defaultDstPoints.resize(4); 
	visible = false;
	pointRadius = 10;
	curPointIndex = -1;
	lastMousePress = 0; 

}

void QuadWarp :: draw(bool lockAxis) {
	
	if(!visible) return;
	
	if(curPointIndex>=0) {
		
		ofVec3f diff(ofGetMouseX(), ofGetMouseY());
		diff-=dragStartPoint;
		diff*=0.1;
		
		if(lockAxis) {
			if(abs(diff.x)-abs(diff.y)>1) diff.y = 0;
			else if (abs(diff.y)-abs(diff.x)>1) diff.x = 0;
		}

		ofVec3f& curPoint = dstPoints[curPointIndex];
		
		
		curPoint = dragStartPoint+diff+clickOffset;
		
		curPoint.x = round(curPoint.x*10)/10;
		curPoint.y = round(curPoint.y*10)/10;
				
	}

	
	
	ofPushStyle();
	ofNoFill();
	
	
	ofEnableSmoothing();
	//ofScale(1024, 768);
	for(int i = 0; i < dstPoints.size(); i++) {
		ofSetColor(ofColor::black);
		ofSetLineWidth(3);
		
		
		ofVec3f& point = dstPoints[i];
		
		ofCircle(point, 1);
		ofSetColor(pointColour);
		ofSetLineWidth(1);
		ofCircle(point, pointRadius);
		ofCircle(point, 1);
	
		if(i == curPointIndex){
			
			ofLine(point.x, point.y - 100, point.x, point.y+100); 
			ofLine(point.x-100, point.y, point.x+100, point.y);
			
			ofDrawBitmapStringHighlight(ofToString(point.x), point.x, point.y-30, ofColor(0,0,0,100));
			ofDrawBitmapStringHighlight(ofToString(point.y), point.x-30, point.y, ofColor(0,0,0,100));
		}
		
		
	}
	
	
	ofPopStyle();
	
}


void QuadWarp ::setDstPoint(int index, ofVec3f point, bool setAsDefault ){
	

	dstPoints[index] = point;
	if(setAsDefault) defaultDstPoints[index] = point;
	
	
}

// stolen from ofxAppUtils - thanks danomatika ! 

void QuadWarp ::apply(ofRectangle sourceRect){
	
	
	// we set it to the default - 0 translation
	// and 1.0 scale for x y z and w
	for(int i = 0; i < 16; i++) {
		if(i % 5 != 0) _glWarpMatrix[i] = 0.0;
		else _glWarpMatrix[i] = 1.0;
	}
	
	// source and destination points
	double src[4][2];
	double dest[4][2];
	
	// we set the warp coordinates
	// source coordinates as the dimensions of our window
	src[0][0] = sourceRect.x;
	src[0][1] = sourceRect.y;
	src[1][0] = sourceRect.width;
	src[1][1] = sourceRect.y;
	src[2][0] = sourceRect.width;
	src[2][1] = sourceRect.height;
	src[3][0] = sourceRect.x;
	src[3][1] = sourceRect.height;
	
	// corners are in 0.0 - 1.0 range
	// so we scale up so that they are at the render scale
	for(int i = 0; i < 4; i++){
		dest[i][0] = dstPoints[i].x;// * (float) width;
		dest[i][1] = dstPoints[i].y;// * (float) height;
	}
	
	// perform the warp calculation
	mapQuadToQuad(src, dest, _warpMatrix);
	
	// copy the values
	_glWarpMatrix[0]	= _warpMatrix[0][0];
	_glWarpMatrix[1]	= _warpMatrix[0][1];
	_glWarpMatrix[3]	= _warpMatrix[0][2];
	
	_glWarpMatrix[4]	= _warpMatrix[1][0];
	_glWarpMatrix[5]	= _warpMatrix[1][1];
	_glWarpMatrix[7]	= _warpMatrix[1][2];
	
	_glWarpMatrix[12]	= _warpMatrix[2][0];
	_glWarpMatrix[13]	= _warpMatrix[2][1];
	_glWarpMatrix[15]	= _warpMatrix[2][2];
	
	// finally lets multiply our matrix
	glMultMatrixf(_glWarpMatrix);

	
	
	
}; 


void QuadWarp :: mousePressed(ofMouseEventArgs &e) {
	
	if(!visible) return;
	
		
	ofVec3f clickPoint(e.x, e.y);
	
	for(int i = 0; i < dstPoints.size(); i++) {
		if(dstPoints[i].distance(clickPoint) < pointRadius) {
			curPointIndex = i;
			ofVec3f &curPoint = dstPoints[i];
			clickOffset = curPoint - clickPoint;
			dragStartPoint = clickPoint;
			
			break;
		}
	}
		
};


void QuadWarp :: mouseDragged(ofMouseEventArgs &e) {
	if(!visible) return;
	
	
		
};



void QuadWarp :: mouseReleased(ofMouseEventArgs &e) {
	if(!visible) return;
	
	if(curPointIndex>=0) {
		
		if(ofGetElapsedTimef() - lastMousePress < 0.4) {
			dstPoints[curPointIndex] = defaultDstPoints[curPointIndex]; 
			
			
		}

		
		curPointIndex = -1;
		saveSettings(); 
	}
	
	lastMousePress  = ofGetElapsedTimef() ; 
		
	
	//saveSettings();
};


bool QuadWarp::loadSettings() {
	
	string filename = "warpdata/"+label+".xml";
	ofxXmlSettings xml;
	if(!xml.loadFile(filename))
		return false;
	
	dstPoints[0].x	= xml.getValue("quad:upperLeft:x", 0.0);
	dstPoints[0].y	= xml.getValue("quad:upperLeft:y", 0.0);
	
	dstPoints[1].x	= xml.getValue("quad:upperRight:x", 1.0);
	dstPoints[1].y	= xml.getValue("quad:upperRight:y", 0.0);
	
	dstPoints[2].x	= xml.getValue("quad:lowerRight:x", 1.0);
	dstPoints[2].y	= xml.getValue("quad:lowerRight:y", 1.0);
	
	dstPoints[3].x	= xml.getValue("quad:lowerLeft:x", 0.0);
	dstPoints[3].y	= xml.getValue("quad:lowerLeft:y", 1.0);
	
	return true;
}

void QuadWarp::saveSettings() {
	
	ofxXmlSettings xml;
	
	string filename = "warpdata/"+label+".xml";

	xml.addTag("quad");
	xml.pushTag("quad");
	
	xml.addTag("upperLeft");
	xml.pushTag("upperLeft");
	xml.addValue("x", dstPoints[0].x);
	xml.addValue("y", dstPoints[0].y);
	xml.popTag();
	
	xml.addTag("upperRight");
	xml.pushTag("upperRight");
	xml.addValue("x", dstPoints[1].x);
	xml.addValue("y", dstPoints[1].y);
	xml.popTag();
	
	xml.addTag("lowerRight");
	xml.pushTag("lowerRight");
	xml.addValue("x", dstPoints[2].x);
	xml.addValue("y", dstPoints[2].y);
	xml.popTag();
	
	xml.addTag("lowerLeft");
	xml.pushTag("lowerLeft");
	xml.addValue("x", dstPoints[3].x);
	xml.addValue("y", dstPoints[3].y);
	xml.popTag();
	
	xml.saveFile(filename);
}


