/*
 *  Particle.cpp
 *  Particle
 *
 *  Created by Seb Lee-Delisle on 26/03/2011.
 *  Copyright 2011 seb.ly. All rights reserved.
 *
 */

#include "Particle.h"
//#include "ofMain.h"


Particle::Particle() {	
	reset(); 
}


void Particle::reset() {
	pos.set(0,0,0);
	vel.set(0,0,0);
	gravity.set(0,0,0); 
	
	lifeTime = 100; 
	drag = 1.0;
	
	fade = 0.0; 
	
	sizeStart= 1; 
	sizeEnd = 1; 
	shimmerMin = 1; 
	
	alphaStart = alphaEnd = 255; 
	
	hueStart = hueEnd = 0;
	brightnessStart = brightnessEnd = 255; 
	saturationStart = saturationEnd = 0; 
	
	color.set(255,255,255);	
	elapsedTime = 0; 
	image = NULL; 
	dragApplyCount = 0; 
	dragFrequency = 30; 
	
	pointInDirection = false; 
	
	//noiseOffset = ofRandom(100); 
	
}

bool Particle::update(float deltaTime) {
	if(!active) return false; 
	
	
	// note that this will be somewhat affected by framerate
	vel+=gravity * deltaTime; 
	
	pos+=vel * deltaTime; 
	
	elapsedTime+=deltaTime;
	
	//float hue = color.getHue();
	//hue = fmod((hue+1.0), 255.0);
	//color.setHue(hue); 
	
	//probably should find a mathematically better way to do this... 
	while(dragApplyCount < elapsedTime * dragFrequency ) {
		vel*=drag;
		dragApplyCount++; 
		
	}

	Effect::update(deltaTime); 
	if((elapsedTime>=lifeTime) && (numActiveEffects==0) )  active = false; 
	
	return active; 
}

bool Particle::draw() {
	if(!active) return false; 
	ofFill(); 
	
	float hue = ofMap(elapsedTime, 0, lifeTime, hueStart, hueEnd);
	float sat = ofMap(elapsedTime, 0, lifeTime, saturationStart, saturationEnd);
	float bri = ofMap(elapsedTime, 0, lifeTime, brightnessStart, brightnessEnd);
	float alpha = ofMap(elapsedTime, 0, lifeTime, alphaStart, alphaEnd);
	
	color.setHsb(hue, sat, bri, alpha);
	
	ofSetColor(color);
	
	// should make size easeable 
	float psize = ofMap(elapsedTime, 0, lifeTime, sizeStart, sizeEnd, true);
	
	if(shimmerMin<1)  psize*=ofRandom(shimmerMin, 1.0);//ofNoise((noiseOffset + elapsedTime)*100); //ofMap(ofNoise(lifeTime*10), 0, 1, shimmerMin, 1);  //ofRandom(shimmerMin, 1.0);
	
	ofPushMatrix(); 
	ofTranslate(pos);
	
	if(pointInDirection) { 
		//cout << "POINT IN DIRECTION " << endl; 
		ofRotateZ(ofRadToDeg(atan2(vel.y, vel.x)));
		
	}
	
	ofScale(psize, psize, psize); 

	
	if(image!=NULL){
				//cout << image->width << "\n";
		image->draw(image->width*-0.5, image->height*-0.5,image->width, image->height); 
		//ofCircle(0, 0, 10 );
		
	} else {
		//ofCircle(0, 0, 20 );
		
		ofRotateX(90); 
		ofNoFill(); 
		ofRect(-10, -10, 20, 20);
		//ofRotateY(90); 
		//ofRect(-10, -10, 20, 20);

	
	}
	ofPopMatrix();
	
	return active | Effect::draw(); 
}