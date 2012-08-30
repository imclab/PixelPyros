//
//  SettingsManager.h
//  PixelPyros
//
//  Created by Jack Lang on 30/08/2012.
//


#pragma once

#include "ofxOsc.h"

class SettingsManager
{
    public:
    
    void setup () ;
    
    void setTriggerUnit ( float val ) ;
	
	// osc sets
	void setBloomUnit ( float val ) ;
	void setGammaUnit ( float val ) ;
	void setBlackUnit ( float val ) ;
	void setWhiteUnit ( float val ) ;
	void setTriggerDebugUnit ( float val ) ;
	
	// normal sets
	void setBloom ( float val ) ;
	void setGamma ( float val ) ;
	void setBlack ( float val ) ;
	void setWhite ( float val ) ;
	void setTriggerDebug ( bool val ) ;
	
    float bloomValue;
    float gammaValue;
    float blackPoint;
    float whitePoint;
	
	bool triggerAreaUpdate;
    ofRectangle triggerarea;
    
	bool triggerDebugUpdate;
	bool triggerDebug;
	
	private:
	
	// ranges
    static const float TRIGGER_Y_TOP = 0.98 ;
    static const float TRIGGER_Y_BOTTOM = 0.72 ;
   
	static const float GAMMA_MIN = 0.5 ;
	static const float GAMMA_MAX = 1.5 ;
	
	// settings vals
	
    float triggerY ;
	
};
