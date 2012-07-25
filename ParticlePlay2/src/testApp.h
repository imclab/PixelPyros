#pragma once

#include "ofMain.h"
#include "ParticleSystem.h"
#include "ParticleData.h"
#include "ParticleSystemSettings.h"
#include "Orb.h"
#include "Rocket.h"


#define APP_SCALE 1 

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	ParticleSystem rocketSystem;
	
	vector <Orb> orbs; 
	
	float lastUpdateTime; 
	Rocket rocket; 
	
};
