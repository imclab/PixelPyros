//
//  SceneShader.h
//  PixelPyros
//
//  Created by Paul King on 30/08/2012.
//

#pragma once

#include "ofShader.h"
#include "ofFbo.h"
#include "QuadWarp.h"
class SceneShader : public ofShader {
    
public:
    
    SceneShader() : ofShader() {
    }
    
    SceneShader(string filename) : ofShader() {
        load(filename);
    }
    
    virtual void setShaderParameters() {
        setUniform1f("bloom", bloomValue);
        setUniform1f("gamma", gammaValue);
        setUniform1f("blackPoint", blackPoint);
        setUniform1f("whitePoint", whitePoint);
    }
    
	// would be nice to make this a little more flexible, right now it is hard coded for
	// two projectors
	
    //void draw(ofFbo &fbo, vector<ofVec3f> & warpPoints1, vector<ofVec3f> & warpPoints2 ) {
	void draw(ofFbo &fbo, QuadWarp& warp1, QuadWarp& warp2 ) {

		
		float w = fbo.getWidth(), h = fbo.getHeight();
		float hw =  w/2;
		float hh =  h/2;
		
		
		ofPushMatrix();
		
			
		begin();
        setUniformTexture("baseTexture", fbo.getTextureReference(), 0);
        setShaderParameters();
		
		
		
		warp1.apply(ofRectangle(0,0,hw, h));
		
		
		glBegin(GL_QUADS);
		
		glTexCoord2f(0, 0);
		glVertex2f(0,0);
		
		glTexCoord2f(hw, 0);
		glVertex2f(hw,0);
		
		glTexCoord2f(hw, h);
		glVertex2f(hw,h);
		
		glTexCoord2f(0, h);
		glVertex2f(0,h);
		
		
		glEnd();
		
		
		end();
		
		ofPopMatrix();
		
		ofPushMatrix();
		
		
		begin();
        setUniformTexture("baseTexture", fbo.getTextureReference(), 0);
        setShaderParameters();
		
		
		
		glPushMatrix();
		warp2.apply(ofRectangle(0,0,hw, h));
		
		
		glBegin(GL_QUADS);
		
		glTexCoord2f(hw, 0);
		glVertex2f(0,0);
		
		glTexCoord2f(w, 0);
		glVertex2f(hw,0);
		
		glTexCoord2f(w, h);
		glVertex2f(hw,h);
		
		glTexCoord2f(hw, h);
		glVertex2f(0,h);
		
		
		glEnd();
		glPopMatrix();
		
		
		end();
		
        ofPopMatrix();
		

			
	}
    
    float bloomValue;
    float gammaValue;
    float blackPoint;
    float whitePoint;
    
private:
    
};

