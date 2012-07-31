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
	newParticleCountPerFrame = 1; 

}

void ParticleSystem::reset(){ 
	
	life.reset(); 
}


bool ParticleSystem::update(float deltaTime) { 
	
	
	life.update(deltaTime); 
	
	if(life.active) {
		addParticles(newParticleCountPerFrame); 
	}
	
	for(int i = 0; i<particles.size(); i++) { 
		Particle &p = *(particles[i]); 
		if(!p.enabled) continue; 
		p.update(deltaTime); 
		if(!p.enabled) {
			// add to spares... 
			spareParticles.push_back(&p);
		}
		
	}
	
	
	
	
	cout << particles.size() << " " << spareParticles.size() << endl;
	
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
		
	initParticle(p);
	return p; 

}

Particle * ParticleSystem::initParticle(Particle * p) { 
	
	
	p->reset(); 
	
	p->pos = pos; 
	
	settings.initVelocity(p->physics.vel); 
	
	p->physics.drag = settings.drag; 
	p->physics.gravity = settings.gravity; 

	p->life.lifeTime = ofRandom(settings.lifeMin, settings.lifeMax); 
	
	p->sizeStart = ofRandom(settings.sizeStartMin, settings.sizeStartMax); 
	p->sizeEnd = p->sizeStart * settings.sizeChangeRatio; 

	settings.initColourModifier(p->colourModifier); 	
	p->shimmerMin = settings.shimmerMin; 
	
	
	return p;
	
}

void ParticleSystem :: addParticles(int count) { 
	for(int i =0; i<count; i++) {
		addParticle(); 
	}
}


void ParticleSystem:: init(ParticleEmitterSettings& pes) {

	life.delay = ofRandom(pes.delayMin, pes.delayMax); 
	life.lifeTime = ofRandom(pes.lifeTimeMin, pes.lifeTimeMax); 
	
	//physics.drag = pes.drag; 
	//physics.gravity = pes.gravity; 
	settings = pes.settings; 
	
	
}
