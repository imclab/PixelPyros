


#pragma once

#include "ofMain.h"

class QuadWarp {
	
	public :
	
	QuadWarp (vector <ofVec3f>& quadPoints);
	
	void draw(); 
	
	void mousePressed(ofMouseEventArgs &e);
	void mouseDragged(ofMouseEventArgs &e);
	void mouseReleased(ofMouseEventArgs &e);
	
	bool hitTestPoints(vector<ofVec2f>& points, ofVec2f& point);
	void drawPoints(vector<ofVec2f>& points, ofColor colour = ofColor::white);

	// applies the distortion matrix to the current draw state
	void apply(ofRectangle sourceRect);
	
	bool visible;
	bool changed; 
	
	vector <ofVec3f>& points;
	ofColor pointColour;
	
	GLfloat _glWarpMatrix[16];
	double _warpMatrix[3][3];
	
	
	ofVec3f *curPoint;
	ofVec3f clickOffset;
	ofVec3f dragStartPoint;
	
	
	
	float pointRadius; 
	
	
};