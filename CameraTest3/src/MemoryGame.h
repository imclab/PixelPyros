//
//  MemoryGame.h
//  PixelPhones
//
//  Created by Seb Lee-Delisle on 07/05/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once


#include "OutputEffect.h"
#include "ConnectedPhone.h"
#include "ofxSimpleGuiToo.h"
#include "MemoryGameLevelData.h"
#include "MemoryGamePhoneData.h"

#define MEM_GAME_STATE_WAITING 0
#define MEM_GAME_STATE_BETWEEN_LEVELS 1
#define MEM_GAME_STATE_SHOWING_LEVEL 2
#define MEM_GAME_STATE_RECEIVING_PRESSES 3
#define MEM_GAME_STATE_OVER 4


class MemoryGame : public OutputEffect {
	
    public:
    
	MemoryGame() : OutputEffect(320,240) {
		gameStartSwitch = false; 
		drawFBOToPhones = false; 
		
		colourRefs[0] = ofColor(255, 0, 0); 
		colourRefs[1] = ofColor(255, 255, 0); 
		colourRefs[2] = ofColor(0, 255, 0); 
		colourRefs[3] = ofColor(0, 0, 255); 
		
		tones[0].loadSound("audio/Tone1.wav");
		tones[1].loadSound("audio/Tone2.wav");
		tones[2].loadSound("audio/Tone3.wav");
		tones[3].loadSound("audio/Tone4.wav");
	};
    
    void start(); 
    void stop(); 
    void update(); 
    void draw(ofRectangle* drawRect); 

	void startGame(); 
	void gameOver();
	
	void initGui(ofxSimpleGuiToo * gui); 
	
	void updatePhoneList(); 
	void updatePhoneCounts(); 
	void newLevel(); 
	void sendAllPhones(string msg); 
	
	void startReceivingPresses(); 
	void stopReceivingPresses(); 	
	
	void getPhoneMessages(); 
	void updateWinners(); 
	
	//bool sortWinnersFunction(MemoryGamePhoneData * first, MemoryGamePhoneData * second);
	
	int gameState; 
	int gameStartTime; 
	int gameEndTime; 
	
	bool gameStartSwitch; 
	bool newLevelSwitch; 
	
    map <ConnectedPhone *, MemoryGamePhoneData *> phoneGameData; 
	vector <MemoryGamePhoneData * > winnersList; 
	vector <int> colours; 
	vector <int> times; 
	int currentShowColourIndex;
	int currentShowColour; 
	ofColor colourRefs[4]; 
	
	ofSoundPlayer tones[4]; 

	
	int levelNum; 
	
	
	int timeNow; 
	int lastUpdateTime; 
	int startReceivingTime; 
	int stopReceivingTime; 
	int startShowingTime; 
	int stopShowingTime;
	int nextLevelStartTime; 
	
	// number of phones that haven't screwed up yet
	int numPhonesInPlay; 
	// number of phones that are still pushing buttons
	int numPhonesPlayingLevel; 
	
	// the length of time each colour should appear. 
	int timePerColourShow; 
	int timePerPress; 
};

