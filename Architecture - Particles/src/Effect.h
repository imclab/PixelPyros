//
//  Effect.h
//
//  Created by Seb Lee-Delisle on 28/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

class Effect { 
	public :
	Effect() { 
		parent = NULL; 
		numActiveEffects = 0; 
		elapsedTime = 0; 
		active = true; 
	}
	
	virtual void start() {
		active = true; 
	}; 
	virtual void stop() {
		active = false;
	}; 
	
	virtual bool update(float deltaTime) { 
		
		if(!active) return false; 
		
		elapsedTime+=deltaTime; 
		
		numActiveEffects = 0; 
		
		for(vector<Effect*>::iterator it = effects.begin(); it != effects.end(); ++it) {
			if(!(*it)->active) continue; 
			if((*it)->update(deltaTime)) numActiveEffects+=(*it)->numActiveEffects+1;
			else removeEffect(*it); 
		}
		
		
		return active; 
	};
	
	virtual bool draw() { 
		
		for(vector<Effect*>::iterator it = effects.begin(); it != effects.end(); ++it) {
			(*it)->draw(); 
		}
	};
	
	virtual void addEffect(Effect * effect) { 
		effects.push_back(effect); 
		effect->parent = this; 
	}

	virtual void removeEffect(Effect * effect) { 
		effect->active = false; 
		spareEffects.push_back(effect); 
	}

	Effect* getSpareEffect() { 
		
		Effect * spare = NULL; 
		
		if(spareEffects.size()>0) { 
			spare = spareEffects.back(); 
			spareEffects.pop_back(); 
			spare->active = true;
			
		}
		
		return spare; 
	
	}
	
	virtual void reset() { 
		elapsedTime = 0; 
		active = true; 
	}
	
	
	bool	active; 
	Effect*	parent; 
	float	elapsedTime; 
	int		numActiveEffects; 
	vector <Effect*>  effects; 
	vector <Effect*>  spareEffects; 

};