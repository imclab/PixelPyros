//
//  ParticleSystem.cpp
//  ParticlePlay3
//
//  Created by Seb Lee-Delisle on 31/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "ParticleSystem.h"

ParticleSystem::ParticleSystem (){ 

	life.lifeTime = 10; 
	life.delay = 0; 
	reset(); 

	attachedPhysicsObject = NULL; 

}

void ParticleSystem::reset(){ 
	
	life.reset(); 
	numParticlesCreated = 0; 
	finished = false; 
}


bool ParticleSystem::update(float deltaTime) { 
	
	
	life.update(deltaTime); 
	
	if(attachedPhysicsObject!=NULL) { 
		
		pos = attachedPhysicsObject->pos; 
		
	}
	
	if(life.active) {
		while(numParticlesCreated<(life.elapsedTime-life.delay)*settings.emitCount){
			Particle& p = *addParticle();
			
			if(attachedPhysicsObject!=NULL) { 
				p.pos = ((attachedPhysicsObject->pos - attachedPhysicsObject->lastPos) * ofMap(numParticlesCreated/settings.emitCount, life.lastUpdateTime, life.elapsedTimeActual,0,1)) + attachedPhysicsObject->lastPos; 
			
			}
		}
	
	}
	
	int activeParticleCount = 0; 
	
	for(int i = 0; i<particles.size(); i++) { 
		Particle &p = *(particles[i]); 
		if(!p.enabled) continue; 
		p.update(deltaTime); 
		if(!p.enabled) {
			// add to spares... 
			spareParticles.push_back(&p);
		}
		
		activeParticleCount++;
	}
	finished = ((activeParticleCount ==0) && (life.isFinished())); 
	return finished; 
}

bool ParticleSystem::draw() { 
	ofPushStyle(); 
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	for(int i = 0; i<particles.size(); i++) { 
		Particle &p = *(particles[i]); 
		if(!p.enabled) continue; 
		particles[i]->draw(); 
		
	}
	ofDisableBlendMode();
	ofPopStyle(); 
	
}

Particle* ParticleSystem :: addParticle() { 
	
	Particle * p ;
	
	if(spareParticles.size() > 0 ){
		p = spareParticles.back(); 
		spareParticles.pop_back();
	} else { 
		
		p = new Particle(); 
	
		particles.push_back(p); 
	}
	
	numParticlesCreated++; 
	initParticle(p);
	return p; 

}

Particle * ParticleSystem::initParticle(Particle * p) { 
	
	
	p->reset(); 
	
	p->pos = pos; 
	
	settings.initVelocity(p->vel); 
	
	if(settings.emitSpeedModifier!=1) { 
		p->vel *= ofMap(life.unitLifeProgress, 0, 1, 1, settings.emitSpeedModifier);
	}
	
	if((attachedPhysicsObject!=NULL) && (settings.emitInheritVelocity!=0)) {
		p->vel += (attachedPhysicsObject->vel*settings.emitInheritVelocity); 
	}
	
	p->drag = settings.drag; 
	p->gravity = settings.gravity; 

	p->life.lifeTime = ofRandom(settings.lifeMin, settings.lifeMax); 
	
	p->sizeStart = ofRandom(settings.sizeStartMin, settings.sizeStartMax); 
	
	if(settings.emitStartSizeModifier!=1) { 
		p->sizeStart *= ofMap(life.unitLifeProgress, 0, 1, 1, settings.emitStartSizeModifier);
	}
	
	p->sizeEnd = p->sizeStart * settings.sizeChangeRatio; 
	
	settings.initColourModifier(p->colourModifier, life); 	
	p->shimmerMin = settings.shimmerMin; 
	
	
	
	return p;
	
}

void ParticleSystem :: addParticles(int count) { 
	for(int i =0; i<count; i++) {
		addParticle(); 
	}
}


void ParticleSystem:: init(ParticleSystemSettings& pes) {

	life.delay = pes.emitDelay; 
	life.lifeTime = pes.emitLifeTime; 
	//attachedPhysicsObject = pes.emitAttachedPhysicsObject;
	
	//physics.drag = pes.drag; 
	//physics.gravity = pes.gravity; 
	settings = pes; 
	
	
}
