//
//  TriggerTest.h
//  openFrameworksLib
//
//  Created by Seb Lee-Delisle on 16/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "TriggerRocket.h"

class TriggerTest : public TriggerRocket {
	
	public : 
	
	TriggerTest(ParticleSystemManager& psm): TriggerRocket (psm) {
		typeLabel = "TriggerTest"; 
		motionDecay = 100;
		type = TRIGGER_TYPE_FIRE_ON_MOTION; 
		//triggerLevel = 0.01;
		motionValueCount = 20;
		lastUpdate = 0; 
	
	};
	
	TriggerTest* clone() const{
		//cout << "clone TriggerTest"<< endl;
		
		return new TriggerTest( *this );
	}
	
	bool update(float deltaTime) { 
		// update bitmap
		
		
		if((elapsedTime-lastUpdate>0.032)||(motionValues.size()==0)) { 
		
			motionValues.push_back(motionLevel); 
			lastUpdate = elapsedTime; 
		
		} else { 
			
			float lastlevel = 0;
			
			
			lastlevel = motionValues[motionValues.size()-1];
			
			motionValues[motionValues.size()-1] = (motionLevel>lastlevel) ? motionLevel : lastlevel; 
		}
		
		//if(motionLevel>0) cout <<motionLevel << endl; 
		if(motionValues.size()>motionValueCount) { 
			motionValues.pop_front(); 
		}
		
		if (TriggerRocket :: update(deltaTime)){
			return true;
		} else { 
			return false; 
		}
		
		
	};
	
	void draw() {
		if(!active) return;

		//cout << "trigger test draw" << endl;
		
		// draw trigger and motion bitmap 
		TriggerRocket::draw();
        
        
		
		
		ofPushMatrix();
		ofPushStyle(); 
		ofTranslate(pos);
        ofScale(1, scale);
		ofTranslate(0, motionValueCount*-2); 
		ofSetColor(ofColor::red); 
		ofFill();
		//ofRect(0,0,200,200); 
		
		
		
        
        for(float i = -0.5; i<=0.5 ; i++){
            
            
            ofPushMatrix();
            
            ofBeginShape();
            
            
            ofScale(i,1);
            
            ofVertex(-1,0);
            float lastvalue = -1; 
            
            for(int i = 0; i<motionValues.size(); i++) { 
            
                float value = motionValues[i]*20; 
                if(value!=lastvalue) { 
                    //ofLine(0,i,motionValues[i]*20,i);
                    ofVertex(lastvalue,(i*2)-1);
                    ofVertex(value,i*2);
                    ofVertex(value,(i*2)+1);
                }
                lastvalue = value;
                //cout << motionValues[i] << " " << i << endl; 
            }
            ofVertex(0,motionValues.size()*2);
            ofVertex(-1,motionValues.size()*2);
            ofEndShape();
            
            ofPopMatrix();
        }
		
		ofPopMatrix();
		ofPopStyle(); 
		
	};
	
	deque <float> motionValues; 
	int motionValueCount; 
	float lastUpdate; 

};