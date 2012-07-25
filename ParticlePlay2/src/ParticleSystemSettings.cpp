/*
 *  ParticleEmitterSettings.cpp
 *  
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
	directionY = 0; 
	directionYVar = 0; 
	
	sizeStart = 1; 
	sizeStartVar = 0; 
	sizeChange = 1; 

	drag =0.98; 
	
	hue = 0;
	hueVar = 0; 
	saturation = 0;  
	saturationVar = 0; 
	brightness = brightnessEnd = 255; 
	brightnessVar = brightnessEndVar = 0; 
	
	
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