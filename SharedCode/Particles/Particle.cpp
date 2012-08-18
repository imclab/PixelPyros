//
//  Particle.cpp
//  ParticlePlay3
//
//  Created by Seb Lee-Delisle on 31/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "Particle.h"

Particle::Particle() : PhysicsObject() {
	reset(); 
	//renderer = new ParticleRendererBase();
	colourModifier = new ColourModifier(); 
}


void Particle::reset() { 
	life.reset();
	
	PhysicsObject::reset(); 
	
	sizeStart = 10; 
	sizeEnd = 0; 
	shimmerMin = 0.2; 
	
	enabled = true;
	
	rotateAroundStartPos = 0;
}


bool Particle :: update(float deltaTime) { 
	if(!enabled) return false;
	
	life.update(deltaTime); 
	
	PhysicsObject::update(deltaTime);
	
    size = ofMap(life.unitLifeProgress, 0, 1, sizeStart, sizeEnd, true);
    
	if(shimmerMin!=1) {
		size = ofMap(ofRandom(1),0,1,size*shimmerMin, size);
	}
    
	colourModifier->update(life.unitLifeProgress);
	
	if(rotateAroundStartPos!=0) {
		
		pos.rotate(rotateAroundStartPos*deltaTime, startPos, ofVec3f(0,1,0));
		vel.rotate(rotateAroundStartPos*deltaTime, ofVec3f(0,1,0));
		
	}
	
	if(life.isFinished()) enabled = false; 
	return enabled; 
}

//bool Particle::draw() { 
//	if(!enabled) return false; 
//	
//	// size modifier default
//	//float size = ofMap(Quint::easeOut(life.unitLifeProgress, 0, 1, 1), 0, 1, sizeStart, sizeEnd, true); 
//	
//	
//	
//	
//	ofPushMatrix(); 
//	ofTranslate(pos);
//	ofScale(size, size, size); 
//	ofSetColor(colourModifier->colour);
//	
//	renderer->render(); 
//	ofPopMatrix(); 
//	
//	return true; 
//	
//}

ofColor& Particle:: getColour() {
    return colourModifier->colour; 

}