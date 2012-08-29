
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
	
	SceneIntro (ParticleSystemManager& psm, ofRectangle* triggerarea) ;
	
	ParticleSystemSettings getSmoke();
	
	ofMesh letterMesh;




};