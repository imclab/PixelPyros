
#include "SceneIntro.h"

SceneIntro :: SceneIntro(ParticleSystemManager& psm, ofRectangle* triggerarea) : Scene(psm, triggerarea) {


	
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
	
	letters.push_back(font.letters['G']);
	letters.push_back(font.letters['O']);
	letters.push_back(font.letters['O']);
	letters.push_back(font.letters['D']);
	letters.push_back(font.letters['N']);
	letters.push_back(font.letters['I']);
	letters.push_back(font.letters['G']);
	letters.push_back(font.letters['H']);
	letters.push_back(font.letters['T']);
	//letters.push_back(font.letters['!']);
	
	
	ofMesh glyph;
	float x = 320;
	
	for(int j = 0; j<letters.size(); j++) {
		
		Letter & letter = letters[j];
		
		for(int i = 0; i<letter.points.size(); i+=2) {
		
			
			ofVec3f v = letter.points[i+1] -letter.points[i];
			ofVec3f p = letter.points[i];
			
			p*=20;
			p+=ofVec3f(x,300);
			v*=20;
			
			
			
			float numPoints = floor(v.length()/15);
			
			for(float t = 0; t<=1; t+=(1.0f/numPoints)) {
				
				letterMesh.addVertex(p+(v*t));
				
			}
			
		}
		x+=110;
	}
	
	
	
	ParticleSystemSettings ps;
	
	ps.emitShape = &letterMesh;


	ps.renderer = new ParticleRendererShape();
	TriggerRocket triggerText(psm);
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
	
	RocketSettings rocket;
	rocket.addParticleSystemSetting(ps);
	
	ParticleSystemSettings smoke = getSmoke();
	smoke.emitShape = &letterMesh;
	
	smoke.lifeMin = 0.5;
	smoke.lifeMax = 2;
	smoke.sizeStartMax = 10;
	smoke.sizeChangeRatio = 5;
	smoke.gravity.y = -100;
	smoke.gravity.x = -20;
	smoke.directionZ = -90;
	smoke.directionY = -90;
	smoke.directionYVar = 20;
	smoke.speedMax =70;
	smoke.emitCount = 1000;
	smoke.brightnessStartMin = 10;
	smoke.brightnessStartMax = 30;
	smoke.shimmerMin = 0.8;
	
	

	rocket.addParticleSystemSetting(smoke);

	
	triggerText.addRocketSettings(rocket);
	
	TriggerPattern pattern;
	pattern.addTrigger(triggerText);
	
	addArrangement(pattern);
	
	

}



ParticleSystemSettings SceneIntro:: getSmoke() {
	
	float hueStartOffset = 200;
	float saturation = 0;
	ParticleSystemSettings ps2;
	// PHYSICS
	ps2.speedMin = 15;
	ps2.speedMax = 20;
	ps2.directionZ = 0;
	ps2.directionZVar = 90;
	ps2.directionYVar = 180;
	ps2.drag = 0.90;
	ps2.gravity.set(0,-30);
	
	//LIFE
	ps2.lifeMin = 1;
	ps2.lifeMax = 1.5;
	
	//APPEARANCE
	
	ps2.sizeStartMin = 2;
	ps2.sizeStartMax = 5;
	ps2.sizeChangeRatio = 5;
	
	ps2.hueStartMin = 0+hueStartOffset;
	ps2.hueStartMax = 0+hueStartOffset;
	ps2.hueChange = 0;
	
	ps2.brightnessStartMin = 20;
	ps2.brightnessStartMax = 70;
	ps2.brightnessEnd = 0;
	
	ps2.saturationMin = saturation;
	ps2.saturationMax = saturation;
	ps2.saturationEnd = saturation;
	
	//ps.shimmerMin = 0.1;
	
	// but also :
	// lifeExpectancy
	// delay
	
	ps2.emitStartSizeModifier = 0;
	//ps2.emitSpeedModifier = 0;
	
	
	ps2.emitMode = PARTICLE_EMIT_CONTINUOUS;
	ps2.emitCount = 500;
	
	ps2.emitDelay = 0;
	ps2.emitLifeTime= 0.5;
	
	ps2.renderer = new ParticleRendererShape();
	
	
	return ps2;
	
	
}



