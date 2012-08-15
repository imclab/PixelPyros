/*
 *  CameraManager.h
 *  PixelPhones
 *
 *  Created by Seb Lee-Delisle on 15/03/2012.
 *  Copyright 2012 seb.ly. All rights reserved.
 *
 */

#pragma once

#include "ofxLibdc.h"
#include "CameraWrapper.h"
#include "CameraVidGrabber.h"
#include "CameraFirewire.h"
#include "CameraVidPlayer.h"

#include "ofxAutoControlPanel.h"

class CameraManager : public ofBaseDraws{ 
	public : 
	
	CameraManager(); 
	void init(); 
	bool update(); 
	void draw(float x, float y); 
	void draw(float x, float y, float w, float h); 
	ofPixelsRef getPixelsRef();
	
	void setAnchorPercent(float xPct, float yPct){};
	void setAnchorPoint(float x, float y){};
	void resetAnchor(){};
	
	
	float getWidth(); 
	float getHeight(); 
	
	void videoSettings(); 
	
	void close(); 
	
	void next(); 
	
	void initControlPanel(ofxAutoControlPanel& gui); 
	void guiEventsIn(guiCallbackData & data);
	
	guiTypeToggle* toggleShowUSBControls;
	guiTypeDrawable* cameraPreview; 
	

	CameraWrapper* camera; 
	vector <CameraWrapper*> cameras; 	
	
	CameraVidGrabber*	cameraVidGrabber; 
	CameraFirewire*		cameraFirewire; 
	CameraVidPlayer*	cameraVidPlayer; 
	
	int gain; 
	int gamma;
	int shutter; 
	int brightness;
	
	//vector <CameraWrapper> cameras; 
	
	
};
