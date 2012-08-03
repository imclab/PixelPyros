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
	
	void setupControlPanel();
	
	void setupScenes(); 
	
	ParticleSystemManager particleSystemManager; 
	
	
	float lastUpdateTime; 
	
	vector <Scene*> scenes; 
	
};
