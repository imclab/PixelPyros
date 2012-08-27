#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	useFbo = true;
	ofSetFrameRate(50);
	lastUpdateTime = ofGetElapsedTimef();
	
    receiver.setup(OSC_RECEIVER_PORT);
    std::cout << "listening on port " << OSC_RECEIVER_PORT << std::endl;
	
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
	soundPlayer.addSound("DirtyTechno", "DirtyTechno", 0.1, 0.8, 0.4, "aif", 0.1);
	soundPlayer.addSound("TechnoMortar", "TechnoMortar", 0.9, 1.2, 0.5, "mp3", 0.02);
	soundPlayer.addSound("LaunchTechno", "LaunchTechno", 0.9, 1.2, 0.5, "aif", 0.02);
	soundPlayer.addSound("LaunchTechno", "LaunchTechnoLow", 1, 0.3, 0.2, "aif", 0.01);
	soundPlayer.addSound("LaunchSweep", "LaunchSweep", 0.2, 2, 0.2, "wav", 0.02);
	soundPlayer.addSound("RetroLaunch", "RetroLaunch", 0.2, 1, 0.2, "wav", 0.02);
	soundPlayer.addSound("RetroExplosion", "RetroExplosion", 0.9, 1, 0.2, "aif", 0.02);
	soundPlayer.addSound("RetroFountain", "RetroFountain", 0.2, 1.5, 0.8, "wav", 0.02);
	soundPlayer.globalVolume = 1;
	
	gui.hide();
	
	fbo.allocate(APP_WIDTH, APP_HEIGHT);
	fbo.begin();
	ofClear(0,0,0);
	fbo.end(); 
    
    shader.load("shaders/bloom");
    bloomValue = 3;
    paused = false;
}

//--------------------------------------------------------------
void testApp::update(){
    
    while( receiver.hasWaitingMessages() )
    {
        ofxOscMessage msg;
        receiver.getNextMessage(&msg);
        handleOSCMessage(msg);
    }

	if(cameraManager.update()){
		
		ofImage image(cameraManager.getPixelsRef()); 

		motionManager.update(cameraManager.getPixelsRef());
		
		sceneManager.updateMotion(motionManager, cameraManager.warper.inverseHomography );
		
	}
	
	// HORRIBLE.
	//bloomValue = bloomValue>0 ? scenes[currentSceneIndex]->bloomLevel : 0;
	
	float time = ofGetElapsedTimef(); 
	float deltaTime =  time - lastUpdateTime;

	lastUpdateTime = time;
	
    if( !paused ) {
        sceneManager.update(deltaTime); 
        particleSystemManager.update(deltaTime);
    }
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
	sceneManager.draw(); 

	
	
	
	float rectWidth = APP_WIDTH*0.6;
	float rectHeight = APP_HEIGHT*0.3;
	
	// For testing the text box!
	if(ofGetMousePressed()) {
		
		rectWidth = ofGetMouseX() - APP_WIDTH*0.2;
		rectHeight = ofGetMouseY() - APP_HEIGHT *0.1;
		
	}

	textWriter.draw(ofRectangle(APP_WIDTH*0.2, APP_HEIGHT*0.1, rectWidth, rectHeight), "The Awesome PixelPyros Text Rendering Demo");
//	textWriter.draw(ofRectangle(500, 400, 800, 400), "One Small Step");
//	textWriter.draw(ofRectangle(800, 750, 300, 50), "One Really Small Step");
	
	
	if(useFbo) {

		fbo.end();
        
        shader.begin();
        shader.setUniformTexture("baseTexture", fbo.getTextureReference(), 0);
        shader.setUniform1f("bloom", bloomValue);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);
            glVertex2f(0, 0);
            
            glTexCoord2f(APP_WIDTH, 0);
            glVertex2f(APP_WIDTH, 0);
            
            glTexCoord2f(APP_WIDTH, APP_HEIGHT);
            glVertex2f(APP_WIDTH, APP_HEIGHT);
            
            glTexCoord2f(0, APP_HEIGHT);
            glVertex2f(0, APP_HEIGHT);
        glEnd();
        shader.end();        
        /*
		ofEnableBlendMode(OF_BLENDMODE_ADD);
		fbo.draw(0,0);
		ofDisableBlendMode();
        */
	}
	
	ofDrawBitmapString(ofToString(ofGetFrameRate()),20,20);
	ofDrawBitmapString(ofToString(particleSystemManager.particleSystems.size()),20,35);
	ofDrawBitmapString(ofToString(particleSystemManager.activeParticleCount),20,50);
	ofDrawBitmapString(ofToString(particleSystemManager.activePhysicsObjectCount),20,65);
	// DEBUG DATA FOR SCENES / ARRANGEMENTS / TRIGGERS.
	// Should probably put this in a GUI or something... :) 
	
	
	
	ofDisableBlendMode();
	//ofSetColor(255);
    //ofNoFill();
    //ofRect(0,0,768*2,1024);
	ofFill();
    
    
    
}

