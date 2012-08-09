#pragma once

#include "ofMain.h"
#include "ParticleSystem.h"
#include "Orb.h"
#include "ofxAutoControlPanel.h"


#define APP_SCALE 0.7 

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit(); 

	void setupControlPanel();
	
		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	void eventsIn(guiCallbackData & data);
	
	float lastUpdateTime; 
	//Rocket rocket; 

	//ParticleSystem ps; 
	
	
	Orb orb; 
	
	ofxAutoControlPanel gui; 
	
};
