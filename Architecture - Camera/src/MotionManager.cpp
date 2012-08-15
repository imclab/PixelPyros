//
//  MotionManager.cpp
//  ArchitectureCamera
//
//  Created by Seb Lee-Delisle on 10/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "MotionManager.h"

using namespace ofxCv; 
using namespace cv; 
MotionManager :: MotionManager(int w, int h){ 
	
	
	onePixel.allocate(1,1,OF_IMAGE_GRAYSCALE); 
	
	init(w, h);  
	
	
};


void MotionManager::init(int w, int h) {
	
	
	if(current.isAllocated()) current.clear(); 
	if(previous.isAllocated()) previous.clear(); 
	if(diff.isAllocated()) diff.clear(); 
	if(smallDiff.isAllocated()) smallDiff.clear(); 
	
	smallDiff.allocate(10,10,OF_IMAGE_GRAYSCALE); 
	
	current.allocate(w,h, OF_IMAGE_GRAYSCALE); 
	previous.allocate(w,h, OF_IMAGE_GRAYSCALE); 
	diff.allocate(w,h, OF_IMAGE_GRAYSCALE); 
	
	width = w; 
	height = h; 
	
	cout << "reinitialising images " << w << " " << h << endl; 
	
};


bool MotionManager :: update(ofPixelsRef image){
	if((image.getWidth()!=width) || (image.getHeight()!=height)){
		init(image.getWidth(), image.getHeight()); 
	}
	
	// like ofSetPixels, but more concise and cross-toolkit
	copy(current, previous);
	
	convertColor(image, current, CV_RGB2GRAY); 
	
	//absdiff(previous, current, diff);
	//threshold(diff, 20.0f);
	//diff.update();
	

	
};


void MotionManager :: setHomography(Mat& newHomography){ 

	homography = newHomography; 
	
	
	
}


float MotionManager :: getMotionAtPosition(ofVec2f pos, int width){
	
	// HOW DO WE DO THAT: 
		//perspectiveTransform(toCv(pos), toCv(pos), homography);
		
	pos.x = ofClamp(pos.x, 0, diff.width-10);
	pos.y = ofClamp(pos.y, 0, diff.height-10);
	
	Mat curMat = toCv(current); // or video
	Mat curRoi(curMat, cv::Rect(pos.x, pos.y, 10, 10));
	Mat prevMat = toCv(previous);
	Mat prevRoi(prevMat, cv::Rect(pos.x, pos.y, 10, 10));
	Mat diffMat = toCv(smallDiff); 
	//Mat diffRoi(prevMat, cv::Rect(pos.x, pos.y, 10, 10));
	
	absdiff(prevRoi, curRoi, diffMat); 
	//diffMat.update();
	
	Scalar avg = mean(diffMat);
	//ofColor avgColor = toOf(avg);
	ofColor avgColor(avg[0]);
	//		
	//		ofPushStyle(); 
	//		ofSetColor(avgColor);
	//		ofNoFill();
	//		ofCircle(pos, 5);
	//		ofPopStyle(); 
	return avgColor.getBrightness(); 
	
};