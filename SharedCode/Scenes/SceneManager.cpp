

#include "SceneManager.h"


SceneManager :: SceneManager(ParticleSystemManager& psm) : particleSystemManager(psm) {
}

void SceneManager::addScene(Scene *scene) {
    addScene(scene, defaultShader);
}

void SceneManager::addScene(Scene *scene, SceneShader *shader) {
    scene->shader = shader;
	
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

// This should really be part of the constructor, but didn't want to change it until Seb's done
void SceneManager::setDefaultShader(SceneShader *shader) {
    defaultShader = shader;
}

SceneShader *SceneManager::getSceneShader() {
    SceneShader *sceneShader = NULL;
    
    if( currentScene != NULL ) {
        sceneShader = currentScene->getShader();
    }
    
    if( sceneShader == NULL ) {
        sceneShader = defaultShader;
    }
    
    return sceneShader;
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

void SceneManager::updateTriggerArea(ofRectangle triggerarea)
{
	for ( int i = 0; i<scenes.size(); i++ )
	{
		scenes[i]->triggerArea = triggerarea;
		if ( scenes[i]==currentScene )
			scenes[i]->updateTriggerArea = true ;
	}
}

void SceneManager::updateTriggerDebug(bool debug)
{
	for ( int i = 0; i<scenes.size(); i++ )
	{
		scenes[i]->triggerDebug = debug;
		if ( scenes[i]==currentScene )
			scenes[i]->updateTriggerDebug = true ;
	}
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
        currentScene->initShaderParameters();
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
