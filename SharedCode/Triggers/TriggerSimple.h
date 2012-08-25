
#pragma once

#include "ParticleSystem.h"
#include "PhysicsObject.h"
#include "RocketSettings.h"
#include "ParticleSystemManager.h"

#include "TriggerBase.h"

class TriggerSimple : public TriggerBase {
	
	public :
	
	TriggerSimple(ParticleSystemManager & psm);
	virtual bool update(float deltaTime);
	virtual void draw();
	
	virtual void start();
	virtual void stop();
	
	virtual void registerMotion(float unitValue);
	
	virtual bool doTrigger();
	
	
	virtual TriggerSimple* clone() const{
		//cout << "clone TriggerRocket"<< endl;
		return new TriggerSimple( *this );
	}
	
	
};