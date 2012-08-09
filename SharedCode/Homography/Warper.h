//
//  Warper.h
//  HomographyExample
//
//  Created by Seb Lee-Delisle on 07/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once 

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxXmlSettings.h"

using namespace ofxCv;
using namespace cv;

class Warper { 

	
	
	public : 
	
	
	Warper() ;
	
	void update();
	
	
	void setSourceImage(ofImage& img) ;
	
	void draw();
	
	void mousePressed(ofMouseEventArgs &e);
	void mouseDragged(ofMouseEventArgs &e);
	void mouseReleased(ofMouseEventArgs &e);
	
	bool hitTestPoints(vector<ofVec2f>& points, ofVec2f& point); 
	void drawPoints(vector<ofVec2f>& points, ofColor colour = ofColor::white);
	
	bool loadSettings(); 
	bool saveSettings(); 
	
	void showGui(); 
	void hideGui(); 
	void toggleGui(); 
	
	ofImage* srcImage; 
	ofImage warpedImage; 
	string  settingsFileLabel; 
	
	vector <ofVec2f> srcVecs, dstVecs; 

	cv::Mat homography;
	
	bool guiVisible; 
	bool changed; 
	bool movingPoint; 
	bool autoSave; 
	ofVec2f *curPoint; 
	

};