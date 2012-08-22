//
//  Pattern.h
//  ParticlePlay5
//
//  Created by Seb Lee-Delisle on 20/08/2012.
//
//

#pragma once;

#include "TriggerSimple.h";

class TriggerPattern  {

	
	public :
	
	template <typename T>
	T* addTrigger(T& trigger, float verticalPos = 0.5, float verticalPosVariation = 0, float horizSpacing = 1){
		
		
		triggers.push_back(new T(trigger));
		verticalPositions.push_back(verticalPos);
		
		
		
	}




	vector <TriggerBase* > triggers;
	vector <float> verticalPositions;







};