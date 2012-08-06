/*
 *  CameraVidGrabber.cpp
 *  PixelPhones
 *
 *  Created by Seb Lee-Delisle on 16/03/2012.
 *  Copyright 2012 seb.ly. All rights reserved.
 *
 */

#include "CameraVidGrabber.h"

bool CameraVidGrabber::setup(string _name, int width, int height, int framerate){
	
	if(!vidGrabber.initGrabber(width, height)) return false;
	vidGrabber.setDesiredFrameRate(framerate); 
	name = _name; 
    frameNum = 0; 
	
	return true;
   
}
bool CameraVidGrabber::update() {
	vidGrabber.update(); 
    bool newFrame = vidGrabber.isFrameNew();
    
   	return newFrame; 
	
}

void CameraVidGrabber::draw(float x, float y) {
	vidGrabber.draw(x, y); 
}
ofPixelsRef CameraVidGrabber::getPixelsRef(){
	return vidGrabber.getPixelsRef();

}
int CameraVidGrabber::getWidth(){
	return vidGrabber.getWidth(); 

}
int CameraVidGrabber::getHeight(){
	return vidGrabber.getHeight(); 

}
bool CameraVidGrabber::videoSettings(){
	vidGrabber.videoSettings(); 
	
}
void CameraVidGrabber::close() { 
	vidGrabber.close(); 
	
	
}
