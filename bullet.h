#pragma once
#include <cassert>
#include <iostream>
#include <list>
#include "ground.h"
#include "position.h"
#include "Lab07.cpp"
#include <queue>
#include "physics.h"


/// <summary>
/// Test class to test the updating of the bullet
/// </summary>
class Bullet
{
public:

	std::queue<double> listX;
	std::queue<double> listY;
	double componentX;
	double componentY;
	double x = 0.0;
	double y = 0.0;

	Bullet(Position* howitzer)
	{
		for (int count = 1; count <= 19; count++)
		{
			listX.push(0);
			listY.push(0);
		}
		x = howitzer->getMetersX();
		y = howitzer->getMetersY();
		listX.push(x);
		listY.push(y);
	}

	void updatePosition()
	{
		x = x + componentX;

		listX.pop();
		listX.push(x);


		y = y + componentY;

		listY.pop();
		listY.push(y);

		if (y < 0)
		{
			for (int count = 0; count < 20; count++)
			{
				listX.pop();
				listX.push(0);
				listY.pop();
				listY.push(0);
			}
		}
	}

private:
	Position position = Position();
};

