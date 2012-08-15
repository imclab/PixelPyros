//
//  CameraFirewire.h
//  PixelPhones
//
//  Created by Seb Lee-Delisle on 26/04/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "CameraWrapper.h"
#include "ofxLibdc.h"
#include "ofxAutoControlPanel.h"

class CameraFirewire : public CameraWrapper{ 


    public :
	bool setup(string _name, int width = 640, int height = 480, int framerate =30);
	bool update();  // returns true if frame is new
	
	virtual ofPixelsRef getPixelsRef();	
	
	void draw(float x, float y);
	void draw(float x, float y, float w, float h); 
	float getWidth();	
	float getHeight();
	
	bool videoSettings(); 
	void close(); 
    
	void setGain(int value); 
	int getGain();
	void setShutter(int value); 
	int getShutter(); 
	
	int getGamma();
	void setGamma(int value); 
	int getBrightness();
	void setBrightness(int value); 

	void initControlPanel(ofxAutoControlPanel& gui, float w); 
	
    ofxLibdc::Camera camera;	
	
	// ofImage is where we store the current frame we grabbed from the Camera 
	ofImage curFrame;
    




};