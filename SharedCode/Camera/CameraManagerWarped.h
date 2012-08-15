//
//  CameraManagerWarped.h
//  ArchitectureCamera
//
//  Created by Seb Lee-Delisle on 09/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once

#include "CameraManager.h"
#include "Warper.h"

class CameraManagerWarped : public CameraManager { 

	public :
	
	CameraManagerWarped() : CameraManager() { 
		
	
		testImage.allocate(1024, 768, OF_IMAGE_GRAYSCALE);
		
		testImage.loadImage("JubileeLibrary.jpg");
		// check camera exists! 
		
		warper.setSourceImage(testImage);
		
		warper.guiVisible = true; 

		
	}
	
	bool update()  { 
	
		
		if( CameraManager::update()) { 
			
			testImage.setFromPixels(camera->getPixelsRef());
			warper.update(); 		
			return true;
		} else { 
			return false; 
			
		}
		
	}
	void draw(float x,float y)  { 
		if(!warper.guiVisible) CameraManager::draw(x,y);
		warper.draw(); 
		
	}

	
	Warper warper; 
	ofImage testImage; 
	
	
	


};