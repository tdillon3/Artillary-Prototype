#pragma once
#include <cassert>
#include <iostream>
#include "ground.h"
#include "position.h"

class testBullet
{
public:
	void run() 
	{

	}

private:
	void constructor() 
	{

	}

	void singleUpdate()
	{
		// Set-up
		Bullet bullet = Bullet();

		// Exercise
		bullet.componentX = 8;
		bullet.componentY = 7;
		bullet.updatePosition();

		// Verify
		assert(bullet.listx[0] == 8);
		assert(bullet.listx.size() == 20);
		assert(bullet.listy[0] == 7);
		assert(bullet.listy.size() == 20);
	}

	void largeUpdate()
	{
		Bullet bullet = Bullet();

		bullet.componentX = 8;
		bullet.componentY = 7;
		bullet.Position();

		bullet.componentX = 600;
		bullet.componentY = 900;
		bullet.Position();

		// Verify
		assert(bullet.listx[0] == 608);
		assert(bullet.listx[1] == 8);
		assert(bullet.listx.size() == 20);
		assert(bullet.listy[0] == 907);
		assert(bullet.listy[1] == 7);
		assert(bullet.listy.size() == 20);
	}

	void hitGround()
	{
		Bullet bullet = Bullet();
		Ground ground = ground();

		Position targetPosition = ground.getTarget();
		
		bullet.componentX = 8;
		bullet.componentY = 7;
		bullet.updatePosition();

		bullet.componentX = 600;
		bullet.componentY = 900;
		bullet.updatePosition();

		bullet.componentX = targetPosition.getPixelsX() - bullet.x;
		bullet.componentY = targetPosition.getPixelsY() - bullet.y;
		bullet.updatePosition();

		for (int count = 0; count < 20; count++)
		{
			assert(bullet.listx[count] == 0);
			assert(bullet.listy[count] == 0);
		}
	}

};

