#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	
	ofSetFrameRate(60);
	lastUpdateTime = ofGetElapsedTimef();
	
	setupControlPanel();
	

	orb.reset(); 
	orb.pos.set(ofGetWidth()/2, ofGetHeight()*0.9);
	
	gui.hide();
	
	ofBackground(0);

}

//--------------------------------------------------------------
void testApp::update(){

	float time = ofGetElapsedTimef(); 
	float deltaTime =  time - lastUpdateTime; 

	
		
	lastUpdateTime = time;
	
	orb.update(deltaTime); 
	
	
}

//--------------------------------------------------------------
void testApp::draw(){

	ofPushMatrix(); 
	
	ofTranslate(0,ofGetHeight()*0.9); 
	ofRotateX(5); 
	ofTranslate(0,ofGetHeight()*-0.9);
	orb.draw(); 
	ofPopMatrix(); 
}

void testApp::setupControlPanel(){
	gui.setup("Particle", 20, 20, 250, 700);
	gui.addPanel(" Particle System Settings", 1);
	

	gui.setWhichPanel(0);
	gui.setWhichColumn(0);
	
	const vector <string> boxNames = ofSplitString("CONTINUOUS|BURST", "|");
	
	//gui.addMultiToggle("Spawn type", "SPAWN_TYPE", 0, boxNames);
//	gui.addTextDropDown("Spawn mode", "SPAWN_MODE", ps.settings.spawnMode, boxNames);
//	
//	gui.addButtonSlider("Spawn frequency", "FREQUENCY", ps.settings.frequency, 0, 5000, false);	
//	
//	gui.addButtonSlider("Start speed", "SPEED", ps.settings.speed, 0, 5000, false);	
//	gui.addButtonSlider("Speed variation", "SPEED_VAR", ps.settings.speedVar, 0, 5000, false);	
//	
////	gui.addSlider("Start speed", "SPEED", ps.settings.speed, 0, 5000, false);	
////	gui.addSlider("Speed variation", "SPEED_VAR", ps.settings.speedVar, 0, 5000, false);	
//
//	gui.addSlider("Start direction", "DIRECTION", ps.settings.direction, 0, 360, false);	
//	gui.addSlider("Direction variation", "DIRECTION_VAR", ps.settings.directionVar, 0, 180, false);	
//	
//	gui.addToggle("Point in direction", "POINT_IN_DIRECTION", ps.settings.pointInDirection);
//	
//	gui.addSlider("Gravity", "GRAVITY", ps.settings.gravity.y, 0, 1000, false);

	
	
	//gui.addSlider("AdapThresh Constant", "ADAPTHRESH_CONSTANT", 45, 0, 100, true);
	//gui.addSlider("MinContourArea", "MIN_CONTOUR_AREA", 1, 0,  50, true);
	//gui.addSlider("MaxContourArea", "MAX_CONTOUR_AREA", 300, 0, 1000, true);
	//gui.addSlider("CircularityThresh", "CIRCULARITY_THRESH", 0.8, 0, 1.0, false);
	
	
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
	gui.saveSettings();

}