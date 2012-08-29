
#include "SceneIntro.h"

SceneIntro :: SceneIntro(ParticleSystemManager& psm, ofRectangle triggerarea) : Scene(psm, triggerarea) {


	
	for(float i = 0; i<360; i+=10) {
		
		ofVec3f v(100,0,0);
		v.rotate(i, ofVec3f(0,0,1));
		textLines.addVertex(v+ofVec3f(400,400));
		
	}
	
	
	
	
	ParticleSystemSettings ps;
	
	ps.emitShape = &textLines;


	ps.renderer = new ParticleRendererShape();
	TriggerRocket triggerText(psm);
	
	
	RocketSettings rocket;
	rocket.addParticleSystemSetting(ps);
	rocket.startSpeedMin = rocket.startSpeedMax = 10;
	
	triggerText.addRocketSettings(rocket);
	
	TriggerPattern pattern;
	pattern.addTrigger(triggerText);
	
	addArrangement(pattern);
	
	

}





