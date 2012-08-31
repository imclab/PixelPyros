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



class SlideTimer: public CentredSlideText {
    
public:
    
    SlideTimer(int screenWidth, int screenHeight, ofRectangle rect, ofColor c, float fontSize, vector<string> times): CentredSlideText(screenWidth, screenHeight, rect, c, fontSize, "") {
        showTimes = times;
        
        for( int i = 0; i < showTimes.size(); i++ ) {
            showTimeStamps.push_back(hoursMinutesToEpoch(showTimes[i]));
        }
    }
    
    time_t hoursMinutesToEpoch(string t) {
        struct tm tm;
        
        string timeString = ofGetTimestampString("%Y-%m-%d") + t;
        if( strptime(timeString.c_str(), "%Y-%m-%d %H:%M", &tm) != NULL ) {
            time_t epoch = mktime(&tm);
            return epoch;
            // std::cout << "added " << epoch << std::endl;
        }
        
        return 0;
    }
    
     string hoursMinutesToMinutesSecondsString(string t) {
         vector<string> parts = ofSplitString(t, ":");
         
         if( parts.size() != 2 ) {
             std::cout << "Unrecognised hoursMinutes string: " << t << std::endl;
             return 0;
         }
         
         // This is horrible, but I'm rushing
         unsigned long totalSeconds = atoi(parts[0].c_str()) * 60 + atoi(parts[1].c_str());
         string minutes = ofToString(totalSeconds / 60);
         if( minutes.length() < 2 ) {
             minutes = "0" + minutes;
         }
         
         string seconds = ofToString(totalSeconds % 60);
         if( seconds.length() < 2 ) {
             seconds = "0" + seconds;
         }
         return minutes + ":" + seconds;
    }
    
    string hoursMinutesToSecondsInt(string t) {
        
    }
    
    string getNextShowTime(unsigned long timeStamp = 0) {
        if( timeStamp == 0 ) {
            timeStamp = ofGetUnixTime();
        }
        
        for( int i = 0; i < showTimeStamps.size(); i++ ) {
            if( timeStamp < showTimeStamps[i] ) {
                return showTimes[i];
            }
        }
        
        return "";
    }
    
    string getTimeToNextShow() {
        string nextShow = getNextShowTime();
        if( nextShow == "" ) {
            return 0;
        }
        
        std::cout << "\nNext show: " << nextShow << std::endl;
        return hoursMinutesToMinutesSecondsString(nextShow);
    }
    
    virtual void draw() {
        ofPushStyle();
        
        ofSetColor(col);
        writer.drawFixedSize(box, "Next Show: " + getTimeToNextShow(), fontSize, false);
        
        ofPopStyle();
    }
    
    vector<string> showTimes;
    vector<time_t> showTimeStamps;
    TextWriter writer;
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
    
    SceneSlideshow(ParticleSystemManager &, ofRectangle);
    
    virtual bool draw();
   	virtual bool startArrangement(int);
    virtual void initShaderParameters();
    
private:
        
    SlideShow slideShow;
    
    ofImage defaultBackground;
    vector<SceneSlide *> slides;
    float defaultFontSize;
    
    int currentSlide;
    float lastUpdateTime;
    
};
