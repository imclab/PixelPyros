//
//  Starfield.h
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 22/08/2012.
//
//

#pragma once
#include "testApp.h"
#include "ofMain.h"

class Starfield {
	public : 
	
	Starfield() {
	
		for(int i = 0; i<5000; i++) {
			stars.push_back(ofVec3f(ofRandom(-200,APP_WIDTH+200), ofRandom(-200,APP_HEIGHT+200), ofRandom(-2000,2000)));
			
			
			
		}
		
		elapsedTime = 0; 
	}
	
	void update(float deltaTime) {
		
		for(std::vector<ofVec3f>::iterator it = stars.begin(); it != stars.end(); ++it) {
			ofVec3f& s = *it;
			//mesh.addVertex(s);
			//mesh.addColor(ofColor(ofRandom(200,255)));
			s.z+=deltaTime*50;
			if(s.z>2000) s.z-=4000;
			
		}
		elapsedTime+=deltaTime;
		
		
	}
	
	void draw() {
		
		ofPushMatrix();
		//ofRotateY(sin(elapsedTime)*5);
		ofMesh mesh ;
		mesh.setMode(OF_PRIMITIVE_POINTS);
		
		
		for(std::vector<ofVec3f>::iterator it = stars.begin(); it != stars.end(); ++it) {
			ofVec3f& s = *it;
			mesh.addVertex(s);
			mesh.addColor(ofColor(ofMap(s.z,0,-2000,255,10,true )));
			
		
		}
		
		mesh.draw();
		
		ofPopMatrix();
		
	}
	
	
	
	vector <ofVec3f> stars;
	
				 float elapsedTime; 
	
	
	
};