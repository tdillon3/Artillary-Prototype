#pragma once
#include <cassert>
#include <iostream>
#include "ground.h"
#include "position.h"

/// <summary>
/// Test class to test the updating of the bullet
/// </summary>
class TestBullet
{
public:
	void run() 
	{
		constructor();

		singleUpdate();
		singleUpdateNegative();

		largeUpdate();
		hitGround();

		fullList();
		fullListNegative();
		fullListDecimal();

		overflowList();

		updateVelocity30Once();
		updateVelocity30Thrice();
		updateVelocity60Once();
		updateVelocity60Twice();
	}

private:
	void constructor()
	{
		// Set-up
		Bullet bullet = Bullet();

		// Verify
		for (int count = 0; count < 20; count++)
		{
			assert(bullet.listx[count] == 0);
			assert(bullet.listy[count] == 0);
		}
		assert(bullet.listX.size() == 20);
		assert(bullet.listY.size() == 20);
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
	void singleUpdateNegative()
	{
		// Set-up
		Bullet bullet = Bullet();

		// Exercise
		bullet.componentX = -18;
		bullet.componentY = 7;
		bullet.updatePosition();

		// Verify
		assert(bullet.listx[0] == -18);
		assert(bullet.listx.size() == 20);
		assert(bullet.listy[0] == 7);
		assert(bullet.listy.size() == 20);
	}
	void largeUpdate()
	{
		// Set-up
		Bullet bullet = Bullet();

		// Exercise
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

	// Zero out the position history when bullet hits ground
	void hitGround()
	{
		// Set-up
		Bullet bullet = Bullet();
		Ground ground = ground();

		// Exercise
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

		// Verify
		for (int count = 0; count < 20; count++)
		{
			assert(bullet.listx[count] == 0);
			assert(bullet.listy[count] == 0);
		}
	}
	void fullList()
	{
		// Set-up
		Bullet bullet = Bullet();

		// Exercise
		for (int count = 0; count < 20; count++)
		{
			bullet.componentX = count;
			bullet.componentY = count;
			bullet.updatePosition();
		}

		// Verify
		assert(bullet.listX[0] == 190);
		assert(bullet.listY[0] == 190);
		assert(bullet.listX[19] == 0);
		assert(bullet.listY[19] == 0);
	}
	void fullListNegative()
	{
		// Set-up
		Bullet bullet = Bullet();

		// Exercise
		for (int count = 0; count < 20; count++)
		{
			bullet.componentX = -1 * count;
			bullet.componentY = count;
			bullet.updatePosition();
		}

		// Verify
		assert(bullet.listX[0] == -190);
		assert(bullet.listY[0] == 190);
		assert(bullet.listX[19] == 0);
		assert(bullet.listY[19] == 0);
	}
	void fullListDecimal()
	{
		// Set-up
		Bullet bullet = Bullet();

		// Exercise
		for (int count = 0; count < 20; count++)
		{
			bullet.componentX = count - 0.5;
			bullet.componentY = count;
			bullet.updatePosition();
		}

		// Verify
		assert(bullet.listX[0] == 180);
		assert(bullet.listY[0] == 190);
		assert(bullet.listX[19] == -0.5);
		assert(bullet.listY[19] == 0);
	}
	void overflowList()
	{
		// Set-up
		Bullet bullet = Bullet();

		// Exercise
		for (int count = 0; count < 35; count++)
		{
			bullet.componentX = -1 * count;
			bullet.componentY = count;
			bullet.updatePosition();
		}

		// Verify
		assert(bullet.listX[0] == 595);
		assert(bullet.listY[0] == 34);
		assert(bullet.listX[19] == 15);
		assert(bullet.listY[19] == 15);
	}
	void updateVelocity30Once()
	{
		// Set-up
		Bullet bullet = Bullet();

		// Exercise
		bullet.angle.setAngle(30);
		bullet.updateVelocity();

		// Assert
		assert(bullet.dx == 391.6);
		assert(bullet.dy == 688.4);
	}
	void updateVelocity30Thrice()
	{
		// Set-up
		Bullet bullet = Bullet();

		// Exercise
		bullet.angle.setAngle(30);
		bullet.updateVelocity();
		bullet.updateVelocity();
		bullet.updateVelocity();

		// Assert
		assert(bullet.dx == 356.5);
		assert(bullet.dy == 589.4);
	}
	void updateVelocity60Once()
	{
		// Set-up
		Bullet bullet = Bullet();

		// Exercise
		bullet.angle.setAngle(60);
		bullet.updateVelocity();
		bullet.updateVelocity();
		bullet.updateVelocity();

		// Assert
		assert(bullet.dx == 678.2);
		assert(bullet.dy == 381.8);
	}
	void updateVelocity60Twice()
	{
		// Set-up
		Bullet bullet = Bullet();

		// Exercise
		bullet.angle.setAngle(60);
		bullet.updateVelocity();
		bullet.updateVelocity();

		// Assert
		assert(bullet.dx == 644.5);
		assert(bullet.dy == 353);
	}
};

