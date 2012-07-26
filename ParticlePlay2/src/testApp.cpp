#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	

	
	
	ofSetFrameRate(60);
	lastUpdateTime = ofGetElapsedTimef();
	
	//rockets.push_back(rocket); 
	
	for(int i = 0; i<14; i++) { 
		Orb orb = Orb(); 
		
		orb.pos.set(ofMap(i, 0, 13, ofGetWidth()/ APP_SCALE *0.1 , ofGetWidth()/ APP_SCALE *0.9), ofGetHeight()/ APP_SCALE * 0.9, 0); 
		
		orbs.push_back(orb);
		
		
	}
	
	

}

//--------------------------------------------------------------
void testApp::update(){

	float time = ofGetElapsedTimef(); 
	float deltaTime =  time - lastUpdateTime; 

	//rocket.update(deltaTime); 
	for(int i = 0; i<rockets.size(); i++) { 
		Rocket & rocket = rockets[i]; 
		if(!rocket.enabled) continue; 
		rocket.update(deltaTime); 
		if(!rocket.enabled) { 
			spareRockets.push_back(&rocket); 
		}
		
	}
	
	if(ofRandom(10)<1) makeRocket(); 
	for(int i = 0; i<orbs.size(); i++) {
		orbs.at(i).update(deltaTime); 
	}
	lastUpdateTime = time; 
	
	
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofPushMatrix(); 
	
	ofScale(APP_SCALE, APP_SCALE, APP_SCALE );
	
	ofBackground(0, 0, 0);
	ofPushStyle();
	ofEnableBlendMode(OF_BLENDMODE_ADD);

//	rocket.draw(); 
	for(int i = 0; i<rockets.size(); i++) {
		Rocket & rocket = rockets[i]; 
		if(!rocket.enabled) continue; 
		rocket.draw(); 
	}
	
	//();
	//ofEnableBlendMode(OF_BLENDMODE_ADD);

	for(int i = 0; i<orbs.size(); i++) {
		orbs.at(i).draw(); 
	}

	
	ofPopStyle();
	ofPopMatrix();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

	
	
		
//	}
		
		
		
}


void testApp::makeRocket() { 
	
	Orb& orb = orbs.at(ofRandom(orbs.size())); 
	
	if(spareRockets.size()>0) { 
		Rocket* rocket;
		rocket = spareRockets.back(); 
		spareRockets.pop_back(); 
		rocket->reset(orb.pos); 
		
	} else { 
		rockets.push_back(Rocket());	
		
		Rocket* r = &rockets.back();;
		r->reset(orb.pos); 
	}
	
	cout << "rocket count : " << rockets.size() << "\n"; 
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
		
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}