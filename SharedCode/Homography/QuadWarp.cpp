//
//  QuadWarp.cpp
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 30/08/2012.
//
//

#include "QuadWarp.h"

#include "matrix_funcs.h"

QuadWarp :: QuadWarp (vector <ofVec3f>& quadPoints) : points(quadPoints) {
	
	ofAddListener(ofEvents().mousePressed, this, &QuadWarp::mousePressed);
	ofAddListener(ofEvents().mouseDragged, this, &QuadWarp::mouseDragged);
	ofAddListener(ofEvents().mouseReleased, this, &QuadWarp::mouseReleased);

	pointColour = ofColor :: white;

	visible = true;
	pointRadius = 10;
	curPoint = NULL; 

}

void QuadWarp :: draw() {
	
	
	ofPushStyle();
	ofNoFill();
	
	
	ofEnableSmoothing();
	//ofScale(1024, 768);
	for(int i = 0; i < points.size(); i++) {
		ofSetColor(ofColor::black);
		ofSetLineWidth(3);
		
		
		ofVec3f& point = points[i];
		
		ofCircle(point, 1);
		ofSetColor(pointColour);
		ofSetLineWidth(1);
		ofCircle(point, pointRadius);
		ofCircle(point, 1);
	
		if(&point == curPoint){
			
			ofLine(point.x, point.y - 100, point.x, point.y+100); 
			ofLine(point.x-100, point.y, point.x+100, point.y);
			
			ofDrawBitmapStringHighlight(ofToString(point.x), point.x, point.y-30, ofColor(0,0,0,100));
			ofDrawBitmapStringHighlight(ofToString(point.y), point.x-30, point.y, ofColor(0,0,0,100));
		}
		
		
	}
	
	
	ofPopStyle();
	
}


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
		dest[i][0] = points[i].x;// * (float) width;
		dest[i][1] = points[i].y;// * (float) height;
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
	
	for(int i = 0; i < points.size(); i++) {
		if(points[i].distance(clickPoint) < pointRadius) {
			curPoint = &points[i];
			clickOffset.set(curPoint->x  - clickPoint.x, curPoint->y - clickPoint.y);
			dragStartPoint = clickPoint;
			
			break;
		}
	}
		
};


void QuadWarp :: mouseDragged(ofMouseEventArgs &e) {
	if(!visible) return;
	
	
	if(curPoint!=NULL) {
		
		ofVec3f diff(e.x, e.y);
		diff-=dragStartPoint;
		diff*=0.1;
		
		
		*curPoint = dragStartPoint+diff+clickOffset;
		
		curPoint->x = round(curPoint->x*10)/10;
		curPoint->y = round(curPoint->y*10)/10;
		//*curPoint+=clickOffset;
		
		changed = true;
		
	}
	
};



void QuadWarp :: mouseReleased(ofMouseEventArgs &e) {
	if(!visible) return;
	
	if(curPoint!=NULL) {
		curPoint = NULL; 
		changed = true;
	}
	
	
	//saveSettings();
};




