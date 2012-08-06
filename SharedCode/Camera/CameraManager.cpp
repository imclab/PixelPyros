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
	cameraFirewire		= new CameraFirewire(); 
	cameraVidPlayer		= new CameraVidPlayer(); 
    cameraVidGrabber	= new CameraVidGrabber(); 

}

void CameraManager::init() { 
	
	if(cameraFirewire->setup("Firewire", 1024, 768, 60)) {
		cameras.push_back(cameraFirewire); 
	}; 
//	if(cameraVidGrabber->setup("USB", 640, 480, 60)){
//		cameras.push_back(cameraVidGrabber); 
//	}; 
//	if(cameraVidPlayer->setup("Video", 1024, 768, 60)) {
//		cameras.push_back(cameraVidPlayer); 
//	}; 
	cameraFirewire->setGain(700); 
	if(cameras.size()==0) { 
		ofLog(OF_LOG_ERROR, "No cameras initialised!");
		camera = new CameraWrapper(); 
	} else { 
		camera = cameras[0]; 
	}
		
	
	
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

void CameraManager::next() { 
	for(int i = 0; i<cameras.size(); i++) { 
		CameraWrapper * currentCamera = cameras[i]; 
		if(currentCamera == camera) {
			if(i==cameras.size()-1) {
				camera = cameras[0];
			} else { 
				camera = cameras[i+1]; 
			}
			break; 

		}
	}
}

void CameraManager::close() { 
	for(int i = 0; i<cameras.size(); i++) {
		cameras[i]->close();
		delete cameras[i]; 
	}
	
}