#pragma once
#ifndef GAME_ENGINE
# define GAME_ENGINE

#include <irrlicht.h>
#include "StateManager.h"

# define WINDOW_WIDTH (1600)
# define WINDOW_HEIGHT (900)

class GameEngine {
private:
	irr::IrrlichtDevice *device_;

	irr::video::IVideoDriver* driver = device_->getVideoDriver();
	irr::scene::ISceneManager* scenemgr = device_->getSceneManager();

public:
	GameEngine();
	~GameEngine();

	irr::IrrlichtDevice& get_device() { return *device_; }

	bool running() { return device_->run() && StateManager::get().has_active_state(); }
	void Events(EventReceiver *receiver);
	void Update();
	void Render();
};

#endif // GAME_ENGINE