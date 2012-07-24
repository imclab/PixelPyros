/*
 *  ParticleSystem.cpp
 *  ParticleTest
 *
 *  Created by Seb Lee-Delisle on 30/03/2011.
 *  Copyright 2011 seb.ly. All rights reserved.
 *
 */

#include "ParticleSystem.h"

ParticleSystem :: ParticleSystem() 
{ 
	image = NULL; 
	elapsedTime = 0; 
	particleCount = 0;
	enabled = true; 
	aliveParticlesCount = 0; 
}


void ParticleSystem :: init(ParticleSystemSettings& settingsRef)
{
	
	settings = settingsRef;
//	elapsedTime = 0; 
//	particleCount = 0; 
//	
	image = settings.image; 	
	
	
}

void ParticleSystem::update(float deltaTime)
{
	
	
	
	Particle * p;
	
	aliveParticlesCount = 0; 
	
	for(int i=0; i< particles.size(); i++)
	{
		p = &particles[i]; 
		if(!p->enabled) continue; 
		
		p->update(deltaTime); 
		if(!p->enabled) spareParticles.push_back(p); 
		else aliveParticlesCount++;
	}
	
	if(enabled) elapsedTime+=deltaTime; 

	while(particleCount< elapsedTime*settings.frequency ) {
		makeParticle();
	
	}
	
	//cout << particleCount<<" " << elapsedTime << " " << settings.frequency << " " << (elapsedTime*settings.frequency) << " " << deltaTime << "\n";
} 

void ParticleSystem::draw()
{
	
	for(int i=0; i< particles.size(); i++)
	{
		particles[i].draw(); 
	}
	
}

//void ParticleSystem::makeParticles(vector<ParticleData>* particleData)
//{
//	for(int i=0; i<particleData->size(); i++)
//	{
//		
//		//if(frequency<ofRandom(1)) continue; 
//		ParticleData  pd = particleData->at(i); 
//		
//		Particle * p = makeParticle();
//		p->pos.set(pd.x, pd.y); 
//		p->size *= pd.strength; 
//		p->vel*= pd.strength;
//		
//		particleCount++; 
//	
//	}	
//} 
void ParticleSystem::makeParticles(int count)
{
	for(int i=0; i<count; i++)
	{
		
		//if(frequency<ofRandom(1)) continue; 
		//ParticleData  pd = particleData->at(i); 
		
		Particle * p = makeParticle();
//		p->pos.set(pd.x, pd.y); 
//		p->size *= pd.strength; 
//		p->vel*= pd.strength;
//		
	
	}	
} 
Particle * ParticleSystem::makeParticle()
{
	
	Particle * p;
	
	if(spareParticles.size()>0)
	{
		p = spareParticles.back(); 
		spareParticles.pop_back(); 
		p->enabled = true; 
		
	}
	else 
	{
		particles.push_back(Particle());	
		p = &particles.back(); 
	}
	
	initParticle(p); 

	particleCount++; 

	
	return p; 
}
void ParticleSystem::initParticle(Particle * p)
{
	
	ParticleSystemSettings& s = settings; 
	
	p->reset(); 
	
	p->pos.set(pos); // = lastMousePos + (mouseVel*((float)i/(float)count)); 
	p->vel.set(ofRandom(s.speed - s.speedVar,
						s.speed + s.speedVar),0);
	
	p->vel.rotate(0, 0, ofRandom(s.direction - s.directionVar, 
								 s.direction + s.directionVar));
	p->vel.rotate(0,ofRandom(-180,180),0); 
	
	p->gravity = s.gravity;
	p->drag = s.drag;
	p->lifeTime = ofRandom(s.lifeTime- s.lifeTimeVar, s.lifeTime+s.lifeTimeVar); 
	p->sizeStart = ofRandom(s.sizeStart - s.sizeStartVar,
					   s.sizeStart + s.sizeStartVar); 
	p->sizeEnd = p->sizeStart * s.sizeChange; 
	p->shimmerMin = s.shimmerMin; 
	
	p->hueStart = p->hueEnd = ofRandom(s.hue - s.hueVar, s.hue + s.hueVar);
						   
						   
	p->saturationStart = p->saturationEnd = ofRandom(s.saturation - s.saturationVar, s.saturation + s.saturationVar);
	
	p->brightnessStart = p->brightnessEnd = ofRandom(s.brightness - s.brightnessVar, s.brightness + s.brightnessVar);
	
	p->pointInDirection = s.pointInDirection; 

	// setting the image to this image. Note that NULL will 
	// passed through
	p->image = image; 
	
	
	   

		
}
