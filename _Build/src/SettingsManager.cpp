//
//  SettingsManager.cpp
//  PixelPyros
//
//  Created by Jack Lang on 30/08/2012.
//


#include "SettingsManager.h"

SettingsManager::SettingsManager() {
	
	oscManager = NULL;
	controlPanel = NULL; 
	
}

void SettingsManager::setup (OscManager * osc, ofxControlPanel * gui) {
		
	oscManager = osc;
	controlPanel = gui; 
	
	
}


void SettingsManager::update() {
	
	
	for(int i = 0; i<settingFloats.size(); i++) {
		
		SettingFloat* setting = settingFloats[i];
		
		if(setting->checkChanged()) {
			cout << "value changed " << endl; 
			oscManager->sendNewValue(*setting);
			controlPanel->setValueF(setting->xmlLabel, setting->value);
			
			controlPanel->saveSettings();
			
			
		}
	}
	
	
	for(int i = 0; i<settingBools.size(); i++) {
		
		SettingBool* setting = settingBools[i];
		
		if(setting->checkChanged()) {
			cout << "value changed " << endl;
			oscManager->sendNewValue(*setting);
			controlPanel->setValueB(setting->xmlLabel, setting->value);
			
			controlPanel->saveSettings();
			
			
		}
	}
	
	
}


void SettingsManager::addSettingFloat(float * valuePointer, string xmlname, string osclabel, float min, float max ) {
	
	SettingFloat* settingFloat = new SettingFloat(valuePointer, xmlname, osclabel, min, max);
	
	//threshold = SettingFloat(targetThreshold, "THRESHOLD", "/PixelPyros/Setup/Threshold/x", 0, 255);
	oscManager->addSettingFloat(*settingFloat);
	settingFloats.push_back(settingFloat);
	
}


void SettingsManager::addSettingBool(bool * valuePointer, string xmlname, string osclabel, bool sendCurrent) {
	
	SettingBool* setting = new SettingBool(valuePointer, xmlname, osclabel);
	
	//threshold = SettingFloat(targetThreshold, "THRESHOLD", "/PixelPyros/Setup/Threshold/x", 0, 255);
	oscManager->addSettingBool(*setting);
	settingBools.push_back(setting);
	if(sendCurrent) setting->value = !*setting->target; 
	
}
