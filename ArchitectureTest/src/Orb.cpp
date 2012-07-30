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
	
	smokeImage.loadImage("img/ParticleWhite.png"); 
	
	
	ParticleSystemSettings smokesettings;
	
	smokesettings.frequency = 10; 
	smokesettings.image = &smokeImage; 
	//smokesettings.image->loadImage();
	smokesettings.sizeStart = 0.6; 
	smokesettings.sizeStartVar = 0.1; 
	smokesettings.sizeChange = 0; 
	smokesettings.speed = 2.5;
	smokesettings.speedVar = 2.5; 
	smokesettings.directionVar = 180; 
	smokesettings.lifeTime = 1; 
	//smokesettings.shimmerMin = 0.2; 
	smokesettings.brightness = 35;
	smokesettings.brightnessVar = 5; 
	smokesettings.hue = 120; 
	//smokesettings.hueVar = 10; 
	smokesettings.saturation = 100; 
	smokesettings.saturationVar = 50; 
	smokesettings.drag = 0.96; 
	
	smokeSystem = new ParticleSystem(); 
	smokeSystem->init(smokesettings); 
	smokeSystem->start(); 

	
	addEffect(smokeSystem); 
	
}

bool Orb:: update(float deltaTime)  { 
	
	if(ofRandom(10)<1) makeRocket(); 
	
	rot1+= vel1 * deltaTime;
	rot2+= vel2 * deltaTime;
	rot3+= vel3 * deltaTime;
	
	
	smokeSystem->pos = pos; 
	
	//smokeSystem.update(deltaTime); 
	
	Effect::update(deltaTime); 
	
	return true; 
	

}

Rocket * Orb :: makeRocket() { 
	
	
	Rocket * rocket = NULL; 
	
	rocket = (Rocket * ) Effect::getSpareEffect(); 
	
	if(rocket==NULL) 
		rocket = new Rocket(); 
	rocket->pos = pos; 
	rocket->image = &smokeImage; 
	rocket->sizeStart = 0.1; 
	rocket->sizeEnd = 0; 
	//rocket->rocketTrail->settings.image = &smokeImage; 
	
	addEffect(rocket); 
	
	return rocket; 
	
	
}

bool Orb:: draw() { 
	// orbSize =0.3f; 
	
	ofPushMatrix(); 
	ofTranslate(pos); 
	//orbSize = 0.5; 

	//cout << orbSize << "\n";
	
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
	
	Effect::draw(); 

	
	ofPushMatrix(); 
	ofTranslate(pos); 
	ofScale(orbSize,orbSize,orbSize); 
	
	
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