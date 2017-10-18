#pragma once
#ifndef INTRO_STATE
# define INTRO_STATE

#include "Eventreceiver.h"
#include <irrlicht.h>

class IntroState {
public:
	IntroState(irr::IrrlichtDevice& device);
	~IntroState();

	void Events(EventReceiver *receiver);
	void Update();
	void Render();
};


#endif // !INTRO_STATE
