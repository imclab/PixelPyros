#pragma once

#include "ofMain.h"
#include "Scene.h"
#include "ParticleSystemManager.h"
#include "ParticleSystemSettings.h"
#include "RocketSettings.h"


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
	
	void setupControlPanel();
	
	void setupScenes(); 
	bool nextScene(); 
	bool prevScene(); 
	
	ParticleSystemManager particleSystemManager; 
	
	vector <Scene*> scenes; 
	int currentSceneIndex;
	
	float lastUpdateTime; 
	
	
};
