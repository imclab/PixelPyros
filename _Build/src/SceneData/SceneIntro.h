
#pragma once 

#include "Scene.h"
#include "ParticleRendererShape.h"
#include "RocketBasic.h"
#include "ParticleSystemManager.h"
#include "ofMain.h"

class SceneIntro : public Scene {
	
	public :
	
	SceneIntro (ParticleSystemManager& psm, ofRectangle* triggerarea) ;
	

	
	ofMesh textLines; 




};