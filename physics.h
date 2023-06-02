

#pragma once
#include <iostream>
#include <cmath>
using namespace std;
#define  M_PI  3.1415926535897932384626433



class Physics
{
private:
    // Convert degrees to radians
    double degreesToRadians(double degrees) {
        return degrees * (M_PI / 180.0);
    }

    // Convert radians to degrees
    double radiansToDegrees(double radians) {
        return radians * (180.0 / M_PI);
    }

    // Calculate the vertical component
    double calculateVerticalComponent(double overallSpeed, double angle) {
        return overallSpeed * cos(angle);
    }

    // Calculate the horizontal component
    double calculateHorizontalComponent(double overallSpeed, double angle) {
        return overallSpeed * sin(angle);
    }

    // Calculate the angle from horizontal and vertical components
    double calculateAngle(double dx, double dy) {
        return atan2(dx, dy);
    }

    // Calculate the overall speed using the Pythagorean theorem
    double calculateOverallSpeed(double dx, double dy) {
        return sqrt(pow(dx, 2) + pow(dy, 2));
    }

    // Perform linear interpolation between two points
    double linearInterpolation(double r0, double d0, double r1, double d1, double r, double d) {
        return ((r1 - r0) * (d - d0) / (d1 - d0)) + r0;
    }

    double calculateDrag(double c, double p, double v, double a)
    {
        return -1 * (c * p * a * (v * v)) / 2;
    }

    double calculateAreaOfCircle(double r)
    {
        return (r * r) * 3.14195;
    }

    double calculateAcceleration(double f, double m)
    {
        return f / m;
    }

    // TODO: create variable gravity based on altitude
    double calculateGravity(double altitute) 
    {
        return -9.8;
    }

    // TODO: create variable coeficient based on altitude.
    // The altitude impacts the speed of sound and the
    // speed of sounds relative to the object's speed 
    // determines the drag coeficient.
    double calculateDragCoefficient(double altitude)
    {
        return 0.3;
    }

    // TODO: create variable density based on altitude
    double calculateAirDensity(double altitude)
    {
        return 0.6;
    }

public:
    void computeDistance(double aDegrees)
    {
        // TODO Most of these can become fields
        double aRadians = degreesToRadians(aDegrees);
        double totalComponent = 827;
        double dx = calculateHorizontalComponent(totalComponent, aRadians);
        double dy = calculateVerticalComponent(totalComponent, aRadians);
        double ddx;
        double ddy;
        double mass = 46.7;
        double distance = 0;
        double altitude = 0;
        double hangTime = 0;
        double t = 0.01;
        double gravity;
        double drag;
        double dragCoefficient;
        double airDensity;
        double dragY;
        double dragX;
        double radius = 0.077445;
        double surfaceArea = calculateAreaOfCircle(radius);
        do 
        {
            totalComponent = calculateOverallSpeed(dx, dy);

            // Calculate the drag at the given altitude
            dragCoefficient = calculateDragCoefficient(altitude);
            airDensity = calculateAirDensity(altitude);
            drag = calculateDrag(dragCoefficient, airDensity, totalComponent, surfaceArea);

            // Convert drag from force to acceleration
            drag = calculateAcceleration(drag, mass);

            // Split the drag into the horizontal and vertical components.
            ddx = calculateHorizontalComponent(drag, aRadians);
            ddy = calculateVerticalComponent(drag, aRadians);


            // Update the altitude
            gravity = calculateGravity(altitude);
            double test = gravity + ddy;
            dy = dy + ((gravity + ddy) * t);
            altitude = altitude + (dy * t);

            // Update the distance
            dx = dx + (ddx * t);
            distance = distance + (dx * t);

            // Find the new angle
            aRadians = calculateAngle(dx, dy);

            hangTime += t;
        } 
        while (altitude > 0);

        cout << "Distance: " << distance << "\n";
        cout << "Altitude: " << altitude << "\n";
        cout << "Hang time: " << hangTime << "\n";
    }
};

//int main()
//{   
//    //double dragCoe = 0.4258;
//    //double density = 0.4135000;
//    //double velocity = 299;
//    //double radius = .077445;
//    //double sArea = (radius * radius) * 4 * 3.14195;
//    //double mass = 46.7;
//    //double acceleration = 29.9;
//
//    //double drag = dragForce(dragCoe, density, velocity, sArea);
//    //double area = circleArea(radius);
//    //double motion = secondNewton(mass, acceleration);
//
//    //cout << drag << endl;
//    //cout << area << endl;
//    //cout << motion << endl;
//    
//
//    return 0;
//}