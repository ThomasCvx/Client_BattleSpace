/*
	Thomas Couavoux EPITECH
	Project : BattleSpace
	Part : Client_BattleSpace
*/

#include "ClientNetwork.h"
#include "GameEngine.h"
#include "IntroState.h"

int main()
{
	ClientNetwork cn;
	GameEngine *ge;
	IntroState *is;
	EventReceiver *receiver;

	cn.connectServer("IP", 9999);

	while (ge->running()) {
		ge->Events(receiver);
		ge->Update();
		ge->Render();
		// Boucle de jeu
	}

	return 1;
}