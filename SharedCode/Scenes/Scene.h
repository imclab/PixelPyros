//
//  Scene.h
//  SceneCalibration
//
//  Created by Seb Lee-Delisle on 02/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once 

#include "Arrangement.h"
#include "ParticleSystemManager.h"
#include "MotionManager.h"
#include "ofxCV.h"

#include "SceneShader.h"

class Scene { 


	public : 
	
	Scene(ParticleSystemManager& psm, ofRectangle triggerarea);
	Scene(ParticleSystemManager& psm, ofRectangle triggerarea, SceneShader *);
	
	virtual void start();
	virtual void stop();
	
	virtual bool update(float deltaTime); 
	virtual bool draw();
	
	virtual void updateMotion(MotionManager& motionManager, cv::Mat homography);
    virtual void initShaderParameters();
    SceneShader *getShader();
	
	virtual bool startArrangement(int num);
	
	Arrangement& addArrangement(TriggerPattern& pattern, bool fixedPosition = false);
	
	void updateTriggerSettings(ofRectangle triggerarea, float spacing);
	void setShowTriggerDebug(bool);
	void  setTriggersDisabled(bool disabled);

	 
 
	bool next();
	bool previous(); 
	
	bool active; 
	bool stopping;
	
    SceneShader *shader;
	
	vector <Arrangement*> arrangements;
	int currentArrangementIndex;
	int activeArrangements; 
	
	ParticleSystemManager& particleSystemManager; 
	
	ofRectangle triggerArea; 
	bool triggerDebug; 
    
private:
        
    void init(ofRectangle triggerarea);
};