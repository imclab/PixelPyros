#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	
	ofSetFrameRate(60);
	lastUpdateTime = ofGetElapsedTimef();
	
	//setupControlPanel();
	
	//gui.hide();
	
	ofBackground(0);
	
//	rocket.reset(ofGetWidth()/2, ofGetHeight()*0.8, 0); 
//	rocket.physics.vel.y = -600;
//	rocket.physics.gravity.y = 500; 
//	
	psystem.pos.set(ofGetWidth()/2, ofGetHeight()*0.8, 0);
	setupScenes(); 

}

//--------------------------------------------------------------
void testApp::update(){

	float time = ofGetElapsedTimef(); 
	float deltaTime =  time - lastUpdateTime; 

	lastUpdateTime = time;
	
	psystem.update(deltaTime); 
	
}

//--------------------------------------------------------------
void testApp::draw(){

	ofPushMatrix(); 
	
	ofTranslate(0,ofGetHeight()*0.9); 
	ofRotateX(5); 
	ofTranslate(0,ofGetHeight()*-0.9);

	psystem.draw(); 
	// ofCircle(particle.getPos(), 2); 
	
	ofPopMatrix(); 
}

void testApp:: mousePressed(int x, int y, int button ) { 
	psystem.reset(); 
	//rocket.physics.vel.y = -600;

}

void testApp:: setupScenes() { 

	
	
	// ParticleData
	// size range
	// size modifier
	// velocity range
	// life range
	// drag 
	// gravity 
	// colour
	// colour modifier
	// renderer
	
	// EmmisionData
	// Frequency
	// Burst/continuous
	// range of start sizes for particles
	// range of colours for particles
	
	
	
	// optional colour modifier
	
	ParticleSettings ps; 
	// PHYSICS
	ps.speedMin = 20; 
	ps.speedMax = 100; 
	ps.rotationZ = 0; 
	ps.rotationZVar = 180; 
	ps.drag = 0.96; 
	ps.gravity.set(0,30); 
	
	//LIFE
	ps.lifeMin = 2; 
	ps.lifeMax = 4; 
	
	//APPEARANCE
	
	ps.sizeStartMin = 10; 
	ps.sizeStartMax = 10;
	ps.sizeChangeRatio = 2; 
	
	ps.hueStartMin = -70; 
	ps.hueStartMax = -10; 
	ps.hueChange = 0; 
	
	ps.brightnessStartMin = 150; 
	ps.brightnessStartMax = 150;
	ps.brightnessEnd = 0; 
	
	ps.saturationMin = 205; 
	ps.saturationMax = 255; 
	
	ps.shimmerMin = 1; 
	
	
	//rocket.trail->settings = ps; 
	
	
	
	
	// WHAT DOES PARTICLEEMITTERDATA STORE ? 
	// everything that we have so far in ParticleSystemSettings 
	// emission rate (over time?) 
	
	// start ParticleSettings
	// end ParticleSettings
	// if no end settings, then doesn't change
	
	// drag 
	// gravity
	
	// but also : 
	// lifeExpectancy
	// delay

	ParticleEmitterSettings pes; 
	
	
	
	pes.emitMode = PARTICLE_EMIT_CONTINUOUS;
	pes.emitCount = 200; 
	
	pes.speedMin = 300; 
	pes.speedMax = 350; 
	pes.rotationZ = 270; 
	pes.rotationZVar = 10; 
	
	pes.delayMax = pes.delayMin = 0; 
	pes.lifeTimeMax = pes.lifeTimeMin = 2;
	
	pes.drag = 0.99; 
	pes.gravity.set(0,300); 
	pes.settings = ps; 
	
	
	psystem.init(pes); 
	
	
	//ped
	
	
	
	
	
	
	
//	particleSystemData.addSettings(settings, "squareExplosion"); 
	
	// WHAT DOES ROCKETDATA STORE? 
	
	// particleSystemSettings * n
	// startDirection / Var
	// startSpeed / Var
	// gravity
	// drag
	
//	rs.
	
	
	//rocketData.addSettings(rocketsettings, "BasicRocket"); 
	
	//Scene scene1; 
	
	//scene1.addOrbs(orbData.getOrbByName["Rocket1"], defaultPositions); 
	
	//scenes.push(&scene1); 
	
	
	
	// Particle object has : 
	// PHYSICS : 
	// position 
	// velocity
	// other physics stuff 
	//		gravity
	//		drag
	
	// UPDATING / ENABLING
	// elapsedTime
	// lifeTime
	// enabled
	
	// VISUAL STUFF 
	// size
	// start / end size
	// texture
	// geometry
	// start / end colour
	
	
}






/*


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
*/

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
	//gui.saveSettings();

}