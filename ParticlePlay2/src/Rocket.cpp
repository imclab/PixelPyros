//
//  Rocket.cpp
//  ParticlePlay
//
//  Created by Seb Lee-Delisle on 24/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "Rocket.h"


Rocket :: Rocket(): Particle() { 
	
		
	//cout << "making new rocket" << "\n"; 
	
	rocketTrail = new ParticleSystem(); 
	makeRocketTrail(rocketTrail); 
	particleSystems.push_back(rocketTrail);

	explosionBurst = new ParticleSystem(); 
	makeExplosionBurst(explosionBurst); 
	particleSystems.push_back(explosionBurst); 
	
	reset( *(new ofVec3f(0.0,0.0,0.0)) ); 
	
	//cout << "new rocket particlesystem count : " << particleSystems.size() << "\n";


}

void Rocket :: update(float deltaTime) { 

	//cout << " rocket particlesystem count : " << particleSystems.size() << "\n";
	if(!enabled) return; 
	
	Particle::update(deltaTime); 
	
	int aliveParticleCount = 0 ; 
	
	
	for(int i = 0; i<particleSystems.size(); i++) { 
		ParticleSystem& ps = *particleSystems.at(i); 
		
	//	cout << "ps length : " << particleSystems.size() << " " << i << " " << &ps << "\n"; 
		
		
		ps.pos = pos; 
		ps.update(deltaTime); 
		aliveParticleCount+=ps.aliveParticleCount; 
		
		
	}
	
	if((!enabled) && (aliveParticleCount==0)) {
		enabled = false; 
	} else { 
		enabled = true;
	}
	rocketTrail->settings.sizeChange*=0.98;
	rocketTrail->settings.lifeTime*=0.95;
	
	//cout << "vel.y " << vel.y  << " " << rocketTrail->enabled << "\n"; 
	if((rocketTrail->enabled) && (vel.y>200)) {
		//cout << "BURST ----------------- \n"; 
		rocketTrail->enabled = false; 
		explosionBurst->enabled = true; 
		
	}
	//cout << "rocket enabled " << enabled << " " << elapsedTime << " " << aliveParticleCount << "\n";



}

void Rocket :: draw() { 
	
	if(!enabled) return; 
	for(int i = 0; i<particleSystems.size(); i++) { 
		ParticleSystem& ps = *particleSystems.at(i); 
		
		ps.draw(); 
		
		
	}
	

}

void Rocket :: reset(ofVec3f& newpos) { 

	Particle::reset(); 
	pos.set(newpos);
	vel.set(ofRandom(-100,100)*0, ofRandom(-1500, -1700), ofRandom(-100,-200)); 
	gravity.set(0,500,0); 
	drag = 0.96;
	//cout << "new vel : " << vel << "\n"; 
	
	rocketTrail->enabled = true; 
	rocketTrail->settings.sizeChange = 100; 
	//explosionBurst.enabled = false; 
		lifeTime = 1; 
	
	
}

ParticleSystem* Rocket:: makeRocketTrail(ParticleSystem * rocket) { 
	
	ParticleSystemSettings s;
	
	
	s.frequency = 300; 
	//s.image = smokesettings.image;
	s.sizeStart = 0.01; 
	s.sizeChange = 100; 
	s.shimmerMin = 0.3;
	//s.frequency = 100;
	//s.pointInDirection = true;
	
	s.gravity.y = 50; 
	s.drag = 0.959; 
	s.lifeTime = 1;
	s.lifeTimeVar = 0.8; 
	s.speed = 0; 
	s.speedVar = 5; 
	
	s.direction = 0;
	s.directionVar = 0;
	
	
	//s.speedVar = 200; 
	
	s.brightness = 255;
	s.brightnessEnd = 0;
	
	//rocketsettings.brightnessVar = 80; 
	s.saturation = 50; 
	s.saturationVar = 50; 
	s.hue = 120; 
	
	//rocketTrail = ParticleSystem(); 
	rocket->init(s); 
	
	return rocket; 
	
}

ParticleSystem *  Rocket :: makeExplosionBurst(ParticleSystem * ps) { 
	
	ParticleSystemSettings rocketsettings;
	
	rocketsettings.spawnMode = PARTICLE_SPAWN_BURST; 
	rocketsettings.frequency = 400; 
	//rocketsettings.image = smokesettings.image;
	rocketsettings.sizeStart = 2; 
	rocketsettings.sizeChange = 0; 
	rocketsettings.shimmerMin = 0.3;
	//rocketsettings.frequency = 100;
	//rocketsettings.pointInDirection = true;
	
	rocketsettings.gravity.y = 50; 
	rocketsettings.drag = 0.959; 
	rocketsettings.lifeTime = 1;
	rocketsettings.lifeTimeVar = 0.8; 
	rocketsettings.speed = 700; 
	rocketsettings.speedVar = 100; 
	
	rocketsettings.direction = 0;
	rocketsettings.directionVar = 0;
	rocketsettings.directionY = 0;
	rocketsettings.directionYVar = 180;
	
	//rocketsettings.speedVar = 200; 
	
	//rocketsettings.brightness = 100;
	//rocketsettings.brightnessVar = 80; 
	rocketsettings.saturation = 50; 
	rocketsettings.saturationVar = 50; 
	rocketsettings.hue = 120; 
	
	//ParticleSystem ps = ParticleSystem(); 
	
	
	ps->init(rocketsettings); 
	//ps.pos.set(ofGetWidth()/2, ofGetHeight()/2);
	ps->enabled = false; 
	return ps; 

	
}
