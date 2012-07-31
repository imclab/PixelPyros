#pragma once

#include "ofMain.h"
#include "ofxAutoControlPanel.h"
#include "Rocket.h"
#include "ParticleEmitterSettings.h"
#include "ParticleSettings.h"



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
	
	ParticleSystem psystem; 
	
	void eventsIn(guiCallbackData & data);
	
	float lastUpdateTime; 
	
	
	//ofxAutoControlPanel gui; 
	
};
