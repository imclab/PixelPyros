#pragma once

#include "ofMain.h"
#include "ParticleSystem.h"
#include "PhysicsObject.h"
#include "RocketSettings.h"


#define APP_SCALE 0.7 

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit(); 
		void mousePressed( int x, int y, int button );
		void makeRocket(RocketSettings rs); 

	void setupControlPanel();
	
	void setupScenes(); 
	
	//ParticleSystem psystem; 
	//PhysicsObject rocket; 
	RocketSettings rocketSettings; 
	
	vector <ParticleSystem*> particleSystems; 
	vector <ParticleSystem*> spareParticleSystems; 
	vector <PhysicsObject*> physicsObjects; 	
	vector <PhysicsObject*> sparePhysicsObjects; 
	
	
	float lastUpdateTime; 
	
};
