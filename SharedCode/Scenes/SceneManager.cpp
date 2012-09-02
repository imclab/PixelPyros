

#include "SceneManager.h"


SceneManager :: SceneManager(ParticleSystemManager& psm) : particleSystemManager(psm) {
	nextFlag = false;
	previousFlag = false;

	nextArrangementFlag = false;
	previousArrangementFlag = false;
	

}

void SceneManager::addScene(Scene *scene) {
  
	scenes.push_back(scene);
	
	if(scenes.size() ==1) {
		changeScene(0);
	}
	
}


bool SceneManager ::update(float deltaTime){

	if(nextFlag) nextScene();
	if(previousFlag) prevScene();
	
	if(currentScene!=NULL) {
		if(nextArrangementFlag) nextArrangement();
		if(previousArrangementFlag) previousArrangement();
		
		currentSceneArrangement = ofToString ( currentScene->currentArrangementIndex + 1 ) ;
	}
	nextArrangementFlag = previousArrangementFlag = false;
	
	for(int i = 0; i<scenes.size(); i++) {
		scenes[i]->update(deltaTime);
	}
}

void SceneManager::draw() {

	for(int i = 0; i<scenes.size(); i++) {
		scenes[i]->draw();
	}
	
	string activeSceneMap = "";
	string activeSceneArrangements = "";
	string activeArrangementNumbers = "";
	for(int i = 0; i<scenes.size(); i++) {
		Scene* scene = scenes[i];

		activeSceneMap += (scene->active ? "1 " : "0 ");
		activeSceneArrangements += ofToString(scene->activeArrangements)+" ";
		activeArrangementNumbers += ofToString(scene->currentArrangementIndex)+" ";
	}
//	ofDrawBitmapString(ofToString(currentSceneIndex), 20,85);
//	ofDrawBitmapString(activeSceneMap,20,100);
//	ofDrawBitmapString(activeArrangementNumbers,20,115); ;

	
	
}

void SceneManager ::updateMotion(MotionManager& motionManager, cv::Mat homography){
	
	if(currentScene!=NULL) currentScene->updateMotion(motionManager, homography); 

}

void SceneManager::updateTriggerSettings(ofRectangle triggerarea, float spacing) {
	triggerSpacing = spacing;
	for ( int i = 0; i<scenes.size(); i++ ) {
		scenes[i]->updateTriggerSettings(triggerarea, spacing);
		
	}
}

void SceneManager::updateTriggerDebug(bool debug) {
	
	triggerShowDebug = debug;
	
	for ( int i = 0; i<scenes.size(); i++ ) {
		scenes[i]->setShowTriggerDebug (debug) ;
	}
}

void SceneManager::setTriggersDisabled(bool disabled) {
	
	triggersDisabled = disabled;
	
	for ( int i = 0; i<scenes.size(); i++ ) {
		scenes[i]->setTriggersDisabled (disabled) ;
	}
}

bool SceneManager :: changeScene(int sceneIndex) {

	if(sceneIndex>=scenes.size()) return false;
	else return changeScene(scenes[sceneIndex]);
		
		
}


bool SceneManager :: changeScene (Scene* scene) {

	if(scene == NULL ) return false;
	if(currentScene == scene) return false;
	
	int newSceneIndex = -1;
	
	for(int i = 0 ; i<scenes.size(); i++) {
		if(scenes[i] == scene) {
			newSceneIndex = i;
			scene->start();
			currentSceneIndex = newSceneIndex;
			currentScene = scene;
			currentSceneName = scene->name ;

		} else {
			scenes[i]->stop();
		}
		
	}
	if(newSceneIndex == -1) {
		ofLog(OF_LOG_ERROR,"SceneManager :: changeScene - scene not found!");
		currentScene = NULL;
		currentSceneIndex = -1;
		return false;
	}
	
	return true;
}

bool SceneManager::nextScene(){
	
	nextFlag = false;

	if(currentSceneIndex == scenes.size()-1) {
		return false;
	} else {
		return changeScene(currentSceneIndex+1);

	}
	
}

bool SceneManager::prevScene(){
	
	previousFlag = false;
	if(currentSceneIndex == 0) {
		return false;
	} else {
		return changeScene(currentSceneIndex-1);
	}
	
}


bool SceneManager::nextArrangement(){
	if(currentScene == NULL) return false;
	else return currentScene->next();
	
}

bool SceneManager::previousArrangement(){
	if(currentScene == NULL) return false;
	else return currentScene->previous();

	
}

void SceneManager::initSceneControls(SettingsManager & settingsManager) {
	
	settingsManager.addSettingString(&currentSceneName, "/PixelPyros/SceneData/content" );
	settingsManager.addSettingString(&currentSceneArrangement, "/PixelPyros/SceneArrangement/content" );
	
	for(int i = 0; i<scenes.size(); i++) {

		Scene & scene = *scenes[i];
		
		
		for(int j = 0; j<scene.arrangements.size(); j++) {
		
			settingsManager.addSettingBool(scene.arrangementTriggers[j], "", "/PixelPyros/Scenes/"+scene.name+"Arr"+ofToString(j+1)+"/x", true);
			cout << "adding " << "/PixelPyros/Scenes/"+scene.name+"Arr"+ofToString(j+1)+"/x control"<< endl;
	
		}
		
		
	}
	
	
}


