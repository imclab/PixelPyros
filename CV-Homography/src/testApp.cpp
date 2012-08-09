#include "testApp.h"

using namespace ofxCv;
using namespace cv;

void testApp::setup() {
	//ofSetVerticalSync(true);
	

	right.loadImage("JubileeLibrary.jpg");

	warper.setSourceImage(right); 
	
	warper.guiVisible = true; 
				   
				   
				   
}

void testApp::update() {
	
	warper.update(); 
	 
 
}

void testApp::draw() {
	
	warper.draw();
		
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
}

void testApp::keyPressed(int key) {
	
	if(key == 'g') { 
		warper.toggleGui(); 
	}
	
}