//
//  SceneSpace.h
//  ArchitectureCamera
//
//  Created by Seb Lee-Delisle on 14/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//
#pragma once

#include "Scene.h"
#include "RocketBasic.h"
#include "TriggerRocket.h"
#include "RocketThinFountain.h"
#include "ParticleRendererStar.h"
#include "RocketFountain.h"

#include "Starfield.h"

class SceneSpace : public Scene {
	
	public : 
	
	SceneSpace(string scenename, ParticleSystemManager& psm, ofRectangle triggerarea) ;
	
	bool update(float deltaTime);
	bool draw();
	
	RocketSettings getPlanetRocket();
	
	RocketSettings getStarryRocket();

	ParticleRendererShape* renderer;
	
	Starfield starfield; 
	
};