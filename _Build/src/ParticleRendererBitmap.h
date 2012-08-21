//
//  ParticleBitmapRenderer.h
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 21/08/2012.
//
//

#pragma once 

#include "ofMain.h"

class ParticleRendererBitmap : public ParticleRendererBase {
	
	
	public :
	
	// SHOULD AVOID POINTER?
	
	ParticleRendererBitmap(ofImage* img) : ParticleRendererBase(){
		
		cout <<"rendererbitmap contstructor" << endl;
		image = img;
		
		shape.clear();
		
		shape.push_back(ofVec3f( -0.5, -0.5));
		shape.push_back(ofVec3f(  0.5, -0.5));
		
		shape.push_back(ofVec3f(  0.5, 0.5 ));
		shape.push_back(ofVec3f( -0.5, 0.5 ));
				
		meshMode = OF_PRIMITIVE_TRIANGLES;
		
		
	}
	
	void renderParticles(vector <Particle * > particles){
  
		cout <<"rendererbitmap renderParticles" << endl;

        // BASIC TRIANGLE RENDERER
		return; 
		ofEnableBlendMode(OF_BLENDMODE_ADD);
		
		ofMesh mesh;

		mesh.setMode(meshMode);
		//mesh.enableTextures();

		
		//ofMatrix4x4 mat;
		
		for(std::vector<Particle *>::iterator it = particles.begin(); it != particles.end(); ++it) {
			
			Particle& p = **it; // *(particles[i]);
			if((!p.enabled) || (p.size<1)) continue;
			
			int vertexIndex = mesh.getNumVertices();
			
			for(int i = 0; i<shape.size(); i++) {
				ofVec3f v = shape[i];
				
				v*=p.size;
				v+=p.pos;
				mesh.addVertex(v);
				mesh.addColor(p.getColour());
				//mesh.addTexCoord(ofVec2f(i%2, floor(i/2)));
				
				
			}
			
			//mesh.addTriangle(vertexIndex, vertexIndex+1, vertexIndex+2);
			//mesh.addTriangle(vertexIndex+2, vertexIndex+3, vertexIndex+1);
			
			
			
		}
		
        mesh.draw();
		ofDisableBlendMode();

		
        
    }

	
	
	ofImage* image;
	
	
	






};