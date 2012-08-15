//
//  MotionManager.h
//  ArchitectureCamera
//
//  Created by Seb Lee-Delisle on 09/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once 

#include "ofMain.h"
#include "ofxCv.h"
using namespace cv; 
using namespace ofxCv; 

class MotionManager { 

	public : 
	
	MotionManager(int w=640, int h=480);	
	void init(int w, int h);
	
	bool update(ofPixelsRef image);
	
	void setHomography(Mat& newHomography); 
	
	float getMotionAtPosition(ofVec2f pos, int width);

	int width, height;
		
	
	Mat homography; 
	
	ofImage onePixel; 
	ofImage current; 
	ofImage previous; 
	ofImage diff; 
	ofImage smallDiff; 

};