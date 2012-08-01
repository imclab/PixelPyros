//
//  ParticleSystem.h
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 30/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//


#pragma once
#include "Particle.h"
#include "ParticleSettings.h"
#include "ParticleSystemSettings.h"
#include "LifeCycle.h"

class ParticleSystem { 

	public : 
	
	ParticleSystem();
	
	void reset();
	void init(ParticleSystemSettings& pes); 
	
	bool update(float deltaTime) ;
	
	bool draw();
	
	void addParticles(int count);
	
	Particle * addParticle() ;	
	Particle * initParticle(Particle * p); 
	
	vector <Particle * > particles; 
	vector <Particle * > spareParticles; 
	
	ofVec3f pos ; 
	
	
	
	LifeCycle life; 
	
	int newParticleCountPerFrame; 
	ParticleSettings settings; 
	
	
	

}; 

