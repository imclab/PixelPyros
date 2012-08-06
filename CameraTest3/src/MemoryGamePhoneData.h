//
//  MemoryGamePhoneData.h
//  PixelPhones
//
//  Created by Seb Lee-Delisle on 13/06/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once
#include "MemoryGameLevelData.h"

class MemoryGamePhoneData {
    
    // need to store : 
    //  -   all the button press data
    //      -   colour and time
    //  -   whether they're in or out
    //  -   average button press time
    public :
    
    MemoryGamePhoneData() { 
		reset(); 
    };
    
	void reset() { 
		inPlay = true;
		levelSuccess = false; 
        levels.clear(); 
		
		currentLevel = NULL; 
		
	}
	
	void addButtonPress(int levelnum, int button, int time) { 
		
		while(levels.size()<=levelnum) { 
			levels.push_back(MemoryGameLevelData()); 
		}
		
		levels[levelnum].pressTimes.push_back(time);
		levels[levelnum].pressButtons.push_back(button);
		levels[levelnum].averagePressTime = (float)time/(float)(levels[levelnum].pressTimes.size()); 
		currentLevel = &(levels[levelnum]); 
		
	};
	
	// returns how many we've got right or -1 if we screwed up! 
	int checkButtonPresses(vector <int> * colours, int levelnum) { 
		// CHECK INITIALISATION OF LEVELS 
		if(levelnum>=levels.size()) return -1;  
		cout << "levels size " << levels.size() << " level num : " << levelnum << "\n";
		vector <int> pressButtons = levels[levelnum].pressButtons;
		for(int i = 0; i<pressButtons.size(); i++) { 
			// if we have more button presses than 
			// colours in the level then success!
			if(i>=colours->size()) return i; 
			// if we got it wrong then blap blap (that's the 
			// sound from Family Fortunes) 
			if(colours->at(i)!=pressButtons[i]) return -1;
		}
		
		return pressButtons.size();
		
	};
	
	void updateAveragePressTime() { 
		averagePressTime = 0; 
		for (int i = 0; i<levels.size(); i++) { 
			averagePressTime+=levels[i].averagePressTime; 
		}
		
		averagePressTime/=(float)(levels.size()); 
	}
	
	
    vector <MemoryGameLevelData> levels; 
	MemoryGameLevelData * currentLevel; 
    
	bool inPlay;
	bool levelSuccess; 
	int ID; 
	float averagePressTime; 
    
};

