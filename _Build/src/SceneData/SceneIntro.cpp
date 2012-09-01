
#include "SceneIntro.h"

SceneIntro :: SceneIntro(ParticleSystemManager& psm, ofRectangle triggerarea) : Scene(psm, triggerarea) {


	softWhiteImage.loadImage("img/ParticleWhite.png");
//	for(float i = 0; i<360; i+=10) {
//		
//		ofVec3f v(100,0,0);
//		v.rotate(i, ofVec3f(0,0,1));
//		textLines.addVertex(v+ofVec3f(400,400));
//		
//	}

	
	VectorFont font;
	
	Letter letter = font.letters['Q'];
	vector <Letter> letters;
	
//	letters.push_back(font.letters['G']);
//	letters.push_back(font.letters['O']);
//	letters.push_back(font.letters['O']);
//	letters.push_back(font.letters['D']);
//	letters.push_back(font.letters['N']);
//	letters.push_back(font.letters['I']);
//	letters.push_back(font.letters['G']);
//	letters.push_back(font.letters['H']);
//	letters.push_back(font.letters['T']);
//	
	
	
//	letters.push_back(font.letters['A']);
//	letters.push_back(font.letters['C']);
//	letters.push_back(font.letters['T']);
//	letters.push_back(font.letters['I']);
//	letters.push_back(font.letters['V']);
//	letters.push_back(font.letters['A']);
//	letters.push_back(font.letters['T']);
//	letters.push_back(font.letters['E']);
//	letters.push_back(font.letters['D']);
	
	letters.push_back(font.letters['I']);
	letters.push_back(font.letters['N']);
	letters.push_back(font.letters['I']);
	letters.push_back(font.letters['T']);
	letters.push_back(font.letters['I']);
	letters.push_back(font.letters['A']);
	letters.push_back(font.letters['L']);
	letters.push_back(font.letters['I']);
	letters.push_back(font.letters['Z']);
	letters.push_back(font.letters['E']);
	letters.push_back(font.letters['D']);
	letters.push_back(font.letters['!']);
	
	
	float letterscale = 13;
	float letterspacing = (5*letterscale) + 13;
	float lettercount = letters.size();
	lettercount += (letters.size() % 2);
	float x = APP_WIDTH/2 - (lettercount*letterspacing/2)+15;
	
	float fuseTime = 5;
	float letterSparkTime = 20; 

	float triggerSpacing = 0.1;
	float triggerCentre = APP_WIDTH * 0.7;
	
	float sparklerSpacing = 10;
	float verticalPosition = 400; 
	
	
	
	ParticleSystemSettings ps = getLetterSparks();

	ps.emitDelay = fuseTime;
	ps.emitLifeTime = 20;
	
	ParticleSystemSettings smoke = getSmoke();

	smoke.emitDelay = fuseTime;
	smoke.emitLifeTime = letterSparkTime;
	smoke.emitStartSizeModifier = 1;
	
	ParticleSystemSettings letterBurst = getLetterBurst();
	letterBurst.emitDelay = fuseTime;
	letterBurst.emitLifeTime = letterSparkTime/2;
	
	
	ParticleSystemSettings sparkler = getFuseSparkles();
	sparkler.emitLifeTime = fuseTime; 

	ParticleSystemSettings sparklerSmoke = getSmoke();
	sparklerSmoke.emitLifeTime = fuseTime;
	sparklerSmoke.emitCount = 100;
	sparklerSmoke.emitStartSizeModifier = 1;
	
	
	
	RocketSettings rocketTemplate;
	rocketTemplate.directionVar = 0; 
	
	rocketTemplate.addParticleSystemSetting(sparkler);
	rocketTemplate.addParticleSystemSetting(sparklerSmoke);
	
	TriggerRocket triggerTemplate(psm);
	triggerTemplate.restoreSpeed = 0; 
	
	
	TriggerPattern pattern;

	
		
	for(int j = 0; j<letters.size(); j++) {
		
		
		ofMesh glyph;
		
		Letter & letter = letters[j];
		
		
		
		
		
		for(int i = 0; i<letter.points.size(); i+=2) {
		
			ofVec3f pos = ofVec3f(x,verticalPosition);
			
			letterMesh.addVertex(letter.points[i]*letterscale +pos);
			letterMesh.addVertex(letter.points[i+1]*letterscale +pos);
			
			
			ofVec3f v = letter.points[i+1] -letter.points[i];
			ofVec3f p = letter.points[i];
			
			p*=letterscale;
			p+=pos;
			v*=letterscale;
			
			
			
			float numPoints = floor(v.length()/sparklerSpacing);
			if(numPoints<1) numPoints = 1;
			
			for(float t = 0; t<=1; t+=(1.0f/numPoints)) {
				
				glyph.addVertex(p+(v*t));
				
				
				
			}
			
		}
		
		ParticleSystemSettings sparks(ps);
		ParticleSystemSettings smokes(smoke);
		ParticleSystemSettings burst(letterBurst);
		ps.emitShape =  
			smoke.emitShape = 
			burst.emitShape = new ofMesh(glyph); 
		
		RocketSettings rocket(rocketTemplate);
		rocket.addParticleSystemSetting(ps);
		rocket.addParticleSystemSetting(smoke);
		rocket.addParticleSystemSetting(burst);
		
		
		
		TriggerRocket trigger(triggerTemplate);
		trigger.pos.x = ((x- (APP_WIDTH/2)) * triggerSpacing) + (triggerCentre);
		trigger.fixedPosition = true;
		
		ofVec3f targetToLetter = ofVec3f(x,450) - trigger.pos;
		
		// dunno why i have to do this. 
		//targetToLetter.y = -targetToLetter.y;
		rocket.direction = -targetToLetter.angle(ofVec3f(1,0,0));
		rocket.startSpeedMin = rocket.startSpeedMax = targetToLetter.length() / fuseTime;
		
		trigger.addRocketSettings(rocket);
		
		
		
		
		pattern.addTrigger(trigger);
		
		
		x+=letterspacing;
	}
	
	
	

	

	
		
	
	addArrangement(pattern, true);
	
	

}

