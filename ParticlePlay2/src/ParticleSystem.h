/*
 *  ParticleSystem.h
 *  ParticleTest
 *
 *  Created by Seb Lee-Delisle on 30/03/2011.
 *  Copyright 2011 seb.ly. All rights reserved.
 *
 */
#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "ParticleSystemSettings.h"

class ParticleSystem{

	public : 
	
	ParticleSystem(); 
	
	ofVec3f pos; 
	
	void init(ParticleSystemSettings& settings); 
	
	void update(float deltaTime); 
	void draw(); 
	//void makeParticles(vector<ParticleData>* particleData); 
	void makeParticles(int count); 
	Particle * makeParticle(); 
	
	virtual void initParticle(Particle * p); 
	
	void reset();
	bool setFrequency(float f); 	
	bool setSpawnMode(int m); 
	
	
	vector<Particle> particles; 
	vector<Particle*> spareParticles; 
	
	ParticleSystemSettings settings;
	
	ofImage * image; 
	
	float elapsedTime; 
	int particleCount; 
	
	bool enabled; 
	int aliveParticleCount; 
	
};