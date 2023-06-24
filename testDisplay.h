#pragma once
#include <cassert>
#include "display.h"

/// <summary>
/// Test cases for the display that shows the current altitude, velocity, distance and time.
/// This is a more trivial class, but we have already written most of the physics so I thought
/// it would be more helpful to have tests for code we have not written.
/// </summary>
class TestDisplay
{
public:
	void run()
	{
		altitudeReset();

		distanceReverse1();
		distanceReverse2();

		speedCalculation1();
		speedCalculation2();
		speedCalculation3();
		speedCalculation4();

		cout << "All display tests passed!\n";
	}

private:
	void altitudeReset()
	{
		// Set-up
		Display display = Display();
		
		// Exercise
		display.setDisplay(-10000, 100, 10.1);

		// Verify
		assert(display.altitude == 0);
	}
	void distanceReverse1()
	{
		// Set-up
		Display display = Display();

		// Exercise
		display.setDisplay(100, -100000, 5.4);

		// Verify
		assert(display.distance == 100000);
	}
	void distanceReverse2()
	{
		// Set-up
		Display display = Display();

		// Exercise
		display.setDisplay(100, 0, 5);

		// Verify
		assert(display.distance == 0);
	}
	void speedCalculation1()
	{
		// Set-up
		Display display = Display();
		double dx = 100;
		double dy = 100;

		// Exercise
		display.calculateOverallSpeed(dx, dy);

		// Verify
		assert(display.speed == 141.4);
	}
	void speedCalculation2()
	{
		// Set-up
		Display display = Display();
		double dx = 0;
		double dy = 490;

		// Exercise
		display.calculateOverallSpeed(dx, dy);

		// Verify
		assert(display.speed == 490);
	}
	void speedCalculation3()
	{
		// Set-up
		Display display = Display();
		double dx = 720;
		double dy = 0;

		// Exercise
		display.calculateOverallSpeed(dx, dy);

		// Verify
		assert(display.speed == 720);
	}
	void speedCalculation4()
	{
		// Set-up
		Display display = Display();
		double dx = 0;
		double dy = 0;

		// Exercise
		display.calculateOverallSpeed(dx, dy);

		// Verify
		assert(display.speed == 0);
	}
	void timeNegative()
	{
		// Set-up
		Display display = Display();

		// Exercise
		display.setDisplay(100, 200, -10);

		// Verify
		assert(display.time != -10);
	}
};

