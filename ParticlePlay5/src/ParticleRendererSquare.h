//
//  ParticleRendererSquare.h
//  ParticlePlay5
//
//  Created by Seb Lee-Delisle on 18/08/2012.
//
//

#pragma once

class ParticleRendererSquare : public ParticleRendererBase {

public:

	ParticleRendererSquare() : ParticleRendererBase(){
		shape.clear();
		
		shape.push_back(ofVec3f( -0.5, 0, -0.5 ));
		shape.push_back(ofVec3f(  0.5, 0, -0.5 ));
		
		shape.push_back(ofVec3f(  0.5, 0, -0.5 ));
		shape.push_back(ofVec3f(  0.5, 0, 0.5 ));
		
		shape.push_back(ofVec3f(  0.5, 0, 0.5 ));
		shape.push_back(ofVec3f( -0.5, 0, 0.5 ));
		
		shape.push_back(ofVec3f( -0.5, 0, 0.5 ));
		shape.push_back(ofVec3f( -0.5, 0, -0.5 ));
		
		meshMode = OF_PRIMITIVE_LINES;

		
	}








};