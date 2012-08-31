
#pragma once 

#include "Scene.h"
#include "ParticleRendererGlitchLine.h"

#include "ParticleRendererLine.h"
#include "RocketBasic.h"
#include "ParticleSystemManager.h"
#include "ofMain.h"
#include "TextWriter.h"

class SceneIntro : public Scene {
	
	public :
	
	SceneIntro (ParticleSystemManager& psm, ofRectangle triggerarea) ;
	
	bool update(float deltaTime); 
	
	ParticleSystemSettings getSmoke();
	ParticleSystemSettings getLetterSparks();
	ParticleSystemSettings getFuseSparkles();
	ofMesh letterMesh;




};