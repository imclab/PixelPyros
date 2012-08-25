//
//  Particle.h
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 30/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once

#include "PhysicsObject.h"
//#include "Quint.h"
#include "ColourModifier.h"
#include "VelocityModifier.h"

class Particle : public PhysicsObject{
	
	public : 
	
	Particle();
	
	void reset();
	
	bool update(float deltaTime) ;
    ofColor& getColour();
		
    float size;
    
	float sizeStart; 
	float sizeEnd; 
	float shimmerMin; 
	
	bool	enabled; 
	
	
	ColourModifier * colourModifier;
	VelocityModifier velocityModifier;
	
	ofVec3f startPos;
	
	
	
};

