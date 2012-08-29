
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
	
	
	ofMesh glyph;
	float x = 300; 
	
	for(int j = 0; j<letters.size(); j++) {
		
		Letter & letter = letters[j];
		
		for(int i = 0; i<letter.points.size(); i+=2) {
		
			
			ofVec3f v = letter.points[i+1] -letter.points[i];
			ofVec3f p = letter.points[i];
			
			p*=20;
			p+=ofVec3f(x,400);
			v*=20;
			
			
			
			float numPoints = floor(v.length()/15);
			
			for(float t = 0; t<=1; t+=(1.0f/numPoints)) {
				
				letterMesh.addVertex(p+(v*t));
				
			}
			
		}
		x+=100;
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
	ps.speedMax = 300;
	ps.gravity.y = 200;
	
	RocketSettings rocket;
	rocket.addParticleSystemSetting(ps);
//	rocket.startSpeedMin = 0
//	rocket.startSpeedMax = 0;
	
	triggerText.addRocketSettings(rocket);
	
	TriggerPattern pattern;
	pattern.addTrigger(triggerText);
	
	addArrangement(pattern);
	
	

}





