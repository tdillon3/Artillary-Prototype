//#pragma once
//#include <cassert>
//#include <iostream>
//#include "ground.h"
//#include "position.h"
//#include "bullet.h"
//
///// <summary>
///// Test class to test the updating of the bullet
///// </summary>
//class TestBullet
//{
//public:
//	void run() 
//	{
//		constructor();
//
//		singleUpdate();
//		singleUpdateNegative();
//		largeUpdate();
//
//		fullList();
//		fullListNegative();
//		fullListDecimal();
//
//		overflowList();
//		overflowListNegative();
//
//		cout << "All bullet tests passed!\n";
//	}
//
//private:
//	void constructor()
//	{
//		// Set-up
//		Bullet bullet = Bullet();
//
//		// Verify
//		assert(bullet.listX.front() == 0);
//		assert(bullet.listX.back() == 0);
//		assert(bullet.listY.front() == 0);
//		assert(bullet.listY.back() == 0);
//		assert(bullet.listX.size() == 20);
//		assert(bullet.listY.size() == 20);
//	}
//	void singleUpdate()
//	{
//		// Set-up
//		Bullet bullet = Bullet();
//
//		// Exercise
//		bullet.componentX = 8;
//		bullet.componentY = 7;
//		bullet.updatePosition();
//
//		// Verify
//		assert(bullet.listX.back() == 8);
//		assert(bullet.listX.size() == 20);
//		assert(bullet.listY.back() == 7);
//		assert(bullet.listY.size() == 20);
//	}
//	void singleUpdateNegative()
//	{
//		// Set-up
//		Bullet bullet = Bullet();
//
//		// Exercise
//		bullet.componentX = -18;
//		bullet.componentY = 7;
//		bullet.updatePosition();
//
//		// Verify
//		assert(bullet.listX.back() == -18);
//		assert(bullet.listX.size() == 20);
//		assert(bullet.listY.back() == 7);
//		assert(bullet.listY.size() == 20);
//	}
//	void largeUpdate()
//	{
//		// Set-up
//		Bullet bullet = Bullet();
//
//		// Exercise
//		bullet.componentX = 8;
//		bullet.componentY = 7;
//		bullet.updatePosition();
//
//		bullet.componentX = 600;
//		bullet.componentY = 900;
//		bullet.updatePosition();
//
//		// Verify
//		assert(bullet.listX.back() == 608);
//		assert(bullet.listX.size() == 20);
//		assert(bullet.listY.back() == 907);
//		assert(bullet.listY.size() == 20);
//	}
//
//	void fullList()
//	{
//		// Set-up
//		Bullet bullet = Bullet();
//
//		// Exercise
//		for (int count = 0; count < 20; count++)
//		{
//			bullet.componentX = count;
//			bullet.componentY = count;
//			bullet.updatePosition();
//		}
//
//		// Verify
//		assert(bullet.listX.back() == 190);
//		assert(bullet.listY.back() == 190);
//		assert(bullet.listX.front() == 0);
//		assert(bullet.listY.front() == 0);
//	}
//	void fullListNegative()
//	{
//		// Set-up
//		Bullet bullet = Bullet();
//
//		// Exercise
//		for (int count = 0; count < 20; count++)
//		{
//			bullet.componentX = -1 * count;
//			bullet.componentY = count;
//			bullet.updatePosition();
//		}
//
//		// Verify
//		assert(bullet.listX.back() == -190);
//		assert(bullet.listY.back() == 190);
//		assert(bullet.listX.front() == 0);
//		assert(bullet.listY.front() == 0);
//	}
//	void fullListDecimal()
//	{
//		// Set-up
//		Bullet bullet = Bullet();
//
//		// Exercise
//		for (int count = 0; count < 20; count++)
//		{
//			bullet.componentX = count - 0.5;
//			bullet.componentY = count;
//			bullet.updatePosition();
//		}
//
//		// Verify
//		assert(bullet.listX.back() == 180);
//		assert(bullet.listY.back() == 190);
//		assert(bullet.listX.front() == - 0.5);
//		assert(bullet.listY.front() == 0);
//	}
//	void overflowListNegative()
//	{
//		// Set-up
//		Bullet bullet = Bullet();
//
//		// Exercise
//		for (int count = 0; count < 35; count++)
//		{
//			bullet.componentX = -1 * count;
//			bullet.componentY = count;
//			bullet.updatePosition();
//		}
//
//		// Verify
//		assert(bullet.listX.back() == -595);
//		assert(bullet.listY.back() == 595);
//		assert(bullet.listX.front() == -120);
//		assert(bullet.listY.front() == 120);
//	}
//	void overflowList()
//	{
//		// Set-up
//		Bullet bullet = Bullet();
//
//		// Exercise
//		for (int count = 0; count < 35; count++)
//		{
//			bullet.componentX = count;
//			bullet.componentY = count;
//			bullet.updatePosition();
//		}
//
//		// Verify
//		assert(bullet.listX.back() == 595);
//		assert(bullet.listY.back() == 595);
//		assert(bullet.listX.front() == 120);
//		assert(bullet.listY.front() == 120);
//	}
//};
//
