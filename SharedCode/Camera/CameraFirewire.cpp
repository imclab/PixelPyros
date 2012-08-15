/*
 *  CameraFirewire.cpp
 *  PixelPhones
 *
 *  Created by Seb Lee-Delisle on 16/03/2012.
 *  Copyright 2012 seb.ly. All rights reserved.
 *
 */

#include "CameraFirewire.h"

bool CameraFirewire::setup(string _name, int width, int height, int framerate){
	
    //camera.setBayerMode(DC1394_COLOR_FILTER_GBRG);
//    camera.set1394b(true); 

    
	// setup() will pick the first camera. Or if there are multiple cameras you
	// can use the number, or the GUID of the camera.
    if(!camera.setup()) return false;
	
    camera.setBayerMode(DC1394_COLOR_FILTER_GBRG);
    
	
	unsigned int min, max; 
	camera.getBrightnessRawRange(&min, &max);
	camera.getGammaRawRange(&min, &max);

	cout << "min " << min << " max " << max << endl; 
	//camera.setExposureRaw(1);
    //camera.setFeatureAbs(<#dc1394feature_t feature#>, <#float value#>)tBayerMode(DC1394_COLOR_FILTER_GBRG);
   // setGain(500); 
   // setShutter(framerate); 
    name = _name; 
    frameNum = 0; 
	
	//curFrame.allocate(width, height, OF_IMAGE_COLOR);
	
	return true; 
	
}
bool CameraFirewire::update() {
	//setShutter(50); 
	//setGain(100); 
	camera.setExposureRaw(20);
	if(camera.grabVideo(curFrame)) {
		curFrame.update();
//        
//        cout << camera.getFrameRate() << " " << 
//                camera.getGainRaw() << " " << 
//                camera.getShutterRaw() << " " << 
//                camera.getBrightnessRaw() << " " << 
//                camera.getExposureRaw() << " " << 
//                camera.getGammaRaw() << "\n"; 
                
        return true;
	}	
    return false; 
}

void CameraFirewire::draw(float x, float y) {
	curFrame.draw(x, y); 
}

void CameraFirewire::draw(float x, float y, float w, float h) {
	curFrame.draw(x, y, w, h); 
}

ofPixelsRef CameraFirewire::getPixelsRef(){
	return curFrame.getPixelsRef();
    
}
float CameraFirewire::getWidth(){
	return camera.getWidth(); 
    
}
float CameraFirewire::getHeight(){
	return camera.getHeight(); 
    
}
bool CameraFirewire::videoSettings(){
	//camera.videoSettings(); 
	
}
void CameraFirewire::close() { 
	
}

void CameraFirewire :: initControlPanel(ofxAutoControlPanel &gui, float w) { 
	
	gui.addLabel("Firewire camera");
	
	unsigned int min, max; 
	
	
	gui.addSlider("Shutter", "FW_SHUTTER", getShutter(), 1, 500, true)->setDimensions(400, 10); // actual top limit is 4000
	
	gui.addSlider("Brightness", "FW_BRIGHTNESS", getBrightness(), 0, 255, true)->setDimensions(400, 10); ;
	
	gui.addSlider("Gain", "FW_GAIN", getGain(), 180, 1023, true)->setDimensions(400, 10); ;
	
	gui.addSlider("Gamma", "FW_GAMMA", getGamma(), 10, 22, true)->setDimensions(400, 10); ;	

	
}


int CameraFirewire::getGain() { 
	return camera.getGainRaw(); 
}

void CameraFirewire::setGain(int v) { 
	camera.setGainRaw(v); 
	
	//cout << "gain " << camera.getGainRaw() << "\n"; 
}

int CameraFirewire::getGamma() { 
	return camera.getGammaRaw(); 
}

void CameraFirewire::setGamma(int v) { 
	camera.setGammaRaw(v); 
	
	//cout << "gamma " << camera.getGammaRaw() << "\n"; 
}

int CameraFirewire::getBrightness() { 
	return camera.getBrightnessRaw(); 
}

void CameraFirewire::setBrightness(int v) { 
	camera.setBrightnessRaw(v); 
	
	//cout << "brightness " << camera.getGammaRaw() << "\n"; 
}

int CameraFirewire::getShutter() { 
	return camera.getShutterRaw(); 
}

void CameraFirewire::setShutter(int v) { 
	camera.setShutterRaw(v) ;
	cout << "shutter " << camera.getShutterRaw()<< "\n";  
}
