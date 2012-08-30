
#pragma once

#include "Scene.h"
#include "ParticleRendererShape.h"
#include "ParticleRendererLowRes.h"
#include "RocketSettings.h"
#include "ParticleSystemSettings.h"
#include "testApp.h"

class SceneRetro : public Scene {

	public :

	SceneRetro (ParticleSystemManager& psm, ofRectangle* triggerarea) ;

	bool draw();
	
	RocketSettings getRetroRocket(float hue = -30, float hueChange = 40);
	ParticleSystemSettings getPixelTrailParticles(float hue = -30, float hueChange = 40);
	ParticleSystemSettings getPixelExplosionParticles(float hue = -30, float hueChange = 40);

	RocketSettings getRetroFountain(); 
	
	RocketSettings getFluffyRocket();
    
	unsigned int pixelSize; 
    
    virtual void initShaderParameters();
};