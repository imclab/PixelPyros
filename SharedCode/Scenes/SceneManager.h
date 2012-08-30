

#pragma once 

#include "ParticleSystemManager.h"
#include "Scene.h"

class SceneManager {

	public :
	
	SceneManager(ParticleSystemManager& psm);
	
	void addScene(Scene * scene);
	bool changeScene(int sceneIndex);
	bool changeScene(Scene * scene); 
	bool nextScene();
	bool prevScene();
	
	bool update(float deltaTime);
	void draw(); 
	void updateMotion(MotionManager& motionManager, cv::Mat homography);
	void updateTriggerArea(ofRectangle triggerarea);
	void updateTriggerDebug(bool debug);
	
	bool nextArrangement();
	bool previousArrangement(); 
	
	
	vector <Scene*> scenes;
	
	int currentSceneIndex;
	Scene * currentScene;
	
	ParticleSystemManager & particleSystemManager;
	

};