/*
 *  CameraWrapper.h
 *  PixelPhones
 *
 *  Created by Seb Lee-Delisle on 16/03/2012.
 *  Copyright 2012 seb.ly. All rights reserved.
 *
 */

#pragma once

//#include "ofMain.h"

class CameraWrapper { 

	public : 
	
	virtual bool setup(string _name, int width = 640, int height = 480, int framerate =30){};
	virtual bool update(){};  // returns true if frame is new
	
	virtual ofPixelsRef getPixelsRef(){};	
	virtual void draw(float x, float y){}; 
	virtual int getWidth(){};	
	virtual int getHeight(){};
	virtual bool videoSettings(){}; 
	virtual void close(){}; 
    
  	virtual void setGain(int value){}; 
	virtual int getGain(){};
	virtual void setShutter(int value){}; 
	virtual int getShutter(){}; 
	
	virtual int getGamma(){};
	virtual void setGamma(int value){}; 
	virtual int getBrightness(){};
	virtual void setBrightness(int value){}; 

	
	
	int frameNum; 
	

	string name; 


};