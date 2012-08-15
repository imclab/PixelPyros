#pragma once

#include "ofMain.h"
#include "Scene.h"
#include "ParticleSystemManager.h"
#include "ParticleSystemSettings.h"
#include "RocketSettings.h"
#include "CameraManagerWarped.h"
#include "MotionManager.h"
#include "ofxAutoControlPanel.h"
#include "Scene1.h"
#include "Scene2.h"

#define APP_SCALE 1

class testApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	void exit(); 
	void mousePressed( int x, int y, int button );
	void mouseMoved( int x, int y );
	void keyPressed( int key );
	
	void setupControlPanel();
	void eventsIn(guiCallbackData & data);

	void setupScenes(); 
	bool nextScene(); 
	bool prevScene(); 
	
	
	ParticleSystemManager particleSystemManager; 
	CameraManagerWarped cameraManager; 
	MotionManager		motionManager; 
	
	ofxAutoControlPanel gui; 
	
	
	vector <Scene*> scenes; 
	
	int currentSceneIndex;
	
	float lastUpdateTime; 
	
	
};
