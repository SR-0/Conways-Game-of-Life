#include "Engine.h"

// SFML includes
#include <SFML/Window/Event.hpp>

// STL includes
#include <iostream>

#pragma region CONSTRUCTORS - DESTRUCTORS

Engine::Engine(
	unsigned int	width, 
	unsigned int	height,
	const char*		id, 
	bool			isFullscreen)
{
	// all creation/initialization
	create(width, height, id, isFullscreen);

	// all setup
	setup();
}

Engine::~Engine()
{
	// all destruction
	destroy();
}

#pragma endregion CONSTRUCTORS - DESTRUCTORS



#pragma region CREATE - SETUP - DESTROY

void Engine::create(unsigned int width, unsigned int height, const char* id, bool isFullscreen)
{
	// core creation/initialization
	window			= new sf::RenderWindow(sf::VideoMode(width, height), id, (isFullscreen ? sf::Style::Fullscreen : sf::Style::None));
	clock			= new sf::Clock;
	//threadManager	= new ThreadManager;

	// game object creation/initialization
	backGround	= new sf::RectangleShape(sf::Vector2f((float)width, (float)height));
	cellGrid	= new CellGrid(0, 0, (width / 10), (height / 10), 10.0f);

	// seed random number aka 'rand()'
	srand(time(0));

	// maximum random spawn/create positions
	static const int xMaximum = (width / 10)	- largestBlockWidth;
	static const int yMaximum = (height / 10)	- largestBlockHeight;

	if (true) // still lifes
	{
		
		// create blocks
		for (unsigned int i = 0; i < numberOfBlocks; i++)
		{
			cellGrid->createBlock(0 + rand() % (xMaximum) + 1, 0 + rand() % (yMaximum) + 1);
		}

		// create beehives (horizontal)
		for (unsigned int i = 0; i < numberOfBeehiveHorizontals; i++)
		{
			cellGrid->createBeehiveHorizontal(  0 + rand() % (xMaximum) + 1, 0 + rand() % (yMaximum) + 1);
		}

		// create beehives (vertical)
		for (unsigned int i = 0; i < numberOfBeehiveVerticals; i++)
		{
			cellGrid->createBeehiveVertical(0 + rand() % (xMaximum) + 1, 0 + rand() % (yMaximum) + 1);
		}

		// create Loafs (direction)
		for (unsigned int i = 0; i < numberOfLoafUpLefts; i++)
		{
			cellGrid->createLoafUpLeft(0 + rand() % (xMaximum) + 1, 0 + rand() % (yMaximum) + 1);
		}

		// create Loafs (direction)
		for (unsigned int i = 0; i < numberOfLoafUpRights; i++)
		{
			cellGrid->createLoafUpRight(0 + rand() % (xMaximum) + 1, 0 + rand() % (yMaximum) + 1);
		}

		// create Loafs (direction)
		for (unsigned int i = 0; i < numberOfLoafDownLefts; i++)
		{
			cellGrid->createLoafDownLeft(0 + rand() % (xMaximum) + 1, 0 + rand() % (yMaximum) + 1);
		}

		// create Loafs (direction)
		for (unsigned int i = 0; i < numberOfLoafDownRights; i++)
		{
			cellGrid->createLoafDownRight(0 + rand() % (xMaximum) + 1, 0 + rand() % (yMaximum) + 1);
		}

		// create boats (direction)
		for (unsigned int i = 0; i < numberOfBoatUpLefts; i++)
		{
			cellGrid->createBoatUpLeft(0 + rand() % (xMaximum) + 1, 0 + rand() % (yMaximum) + 1);
		}

		// create boats (direction)
		for (unsigned int i = 0; i < numberOfBoatUpRights; i++)
		{
			cellGrid->createBoatUpRight(0 + rand() % (xMaximum) + 1, 0 + rand() % (yMaximum) + 1);
		}

		// create boats (direction)
		for (unsigned int i = 0; i < numberOfBoatDownLefts; i++)
		{
			cellGrid->createBoatDownLeft(0 + rand() % (xMaximum) + 1, 0 + rand() % (yMaximum) + 1);
		}

		// create boats (direction)
		for (unsigned int i = 0; i < numberOfBoatDownRights; i++)
		{
			cellGrid->createBoatDownRight(0 + rand() % (xMaximum) + 1, 0 + rand() % (yMaximum) + 1);
		}

		// create Tubs
		for (unsigned int i = 0; i < numberOfTubs; i++)
		{
			cellGrid->createTub(0 + rand() % (xMaximum) + 1, 0 + rand() % (yMaximum) + 1);
		}

	}

	if (true) // oscillators
	{
		
		// create blinkers (stage 1)
		for (unsigned int i = 0; i < numberOfBlinker_Stage1s; i++)
		{
			cellGrid->createBlinker_Stage1(0 + rand() % (xMaximum) + 1, 0 + rand() % (yMaximum) + 1);
		}

		// create blinkers (stage 2)
		for (unsigned int i = 0; i < numberOfBlinker_Stage2s; i++)
		{
			cellGrid->createBlinker_Stage2(0 + rand() % (xMaximum) + 1, 0 + rand() % (yMaximum) + 1);
		}

	}

	if (true) // spaceships
	{

		// create gliders (left direction)
		for (unsigned int i = 0; i < numberOfGliderUpLeft_Stage1s; i++)
		{
			cellGrid->createGliderUpLeft_Stage1(0 + rand() % (xMaximum ) + 1, 0 + rand() % (yMaximum) + 1);
		}
		
		// create gliders (direction)
		for (unsigned int i = 0; i < numberOfGliderUpRight_Stage1s; i++)
		{
			cellGrid->createGliderUpRight_Stage1(0 + rand() % (xMaximum ) + 1, 0 + rand() % (yMaximum) + 1);
		}
		
		// create gliders (direction)
		for (unsigned int i = 0; i < numberOfGliderDownLeft_Stage1s; i++)
		{
			cellGrid->createGliderDownLeft_Stage1(0 + rand() % (xMaximum ) + 1, 0 + rand() % (yMaximum) + 1);
		}
		
		// create gliders (direction)
		for (unsigned int i = 0; i < numberOfGliderDownRight_Stage1s; i++)
		{
			cellGrid->createGliderDownRight_Stage1(0 + rand() % (xMaximum ) + 1, 0 + rand() % (yMaximum) + 1);
		}

		// create HWSSs (Left (direction)
		for (unsigned int i = 0; i < numberOfHWSSLeft_Stage1s; i++)
		{
			cellGrid->createHWSSLeft_Stage1(0 + rand() % (xMaximum ) + 1, 0 + rand() % (yMaximum) + 1);
		}

		// create HWSSs (Right direction)
		for (unsigned int i = 0; i < numberOfHWSSRight_Stage1s; i++)
		{
			cellGrid->createHWSSRight_Stage1(0 + rand() % (xMaximum ) + 1, 0 + rand() % (yMaximum) + 1);
		}
		
	}

	if (true)
	{
			
		// glider guns (horizontal under-over)
		for (unsigned int i = 0; i < numberOfGliderGunHorizontalUnderOvers; i++)
		{
			cellGrid->createGliderGunHorizontalUnderOver(10, 10);
			cellGrid->createGliderGunHorizontalUnderOver(10, 40);
			cellGrid->createGliderGunHorizontalUnderOver(10, 70);
		}

		// glider guns (horizontal over-under)
		for (unsigned int i = 0; i < numberOfGliderGunHorizontalOverUnders; i++)
		{
			cellGrid->createGliderGunHorizontalOverUnder(10, 130);
			cellGrid->createGliderGunHorizontalOverUnder(10, 160);
			cellGrid->createGliderGunHorizontalOverUnder(10, 190);
		}
	}
}

