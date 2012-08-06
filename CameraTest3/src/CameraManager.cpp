/*
 *  CameraManager.cpp
 *  PixelPhones
 *
 *  Created by Seb Lee-Delisle on 15/03/2012.
 *  Copyright 2012 seb.ly. All rights reserved.
 *
 */

#include "CameraManager.h"



CameraManager::CameraManager() { 
	//camera = new CameraVidGrabber(); 
    camera = new CameraFirewire(); 
    //camera = new CameraVidPlayer(); 

}

void CameraManager::init() { 
	
	camera->setup("vidPlayer", 1024, 768, 60); 
	
}


bool CameraManager::update() { 
	
	if(camera->getGain()!=gain) camera->setGain(gain); 
	if(camera->getGamma()!=gamma) camera->setGamma(gamma); 
	if(camera->getShutter()!=shutter) camera->setShutter(shutter); 
	if(camera->getBrightness()!=brightness) camera->setBrightness(brightness); 
	
	return camera->update();


}

void CameraManager::draw(float x, float y) { 
	
	camera->draw(x, y); 
	
}

ofPixelsRef CameraManager::getPixelsRef() { 
	return camera->getPixelsRef();

}

int CameraManager::getWidth() { 
	return camera->getWidth(); 
}

int CameraManager::getHeight() { 
	return camera->getHeight(); 
}

void CameraManager::videoSettings() {
	
	camera->videoSettings(); 
	
}


void CameraManager::close() { 

	camera->close();
	


}