//--------------------------------------------------------------
void testApp::handleOSCMessage(ofxOscMessage msg) {
    string address = msg.getAddress().substr(0, msg.getAddress().find(":"));
    std::cout << "OSC Message: " << address << std::endl;
    
    if( address.compare(OSC_CMD("Present")) == 0 ) {
        std::cout << "OscClient connected" << std::endl;
    }
    else if( address.compare(OSC_CMD("NotPresent")) == 0 ) {
        std::cout << "OscClient disconnect" << std::endl;
    } else {
        std::vector<std::string> params = ofSplitString(address, "/");
        if( params.size() >= 4 ) {
            string widgetType = params[2];
            int widgetIndex = atoi(params[3].c_str());
            int widgetState = msg.getArgAsInt32(0);
            
            // Push buttons send 'on' (0) and 'off' (1000)
            if( (widgetType == "pushbutton") || (widgetType == "togglebutton") ) {
                switch( widgetIndex ) {
                    case 1:
                        if( OSC_OFF(widgetState) ) {
                            sceneManager.prevScene();
                        }
                        break;
                    
                    case 2:
                        if( OSC_OFF(widgetState) ) {
                            sceneManager.nextScene();
                        }
                        break;
                        
                    case 3:
                        if( OSC_OFF(widgetState) ) {
                            cameraManager.toggleWarperGui(); 
                        }
                        break;
                        
                    case 4:
                        if( OSC_OFF(widgetState) ) {
                            cameraManager.next(); 
                        }
                        break;
                }
            }
        }
    }
}
                               
//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
	if(key==OF_KEY_LEFT) {
		if((glutGetModifiers() & GLUT_ACTIVE_SHIFT))
			sceneManager.prevScene();
		else
			sceneManager.previousArrangement();
	} else if(key==OF_KEY_RIGHT) { 
		if((glutGetModifiers() & GLUT_ACTIVE_SHIFT))
			sceneManager.nextScene();
		else
			sceneManager.nextArrangement();
	} else if(key=='c') {
		cameraManager.next(); 
	} else if(key=='w') { 
		cameraManager.toggleWarperGui(); 
	} else if( key == 'b' ) {
        //bloomValue = bloomValue>0 ? 0 : scenes[currentSceneIndex]->bloomLevel;
    } else if( key == 'p' ) {
        paused = !paused;
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
	
	
	sceneManager.addScene(new SceneTest(particleSystemManager, triggerarea));
	//scenes.push_back(new ScenePatternTest(particleSystemManager,  triggerarea));

	//scenes.push_back(new SceneFountains(particleSystemManager, triggerarea));
	sceneManager.addScene(new SceneRetro(particleSystemManager, triggerarea));
	
	sceneManager.addScene(new SceneRealistic(particleSystemManager, triggerarea));
	sceneManager.addScene(new SceneTron(particleSystemManager, triggerarea));
	
	sceneManager.addScene(new SceneSpace(particleSystemManager, triggerarea));
	
	
}




void testApp::mouseMoved( int x, int y ){
	
	vector <Scene*>& scenes = sceneManager.scenes;
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