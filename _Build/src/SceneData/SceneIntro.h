//
//  SceneIntro.h
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 02/09/2012.
//
//
#pragma once

#include "Scene.h"
#include "ParticleRendererShape.h"
#include "ParticleRendererLowRes.h"
#include "ParticleRendererBitmap.h"
#include "RocketSettings.h"
#include "ParticleSystemSettings.h"
#include "testApp.h"

class SceneIntro : public Scene{
	
	
	
	
	public :
	
	SceneIntro (string scenename, ParticleSystemManager& psm, ofRectangle triggerarea) ;
	
	//bool draw();
	
	virtual bool draw();
	
	
	
	RocketSettings getBasicRocket(float hue = 20, float hueChange = -5);
	
	ParticleSystemSettings getFlowerTrailParticles(float hue = 20, float hueChange = -5);
	ParticleSystemSettings getFlowerExplosionParticles(float hue = 20, float hueChange = -5);
	ParticleSystemSettings getLineExplosionParticles(float hue = 20, float hueChange = -5);
	
	RocketSettings getFountain(float hueStartOffset = 150, float hueChange = 0);
	
	ParticleSystemSettings getSmoke();
	
	ofImage softWhiteImage;
	ofImage bangerFlashImage;

	
	
	bool showText;
	
	vector <string> texts;
	int currentText;
	
	TextWriter textWriter; 
	
	
	
	
};