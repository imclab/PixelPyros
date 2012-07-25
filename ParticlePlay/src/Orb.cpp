//
//  Orb.cpp
//  ParticlePlay
//
//  Created by Seb Lee-Delisle on 23/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "Orb.h" 

Orb::Orb() {
	
	rot1 = ofRandom(360); 
	rot2 = ofRandom(360); 
	rot3 = ofRandom(360);
	vel1 = ofRandom(400,440); 
	vel2 = ofRandom(320,380); 
	vel3 = ofRandom(280,320); 
	
	pos.set(ofGetWidth()/2, ofGetHeight()/2); 
	orbSize = 0.5; 
	
	
	ParticleSystemSettings smokesettings;
	
	smokesettings.frequency = 10; 
	smokesettings.image = new ofImage(); 
	smokesettings.image->loadImage("img/ParticleWhite.png");
	smokesettings.sizeStart = 1.2; 
	smokesettings.sizeStartVar = 0.2; 
	smokesettings.sizeChange = 0; 
	smokesettings.speed = 20;
	smokesettings.directionVar = 180; 
	smokesettings.lifeTime = 1; 
	//smokesettings.shimmerMin = 0.2; 
	smokesettings.brightness = 35;
	smokesettings.brightnessVar = 5; 
	smokesettings.hue = 120; 
	//smokesettings.hueVar = 10; 
	smokesettings.saturation = 100; 
	smokesettings.saturationVar = 50; 
	
	
	smokeSystem.init(smokesettings); 
	
	
	
}

void Orb:: update(float deltaTime)  { 
	
	rot1+= vel1 * deltaTime;
	rot2+= vel2 * deltaTime;
	rot3+= vel3 * deltaTime;
	
	smokeSystem.update(deltaTime); 



}

void Orb:: draw() { 
	// orbSize =0.3f; 
	
	ofPushMatrix(); 
	ofTranslate(pos); 
	//orbSize = 0.5; 

	cout << orbSize << "\n";
	
	ofScale(orbSize,orbSize,orbSize); 
	
	
	
	ofEnableSmoothing(); 
	//ofSetColor(255,50); 
	//ofFill();
	//ofCircle(0,0,22); 
	
	ofSetColor(200);
	ofSetLineWidth(1);
	
	ofPushMatrix(); 
	ofRotateY(30);
	ofRotateX(rot1); 
	ofNoFill(); 
	ofCircle(0, 0, 10, 20);
	ofPopMatrix(); 
	
	ofPushMatrix(); 
	ofRotateZ(120);
	ofRotateX(rot2); 
	ofNoFill(); 
	ofCircle(0, 0, 10, 20);
	ofPopMatrix(); 
	
	ofPushMatrix(); 
	ofRotateZ(240);
	ofRotateX(rot3); 
	ofNoFill(); 
	ofCircle(0, 0, 10, 20);
	ofPopMatrix(); 
	
	
	ofPopMatrix(); 
	
	
	ofDisableSmoothing(); 
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	
	
	
	ofPushMatrix(); 
	ofTranslate(pos); 
	ofScale(orbSize,orbSize,orbSize); 
	
	smokeSystem.draw(); 

	//ofSetColor(255,50); 
	//ofFill();
	//ofCircle(0,0,22); 
	
	ofSetColor(20);
	ofSetLineWidth(5);
	
	ofPushMatrix(); 
	ofRotateY(30);
	ofRotateX(rot1); 
	ofNoFill(); 
	ofCircle(0, 0, 10, 20);
	ofPopMatrix(); 
	
	ofPushMatrix(); 
	ofRotateZ(120);
	ofRotateX(rot2); 
	ofNoFill(); 
	ofCircle(0, 0, 10, 20);
	ofPopMatrix(); 
	
	ofPushMatrix(); 
	ofRotateZ(240);
	ofRotateX(rot3); 
	ofNoFill(); 
	ofCircle(0, 0, 10, 20);
	ofPopMatrix(); 
	
	
	ofPopMatrix(); 



}