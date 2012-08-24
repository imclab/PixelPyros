#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	useFbo = true;
	ofSetFrameRate(50);
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
	
	fbo.allocate(APP_WIDTH, APP_HEIGHT);
	fbo.begin();
	ofClear(0,0,0);
	fbo.end(); 
	
	
	

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

	ofBackground(0);
	ofSetColor(255); 
	cameraManager.draw(0,0);
	motionManager.draw();

	if(useFbo) {
		fbo.begin();
		
//		FOR TRAILS :
//		ofEnableAlphaBlending();
//		ofSetColor(0, 100);
//		ofRect(0,0,APP_WIDTH,APP_HEIGHT);
//		ofDisableAlphaBlending();
//		
		ofClear(0);
		//ofSetColor(255);
	}
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

	if(useFbo) {
		fbo.end();
		ofEnableBlendMode(OF_BLENDMODE_ADD);
		fbo.draw(0,0);
		ofDisableBlendMode();
	}
	
	ofDrawBitmapString(ofToString(ofGetFrameRate()),20,20);
	ofDrawBitmapString(ofToString(particleSystemManager.particleSystems.size()),20,35);
	ofDrawBitmapString(ofToString(particleSystemManager.activeParticleCount),20,50);
	ofDrawBitmapString(ofToString(particleSystemManager.activePhysicsObjectCount),20,65);
	// DEBUG DATA FOR SCENES / ARRANGEMENTS / TRIGGERS.
	// Should probably put this in a GUI or something... :) 
	
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
	
	
	ofDisableBlendMode();
	//ofSetColor(255);
    //ofNoFill();
    //ofRect(0,0,768*2,1024);
	ofFill();
    
    
    
}



void testApp::keyPressed(int key){
	
	
	if(key==OF_KEY_LEFT) {
		if((glutGetModifiers() & GLUT_ACTIVE_SHIFT))
			prevScene();
		else
			scenes[currentSceneIndex]->previous();
	} else if(key==OF_KEY_RIGHT) { 
		if((glutGetModifiers() & GLUT_ACTIVE_SHIFT))
			nextScene();
		else
			scenes[currentSceneIndex]->next();
	} else if(key=='c') {
		cameraManager.next(); 
	} else if(key=='w') { 
		cameraManager.toggleWarperGui(); 
	}

}
//
//void testApp:keyReleased(int key){
//	
//	
//	
//}

void testApp:: mousePressed(int x, int y, int button ) { 

}

void testApp:: setupScenes() { 
	

	ofRectangle triggerarea(APP_WIDTH*0.05 ,APP_HEIGHT*0.85,APP_WIDTH*0.9,10);
	
	
	scenes.push_back(new SceneTest(particleSystemManager, triggerarea));
	scenes.push_back(new ScenePatternTest(particleSystemManager,  triggerarea));

	scenes.push_back(new SceneFountains(particleSystemManager, triggerarea));

	scenes.push_back(new Scene1(particleSystemManager, triggerarea));
	scenes.push_back(new SceneTron(particleSystemManager, triggerarea));
	
	
	currentSceneIndex = 4;

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
		vector<Arrangement*> * arrangements = &scene1->arrangements;
		for(int k = 0; k<arrangements->size(); k++)
		{
			vector <TriggerBase*> triggers = arrangements->at(k)->triggers;
			for(int i = 0; i<triggers.size(); i++) { 
				TriggerBase * trigger = triggers[i]; 
				float distance = trigger->pos.distance(ofVec3f(x,y));
				if(distance<20) { 
					trigger->registerMotion(1.0f-(distance/20.0f)); 
					
				}
				
			}
		}
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