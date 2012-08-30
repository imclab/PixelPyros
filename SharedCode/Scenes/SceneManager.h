

#pragma once 

#include "ParticleSystemManager.h"
#include "Scene.h"
#include "SceneShader.h"

class SceneManager {

public :
	
	SceneManager(ParticleSystemManager& psm);
	
	void addScene(Scene * scene);
    void addScene(Scene * scene, SceneShader *);
    
	bool changeScene(int sceneIndex);
	bool changeScene(Scene * scene); 
	bool nextScene();
	bool prevScene();
	
	bool update(float deltaTime);
	void draw(); 
	void updateMotion(MotionManager& motionManager, cv::Mat homography);
	
	bool nextArrangement();
	bool previousArrangement(); 
    
    void setDefaultShader(SceneShader *);
    SceneShader *getSceneShader();
	
	vector <Scene*> scenes;
	
	int currentSceneIndex;
	Scene * currentScene;
	
	ParticleSystemManager & particleSystemManager;
	
private:
    
    SceneShader *defaultShader;
    
};