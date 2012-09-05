
#include "ofMain.h"
#include "constants.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"


//========================================================================
int main( ){

    ofAppGlutWindow window;
	
	//ofSetupOpenGL(&window, 1920 * APP_SCALE,1080*APP_SCALE, OF_WINDOW);			// <-------- setup the GL context
	ofSetupOpenGL(&window, APP_WIDTH, APP_HEIGHT, OF_WINDOW);			// <-------- setup the GL context
	
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new testApp());

}
