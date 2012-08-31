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
    sender.setup("SebsiPad.local", OSC_SENDER_PORT);
    
	sendOSCMessage("/setTriggerHeight", 0.1);
	
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
    
    std::cout << "OSC Message: " << msg.getAddress() <<" " << msg.getArgAsFloat(0) << std::endl;

	for(int i = 0; i<settingFloats.size(); i++) {
		
		
		SettingFloat * setting = settingFloats[i];
		
		if(msg.getAddress()==setting->oscLabel) {
			
			setting->setFromUnit(msg.getArgAsFloat(0));
			
			cout << "changing  " << setting->oscLabel << " to " << setting->target << endl;
			
		}
	}
	
	for(int i = 0; i<settingBools.size(); i++) {
		
		
		SettingBool * setting = settingBools[i];
		
		if(msg.getAddress()==setting->oscLabel) {
			
			setting->set(msg.getArgAsFloat(0));
			
			cout << "changing  " << setting->oscLabel << " to " << setting->target << endl;
			
		}
	}
	

}

void OscManager::sendOSCMessage(string address, float arg )
{
    ofxOscMessage message ;
    message.setAddress(address) ;
    message.addFloatArg(arg) ;
    sender.sendMessage(message) ;
}