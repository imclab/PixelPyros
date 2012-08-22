#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetFrameRate(50); 
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);
	
	ofTranslate(20,20); 
	fontWriter.writeText("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	ofTranslate(0,40);
    fontWriter.writeText("1234567890");
	ofTranslate(0,40);
    fontWriter.writeText("OMG What a freaking awesome \nvector font!");
	
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	if(key=='s') {
		
	} else if (key=='d') {
	
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