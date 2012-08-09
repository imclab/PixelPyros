#pragma once

#include "ofMain.h"
#include "Warper.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	
	ofImage right;
	

	Warper warper; 
	
};
