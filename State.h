#pragma once
#ifndef STATE_H
# define STATE_H

#include <irrlicht.h>
#include "EventReceiver.h"

class State {
protected:
	irr::IrrlichtDevice *device_;
	//Network& net_driver_;
	//Context& ctx_;

public:
	State() = delete;
 	State(irr::IrrlichtDevice& device) : device_(&device) {}
		//Network& net_driver, Context& ctx) 
	//	: window_(window) {} //, net_driver_(net_driver), ctx_(ctx) {}
	State(const State&) = delete;
	virtual ~State() {}

	virtual void Events(EventReceiver *receiver) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};

#endif  // STATE_H