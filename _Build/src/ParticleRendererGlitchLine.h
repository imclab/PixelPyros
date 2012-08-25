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

class ParticleRendererGlitchLine : public ParticleRendererBase {
	
public:
	
	ParticleRendererGlitchLine(float linewidth = 1, bool smoothline = false) : ParticleRendererBase() {
		lineWidth = linewidth;
		smooth = smoothline;
		
	}
	
	void renderParticles(vector <Particle * > particles){
        
        // BASIC TRIANGLE RENDERER
		if(smooth)
			ofEnableSmoothing();
		else
			ofDisableSmoothing();
		
			
		ofEnableBlendMode(OF_BLENDMODE_ADD);
		//		ofEnableAlphaBlending();
		//
		
		ofSetLineWidth(lineWidth);
		ofMesh mesh;
		
		mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
		
		//ofMatrix4x4 mat;
		
		for(std::vector<Particle *>::iterator it = particles.begin(); it != particles.end(); ++it) {
			
			Particle& p = **it; // *(particles[i]);
			if(!p.enabled)  continue;
			
			//int vertexIndex = mesh.getNumVertices();
			
			mesh.addVertex(p.pos);
			mesh.addColor(p.getColour());
			
					
		}
		
		mesh.draw();
		ofDisableBlendMode();
		
		
        
    }
	
	float lineWidth;
	bool smooth; 
};