//
//  CameraVidPlayer.cpp
//  PixelPhones
//
//  Created by Seb Lee-Delisle on 01/05/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "CameraVidPlayer.h"

bool CameraVidPlayer::setup(string _name, string filename, int width, int height, int framerate){
    
    
	//vidPlayer.initGrabber(width, height);
	//vidPlayer.setDesiredFrameRate(framerate); 
	
    if(!vidPlayer.loadMovie(filename)) {
	
		ofLog(OF_LOG_ERROR, "video file didn't load! ("+filename+")"); 
		return false;
    	
	}
    name = _name; 
    frameNum = 0; 
    vidPlayer.play();

    return true; 
	
}
bool CameraVidPlayer::update() {
	vidPlayer.update(); 
    bool newFrame = vidPlayer.isFrameNew();
    
   	return newFrame; 
	
}

void CameraVidPlayer::draw(float x, float y) {
	vidPlayer.draw(x, y); 
}

void CameraVidPlayer::draw(float x, float y, float w, float h) {
	vidPlayer.draw(x, y, w, h); 
}

ofPixelsRef CameraVidPlayer::getPixelsRef(){
	return vidPlayer.getPixelsRef();
}

float CameraVidPlayer::getWidth(){
	return vidPlayer.getWidth(); 
    
}
float CameraVidPlayer::getHeight(){
	return vidPlayer.getHeight(); 
    
}
bool CameraVidPlayer::videoSettings(){
	//vidPlayer.videoSettings(); 
    vidPlayer.setPosition(0); 
	
}
void CameraVidPlayer::close() { 
	vidPlayer.close(); 
	
	
}
