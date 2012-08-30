//
//  OscManager.cpp
//  PixelPyros
//
//  Created by Jack Lang on 30/08/2012.
//

#include <iostream>
#include "OscManager.h"

void OscManager::setup ()
{
	receiver.setup(OSC_RECEIVER_PORT);
    std::cout << "listening on port " << OSC_RECEIVER_PORT << std::endl;
	
    // we'll need to setup a vector of devices for this
    sender.setup("JIP2.local", OSC_SENDER_PORT);
    
}

void OscManager::update ()
{
	while( receiver.hasWaitingMessages() )
    {
        ofxOscMessage msg;
        receiver.getNextMessage(&msg);
        handleOSCMessage(msg);
    }
}

void OscManager::handleOSCMessage(ofxOscMessage msg) 
{
    string address = msg.getAddress().substr(0, msg.getAddress().find(":"));
    //std::cout << "OSC Message: " << address << std::endl;
    
    std::cout << "OSC Message: " << msg.getAddress() << std::endl;
	std::vector<std::string> params = ofSplitString(address, "/");
    int paramsLength = params.size();
	if( paramsLength >= 2 ) 
	{
		string objectName = params[paramsLength-2];
        string objectProperty = params[paramsLength-1]; 
        float arg = msg.getArgAsFloat(0) ;
            
		if ( objectName == "VPOS" )
        {
			// we're getting multiple osc messages per frame due to physics and stuff, so thought it would be better to give update flag for this, rather than a forced redraw, don't want to hurt performance
			settingsManager->setTriggerUnit(arg) ;
		}
		else if ( objectName == "Black" )
		{
			settingsManager->setBlackUnit(arg) ;
		}
		else if ( objectName == "Gamma" )
		{
			settingsManager->setGammaUnit(arg) ;
		}
		else if ( objectName == "White" )
		{
			settingsManager->setWhiteUnit(arg) ;
		}
		else if ( objectName == "MotionDebug" )
		{
			settingsManager->setTriggerDebugUnit(arg) ;
		}
	}
		
		/*            if( (widgetType == "pushbutton") || (widgetType == "togglebutton") ) {
			switch( widgetIndex ) {
			 case 1:
			 if( OSC_OFF(widgetState) ) {
			 sceneManager.prevScene();
			 }
			 break;
			 
			 case 2:
			 if( OSC_OFF(widgetState) ) {
			 sceneManager.nextScene();
			 }
			 break;
			 
			 case 3:
			 if( OSC_OFF(widgetState) ) {
			 cameraManager.toggleWarperGui(); 
			 }
			 break;
			 
			 case 4:
			 if( OSC_OFF(widgetState) ) {
			 cameraManager.next(); 
			 }
			 break;
			 }
			 }*/
}

void OscManager::sendOSCMessage(string address, float arg )
{
    ofxOscMessage message ;
    message.setAddress(address) ;
    message.addFloatArg(arg) ;
    sender.sendMessage(message) ;
}