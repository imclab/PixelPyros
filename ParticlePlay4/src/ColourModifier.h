//
//  ColourModifier.h
//  ParticlePlay3
//
//  Created by Seb Lee-Delisle on 31/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once

#include "ofMain.h"

class ColourModifier { 

	public : 
	ColourModifier() { 
		hueStart = 0; 
		hueEnd = 0; 
		brightnessStart = 255; 
		brightnessEnd = 255; 
		saturation = 255; 
				
	}; 
	
	void update(float unitLifeTime) { 
		float hue = ofMap(unitLifeTime, 0, 1, hueStart, hueEnd, true); 
		while (hue<0) hue+=255;
		while (hue>255) hue-=255; 
		
		colour.setHsb(hue, saturation, ofMap(unitLifeTime, 0, 1, brightnessStart, brightnessEnd, true));
		
	}
	
	ofColor colour; 
	
	
	float hueStart; 
	float hueEnd; 
	float brightnessStart; 
	float brightnessEnd; 
	float saturation; 
	
	
}; 