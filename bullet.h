#pragma once
#include <cassert>
#include <iostream>
#include <list>
#include "ground.h"
#include "position.h"
#include <deque>
#include "physics.h"


/// <summary>
/// Test class to test the updating of the bullet
/// </summary>
class Bullet
{
public:

	std::deque<double> listX;
	std::deque<double> listY;
	double componentX;
	double componentY;
	double x = 0.0;
	double y = 0.0;

	void newBullet(Position* howitzer)
	{
		listX.clear();
		listY.clear();
		for (int count = 1; count <= 19; count++)
		{
			listX.push_front(0);
			listY.push_front(0);
		}
		x = howitzer->getMetersX();
		y = howitzer->getMetersY();
		listX.push_front(x);
		listY.push_front(y);
	}

	void updatePosition()
	{
		x = x + componentX;

		listX.pop_back();
		listX.push_front(x);


		y = y + componentY;

		listY.pop_back();
		listY.push_front(y);

		if (y < 0)
		{
			for (int count = 0; count < 20; count++)
			{
				listX.pop_back();
				listX.push_front(0);
				listY.pop_back();
				listY.push_front(0);
			}
		}
	}

private:
	Position position = Position();
};
