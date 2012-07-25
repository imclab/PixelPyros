#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ParticleSystemSettings rocketsettings;
	
	
	rocketsettings.frequency = 3000; 
	//rocketsettings.image = smokesettings.image;
	rocketsettings.sizeStart = 1; 
	rocketsettings.sizeChange = 0; 
	rocketsettings.shimmerMin = 0.3;
	//rocketsettings.frequency = 100;
	//rocketsettings.pointInDirection = true;
	
	rocketsettings.gravity.y = 50; 
	rocketsettings.drag = 0.959; 
	rocketsettings.lifeTime = 1;
	rocketsettings.lifeTimeVar = 0.8; 
	rocketsettings.speed = 600; 
	rocketsettings.speedVar = 300; 
	
	rocketsettings.direction = 0;
	rocketsettings.directionVar = 0;
	rocketsettings.directionY = 0;
	rocketsettings.directionYVar = 180;
	
	//rocketsettings.speedVar = 200; 
	
	//rocketsettings.brightness = 100;
	//rocketsettings.brightnessVar = 80; 
	rocketsettings.saturation = 50; 
	rocketsettings.saturationVar = 50; 
	rocketsettings.hue = 120; 
	
	rocketSystem.init(rocketsettings); 
	rocketSystem.pos.set(ofGetWidth()/2, ofGetHeight()/2);
	rocketSystem.enabled = false; 
	
	
	
	ofSetFrameRate(60);
	lastUpdateTime = ofGetElapsedTimef();
	
	for(int i = 0; i<10; i++) { 
		Orb orb = Orb(); 
		
		orb.pos.set(ofMap(i, 0, 9, ofGetWidth()*0.1, ofGetWidth()*0.9), ofGetHeight() * 0.8, 0); 
		
		orbs.push_back(orb);
		
		
	}
	
	

}

//--------------------------------------------------------------
void testApp::update(){

	float time = ofGetElapsedTimef(); 
	float deltaTime =  time - lastUpdateTime; 
	
	
	rocket.update(deltaTime); 
	
	
	
	rocketSystem.pos.set(ofGetMouseX(), ofGetMouseY());
	rocketSystem.update(deltaTime); 
	
	for(int i = 0; i<orbs.size(); i++) {
		orbs.at(i).update(deltaTime); 
	}
	lastUpdateTime = time; 
	
	
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(0, 0, 0);
	ofPushStyle();
	ofEnableBlendMode(OF_BLENDMODE_ADD);

	rocketSystem.draw(); 
	
	rocket.draw(); 
	
	
	//();
	//ofEnableBlendMode(OF_BLENDMODE_ADD);

	for(int i = 0; i<orbs.size(); i++) {
		orbs.at(i).draw(); 
	}

	
	ofPopStyle();


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
	rocketSystem.enabled = true; 
	Orb& orb = orbs.at(ofRandom(orbs.size())); 
	rocket.reset(orb.pos); 
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	rocketSystem.enabled = false; 
	
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