//
//  Rocket.cpp
//  ParticlePlay
//
//  Created by Seb Lee-Delisle on 24/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "Rocket.h"


Rocket :: Rocket() { 
	
	ParticleSystemSettings rocketsettings;
	
	
	rocketsettings.frequency = 300; 
	//rocketsettings.image = smokesettings.image;
	rocketsettings.sizeStart = 0.01; 
	rocketsettings.sizeChange = 100; 
	rocketsettings.shimmerMin = 0.3;
	//rocketsettings.frequency = 100;
	//rocketsettings.pointInDirection = true;
	
	rocketsettings.gravity.y = 50; 
	rocketsettings.drag = 0.959; 
	rocketsettings.lifeTime = 1;
	rocketsettings.lifeTimeVar = 0.8; 
	rocketsettings.speed = 0; 
	rocketsettings.speedVar = 5; 
	
	rocketsettings.direction = 0;
	rocketsettings.directionVar = 0;
	
	
	//rocketsettings.speedVar = 200; 
	
	rocketsettings.brightness = 255;
	rocketsettings.brightnessEnd = 0;
	
	//rocketsettings.brightnessVar = 80; 
	rocketsettings.saturation = 50; 
	rocketsettings.saturationVar = 50; 
	rocketsettings.hue = 120; 
	
	ParticleSystem ps = ParticleSystem(); 
	ps.init(rocketsettings); 
	
	particleSystems.push_back(ps);

	reset( *(new ofVec3f(0.0,0.0,0.0)) ); 
	
}

void Rocket :: update(float deltaTime) { 

	
	Particle::update(deltaTime); 
	
	for(int i = 0; i<particleSystems.size(); i++) { 
		ParticleSystem& ps = particleSystems.at(i); 
		
		ps.pos = pos; 
		ps.update(deltaTime); 
		
		
	}
	


}

void Rocket :: draw() { 
	
	for(int i = 0; i<particleSystems.size(); i++) { 
		ParticleSystem& ps = particleSystems.at(i); 
		
		ps.draw(); 
		
		
	}
	

}

void Rocket :: reset(ofVec3f& newpos) { 

	Particle::reset(); 
	pos.set(newpos);
	vel.set(ofRandom(-100,100), -1200); 
	gravity.set(0,500,0); 
	drag = 0.96;
	cout << "new vel : " << vel << "\n"; 


}