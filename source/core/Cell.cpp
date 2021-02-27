#include "Cell.h"





#pragma region CELL

Cell::Cell(sf::RectangleShape body, bool isAlive)
	:
	sf::RectangleShape(body),
	isAlive(isAlive),
	localPopulation(0)
{
}

void Cell::birthProcess()
{
	isAlive = true;
	setFillColor(sf::Color(40, 170, 40));
	localPopulation = 0;
}

void Cell::deathProcess()
{
	isAlive = false;
	setFillColor(sf::Color(0, 0, 0));
	localPopulation = 0;
}

#pragma endregion CELL





#pragma region CELLGRID

CellGrid::CellGrid(
	unsigned int	globalPositionX, 
	unsigned int	globalPositionY, 
	unsigned int	columns, 
	unsigned int	rows, 
	float			cellSize)
{
	for (unsigned int y = 0; y < rows + 1; y++)
	{
		// create/initiate vector (row) of Cell objects
		std::vector<Cell> row;

		//  push vector of Cell objects into CellGrid's matrix
		matrix.push_back(row);

		for (unsigned int x = 0; x < columns  +1; x++)
		{
			// create/initiate Cell object
			Cell cell(sf::RectangleShape(sf::Vector2f(cellSize, cellSize)), false);
			
			// setup Cell object
			cell.setOutlineThickness(-1.f);
			cell.setOutlineColor(sf::Color(25, 125, 25));
			cell.setPosition( (x * cellSize) + globalPositionX, (y * cellSize) + globalPositionY);
			cell.setFillColor(sf::Color(0, 0, 0));
			
			// push Cell object into CellGrid's current matrix row
			matrix[y].push_back(cell);
		}
	}
}

#pragma region (SUB) STILL LIFE CREATION

void CellGrid::createBlock(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 0].birthProcess();
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 1][column + 0].birthProcess();
	matrix[row + 1][column + 1].birthProcess();
}

void CellGrid::createBeehiveHorizontal(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 0][column + 2].birthProcess();
	matrix[row + 1][column + 0].birthProcess();
	matrix[row + 1][column + 3].birthProcess();
	matrix[row + 2][column + 1].birthProcess();
	matrix[row + 2][column + 2].birthProcess();
}

void CellGrid::createBeehiveVertical(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 1][column + 0].birthProcess();
	matrix[row + 1][column + 2].birthProcess();
	matrix[row + 2][column + 0].birthProcess();
	matrix[row + 2][column + 2].birthProcess();
	matrix[row + 3][column + 1].birthProcess();
}

void CellGrid::createLoafUpLeft(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 0][column + 2].birthProcess();
	matrix[row + 1][column + 0].birthProcess();
	matrix[row + 1][column + 3].birthProcess();
	matrix[row + 2][column + 0].birthProcess();
	matrix[row + 2][column + 2].birthProcess();
	matrix[row + 3][column + 1].birthProcess();
}

void CellGrid::createLoafUpRight(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 1][column + 0].birthProcess();
	matrix[row + 1][column + 2].birthProcess();
	matrix[row + 2][column + 0].birthProcess();
	matrix[row + 2][column + 3].birthProcess();
	matrix[row + 3][column + 1].birthProcess();
	matrix[row + 3][column + 2].birthProcess();
}

void CellGrid::createLoafDownLeft(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 0][column + 2].birthProcess();
	matrix[row + 1][column + 0].birthProcess();
	matrix[row + 1][column + 3].birthProcess();
	matrix[row + 2][column + 3].birthProcess();
	matrix[row + 2][column + 1].birthProcess();
	matrix[row + 3][column + 2].birthProcess();
}

void CellGrid::createLoafDownRight(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 2].birthProcess();
	matrix[row + 1][column + 1].birthProcess();
	matrix[row + 1][column + 3].birthProcess();
	matrix[row + 2][column + 0].birthProcess();
	matrix[row + 2][column + 3].birthProcess();
	matrix[row + 3][column + 1].birthProcess();
	matrix[row + 3][column + 2].birthProcess();
}

void CellGrid::createBoatUpLeft(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 0].birthProcess();
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 1][column + 0].birthProcess();
	matrix[row + 1][column + 2].birthProcess();
	matrix[row + 2][column + 1].birthProcess();
}

void CellGrid::createBoatUpRight(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 0][column + 2].birthProcess();
	matrix[row + 1][column + 0].birthProcess();
	matrix[row + 1][column + 2].birthProcess();
	matrix[row + 2][column + 1].birthProcess();
}

void CellGrid::createBoatDownLeft(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 1][column + 0].birthProcess();
	matrix[row + 1][column + 2].birthProcess();
	matrix[row + 2][column + 0].birthProcess();
	matrix[row + 2][column + 1].birthProcess();
}

