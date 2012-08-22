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
	
		for(int i = 0; i<500; i++) {
			stars.push_back(ofVec3f(ofRandom(0,APP_WIDTH), ofRandom(0,APP_HEIGHT)));
			
			
			
		}
		
	
	}
	
	
	void draw() {
		
		ofMesh mesh ;
		mesh.setMode(OF_PRIMITIVE_POINTS);
		
		
		for(std::vector<ofVec3f>::iterator it = stars.begin(); it != stars.end(); ++it) {
			ofVec3f& s = *it;
			mesh.addVertex(s);
			//mesh.addColor(ofColor(ofRandom(200,255)));
			
		
		}
		
		mesh.draw();
		
		
		
	}
	
	
	
	vector <ofVec3f> stars;
	
	
	
	
	
};