//
//  ParticleRendererLine.h
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 23/08/2012.
//
//
#pragma once
#include "ParticleRendererBase.h"; 
#include "ofMain.h"

class ParticleRendererLine : public ParticleRendererBase {

	public:
	
	ParticleRendererLine(float linewidth = 1, bool smoothlines = false) : ParticleRendererBase() {
		lineWidth = linewidth;
		smooth = smoothlines; 
		
	}
	
	void renderParticles(vector <Particle * > particles){
        
        // BASIC TRIANGLE RENDERER
		if(smooth) ofEnableSmoothing();
		else ofDisableSmoothing();
		
		ofEnableBlendMode(OF_BLENDMODE_ADD);
		
		//		ofEnableAlphaBlending();
		//
		
		ofSetLineWidth(lineWidth);
		ofMesh mesh;
		
		mesh.setMode(OF_PRIMITIVE_LINES);
		
		//ofMatrix4x4 mat;
		
		for(std::vector<Particle *>::iterator it = particles.begin(); it != particles.end(); ++it) {
			
			Particle& p = **it; // *(particles[i]);
			if(!p.enabled)  continue;
			
			//int vertexIndex = mesh.getNumVertices();
		
			mesh.addVertex(p.pos);
			mesh.addColor(p.getColour());
		
			mesh.addVertex(p.pos-(p.vel*0.1));
			mesh.addColor(ofColor::black);
			
		}
		
		mesh.draw();
		ofDisableBlendMode();
		
		
        
    }
	
	float lineWidth;
	bool smooth; 
};