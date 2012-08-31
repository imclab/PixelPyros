//
//  SettingsManager.cpp
//  PixelPyros
//
//  Created by Jack Lang on 30/08/2012.
//

#include <iostream>
#include "testApp.h"
#include "SettingsManager.h"

void SettingsManager::setup ()
{
	triggerarea = ofRectangle (APP_WIDTH*0.05 ,0,APP_WIDTH*0.9,10);
	
    setTriggerUnit( 0.5f ) ;
	
    setBloom ( 0.5 ) ;
    setGamma ( 1.2 ) ;
    setBlack ( 0.0 ) ;
    setWhite ( 1.0 ) ;
	
	setTriggerDebug(false) ;
}


// unit setters for osc, don't transmit to osc
void SettingsManager::setTriggerUnit ( float val )
{
    triggerY = val ;
    
    triggerarea.y = APP_HEIGHT * ( TRIGGER_Y_TOP + ( ( TRIGGER_Y_BOTTOM - TRIGGER_Y_TOP ) * triggerY ) ) ;
	triggerAreaUpdate = true ;
}

void SettingsManager::setBloomUnit ( float val )
{
	bloomValue = val ;
}

void SettingsManager::setGammaUnit ( float val )
{
	gammaValue = GAMMA_MIN + ( ( GAMMA_MAX - GAMMA_MIN ) * val ) ;
}

void SettingsManager::setBlackUnit ( float val )
{
	blackPoint = val ;
}

void SettingsManager::setWhiteUnit ( float val )
{
	whitePoint = val ;
}

void SettingsManager::setTriggerDebugUnit ( float val )
{
	triggerDebug = val == 1.0 ;
	std::cout << "set debug " << triggerDebug << std::endl ;
	triggerDebugUpdate = true ;
}

// setters for automated osc output
void SettingsManager::setBloom ( float val )
{
	bloomValue = val ;
}

void SettingsManager::setGamma ( float val )
{
	gammaValue = val ;
}

void SettingsManager::setBlack ( float val )
{
	blackPoint = val ;
}

void SettingsManager::setWhite ( float val )
{
	whitePoint = val ;
}

void SettingsManager::setTriggerDebug ( bool val )
{
	triggerDebug = val ;
	triggerDebugUpdate = true ;
}