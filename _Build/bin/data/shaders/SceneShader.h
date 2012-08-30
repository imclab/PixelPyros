//
//  SceneShader.h
//  PixelPyros
//
//  Created by Paul King on 30/08/2012.
//

#pragma once

#include "ofShader.h"
#include "ofFbo.h"

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
	
    void draw(ofFbo &fbo, vector<ofVec3f> & warpPoints1, vector<ofVec3f> & warpPoints2 ) {
        begin();
        setUniformTexture("baseTexture", fbo.getTextureReference(), 0);
        setShaderParameters();
        
        float w = fbo.getWidth(), h = fbo.getHeight();
		float hw =  w/2;
		float hh =  h/2;

		glBegin(GL_QUADS);
		
		glTexCoord2f(0, 0);
		//glVertex2f(warpPoints1[0].x, warpPoints1[0].y);
		glVertex2f(0,0);
		
		glTexCoord2f(hw, 0);
		//glVertex2f(warpPoints1[1].x, warpPoints1[1].y);
		glVertex2f(hw,0);
		
		glTexCoord2f(hw, h);
		//glVertex2f(warpPoints1[2].x, warpPoints1[2].y);
		glVertex2f(hw,h);
		
		glTexCoord2f(0, h);
		//glVertex2f(warpPoints1[3].x, warpPoints1[3].y);
		glVertex2f(0,h);
		
		
//		glTexCoord2f(hw, 0);
//		glVertex2f(warpPoints2[0].x, warpPoints2[0].y);
//		
//		glTexCoord2f(w, 0);
//		glVertex2f(warpPoints2[1].x, warpPoints2[1].y);
//		
//		glTexCoord2f(w, h);
//		glVertex2f(warpPoints2[2].x, warpPoints2[2].y);
//		
//		glTexCoord2f(hw, h);
//		glVertex2f(warpPoints2[3].x, warpPoints2[3].y);
		
		
		
        glEnd();

        
		
		
//        glBegin(GL_QUADS);
//            glTexCoord2f(0, 0);
//            glVertex2f(0, 0);
//            
//            glTexCoord2f(w, 0);
//            glVertex2f(w, 0);
//            
//            glTexCoord2f(w, h);
//            glVertex2f(w, h);
//            
//            glTexCoord2f(0, h);
//            glVertex2f(0, h);
//        glEnd();
        
        end();
    }
    
    float bloomValue;
    float gammaValue;
    float blackPoint;
    float whitePoint;
    
private:
    
};

