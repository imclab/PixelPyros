#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	
	//ofSetFrameRate(50);
	lastUpdateTime = ofGetElapsedTimef();
	
	
	ofBackground(0);

	//rocket.pos.set(ofGetWidth()/2, ofGetHeight()*0.8, 0);
	setupScenes(); 
	
	
	cameraManager.init();
	//cameraManager.shutter = 35; 
	motionManager.init(cameraManager.getWidth(), cameraManager.getHeight()); 
	
	
	setupControlPanel();
	
	soundPlayer.defaultPath = "../../../Sounds/";
	
	
	soundPlayer.addSound("Crackle", "RocketFountain", 1, 1.2, 0.5,"mp3");
	soundPlayer.addSound("ExplosionSynth1", "ExplosionSynth1");
	
	soundPlayer.addSound("mortar", "SynthThud", 1, 0.8, 0.2, "mp3");
	soundPlayer.globalVolume = 1;
	
	gui.hide();
	

}

//--------------------------------------------------------------
void testApp::update(){

	if(cameraManager.update()){
		
		ofImage image(cameraManager.getPixelsRef()); 

		motionManager.update(cameraManager.getPixelsRef());
		
		scenes[currentSceneIndex]->updateMotion(motionManager, cameraManager.warper.inverseHomography ); 
		
	}
	
	float time = ofGetElapsedTimef(); 
	float deltaTime =  time - lastUpdateTime; 

	lastUpdateTime = time;
	
	for(int i = 0; i<scenes.size(); i++) {	
		scenes[i]->update(deltaTime); 
	}
	
	particleSystemManager.update(deltaTime);

	
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(255); 
	cameraManager.draw(0,0);
	motionManager.draw();

	ofPushMatrix(); 
	
	// change perspective so we're looking up
	// THIS SHOULD BE MOVED INTO PARTICLE SYSTEMS I THINK
	//ofTranslate(0,ofGetHeight()*0.9);
	//ofRotateX(5);
	//ofTranslate(0,ofGetHeight()*-0.9);

	

	particleSystemManager.draw();
	
    ofPopMatrix();
    
	// this draws all the triggers, should be outside of the rotation upwards
    // a better solution would be to alter matrix for the particle system dependent on
    // start position. 
    
	for(int i = 0; i<scenes.size(); i++) {	
		scenes[i]->draw(); 
	}

	
	ofDrawBitmapString(ofToString(ofGetFrameRate()),20,20); 
	ofDrawBitmapString(ofToString(particleSystemManager.particleSystems.size()),20,35);
	ofDrawBitmapString(ofToString(particleSystemManager.activeParticleCount),20,50);
	
	//ofDrawBitmapString(ofToString(motion),20,50); 
	
	
	ofDisableBlendMode();
	ofSetColor(255);
    ofNoFill();
    ofRect(0,0,768*2,1024);
	ofFill();
    
    
    
}

void testApp::keyPressed(int key){
	if(key==OF_KEY_LEFT) { 
		prevScene(); 
	} else if(key==OF_KEY_RIGHT) { 
		nextScene(); 
	} else if(key=='c') { 
		cameraManager.next(); 
	} else if(key=='w') { 
		cameraManager.toggleWarperGui(); 
	}

}

void testApp:: mousePressed(int x, int y, int button ) { 
	//trigger.makeRocket();
}

void testApp:: setupScenes() { 
	
//	scenes.push_back(new SceneTest(particleSystemManager));

	scenes.push_back(new ScenePatternTest(particleSystemManager));
//
//	scenes.push_back(new SceneFountains(particleSystemManager));
//
//	scenes.push_back(new Scene1(particleSystemManager));
//	scenes.push_back(new Scene2(particleSystemManager)); 
//	
	
	currentSceneIndex = 0;

	scenes[currentSceneIndex]->start();
	
		

}

bool testApp::nextScene(){ 
	
	if(currentSceneIndex == scenes.size()-1) {
		return false; 
	} else { 
		scenes[currentSceneIndex]->stop(); 
		currentSceneIndex++; 
		scenes[currentSceneIndex]->start(); 
	
		return true; 
	}
		
}

bool testApp::prevScene(){ 
	
	if(currentSceneIndex == 0) {
		return false; 
	} else { 
		scenes[currentSceneIndex]->stop(); 
		currentSceneIndex--; 
		scenes[currentSceneIndex]->start(); 
		
		return true; 
	}
	
}


void testApp::mouseMoved( int x, int y ){
	for(int j = 0 ; j<scenes.size(); j++ ) { 
		Scene* scene1 = scenes[j];
//		vector <TriggerBase*> triggers = scene1->triggers; 
//		for(int i = 0; i<triggers.size(); i++) { 
//			TriggerBase * trigger = triggers[i]; 
//			float distance = trigger->pos.distance(ofVec3f(x,y));
//			if(distance<20) { 
//				trigger->registerMotion(1.0f-(distance/20.0f)); 
//				
//			}
//			
//		}
	}
}


void testApp::setupControlPanel() { 

	
	gui.setup(900, ofGetHeight());
	

	ofxControlPanel::setBackgroundColor(simpleColor(30, 30, 60, 200));
	ofxControlPanel::setTextColor(simpleColor(240, 50, 50, 255));
	
//	gui.loadFont("Andale Mono.ttf", 8);		
	gui.bIgnoreLayout = true;   // doesn't seem to do anything.
                                // and hungarian notation? Ew! 
	gui.addPanel("Cameras");
	
	cameraManager.initControlPanel(gui);

	gui.setWhichColumn(1);
	gui.addPanel("Motion");
	
	motionManager.initControlPanel(gui);

	gui.loadSettings("controlPanelSettings.xml");
	gui.setupEvents();
	gui.enableEvents();

	
	ofAddListener(gui.guiEvent, this, &testApp::eventsIn);
	
}

void testApp::eventsIn(guiCallbackData & data){
	
}




void testApp::exit() { 


}