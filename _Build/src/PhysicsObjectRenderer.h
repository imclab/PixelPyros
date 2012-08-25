//
//  PhysicsObjectRenderer.h
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 25/08/2012.
//
//

#pragma once
#include "PhysicsObject.h"
#include "ofMain.h"

class PhysicsObjectRenderer {

	public :
	
	void render(PhysicsObject& po) {
		
		if(!enabled) return;
		
		ofPushMatrix();
		ofTranslate(po.pos);
		//ofScale(po.size);
		ofCircle(0,0,10);
		ofPopMatrix();
	}










};