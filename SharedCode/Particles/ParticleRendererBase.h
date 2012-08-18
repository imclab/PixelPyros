//
//  ParticleRenderer.h
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 30/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once
#include "Particle.h"
#include "ofMain.h"



class ParticleRendererBase { 

	public:
	
	ParticleRendererBase() {
		
				
		shape.push_back(ofVec3f(    0, -0.5 ));
		shape.push_back(ofVec3f(  -0.5,  0 ));
		shape.push_back(ofVec3f(  0.5,  0 ));
		
		shape.push_back(ofVec3f(  -0.5,  0 ));
		shape.push_back(ofVec3f(  0.5,  0 ));
		shape.push_back(ofVec3f( 0,  0.5 ));
		//	shape.push_back(ofVec3f( -0.5,  0.5 ));
		//	shape.push_back(ofVec3f(    0, -0.5 ));
		
	}
    
    virtual void renderParticles(vector <Particle * > particles, ofMesh& mesh){
        
        // BASIC TRIANGLE RENDERER
        
		mesh.setMode(OF_PRIMITIVE_TRIANGLES);
		
		//ofMatrix4x4 mat;
		
		for(std::vector<Particle *>::iterator it = particles.begin(); it != particles.end(); ++it) {
			
			Particle& p = **it; // *(particles[i]);
			if(!p.enabled) continue;
			
			for(int i = 0; i<shape.size(); i++) {
				ofVec3f v = shape[i];
				
				v*=p.size;
				v+=p.pos; 
				mesh.addVertex(v);
				mesh.addColor(p.getColour());
				
			}
		
		}

        
    	        
        
    }
    
	vector <ofVec3f> shape;

    


};