void CellGrid::createBoatDownRight(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 1][column + 0].birthProcess();
	matrix[row + 1][column + 2].birthProcess();
	matrix[row + 2][column + 1].birthProcess();
	matrix[row + 2][column + 2].birthProcess();
}

void CellGrid::createTub(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 1][column + 0].birthProcess();
	matrix[row + 1][column + 2].birthProcess();
	matrix[row + 2][column + 1].birthProcess();
}

#pragma endregion (SUB) STILL LIFE CREATION

#pragma region (SUB) OSCILLATOR CREATION

void CellGrid::createBlinker_Stage1(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 0].birthProcess();
	matrix[row + 1][column + 0].birthProcess();
	matrix[row + 2][column + 0].birthProcess();
}

void CellGrid::createBlinker_Stage2(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 0].birthProcess();
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 0][column + 2].birthProcess();
}

#pragma endregion (SUB) OSCILLATOR CREATION

#pragma region (SUB) SPACESHIP CREATION

void CellGrid::createGliderUpLeft_Stage1(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 0].birthProcess();
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 0][column + 2].birthProcess();
	matrix[row + 1][column + 0].birthProcess();
	matrix[row + 2][column + 1].birthProcess();
}

void CellGrid::createGliderUpRight_Stage1(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 0].birthProcess();
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 0][column + 2].birthProcess();
	matrix[row + 1][column + 2].birthProcess();
	matrix[row + 2][column + 1].birthProcess();
}

void CellGrid::createGliderDownLeft_Stage1(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 1][column + 0].birthProcess();
	matrix[row + 2][column + 0].birthProcess();
	matrix[row + 2][column + 1].birthProcess();
	matrix[row + 2][column + 2].birthProcess();
}

void CellGrid::createGliderDownRight_Stage1(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 1][column + 2].birthProcess();
	matrix[row + 2][column + 0].birthProcess();
	matrix[row + 2][column + 1].birthProcess();
	matrix[row + 2][column + 2].birthProcess();
}

#pragma endregion (SUB) SPACESHIP CREATION

void CellGrid::createHWSSLeft_Stage1(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 0].birthProcess();
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 0][column + 2].birthProcess();
	matrix[row + 0][column + 3].birthProcess();
	matrix[row + 0][column + 4].birthProcess();
	matrix[row + 0][column + 5].birthProcess();
	matrix[row + 1][column + 0].birthProcess();
	matrix[row + 1][column + 6].birthProcess();
	matrix[row + 2][column + 0].birthProcess();
	matrix[row + 3][column + 1].birthProcess();
	matrix[row + 3][column + 6].birthProcess();
	matrix[row + 4][column + 3].birthProcess();
	matrix[row + 4][column + 4].birthProcess();
}

void CellGrid::createHWSSRight_Stage1(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 1].birthProcess();
	matrix[row + 0][column + 2].birthProcess();
	matrix[row + 0][column + 3].birthProcess();
	matrix[row + 0][column + 4].birthProcess();
	matrix[row + 0][column + 5].birthProcess();
	matrix[row + 0][column + 6].birthProcess();
	matrix[row + 1][column + 0].birthProcess();
	matrix[row + 1][column + 6].birthProcess();
	matrix[row + 2][column + 6].birthProcess();
	matrix[row + 3][column + 0].birthProcess();
	matrix[row + 3][column + 5].birthProcess();
	matrix[row + 4][column + 2].birthProcess();
	matrix[row + 4][column + 3].birthProcess();
}

void CellGrid::createGliderGunHorizontalUnderOver(unsigned int column, unsigned int row)
{
	matrix[row + 0][column + 24].birthProcess();

	matrix[row + 1][column + 22].birthProcess();
	matrix[row + 1][column + 24].birthProcess();

	matrix[row + 2][column + 12].birthProcess();
	matrix[row + 2][column + 13].birthProcess();
	matrix[row + 2][column + 20].birthProcess();
	matrix[row + 2][column + 21].birthProcess();
	matrix[row + 2][column + 34].birthProcess();
	matrix[row + 2][column + 35].birthProcess();

	matrix[row + 3][column + 11].birthProcess();
	matrix[row + 3][column + 15].birthProcess();
	matrix[row + 3][column + 20].birthProcess();
	matrix[row + 3][column + 21].birthProcess();
	matrix[row + 3][column + 34].birthProcess();
	matrix[row + 3][column + 35].birthProcess();

	matrix[row + 4][column + 0 ].birthProcess();
	matrix[row + 4][column + 1 ].birthProcess();
	matrix[row + 4][column + 10].birthProcess();
	matrix[row + 4][column + 16].birthProcess();
	matrix[row + 4][column + 20].birthProcess();
	matrix[row + 4][column + 21].birthProcess();

	matrix[row + 5][column + 0 ].birthProcess();
	matrix[row + 5][column + 1 ].birthProcess();
	matrix[row + 5][column + 10].birthProcess();
	matrix[row + 5][column + 14].birthProcess();
	matrix[row + 5][column + 16].birthProcess();
	matrix[row + 5][column + 17].birthProcess();
	matrix[row + 5][column + 22].birthProcess();
	matrix[row + 5][column + 24].birthProcess();

	matrix[row + 6][column + 10].birthProcess();
	matrix[row + 6][column + 16].birthProcess();
	matrix[row + 6][column + 24].birthProcess();

	matrix[row + 7][column + 11].birthProcess();
	matrix[row + 7][column + 15].birthProcess();
	
	matrix[row + 8][column + 12].birthProcess();
	matrix[row + 8][column + 13].birthProcess();
}

