//
//  FontWriter.h
//  FontTest
//
//  Created by Seb Lee-Delisle on 21/08/2012.
//
//

#pragma once
#include "VectorFont.h"

class FontWriter {


	public : 

	FontWriter() {
		
		
		
		
	}
	
	//void addPoints(vector<int>& letter, )

	void writeText(string text) {
		
		text = ofToUpper(text); 
		ofPushStyle();
		ofEnableSmoothing();
		ofEnableAlphaBlending();
		ofEnableBlendMode(OF_BLENDMODE_ADD);
		ofSetLineWidth(2); 
		
		float xpos = 0;
		float ypos = 0; 
		
		map <int, Letter>& letters = font.letters;
			
		
		for(int i = 0; i<text.size(); i++) {
			ofSetColor(255,ofRandom(150,180));
			int character = text.at(i);
			if(character == '\n'){
				ypos+=40;
				xpos=0; 
			} else {
				drawLetter(letters[character], xpos, ypos);
				xpos+=30;
			}
		}
		
		ofPopStyle();
		
	}
	
	
	void drawLetter(Letter& letter, float x = 0, float y = 0) {
		
		ofMesh mesh;
		mesh.setMode(OF_PRIMITIVE_LINES);
		float randomness = 1;
		
		ofVec2f offset(x,y);
		
		for(int i = 0; i<letter.points.size(); i++) {
			ofVec2f random(ofRandom(-randomness,randomness),ofRandom(-randomness,randomness));
			mesh.addVertex(letter.points[i]*5+offset+random);
			mesh.addColor(ofColor(0,255,10));
				
		}
		mesh.draw();
	}
	
	VectorFont font;
	
};