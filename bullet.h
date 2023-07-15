#pragma once

#include <cassert>
#include <iostream>
#include <list>
#include "ground.h"
#include "position.h"
#include <deque>
#include "physics.h"

// Class to manage bullet objects
class Bullet
{
public:
    // Store the X and Y components of the bullet's position
    std::deque<double> listX;
    std::deque<double> listY;

    double componentX;  // The x-component of the bullet's movement
    double componentY;  // The y-component of the bullet's movement
    double x = 0.0;     // Current x position
    double y = 0.0;     // Current y position

    // Initialize a new bullet at the howitzer's position
    void newBullet(Position* howitzer)
    {
        // Clear any existing values from the deques
        listX.clear();
        listY.clear();

        // Populate deques with zeroes
        for (int count = 1; count <= 19; count++)
        {
            listX.push_front(0);
            listY.push_front(0);
        }

        // Set the initial position of the bullet to the howitzer's position
        x = howitzer->getMetersX();
        y = howitzer->getMetersY();

        // Store the initial position in the deques
        listX.push_front(x);
        listY.push_front(y);
    }

    // Update the position of the bullet
    void updatePosition()
    {
        // Update the x-coordinate
        x = x + componentX;

        // Update the deque for x
        listX.pop_back();
        listX.push_front(x);

        // Update the y-coordinate
        y = y + componentY;

        // Update the deque for y
        listY.pop_back();
        listY.push_front(y);

        // If the y-coordinate is less than zero
        if (y < 0)
        {
            // Clear the deques and replace with zeroes
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
    // Unused Position object
    Position position = Position();
};