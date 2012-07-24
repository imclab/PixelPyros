/*
 *  ParticleEmitterSettings.cpp
 *  HullaApp3
 *
 *  Created by Seb Lee-Delisle on 02/04/2011.
 *  Copyright 2011 seb.ly. All rights reserved.
 *
 */

#include "ParticleSystemSettings.h"


ParticleSystemSettings :: ParticleSystemSettings()
{

	frequency = 10; 
	speed = 200;
	speedVar = 50; 
	direction = 0; 
	directionVar = 180; 
	
	sizeStart = 1; 
	sizeStartVar = 0; 
	sizeChange = 1; 

	drag =0.98; 
	
	hue = 0;
	hueVar = 0; 
	saturation = 0;  
	saturationVar = 0; 
	brightness = 255; 
	brightnessVar = 0; 
	
	shimmerMin = 1; 
	
	gravity.set(0,0); 
	
	lifeTime = 3; 
	lifeTimeVar = 0; 
	image = NULL; 
	
	pointInDirection = false; 
	
	
	
}

ParticleSystemSettings:: ~ParticleSystemSettings()
{

}