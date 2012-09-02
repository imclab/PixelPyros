

#pragma once 

#include "ParticleSystemManager.h"
#include "Scene.h"
#include "SettingsManager.h"

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
	
	void initSceneControls(SettingsManager & settingsManager) ;
	
	void updateTriggerSettings(ofRectangle triggerarea, float triggerSpacing);
	void updateTriggerDebug(bool debug);
	void setTriggersDisabled(bool disabled);
	
	bool nextArrangement();
	bool previousArrangement(); 
    
  	
	vector <Scene*> scenes;
	
	int currentSceneIndex;
	Scene * currentScene;
	string currentSceneName;
	
	float triggerSpacing;
	bool triggerShowDebug;
	bool triggersDisabled;
	
	bool nextFlag;
	bool previousFlag; 
	bool nextArrangementFlag;
	bool previousArrangementFlag;
	
	ParticleSystemManager & particleSystemManager;
	
    
};