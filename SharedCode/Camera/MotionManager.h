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
#include "ofxAutoControlPanel.h"

using namespace cv; 
using namespace ofxCv; 

class MotionManager { 

	public : 
	
	MotionManager(int w=640, int h=480);	
	void init(int w, int h);
	
	bool update(ofPixelsRef image);
	void draw(); 
	
	float getMotionAtPosition(ofVec2f pos, int width);
	float getMotionAtPosition(ofVec2f pos, int width, Mat& homography);
	float getMotionAtPosition(ofVec2f topleft, ofVec2f botright);

	
	void initControlPanel(ofxAutoControlPanel& gui); 
	void guiEventsIn(guiCallbackData & data);

	
	
	int width, height;
	
	float thresholdLevel; 
		
	ofImage current; 
	ofImage previous; 
	ofImage diff; 
	
	vector <ofVec2f> motionPositions; 

};