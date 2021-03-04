#pragma once

// SFML includes
#include <SFML/Graphics/RenderWindow.hpp>

// local includes
#include "Cell.h"

/*
	Engine class will take care of the following: 

		- all creation/initialzation calls
		- all setup calls
		- all destruction calls
		- all update calls
		- all render calls

*/

class Engine
{
public: // constructors and deconstructors

	Engine(
		unsigned int	width,
		unsigned int	height,
		const char*		id,
		bool			isFullscreen);

	~Engine();

private: // creation/initialization, setup, and destruction

	void create(
		unsigned int	width,
		unsigned int	height,
		const char*		id,
		bool			isFullscreen);

	void setup();
	void destroy();

public: // update and render core

	void update();
	void render();

private: // update specific functions

	void updateDelta();
	void updateEvent();
	void updateInput();
	void updateCells();

public: // render specific functions

	void clear();
	void draw();
	void display();

public: // 'get' Funcitons

	bool isRunning();

private: // engine related

	sf::RenderWindow*	window				= nullptr;
	sf::Clock*			clock				= nullptr;
	float				deltaTimeRestart	= 0.f;
	float				deltaTimeElapsed	= 0.f;

private: // game related (Life)

	sf::RectangleShape* backGround	= nullptr;
	CellGrid*			cellGrid	= nullptr;
	unsigned int		maxFPS		= 60;

	static const int	largestBlockWidth						= 37;
	static const int	largestBlockHeight						= 9;
	static const int	numberOfBlocks							= 3;
	static const int	numberOfBeehiveHorizontals				= 3;
	static const int	numberOfBeehiveVerticals				= 3;
	static const int	numberOfLoafUpLefts						= 3;
	static const int	numberOfLoafUpRights					= 3;
	static const int	numberOfLoafDownLefts					= 3;
	static const int	numberOfLoafDownRights					= 3;
	static const int	numberOfBoatUpLefts						= 3;
	static const int	numberOfBoatUpRights					= 3;
	static const int	numberOfBoatDownLefts					= 3;
	static const int	numberOfBoatDownRights					= 3;
	static const int	numberOfTubs							= 3;
	static const int	numberOfBlinker_Stage1s					= 3;
	static const int	numberOfBlinker_Stage2s					= 3;
	static const int	numberOfGliderUpLeft_Stage1s			= 3;
	static const int	numberOfGliderUpRight_Stage1s			= 3;
	static const int	numberOfGliderDownLeft_Stage1s			= 3;
	static const int	numberOfGliderDownRight_Stage1s			= 3;
	static const int	numberOfHWSSLeft_Stage1s				= 5;
	static const int	numberOfHWSSRight_Stage1s				= 5;
	static const int	numberOfGliderGunHorizontalUnderOvers	= 3;
	static const int	numberOfGliderGunHorizontalOverUnders	= 3;

};