//
//  OscManager.h
//  PixelPyros
//
//  Created by Jack Lang on 30/08/2012.
//

#pragma once

#include "ofxOsc.h"
#include "SettingsManager.h"
#include "SceneManager.h"

#define OSC_OFF(x) (x == 0)
#define OSC_ON(x) (x == 1.0f	)


class OscManager
{
	public :
	
	SettingsManager *settingsManager ;
	SceneManager *sceneManager ;
	
	void setup () ;
	void update () ;
	
	void sendOSCMessage(string message, float arg );
    
	private :
	
    void handleOSCMessage(ofxOscMessage);
    static const int OSC_RECEIVER_PORT = 1234;
    static const int OSC_SENDER_PORT = 8000;
    ofxOscReceiver receiver;
    ofxOscSender sender;
	
} ;