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
#include "SceneSpace.h"
#include "SceneTron.h"
#include "SceneFountains.h"
#include "ScenePatternTest.h"
#include "SceneTest.h"
#include "glut/glut.h"

#include "ofxOsc.h"
#include <string.h>

#define OSC_NAMESPACE string("/mrmr")
#define OSC_CMD(x) (OSC_NAMESPACE + x)
#define OSC_OFF(x) (x == 0)
#define OSC_ON(x) (x == 1000)

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
    
    void handleOSCMessage(ofxOscMessage);
	
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
    
private:
    
    static const int OSC_RECEIVER_PORT = 1234;
    ofxOscReceiver receiver;
	
};
