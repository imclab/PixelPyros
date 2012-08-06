#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	
	ofSetFrameRate(50);
	
	lastUpdateTime = ofGetElapsedTimef();
	
	ofBackground(0);
	
	cameraManager.init(); 
	
	cameraManager.shutter = 35; 

	

}

//--------------------------------------------------------------
void testApp::update(){

	
	float time = ofGetElapsedTimef(); 
	float deltaTime =  time - lastUpdateTime; 

	lastUpdateTime = time;
	
	
//	cameraManager.gain = 100; 
//	cameraManager.gamma = 12;
//	cameraManager.brightness = 20; 

	
	cameraManager.update(); 
	


}

//--------------------------------------------------------------
void testApp::draw(){

	cameraManager.draw(0,0); 
	
	
	
}

void testApp::keyPressed(int key){
	if(key == 'v') { 
		cameraManager.next(); 
	} else if(key == 's') { 
		cameraManager.videoSettings();
	}

}

void testApp:: mousePressed(int x, int y, int button ) { 

}

void testApp::mouseMoved( int x, int y ){
	
}

void testApp::exit() { 
	cameraManager.close(); 

}