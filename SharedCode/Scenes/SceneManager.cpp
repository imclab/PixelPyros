

#include "SceneManager.h"


SceneManager :: SceneManager(ParticleSystemManager& psm) : particleSystemManager(psm) {
	
}

void SceneManager::addScene(Scene *scene) {
	
	
	scenes.push_back(scene);
	
	if(scenes.size() ==1) {
		changeScene(0);
	}
	
}


bool SceneManager ::update(float deltaTime){
	
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
	ofDrawBitmapString(activeSceneMap,20,85); ;
	ofDrawBitmapString(activeSceneArrangements,20,100); ;
	ofDrawBitmapString(activeArrangementNumbers,20,115); ;

	
	
}

void SceneManager ::updateMotion(MotionManager& motionManager, cv::Mat homography){
	
	if(currentScene!=NULL) currentScene->updateMotion(motionManager, homography); 

}




bool SceneManager :: changeScene(int sceneIndex) {

	if(scenes.size()<=sceneIndex) return false;
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
		} else {
			scenes[i]->stop();
		}
		
	}
	if(newSceneIndex == -1) {
		ofLog(OF_LOG_ERROR,"SceneManager :: changeScene - scene not found!");
		currentScene = NULL;
		currentSceneIndex = -1;
		return false;
	} else {
		currentSceneIndex = newSceneIndex;
		currentScene = scene;
	}
	
	return true;
}

bool SceneManager::nextScene(){
	
	if(currentSceneIndex == scenes.size()-1) {
		return false;
	} else {
		return changeScene(currentSceneIndex+1);

	}
	
}

bool SceneManager::prevScene(){
	
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
