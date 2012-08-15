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
	if(cameraVidGrabber->setup("USB", 640, 480, 60)){
		cameras.push_back(cameraVidGrabber); 
	}; 
	if(cameraVidPlayer->setup("Video", "../../../TestMovies/TestPyrosCamCropped.mov", 1024, 768, 60)) {
		cameras.push_back(cameraVidPlayer); 
	}; 
	//cameraFirewire->setGain(700); 
	if(cameras.size()==0) { 
		ofLog(OF_LOG_ERROR, "No cameras initialised!");
		//camera = new CameraWrapper(); 
	} else { 
		camera = cameras[0]; 
	}
	
//	cameraPreview->vid = ofBaseDraws(camera->getPixelsRef());
		
	
	
}


bool CameraManager::update() { 
	if(!camera) {
		ofLog(OF_LOG_ERROR, "CameraManager not initialised"); 
		return false; 
	}; 
	
//	cout << toggleShowUSBControls->value.getValueB() << endl; 
//	
	if(toggleShowUSBControls->value.getValueB()){
		
		cameraVidGrabber->videoSettings(); 
		toggleShowUSBControls->value.setValue(0); 
		toggleShowUSBControls->update();
	}
	
	
	
//	if(camera->getGain()!=gain) camera->setGain(gain); 
//	if(camera->getGamma()!=gamma) camera->setGamma(gamma); 
//	if(camera->getShutter()!=shutter) camera->setShutter(shutter); 
//	if(camera->getBrightness()!=brightness) camera->setBrightness(brightness); 
	
	return camera->update();


}

void CameraManager::draw(float x, float y) { 
	
	camera->draw(x, y); 
	
}

void CameraManager::draw(float x, float y, float w, float h){
	
	camera->draw(x,y,w,h);
	
}

ofPixelsRef CameraManager::getPixelsRef() { 
	return camera->getPixelsRef();

}

float CameraManager::getWidth() { 
	return camera->getWidth(); 
}

float CameraManager::getHeight() { 
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

void CameraManager:: initControlPanel(ofxAutoControlPanel &gui){
	
	gui.addPanel("Cameras");
	
	cameraPreview = gui.addDrawableRect("video", this, 400, 300);
	
	gui.addLabel("USB camera");
	toggleShowUSBControls = gui.addToggle("Show controls", "USB_SHOW_CONTROLS", false);

	
	cameraFirewire->initControlPanel(gui, 400); 
	
	
	ofAddListener(gui.guiEvent, this, &CameraManager::guiEventsIn);
	
	
}

void CameraManager::guiEventsIn(guiCallbackData & data){

	if (data.getXmlName() == "USB_SHOW_CONTROLS") {
		
	
	} else if (data.getXmlName() == "FW_SHUTTER") { 
		
		cameraFirewire->setShutter(data.getInt(0));
		
	} else if (data.getXmlName() == "FW_GAIN") { 
		cameraFirewire->setGain(data.getInt(0));
		
	} else if (data.getXmlName() == "FW_BRIGHTNESS") { 
		cameraFirewire->setBrightness(data.getInt(0));
		
	} else if (data.getXmlName() == "FW_GAMMA") { 
		cameraFirewire->setGamma(data.getInt(0));
		
	} 
	
	
	
//	else if (data.getXmlName() ==  "SPEED" )
//		ps.settings.speed = data.getFloat(0); 
//	else if(data.getXmlName() ==  "SPEED_VAR") 
//		ps.settings.speedVar = data.getFloat(0); 
//	else if (data.getXmlName() ==  "DIRECTION" )
//		ps.settings.direction = data.getFloat(0); 
//	else if(data.getXmlName() ==  "DIRECTION_VAR") 
//		ps.settings.directionVar = data.getFloat(0); 
//	else if(data.getXmlName() ==  "POINT_IN_DIRECTION") 
//		ps.settings.pointInDirection = (data.getInt(0)==1); 
//	else if(data.getXmlName() ==  "GRAVITY") 
//		ps.settings.gravity.y = data.getInt(0); 
//	else if(data.getXmlName() ==  "SPAWN_MODE") {
//		ps.setSpawnMode(data.getInt(0)); 
//		ps.reset(); 
//	}
//
	
	
}


void CameraManager::close() { 
	for(int i = 0; i<cameras.size(); i++) {
		cameras[i]->close();
		delete cameras[i]; 
	}

}





























