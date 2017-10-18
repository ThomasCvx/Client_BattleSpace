#include "StateManager.h"
#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine() {
	std::cout << "Starting game engine..." << std::endl;

	device_ = irr::createDevice(irr::video::EDT_DIRECT3D8, irr::core::dimension2d<irr::u32>(WINDOW_WIDTH, WINDOW_HEIGHT));
}

GameEngine::~GameEngine() {
	std::cout << "Stopping game engine..." << std::endl;
}

void GameEngine::Events(EventReceiver *receiver) {
	if (StateManager::get().has_active_state()) {
		StateManager::get().get_active_state()->Events(receiver);
	}
	else {
		std::cerr << "GameEngine critical error : no active state" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void GameEngine::Update() {
	if (StateManager::get().has_active_state()) {
		StateManager::get().get_active_state()->Update();
	}
	else {
		std::cerr << "GameEngine critical error : no active state" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void GameEngine::Render() {
	if (StateManager::get().has_active_state()) {
		StateManager::get().get_active_state()->Render();
	}
	else {
		std::cerr << "GameEngine critical error : no active state" << std::endl;
		exit(EXIT_FAILURE);
	}
}