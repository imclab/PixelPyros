#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	slideShow.folderPath =  "../../../SlideShowImages/";
	slideShow.reloadImages(); 
	lastUpdateTime =  0; 

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);
	
	float deltaTime = ofGetElapsedTimef() - lastUpdateTime;
	slideShow.draw(deltaTime);
	
	lastUpdateTime+=deltaTime; 

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	if(key=='s') {
		slideShow.show();
	} else if (key=='d') {
		slideShow.hide();
	}

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

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