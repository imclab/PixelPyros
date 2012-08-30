//
//  QuadWarp.cpp
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 30/08/2012.
//
//

#include "QuadWarp.h"


QuadWarp :: QuadWarp (vector <ofVec3f>& quadPoints) : points(quadPoints) {
	
	ofAddListener(ofEvents().mousePressed, this, &QuadWarp::mousePressed);
	ofAddListener(ofEvents().mouseDragged, this, &QuadWarp::mouseDragged);
	ofAddListener(ofEvents().mouseReleased, this, &QuadWarp::mouseReleased);

	pointColour = ofColor :: white;

	visible = true;
	pointRadius = 10; 

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




