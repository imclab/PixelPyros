#pragma once

#include "ofMain.h"
#include "CameraManager.h"

#define APP_SCALE 0.7 

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit(); 
		void mousePressed( int x, int y, int button );
		void mouseMoved( int x, int y );
		void keyPressed( int key );
	
	
	
	CameraManager cameraManager; 

	
	float lastUpdateTime; 
	
	
};
