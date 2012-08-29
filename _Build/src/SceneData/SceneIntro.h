
#pragma once 

#include "Scene.h"
#include "ParticleRendererShape.h"
#include "RocketBasic.h"

class SceneIntro : public Scene {
	
	public :
	
	SceneIntro (ParticleSystemManager& psm, ofRectangle triggerarea) ;
	

	
	ofMesh textLines; 




};