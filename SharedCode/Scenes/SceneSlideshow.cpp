//
//  SceneSlideshow.cpp
//  PixelPyros
//
//  Created by Paul King on 30/08/2012.
//

#include "SceneSlideshow.h"
#include "ofMain.h"
#include "testApp.h"

SceneSlideshow::SceneSlideshow(ParticleSystemManager &psm, ofRectangle triggerarea): Scene(psm, triggerarea) {
    /*
    slideShow.folderPath = ofToDataPath("slideshow/");
    slideShow.reloadImages();
    
    lastUpdateTime = 0;
    */
    
    currentSlide = 0;
    lastUpdateTime = 0;
    defaultFontSize = 3.0;
    
    defaultBackground.loadImage(ofToDataPath("slideshow/background.jpg"));
    
    // Slide 1
    
    SceneSlide *slide = new SceneSlide(&defaultBackground);
    // Auto-centred box, x, y are offsets from the middle
    slide->add(new CentredSlideText(APP_WIDTH, APP_HEIGHT,
        ofRectangle(0, -50, 600, 60),
        ofColor(128, 128, 128), 
        defaultFontSize,
        "the official launch of the 2012\nbrighton digital festival!"
    ));
    
    // Absolute x,y coordinates for top left of box
    slide->add(new SlideText(
         ofRectangle(100, 300, 100, 50), 
         ofColor(128, 128, 128), 
         0.5 * defaultFontSize,
         "Absolute Text"
    ));
    
    // Auto-sized, horribleness
    slide->add(new SlideAutoText(
         ofRectangle(APP_WIDTH / 2 - 400, APP_HEIGHT / 2 - 100, 800, 300), 
         ofColor(128, 128, 128), 
        "2012.brightondigitalfestival.co.uk"
    ));
    
    // Duration to show, in seconds
    slide->duration = 5;
    slides.push_back(slide);
    
    // Slide 2
    
    slide = new SceneSlide(&defaultBackground);
    slide->add(new CentredSlideText(APP_WIDTH, APP_HEIGHT,
         ofRectangle(0, 0, 600, 100), 
         ofColor(128, 128, 128), 
         0.9 * defaultFontSize,
         "thanks to:"
    ));
    slide->add(new CentredSlideText(APP_WIDTH, APP_HEIGHT,
         ofRectangle(0, 200, 300, 100), 
         ofColor(128, 128, 128), 
         0.6 * defaultFontSize,
         "val head, paul king, julie sharp, devi,\nbrightart, firefly, solar, pyra\ngraphics, jubilee library, chile pickle"
    ));
    
    slides.push_back(slide);
}

bool SceneSlideshow::draw() {
    if( !active ) {
        return false;
    }
    
    if( (slides.size() == 0) || (currentSlide >= slides.size()) ) {
        return false;
    }
    
    SceneSlide *slide = slides[currentSlide];
    
    ofPushMatrix();
    ofPushStyle();
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofTranslate(APP_WIDTH / 2, APP_HEIGHT / 2);
    
    float xScale = ofGetWidth() / slide->background->getWidth();
    float yScale = ofGetHeight() / slide->background->getHeight();
    float scale = min(xScale, yScale);
    
    if( scale < 1.0 ) {
        ofScale(xScale, yScale);
    }
    
    slide->background->draw(0, 0);
    
    ofPopStyle();
    ofPopMatrix();
    
    for( int i = 0; i < slide->objects.size(); i++ ) {
        slide->objects[i]->draw();
    }
    
    float deltaTime = ofGetElapsedTimef() - lastUpdateTime;
    
    if( deltaTime > slide->duration ) {
        currentSlide++;
        
        if( currentSlide >= slides.size() ) {
            currentSlide = 0;
        }
    
        lastUpdateTime += deltaTime;
    }
}
 
void SceneSlideshow::initShaderParameters() {
    Scene::initShaderParameters();
    shader->bloomValue = 0.0;
}

bool SceneSlideshow::startArrangement(int i) {
    return true;
}