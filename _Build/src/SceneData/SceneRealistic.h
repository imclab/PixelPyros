
#pragma once

#include "Scene.h"
#include "ParticleRendererShape.h"
#include "ParticleRendererLowRes.h"
#include "ParticleRendererBitmap.h"
#include "RocketSettings.h"
#include "ParticleSystemSettings.h"
#include "testApp.h"


class SceneRealistic : public Scene {

	public :
		
	SceneRealistic (ParticleSystemManager& psm, ofRectangle triggerarea) ;
	
	//bool draw();
	
	RocketSettings getFlowerRocket(float hue = 20, float hueChange = -5);
	ParticleSystemSettings getFlowerTrailParticles(float hue = 20, float hueChange = -5);
	ParticleSystemSettings getFlowerExplosionParticles(float hue = 20, float hueChange = -5);
	ParticleSystemSettings getLineExplosionParticles(float hue = 20, float hueChange = -5);
	
	RocketSettings getFountain();
	
	RocketSettings getFluffyRocket();
	
	
	RocketSettings  getBangerRocket();
	ParticleSystemSettings getBangerTrails();
	ParticleSystemSettings getBangerBang();
	ParticleSystemSettings  getBangerCrackles();
	
	ParticleSystemSettings getSmoke();

	ofImage softWhiteImage; 


};