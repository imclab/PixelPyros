//
//  Particle.h
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 30/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once

#include "PhysicsObject.h"
#include "Quint.h"
#include "LifeCycle.h"
#include "ColourModifier.h"


class Particle : public PhysicsObject{
	
	public : 
	
	Particle();
	
	void reset();
	
	bool update(float deltaTime) ;
    ofColor& getColour();
	
//	bool draw();
	
    float size;
    
	float sizeStart; 
	float sizeEnd; 
	float shimmerMin; 
	
	bool	enabled; 
	
	LifeCycle life; 
	//ParticleRendererBase * renderer;
	ColourModifier * colourModifier;
	
	ofVec3f startPos;
	
	float rotateAroundStartPos;
	
};

