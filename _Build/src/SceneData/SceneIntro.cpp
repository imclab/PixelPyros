
#include "SceneIntro.h"

SceneIntro :: SceneIntro(ParticleSystemManager& psm, ofRectangle triggerarea) : Scene(psm, triggerarea) {


	
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
	
	
	letters.push_back(font.letters['A']);
	letters.push_back(font.letters['C']);
	letters.push_back(font.letters['T']);
	letters.push_back(font.letters['I']);
	letters.push_back(font.letters['V']);
	letters.push_back(font.letters['A']);
	letters.push_back(font.letters['T']);
	letters.push_back(font.letters['E']);
	letters.push_back(font.letters['D']);

	
	ParticleSystemSettings ps = getLetterSparks();
	ps.emitShape = &letterMesh;
	ps.emitDelay = 2;
	ps.emitLifeTime = 20;
	
	ParticleSystemSettings smoke = getSmoke();
	smoke.emitShape = &letterMesh;
	smoke.emitDelay = 2;
	smoke.emitLifeTime = 20;
	smoke.emitStartSizeModifier = 1;
	
	
	ParticleSystemSettings sparkler = getFuseSparkles();
	sparkler.emitLifeTime = 2; 

	ParticleSystemSettings sparklerSmoke = getSmoke();
	sparklerSmoke.emitLifeTime = 2;
	sparklerSmoke.emitCount = 100;
	sparklerSmoke.emitStartSizeModifier = 1;
	
	
	
	RocketSettings rocketTemplate;
	rocketTemplate.startSpeedMin = rocketTemplate.startSpeedMax =200;
	
	
	rocketTemplate.addParticleSystemSetting(sparkler);
	rocketTemplate.addParticleSystemSetting(sparklerSmoke);
	
	TriggerRocket triggerTemplate(psm);
	triggerTemplate.restoreSpeed = 0; 
	
	
	TriggerPattern pattern;

	
	float x = 320;
	
	for(int j = 0; j<letters.size(); j++) {
		
		
		ofMesh glyph;
		
		Letter & letter = letters[j];
		
		
		
		
		
		for(int i = 0; i<letter.points.size(); i+=2) {
		
			
			ofVec3f v = letter.points[i+1] -letter.points[i];
			ofVec3f p = letter.points[i];
			
			p*=20;
			p+=ofVec3f(x,300);
			v*=20;
			
			
			
			float numPoints = floor(v.length()/15);
			
			for(float t = 0; t<=1; t+=(1.0f/numPoints)) {
				
				glyph.addVertex(p+(v*t));
				
			}
			
		}
		
		ParticleSystemSettings sparks(ps);
		ParticleSystemSettings smokes(smoke);
		ps.emitShape = new ofMesh(glyph);
		smoke.emitShape = new ofMesh(glyph);
		
		RocketSettings rocket(rocketTemplate);
		rocket.addParticleSystemSetting(ps);
		rocket.addParticleSystemSetting(smoke);
		
		TriggerRocket trigger(triggerTemplate);
		trigger.addRocketSettings(rocket);
		pattern.addTrigger(trigger);
		
		
		x+=110;
	}
	
	
	

	

	
		
	
	addArrangement(pattern);
	
	

}


bool SceneIntro :: update(float deltaTime) {
	// disables reworking of arrangements
	
	updateTriggerArea = false;
	
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
	ps2.gravity.set(-20,-100);
	
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
	ps2.brightnessStartMax = 30;
	ps2.brightnessEnd = 0;
	
	ps2.saturationMin = saturation;
	ps2.saturationMax = saturation;
	ps2.saturationEnd = saturation;
	
	ps2.shimmerMin = 0.8;
	
	// but also :
	// lifeExpectancy
	// delay
	
	ps2.emitStartSizeModifier = 0;
	//ps2.emitSpeedModifier = 0;
	
	
	ps2.emitMode = PARTICLE_EMIT_CONTINUOUS;
	ps2.emitCount = 1000;
	
	ps2.emitDelay = 0;
	ps2.emitLifeTime= 0.5;
	
	ps2.renderer = new ParticleRendererShape();
	

	
	return ps2;
	
	
}

ParticleSystemSettings SceneIntro:: getLetterSparks() {
	ParticleSystemSettings ps;
	
	ps.renderer = new ParticleRendererShape();
	
	ps.directionZ = 0;
	ps.directionZVar = 0;
	ps.directionY = -90;
	ps.drag = 0.93;
	ps.lifeMin = 0.01;
	ps.shimmerMin = 0;
	ps.emitCount = 1000;
	ps.emitSpeedModifier = 0;
	
	ps.brightnessEnd = 0;
	ps.speedMin = 0;
	ps.speedMax = 500;
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

