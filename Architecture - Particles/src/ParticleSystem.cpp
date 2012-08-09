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
	spawning = true; 
	Effect::Effect(); 
	
}


void ParticleSystem :: init(ParticleSystemSettings& settingsRef)
{
	
	settings = settingsRef;
//	elapsedTime = 0; 
//	particleCount = 0; 
//	
	image = settings.image; 	
	
	
}

bool ParticleSystem::update(float deltaTime) {
	
	
	Particle * p;
	
	if(!active) return false; 
	
	
	if((settings.spawnMode == PARTICLE_SPAWN_BURST) && spawning){ 
		particleCount = 0;
		while(particleCount< settings.frequency ) {
			makeParticle();
		}
		spawning = false;
		
	} else if((settings.spawnMode == PARTICLE_SPAWN_CONTINUOUS) && spawning) { 
		while(particleCount< elapsedTime*settings.frequency ) {
			makeParticle();
	
		}
	}
	
	Effect:: update(deltaTime); 
	
	//active = (numActiveEffects>0); 

	

	return active; 
	//cout << particleCount<<" " << elapsedTime << " " << settings.frequency << " " << (elapsedTime*settings.frequency) << " " << deltaTime << "\n";
} 

bool ParticleSystem::draw()
{
	return Effect::draw(); 
}

void ParticleSystem::makeParticles(int count)
{
	
	
	for(int i=0; i<count; i++)
	{
				
		Particle * p = makeParticle();

	
	}	
} 
Particle * ParticleSystem::makeParticle()
{
	
	Particle * p = NULL;

	p = (Particle * ) getSpareEffect(); 
	if(!p) {
		p = new Particle(); 
		addEffect(p); 
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
	p->vel.rotate(0,ofRandom(s.directionY - s.directionYVar, 
							 s.directionY + s.directionYVar),0); 
	
	p->gravity = s.gravity;
	p->drag = s.drag;
	p->lifeTime = ofRandom(s.lifeTime- s.lifeTimeVar, s.lifeTime+s.lifeTimeVar); 
	p->sizeStart = ofRandom(s.sizeStart - s.sizeStartVar,
					   s.sizeStart + s.sizeStartVar); 
	p->sizeEnd = p->sizeStart * s.sizeChange; 
	p->shimmerMin = s.shimmerMin; 
	
	p->hueStart = p->hueEnd = ofClamp(ofRandom(s.hue - s.hueVar, s.hue + s.hueVar), 0, 255);
						   
						   
	p->saturationStart = p->saturationEnd = ofClamp(ofRandom(s.saturation - s.saturationVar, s.saturation + s.saturationVar), 0, 255);
	
	p->brightnessStart = ofClamp(ofRandom(s.brightness - s.brightnessVar, s.brightness + s.brightnessVar), 0, 255);
	
	p->brightnessEnd = ofClamp(ofRandom(s.brightnessEnd - s.brightnessEndVar, s.brightnessEnd + s.brightnessEndVar), 0, 255);
	
	p->pointInDirection = s.pointInDirection; 
	
	//cout << "point in direction " << p->pointInDirection << endl; 

	// setting the image to this image. Note that NULL will 
	// passed through
	p->image = image; 
	
		
}


bool ParticleSystem::setFrequency(float f) { 
	
	if(f!=settings.frequency) { 
		settings.frequency= f; 
		particleCount = elapsedTime*f;
		return true;
	} else { 
		return false; 
	}
}

bool ParticleSystem::setSpawnMode(int m) { 	
	cout << "setting spawn mode " << m << endl; 
	settings.spawnMode= m; 
	return true;
}

void ParticleSystem::reset() { 
	particleCount = 0; 
	elapsedTime = 0; 
	Effect::reset(); 
	spawning = true; 
}
