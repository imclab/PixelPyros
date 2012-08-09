//
//  Created by Seb Lee-Delisle on 30/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//



#include "Rocket.h"

Rocket :: Rocket(): Particle() { 
	
	
	//cout << "making new rocket" << "\n"; 
	
	rocketTrail = new ParticleSystem(); 
	makeRocketTrail(rocketTrail); 
	addEffect(rocketTrail);
	
	explosionBurst = new ParticleSystem(); 
	makeExplosionBurst(explosionBurst); 
	addEffect(explosionBurst); 
	
	reset(); 
	
	//cout << "new rocket particlesystem count : " << particleSystems.size() << "\n";
	
	
}

void Rocket :: reset() { 
	
	Particle::reset(); 
	
	pos.set(ofGetWidth()/2, ofGetHeight()*0.9, 0);
	vel.set(ofRandom(-200,200)*1, ofRandom(-800, -1200), ofRandom(-100,-200)); 
	gravity.set(0,700,0); 
	drag = 0.99;
	//cout << "new vel : " << vel << "\n"; 
	
	rocketTrail->reset(); 
	//rocketTrail->active = true; 
	//rocketTrail->settings.sizeChange = 100; 
	
	lifeTime = 1; 
	sizeEnd = 0; 
	sizeStart = 1; 
	
}

bool Rocket:: update(float deltaTime) { 

	Particle::update(deltaTime); 
	
	
	for(vector<Effect*>::iterator it = effects.begin(); it != effects.end(); ++it) {
		//if(!(*it)->active) continue; 
		
		((ParticleSystem*)(*it))->pos = pos; 
		
	}
	
	if((elapsedTime>1.7) && ( rocketTrail->spawning)) { 
		rocketTrail->spawning = false; 
		explosionBurst->spawning = true; ;
		explosionBurst->reset(); 
			
	}
	
	//if((!active) && (numActiveEffects>0) ) 
		active = true; 
	
	return active; 
	
	
}

ParticleSystem* Rocket:: makeRocketTrail(ParticleSystem * rocket) { 
	
	ParticleSystemSettings s;
	
	
	s.frequency = 100; 
	s.image = new ofImage();
	s.image->loadImage("img/ParticleWhite.png");
	s.sizeStart = 0.01; 
	s.sizeChange = 40; 
	//s.shimmerMin = 0.3;
	//s.frequency = 100;
	//s.pointInDirection = true;
	
	//s.gravity.y = 50; 
	s.drag = 0.959; 
	s.lifeTime = 0.5;
	s.lifeTimeVar = 0.8; 
	s.speed = 0; 
	s.speedVar = 5; 
	
	s.direction = 0;
	s.directionVar = 0;
	
	
	//s.speedVar = 200; 
	
	s.brightness = 50;
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
	ps->active = false; 
	return ps; 
	
	
}