void Engine::setup()
{
	// window setup
	window->setFramerateLimit(maxFPS);
	window->setVerticalSyncEnabled(true);

	// background setup
	backGround->setPosition(0, 0);
	backGround->setFillColor(sf::Color(0, 0, 0));
	backGround->setOutlineColor(sf::Color(25, 125, 25));
	backGround->setOutlineThickness(-2.f);
}

void Engine::destroy()
{
	// core destruction
	delete cellGrid;
	delete backGround;
	delete clock;
	delete window;
}

#pragma endregion CREATE - SETUP - DESTROY



#pragma region UPDATE - RENDER

void Engine::update()
{
	// all update functions
	updateDelta();
	updateEvent();
	updateInput();
	updateCells();
}

void Engine::render()
{
	// all render functions
	clear();
	draw();
	display();
}

#pragma endregion UPDATE - RENDER



#pragma region UPDATE SPECIFIC

void Engine::updateDelta()
{
	// update delta time measurements
	deltaTimeRestart = (float)clock->restart().asMilliseconds();
	deltaTimeElapsed = (float)clock->getElapsedTime().asMilliseconds();
}

void Engine::updateEvent()
{
	// update window event handling (basic)
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
			{
				window->close();
			}
			break;
		}
	}
}

void Engine::updateInput()
{
	// update input (add input manager later if needed)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window->close();
	}
}

void Engine::updateCells()
{
	// update all cells in grid based on Conway's Game of Life Rules
	cellGrid->update();
}

#pragma endregion UPDATE SPECIFIC



#pragma region RENDER SPECIFIC

void Engine::clear()
{
	// clear frame
	window->clear(sf::Color(35, 35, 35, 255));
}

void Engine::draw()
{
	// draw background
	window->draw(*backGround);

	// draw cellGrid
	for (unsigned int y = 0; y < cellGrid->matrix.size(); y++)
	{
		for (unsigned int x = 0; x < cellGrid->matrix[y].size(); x++)
		{
			window->draw(cellGrid->matrix[y][x]);
		}
	}
}

void Engine::display()
{
	//display frame
	window->display();
}

#pragma endregion RENDER SPECIFIC



#pragma endregion 'GET' FUNCTIONS

bool Engine::isRunning()
{
	// this will return true while window object is 'open'
	return window->isOpen();
}

#pragma endregion 'GET' FUNCTIONS