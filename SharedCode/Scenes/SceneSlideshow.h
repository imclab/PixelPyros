//
//  SceneSlideshow.h
//  PixelPyros
//
//  Created by Paul King on 30/08/2012.
//

#pragma once

#include "Scene.h"
#include "SlideShow.h"
#include "TextWriter.h"
#include <vector>

#define DEFAULT_SLIDE_DURATION 5.0


class SlideObject {
    
public:
    SlideObject(ofRectangle rect, ofColor c) {
        box = rect;
        col = c;
    }
    
    virtual void draw() {
        ofPushMatrix();
        ofPushStyle();
        
        ofSetColor(col);
        ofFill();
        ofRect(box);
        
        ofPopStyle();
        ofPopMatrix();
    }
    
    ofRectangle box;
    ofColor col;
};


class SlideText: public SlideObject {

public: 
    SlideText(ofRectangle rect, ofColor c, float fontSize, string s): SlideObject(rect, c) {
        text = s;
        this->fontSize = fontSize;
    }
    
    virtual void draw() {
        ofPushStyle();
        
        ofSetColor(col);
        writer.drawFixedSize(box, text, fontSize, false);
        
        ofPopStyle();
    }
    
    string text;
    float fontSize;
    TextWriter writer;
};

class CentredSlideText: public SlideText {

public:
    CentredSlideText(int screenWidth, int screenHeight, ofRectangle rect, ofColor c, float fontSize, string s): SlideText(rect, c, fontSize, s) {
        box.x += (screenWidth / 2.0) - (box.width / 2.0);
        box.y += (screenHeight / 2.0) - (box.height / 2.0);
    }
    
    virtual void draw() {
        ofPushStyle();
        
        ofSetColor(col);
        writer.drawFixedSize(box, text, fontSize, true);
        
        ofPopStyle();
    }
};

class SlideAutoText: public SlideText {
    
public:
    SlideAutoText(ofRectangle rect, ofColor c, string s): SlideText(rect, c, 1.0, s) {
    }
    
    virtual void draw() {
        ofPushStyle();
        
        ofSetColor(col);
        writer.draw(box, text, true);
        
        ofPopStyle();
    }
};

class SceneSlide {
    
public:
    
    SceneSlide(ofImage *backgroundImage) {
        background = backgroundImage;
        duration = DEFAULT_SLIDE_DURATION;
    }
    
    void add(SlideObject *object) {
        objects.push_back(object);
    }
    
    vector<SlideObject *> objects;
    ofImage *background;
    float duration;
};

class SceneSlideshow : public Scene {

public:
    
    SceneSlideshow(ParticleSystemManager &, ofRectangle *);
    
    virtual bool draw();
   	virtual bool startArrangement(int);
    
private:
        
    SlideShow slideShow;
    
    ofImage defaultBackground;
    vector<SceneSlide *> slides;
    float defaultFontSize;
    
    
    int currentSlide;
    float lastUpdateTime;
    
};
