#pragma once

// SFML includes
#include <SFML/Graphics/RectangleShape.hpp>

// STL includes
#include <vector>

/*
	Cell class is a simple class represented by a modifiable and renderable 
	rectangle shape. It has a state or alive (isAlive) or dead (!isAlive) and
	a variable to represent it's local population for reference. The birthProcess()
	and deathProcess() functions will revive or kill the cell that calls it.
*/

class Cell : public sf::RectangleShape
{
public: // consturctors and desconstructors

	Cell(sf::RectangleShape body, bool isAlive = false);

public: // cell birth and death

	void birthProcess();
	void deathProcess();

public: // cell related

	bool				isAlive;
	unsigned int		localPopulation;

};

/*
	CellGrid class is a 2D array of Cell objects. The size is determined by
	user screen resolution to make things simple. CellGrid also has the
	functionality to spawn/create known structure or groups in Conway's Game 
	of Life at certain positions.
*/

class CellGrid
{
public: // consturctors and desconstructors

	CellGrid(
		unsigned int	globalPositionX,
		unsigned int	globalPositionY,
		unsigned int	columns,
		unsigned int	rows,
		float			cellSize);

public: // still life creation

	void createBlock(unsigned int column, unsigned int row);

	void createBeehiveHorizontal(unsigned int column, unsigned int row);
	void createBeehiveVertical(unsigned int column, unsigned int row);
	
	void createLoafUpLeft(unsigned int column, unsigned int row);
	void createLoafUpRight(unsigned int column, unsigned int row);
	void createLoafDownLeft(unsigned int column, unsigned int row);
	void createLoafDownRight(unsigned int column, unsigned int row);
	
	void createBoatUpLeft(unsigned int column, unsigned int row);
	void createBoatUpRight(unsigned int column, unsigned int row);
	void createBoatDownLeft(unsigned int column, unsigned int row);
	void createBoatDownRight(unsigned int column, unsigned int row);
	
	void createTub(unsigned int column, unsigned int row);

public: // oscillator creation

	void createBlinker_Stage1(unsigned int column, unsigned int row);
	void createBlinker_Stage2(unsigned int column, unsigned int row);

	//void createToadHorizontal_Stage1(unsigned int column, unsigned int row);
	//void createToadHorizontal_Stage2(unsigned int column, unsigned int row);
	//void createToadVertical_Stage1(unsigned int column, unsigned int row);
	//void createToadVertical_Stage2(unsigned int column, unsigned int row);
	
	//void createBeaconUpLeft_Stage1(unsigned int column, unsigned int row);
	//void createBeaconUpLeft_Stage2(unsigned int column, unsigned int row);
	//void createBeaconUpRight_Stage1(unsigned int column, unsigned int row);
	//void createBeaconUpRight_Stage2(unsigned int column, unsigned int row);

public: // spaceship creation

	void createGliderUpLeft_Stage1(unsigned int column, unsigned int row);
	//void createGliderUpLeft_Stage2(unsigned int column, unsigned int row);
	//void createGliderUpLeft_Stage3(unsigned int column, unsigned int row);
	//void createGliderUpLeft_Stage4(unsigned int column, unsigned int row);
	void createGliderUpRight_Stage1(unsigned int column, unsigned int row);
	//void createGliderUpRight_Stage2(unsigned int column, unsigned int row);
	//void createGliderUpRight_Stage3(unsigned int column, unsigned int row);
	//void createGliderUpRight_Stage4(unsigned int column, unsigned int row);
	void createGliderDownLeft_Stage1(unsigned int column, unsigned int row);
	//void createGliderDownLeft_Stage2(unsigned int column, unsigned int row);
	//void createGliderDownLeft_Stage3(unsigned int column, unsigned int row);
	//void createGliderDownLeft_Stage4(unsigned int column, unsigned int row);
	void createGliderDownRight_Stage1(unsigned int column, unsigned int row);
	//void createGliderDownRight_Stage2(unsigned int column, unsigned int row);
	//void createGliderDownRight_Stage3(unsigned int column, unsigned int row);
	//void createGliderDownRight_Stage4(unsigned int column, unsigned int row);
	
	//void createLWSSLeft_Stage1(unsigned int column, unsigned int row);
	//void createLWSSLeft_Stage2(unsigned int column, unsigned int row);
	//void createLWSSLeft_Stage3(unsigned int column, unsigned int row);
	//void createLWSSLeft_Stage4(unsigned int column, unsigned int row);
	//void createLWSSRight_Stage1(unsigned int column, unsigned int row);
	//void createLWSSRight_Stage2(unsigned int column, unsigned int row);
	//void createLWSSRight_Stage3(unsigned int column, unsigned int row);
	//void createLWSSRight_Stage4(unsigned int column, unsigned int row);
	
	//void createMWSSLeft_Stage1(unsigned int column, unsigned int row);
	//void createMWSSLeft_Stage2(unsigned int column, unsigned int row);
	//void createMWSSLeft_Stage3(unsigned int column, unsigned int row);
	//void createMWSSLeft_Stage4(unsigned int column, unsigned int row);
	//void createMWSSRight_Stage1(unsigned int column, unsigned int row);
	//void createMWSSRight_Stage2(unsigned int column, unsigned int row);
	//void createMWSSRight_Stage3(unsigned int column, unsigned int row);
	//void createMWSSRight_Stage4(unsigned int column, unsigned int row);
	
	void createHWSSLeft_Stage1(unsigned int column, unsigned int row);
	//void createHWSSLeft_Stage2(unsigned int column, unsigned int row);
	//void createHWSSLeft_Stage3(unsigned int column, unsigned int row);
	//void createHWSSLeft_Stage4(unsigned int column, unsigned int row);
	void createHWSSRight_Stage1(unsigned int column, unsigned int row);
	//void createHWSSRight_Stage2(unsigned int column, unsigned int row);
	//void createHWSSRight_Stage3(unsigned int column, unsigned int row);
	//void createHWSSRight_Stage4(unsigned int column, unsigned int row);

public:

	void createGliderGunHorizontalUnderOver(unsigned int column, unsigned int row);
	void createGliderGunHorizontalOverUnder(unsigned int column, unsigned int row);

public: // update all cells in grid based on Conway's Game of Life Rules

	void update();

public: // cell grid related

	unsigned int					globalPositionX	= 0;
	unsigned int					globalPositionY	= 0;
	std::vector<std::vector<Cell>>	matrix;

};