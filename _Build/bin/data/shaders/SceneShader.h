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
    
    void draw(ofFbo &fbo) {
        begin();
        setUniformTexture("baseTexture", fbo.getTextureReference(), 0);
        setShaderParameters();
        
        float w = fbo.getWidth(), h = fbo.getHeight();
        
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);
            glVertex2f(0, 0);
            
            glTexCoord2f(w, 0);
            glVertex2f(w, 0);
            
            glTexCoord2f(w, h);
            glVertex2f(w, h);
            
            glTexCoord2f(0, h);
            glVertex2f(0, h);
        glEnd();
        
        end();
    }
    
    float bloomValue;
    float gammaValue;
    float blackPoint;
    float whitePoint;
    
private:
    
};

