#define APP_SCALE 1
#define APP_WIDTH 768*2*APP_SCALE
#define APP_HEIGHT 1024*APP_SCALE


#pragma once

#include "ofMain.h"
#include "Scene.h"
#include "ParticleSystemManager.h"
#include "ParticleSystemSettings.h"
#include "RocketSettings.h"
#include "CameraManagerWarped.h"
#include "SoundPlayer.h"
#include "MotionManager.h"
#include "ofxAutoControlPanel.h"
#include "Scene1.h"
#include "Scene2.h"
#include "SceneFountains.h"
#include "ScenePatternTest.h"
#include "SceneTest.h"
#include "glut/glut.h"



class testApp : public ofBaseApp{
	
public:
	
	testApp():particleSystemManager(soundPlayer) {
		
		
	};
	
	void setup();
	void update();
	void draw();
	void exit(); 
	void mousePressed( int x, int y, int button );
	void mouseMoved( int x, int y );
	void keyPressed( int key );
	
	void setupControlPanel();
	void eventsIn(guiCallbackData & data);

	void setupScenes(); 
	bool nextScene(); 
	bool prevScene(); 
	
	
	ParticleSystemManager particleSystemManager; 
	CameraManagerWarped cameraManager; 
	MotionManager		motionManager;
	SoundPlayer			soundPlayer;
	
	ofFbo	fbo; 
	bool useFbo; 
	
	ofxAutoControlPanel gui; 
	
	
	vector <Scene*> scenes; 
	
	int currentSceneIndex;
	
	float lastUpdateTime; 
	
	
};
