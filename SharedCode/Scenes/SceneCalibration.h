
#pragma once

#include "Scene.h"
#include "TriggerTest.h"

#include "ofMain.h"

class SceneCalibration : public Scene {
	
	public : 
	
	SceneCalibration(ParticleSystemManager& psm, ofRectangle triggerarea) : Scene(psm, triggerarea){		
		RocketBasic rocketSettings(100,10, 120);
		
		TriggerRocket trigger(psm);
		
		trigger.addRocketSettings(rocketSettings); 
		//addTriggers(trigger, 50, 0, ofGetHeight()*0.85, ofGetWidth());
		
		TriggerTest trigger2(psm);
		
		TriggerPattern pattern;
		
		//pattern.addTrigger(trigger);
		pattern.addTrigger(trigger2);
		
		addArrangement(pattern); 
		
		
	}
	
	virtual bool draw() {
		
		
		if((!active) || stopping) return false;
		
		ofPushStyle();
		ofEnableBlendMode(OF_BLENDMODE_ADD);
		ofSetColor(255,0,0);
		ofFill();
		ofRect(0,0,(APP_WIDTH/2), APP_HEIGHT);
		ofSetColor(0,255,0);
		ofRect(APP_WIDTH/2,0,APP_WIDTH/2, APP_HEIGHT);
		
		int numCols = APP_WIDTH/128;
		int numRows = APP_HEIGHT/128;
		ofDisableBlendMode();
		ofEnableAlphaBlending();
		ofSetColor(0,0,0,100);
		for(int x = 0; x<numCols; x++) {
			for(int y = 0; y<numRows; y++) {
				int xpos = x + round((float)x/(float)numCols);
				if((xpos+y)%2==0)
					ofRect(x*128, y*128, 128, 128);
			
			
			}
			
		}
		
		ofSetLineWidth(1);
		
		ofPopStyle(); 
	}
	
	
	
	
	
};