void CellGrid::createGliderGunHorizontalOverUnder(unsigned int column, unsigned int row)
{
	matrix[row + 8][column + 24].birthProcess();

	matrix[row + 7][column + 22].birthProcess();
	matrix[row + 7][column + 24].birthProcess();

	matrix[row + 6][column + 12].birthProcess();
	matrix[row + 6][column + 13].birthProcess();
	matrix[row + 6][column + 20].birthProcess();
	matrix[row + 6][column + 21].birthProcess();
	matrix[row + 6][column + 34].birthProcess();
	matrix[row + 6][column + 35].birthProcess();

	matrix[row + 5][column + 11].birthProcess();
	matrix[row + 5][column + 15].birthProcess();
	matrix[row + 5][column + 20].birthProcess();
	matrix[row + 5][column + 21].birthProcess();
	matrix[row + 5][column + 34].birthProcess();
	matrix[row + 5][column + 35].birthProcess();

	matrix[row + 4][column + 0].birthProcess();
	matrix[row + 4][column + 1].birthProcess();
	matrix[row + 4][column + 10].birthProcess();
	matrix[row + 4][column + 16].birthProcess();
	matrix[row + 4][column + 20].birthProcess();
	matrix[row + 4][column + 21].birthProcess();

	matrix[row + 3][column + 0].birthProcess();
	matrix[row + 3][column + 1].birthProcess();
	matrix[row + 3][column + 10].birthProcess();
	matrix[row + 3][column + 14].birthProcess();
	matrix[row + 3][column + 16].birthProcess();
	matrix[row + 3][column + 17].birthProcess();
	matrix[row + 3][column + 22].birthProcess();
	matrix[row + 3][column + 24].birthProcess();

	matrix[row + 2][column + 10].birthProcess();
	matrix[row + 2][column + 16].birthProcess();
	matrix[row + 2][column + 24].birthProcess();

	matrix[row + 1][column + 11].birthProcess();
	matrix[row + 1][column + 15].birthProcess();

	matrix[row + 0][column + 12].birthProcess();
	matrix[row + 0][column + 13].birthProcess();
}

void CellGrid::update()
{
	static const unsigned int rows		= matrix.size()		- 1;
	static const unsigned int columns	= matrix[0].size()	- 1;

	// population check
	for (unsigned int y = 0; y < rows; y++)
	{
		for (unsigned int x = 0; x < columns; x++)
		{
			// left
			if ((x > 0) && (matrix[y][x - 1].isAlive))
			{
				matrix[y][x].localPopulation++;
			}

			// right
			if ((x < columns) && (matrix[y][x + 1].isAlive))
			{
				matrix[y][x].localPopulation++;
			}

			// top
			if ((y > 0) && (matrix[y - 1][x].isAlive))
			{
				matrix[y][x].localPopulation++;
			}

			// bottom
			if ((y < rows) && (matrix[y + 1][x].isAlive))
			{
				matrix[y][x].localPopulation++;
			}

			// left top
			if ((y > 0) && (x > 0) && (matrix[y - 1][x - 1].isAlive))
			{
				matrix[y][x].localPopulation++;
			}

			// left bottom
			if ((y < rows) && (x > 0) && (matrix[y + 1][x - 1].isAlive))
			{
				matrix[y][x].localPopulation++;
			}

			// right top
			if ((y > 0) && (x < columns) && (matrix[y - 1][x + 1].isAlive))
			{
				matrix[y][x].localPopulation++;
			}

			// right bottom
			if (  (y < rows) && (x < columns) && (matrix[y + 1][x + 1].isAlive) )
			{
				matrix[y][x].localPopulation++;
			}
		}
	}

	// enforce birth and death
	for (unsigned int y = 0; y < rows; y++)
	{
		for (unsigned int x = 0; x < columns; x++)
		{
			if ((!matrix[y][x].isAlive) && (matrix[y][x].localPopulation == 3))
			{
				matrix[y][x].birthProcess();
			}
			else if ((matrix[y][x].isAlive) && ((matrix[y][x].localPopulation < 2) || (matrix[y][x].localPopulation > 3)))
			{
				matrix[y][x].deathProcess();
			}
			else
			{
				matrix[y][x].localPopulation = 0;
			}
		}
	}
}

#pragma endregion CELLGRID