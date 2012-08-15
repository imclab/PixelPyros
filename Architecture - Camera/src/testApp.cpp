#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	
	ofSetFrameRate(50);
	lastUpdateTime = ofGetElapsedTimef();
	
	
	ofBackground(0);

	//rocket.pos.set(ofGetWidth()/2, ofGetHeight()*0.8, 0);
	setupScenes(); 
	
	
	cameraManager.init();
	//cameraManager.shutter = 35; 
	
	
	setupControlPanel();
	
	gui.show();
	

}

//--------------------------------------------------------------
void testApp::update(){

	//cout << particleSystems.size() << " " << physicsObjects.size()<< endl; 
	
	if(cameraManager.update()){
		
		ofImage image(cameraManager.getPixelsRef()); 

		//motionManager.setHomography(cameraManager.warper.inverseHomography);
		motionManager.update(cameraManager.getPixelsRef());
		
		scenes[currentSceneIndex]->updateMotion(motionManager); 
		
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
	//motionManager.diff.draw(0,0, 1024,768);

	ofPushMatrix(); 
	
	// change perspective so we're looking up
	ofTranslate(0,ofGetHeight()*0.9); 
	ofRotateX(5); 
	ofTranslate(0,ofGetHeight()*-0.9);

	
	for(int i = 0; i<scenes.size(); i++) {	
		scenes[i]->draw(); 
	}
	particleSystemManager.draw();
	ofPopMatrix(); 
	
	
	
	ofDrawBitmapString(ofToString(ofGetFrameRate()),20,20); 
	ofDrawBitmapString(ofToString(particleSystemManager.particleSystems.size()),20,35); 
	
	float motion = 	motionManager.getMotionAtPosition(ofVec2f(ofGetMouseX(), ofGetMouseY()), 10);
	ofDrawBitmapString(ofToString(motion),20,50); 
	
	
	ofDisableBlendMode();
	ofSetColor(255); 
	
}

void testApp::keyPressed(int key){
	if(key==OF_KEY_LEFT) { 
		prevScene(); 
	} else if(key==OF_KEY_RIGHT) { 
		nextScene(); 
	} else if(key=='c') { 
		cameraManager.next(); 
	}

}

void testApp:: mousePressed(int x, int y, int button ) { 
	//trigger.makeRocket();
}

void testApp:: setupScenes() { 
	
	scenes.push_back(new Scene1(particleSystemManager));
	
	scenes[0]->start();
	
	currentSceneIndex = 0; 
	
	scenes.push_back(new Scene2(particleSystemManager)); 

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
		vector <Trigger*> triggers = scene1->triggers; 
		for(int i = 0; i<triggers.size(); i++) { 
			Trigger * trigger = triggers[i]; 
			float distance = trigger->pos.distance(ofVec3f(x,y));
			if(distance<20) { 
				trigger->registerMotion(1.0f-(distance/20.0f)); 
				
			}
			
		}
	}
}


void testApp::setupControlPanel() { 

	
	gui.setup(ofGetWidth(), ofGetHeight());
	

	ofxControlPanel::setBackgroundColor(simpleColor(30, 30, 60, 200));
	ofxControlPanel::setTextColor(simpleColor(240, 50, 50, 255));
	
	gui.loadFont("Andale Mono.ttf", 8);		

	cameraManager.initControlPanel(gui);
//	gui.addPanel(" Test Settings");
//	
//	gui.addToggle("Test toggle", "TEST_TOGGLE", false);
//	gui.addSlider("Test slider", "TEST_SLIDER", 50, 0, 100, false);
	
	gui.loadSettings("controlPanelSettings.xml");
	gui.setupEvents();
	gui.enableEvents();

	
	ofAddListener(gui.guiEvent, this, &testApp::eventsIn);
	
}

void testApp::eventsIn(guiCallbackData & data){
	
	//	if (data.getXmlName() == "FREQUENCY") 
	//		ps.setFrequency(data.getFloat(0));
	//	else if (data.getXmlName() ==  "SPEED" )
	//		ps.settings.speed = data.getFloat(0); 
	//	else if(data.getXmlName() ==  "SPEED_VAR") 
	//		ps.settings.speedVar = data.getFloat(0); 
	//	else if (data.getXmlName() ==  "DIRECTION" )
	//		ps.settings.direction = data.getFloat(0); 
	//	else if(data.getXmlName() ==  "DIRECTION_VAR") 
	//		ps.settings.directionVar = data.getFloat(0); 
	//	else if(data.getXmlName() ==  "POINT_IN_DIRECTION") 
	//		ps.settings.pointInDirection = (data.getInt(0)==1); 
	//	else if(data.getXmlName() ==  "GRAVITY") 
	//		ps.settings.gravity.y = data.getInt(0); 
	//	else if(data.getXmlName() ==  "SPAWN_MODE") {
	//		ps.setSpawnMode(data.getInt(0)); 
	//		ps.reset(); 
	//	}
	//	
	
	
	//lets send all events to our logger
	//	if( !data.isElement( "events logger" ) ){
	//		string logStr = data.getXmlName();
	//		
	//		for(int k = 0; k < data.getNumValues(); k++){
	//			logStr += " - " + data.getString(k);
	//		}
	//		
	//		logger.log(OF_LOG_NOTICE, "event - %s", logStr.c_str());
	//	}
	//	
	//	// print to terminal if you want to 
	//	//this code prints out the name of the events coming in and all the variables passed
	printf("testApp::eventsIn - name is %s - \n", data.getXmlName().c_str());
	if( data.getDisplayName() != "" ){
		printf(" element name is %s \n", data.getDisplayName().c_str());
	}
	for(int k = 0; k < data.getNumValues(); k++){
		if( data.getType(k) == CB_VALUE_FLOAT ){
			printf("%i float  value = %f \n", k, data.getFloat(k));
		}
		else if( data.getType(k) == CB_VALUE_INT ){
			printf("%i int    value = %i \n", k, data.getInt(k));
		}
		else if( data.getType(k) == CB_VALUE_STRING ){
			printf("%i string value = %s \n", k, data.getString(k).c_str());
		}
	}
	
	//	printf("\n");
}




void testApp::exit() { 


}