bool SceneIntro :: draw() {
	if (Scene :: draw()) {
		// draw letters
	
		textWriter.draw(ofRectangle(APP_WIDTH*0.2, APP_HEIGHT*0.2, APP_WIDTH *0.6, APP_HEIGHT * 0.2), "Brighton Digital Festival 2012",true);
		
		
		ofSetColor(200);
		letterMesh.setMode(OF_PRIMITIVE_POINTS);
		
		letterMesh.draw();
		
		
		
		return true;
	} else {
		
		return false;
	}
	
	
}
bool SceneIntro :: update(float deltaTime) {
	// disables reworking of arrangements
	
	//updateTriggerArea = false;
	
	return Scene :: update(deltaTime);
	
}


ParticleSystemSettings SceneIntro:: getSmoke() {
	
	float hueStartOffset = 200;
	float saturation = 0;
	ParticleSystemSettings ps2;
	// PHYSICS
	ps2.speedMin = 15;
	ps2.speedMax = 70;
	ps2.directionZ = -90;
	ps2.directionZVar = 90;
	ps2.directionY = -90; 
	ps2.directionYVar = 20;
	ps2.drag = 0.90;
	ps2.gravity.set(-40,-100);
	
	//LIFE
	ps2.lifeMin = 0.5;
	ps2.lifeMax = 2;
	
	//APPEARANCE
	
	ps2.sizeStartMin = 2;
	ps2.sizeStartMax = 5;
	ps2.sizeChangeRatio = 5;
	
	ps2.hueStartMin = 0+hueStartOffset;
	ps2.hueStartMax = 0+hueStartOffset;
	ps2.hueChange = 0;
	
	ps2.brightnessStartMin = 10;
	ps2.brightnessStartMax = 20;
	ps2.brightnessEnd = 0;
	
	ps2.saturationMin = saturation;
	ps2.saturationMax = saturation;
	ps2.saturationEnd = saturation;
	
	//ps2.shimmerMin = 0.8;
	
	// but also :
	// lifeExpectancy
	// delay
	
	ps2.emitStartSizeModifier = 0;
	//ps2.emitSpeedModifier = 0;
	
	
	ps2.emitMode = PARTICLE_EMIT_CONTINUOUS;
	ps2.emitCount = 800;
	
	ps2.emitDelay = 0;
	ps2.emitLifeTime= 0.5;
	
	//ps2.renderer = new ParticleRendererBitmap(&softWhiteImage);
	ps2.renderer = new ParticleRendererShape();
	

	
	return ps2;
	
	
}

ParticleSystemSettings SceneIntro:: getLetterSparks() {
	ParticleSystemSettings ps;
	
	ps.renderer = new ParticleRendererShape();
	ps.speedMin = 0;
	ps.speedMax = 200;
	
	ps.directionZ = 0;
	ps.directionZVar = 0;
	ps.directionY = -90;
	ps.drag = 0.93;
	ps.lifeMin = 0.01;
	ps.shimmerMin = 0;
	ps.emitCount = 1000;
	ps.emitSpeedModifier = 1;
	ps.emitStartSizeModifier = 1;
	
	ps.brightnessEnd = 0;
	
	ps.gravity.y = 200;
	
	
	return ps;
	
}



ParticleSystemSettings SceneIntro:: getFuseSparkles() {
	ParticleSystemSettings ps;
	
	ps.renderer = new ParticleRendererLine(1,false);
	
	ps.directionZ = 0;
	ps.directionZVar = 90;
	ps.directionY = 0;
	ps.directionYVar = 180;
	ps.drag = 0.8;
	
	ps.lifeMin = 0.01;
	ps.lifeMax = 0.2; 
	ps.shimmerMin = 0;
	ps.emitCount = 1000;
	//ps.emitSpeedModifier = 0;
	
	ps.brightnessEnd = 0;
	ps.saturationEnd = 800;
	ps.hueStartMin = 20;
	ps.hueStartMax = 30;
	
	ps.speedMin = 100;
	ps.speedMax = 500;
	ps.gravity.y = 500;
	
	
	return ps;
	
}


ParticleSystemSettings SceneIntro:: getLetterBurst() {
	ParticleSystemSettings ps;
	
	ps.renderer = new ParticleRendererLine(0,false);
	
	ps.speedMin = 200;
	ps.speedMax = 600;
	ps.gravity.y = 100;
	
	
	ps.directionZ = 0;
	ps.directionZVar = 10;
	ps.directionY = -90;
	ps.directionYVar = 10;
	
	ps.drag = 0.93;
	ps.lifeMin = 0.01;
	//ps.shimmerMin = 0;
	ps.emitCount = 5000;
	ps.emitSpeedModifier = 0.5;
	
	ps.sizeStartMin = 0;
	ps.sizeStartMin = 3;
	ps.brightnessStartMin =
		ps.brightnessStartMax = 255;
	
	ps.brightnessEnd = 0;
	ps.saturationEnd = 500;
	ps.hueStartMin = 20;
	ps.hueStartMax = 30;

	
	
	
	//ps.brightnessEnd = 0;
	
	ps.emitLifeTime = 10;
	
	
	
	return ps;
	
}


