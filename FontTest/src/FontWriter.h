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
		
		map <int, Letter>& letters = font.letters;
			
		
		for(int i = 0; i<text.size(); i++) {
			
			int character = text.at(i);
			drawLetter(letters[character], 20 + i*30, 20);
			
		}
				
		
	}
	
	
	void drawLetter(Letter& letter, float x = 0, float y = 0) {
		
		ofMesh mesh;
		mesh.setMode(OF_PRIMITIVE_LINES);
		float randomness = 1;
		
		ofVec2f offset(x,y);
		
		for(int i = 0; i<letter.points.size(); i++) {
			ofVec2f random(ofRandom(-randomness,randomness),ofRandom(-randomness,randomness));
			mesh.addVertex(letter.points[i]*5+offset);
				
		}
		mesh.draw();
	}
	
	VectorFont font;
	
};