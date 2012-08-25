//
//  ParticleRendererShape.h
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 22/08/2012.
//
//

#pragma once
#include "ParticleRendererBase.h"
#include "ofMain.h"


class ParticleRendererShape : public ParticleRendererBase {
	
public:
	
	ParticleRendererShape() {
		
		shape.clear();
		
		shape.push_back(ofVec3f(    0, -0.5 ));
		shape.push_back(ofVec3f(  -0.5,  0 ));
		shape.push_back(ofVec3f(  0.5,  0 ));
		
		shape.push_back(ofVec3f( 0,  0.5 ));
		
		meshMode  = OF_PRIMITIVE_TRIANGLES;
		
		lineWidth = 1; 
	}
    
    virtual void renderParticles(vector <Particle * > particles){
        
        // BASIC TRIANGLE RENDERER
		//		ofDisableSmoothing();
		ofEnableBlendMode(OF_BLENDMODE_ADD);
		//		ofEnableAlphaBlending();
		//
		
		ofSetLineWidth(lineWidth); 
		ofMesh mesh;
		
		mesh.setMode(meshMode);
		
		//ofMatrix4x4 mat;
		
		for(std::vector<Particle *>::iterator it = particles.begin(); it != particles.end(); ++it) {
			
			Particle& p = **it; // *(particles[i]);
			if((!p.enabled) || (p.size<0.1)) continue;
			
			int vertexIndex = mesh.getNumVertices();
			
			for(int i = 0; i<shape.size(); i++) {
				ofVec3f v = shape[i];
				
				v*=p.size;
				v+=p.pos;
				mesh.addVertex(v);
				mesh.addColor(p.getColour());
				
			}
			
			mesh.addTriangle(vertexIndex, vertexIndex+1, vertexIndex+2);
			mesh.addTriangle(vertexIndex+1, vertexIndex+2, vertexIndex+3);
			
			
		}
		
		mesh.draw();
		ofDisableBlendMode();
		
		
        
    }
	
	vector <ofVec3f> shape;
	ofPrimitiveMode meshMode;
	float lineWidth; 
    
	
	
};