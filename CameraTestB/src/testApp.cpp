#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){
	
	
	guiSetup(); 

    drawRect.set(0, 0, ofGetWidth(), ofGetHeight());
	
	cameraManager.init();
	
	ofBackground(0,0,0);
	toggleBroadcastIDs = false; 
    calibrating = false; 
	
	
}

//--------------------------------------------------------------
void testApp::update(){
	        
        	
	cameraManager.update(); 
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
      
    cameraManager.draw(0,0); 
	
	int framerate = ofGetFrameRate();
	if(framerate<60) { 
		//ofSetColor(255,ofMap(framerate, 30, 60, 0,255, true),0); 
		ofFill();
		ofRect(0,0,10,10); 
	}

    ofNoFill(); 
    ofRect(drawRect); 
   		
	gui.draw(); 
	
	
}


void testApp::guiSetup() {
	gui.addSlider("Port number", portNum, 11995, 12000); 
	gui.addFPSCounter(); 
	
	//gui.addSlider("videoScale", vidScale, 1,4);
	//gui.addButton("resetVideo", vidReset);
//	gui.addSlider("numBitsMin", numBitsMin, 4, 15);
//	gui.addSlider("numBits", numBits, 4, 15);
//	gui.addToggle("updateVideo", phoneTracker.updateVideo);
//	gui.addToggle("updateDiff", phoneTracker.updateDiff);
//    gui.addToggle("Flip X", phoneTracker.flipX).setSize(200,30); 
//	gui.addToggle("Flip Y", phoneTracker.flipY).setSize(200,30); 
	gui.addSlider("Gain", cameraManager.gain, 180, 1023).setSize(200,30); 
	gui.addSlider("Gamma", cameraManager.gamma, 10, 22).setSize(200,30); 
	gui.addSlider("Brightness", cameraManager.brightness, 0, 255).setSize(200,30); 
	gui.addSlider("Shutter", cameraManager.shutter, 1, 512).setSize(200,30); 

	
	gui.addPage("PhoneTracking");
	
//	gui.addContent("Difference feed", phoneTracker.cvDiff,200);
//	gui.addContent("Difference blend", phoneTracker.cvDiffBlended,200);
//	gui.addSlider("differenceThreshold", phoneTracker.differenceThreshold, 0, 255).setNewColumn(true).setSize(200,30);
//	gui.addSlider("position brightness", commsManager.posBrightness,0,255).setSize(200,30); 
//	gui.addToggle("showPositions P", commsManager.showPositions).setSize(200,30); 
//	gui.addToggle("showTrails T", phoneTracker.showTrails).setSize(200,30); 
	gui.addToggle("broadcast IDs I", toggleBroadcastIDs).setNewColumn(true).setSize(200,30);
		
	//ofxSimpleGuiContent * cam = (ofxSimpleGuiContent * )&
	//gui.addContent("Camera feed", phoneTracker.cvColour, 220).setNewColumn(true);
	
//	gui.addToggle("Recording Video", phoneTracker.recording).setSize(200,30); 
//	gui.addToggle("Calibrate", calibrating).setSize(200,30); 
  //  gui.addSlider("calibrationCount", commsManager.calibrationCount,0,10000).setSize(200,30); 

		
	
	gui.addSlider("phoneFrameRate", phoneFrameRate, 1, 30).setNewColumn(true).setSize(200,30);
    gui.addSlider("blackToWhiteRatio", doubleToSingleRatio, 2, 6).setSize(200,30); 
    gui.addSlider("blackTimeOffset", blackTimeOffset, 0, 200).setSize(200,30); 
    
	gui.addPage("screenwarp"); 
	
	gui.addPage("PhoneRenderer"); 

	
	gui.loadFromXML();

	gui.show();
    

}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	if(key>='0' && key<='9') {
		gui.setPage(key - '0');
		gui.show();
	} else {
		switch(key) {
			case ' ': gui.toggleDraw(); break;
			case '[': gui.prevPage(); break;
			case ']': gui.nextPage(); break;
			//case 'p': gui.nextPageWithBlank(); break;
			case 'i':
				toggleBroadcastIDs = !toggleBroadcastIDs; 
				break; 
			   
			case 'v': 

				cameraManager.videoSettings(); 
				break;

//				
			//default:
//				ofColor col = ofColor();
//				col.setHsb(ofRandom(255), 255, 255);
//				commsManager.sendAllPhonesColour(col);
//				break; 	
				
		}
	}
	
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

void testApp::exit() { 
	
	cameraManager.close(); 
	
}