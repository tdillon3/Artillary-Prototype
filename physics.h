

#pragma once
#include <iostream>
#include <cmath>
using namespace std;
#define  M_PI  3.1415926535897932384626433

// Convert degrees to radians
double degreesToRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}

// Convert radians to degrees
double radiansToDegrees(double radians) {
    return radians * (180.0 / M_PI);
}

// Calculate the vertical component of speed
double calculateVerticalSpeed(double overallSpeed, double angle) {
    return overallSpeed * cos(angle);
}

// Calculate the horizontal component of speed
double calculateHorizontalSpeed(double overallSpeed, double angle) {
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
    return ((r1 - r0)*(d - d0) / (d1 - d0)) + r0;
}   

// Calculate the drag force 
double dragForce(double c, double p, double v, double a)
{
    double d = (c * p * a * (v * v)) / 2;
    return d;
}

// Calculate the area of the circle
double circleArea(double r)
{
    double a = (r * r) * 3.14195;
    return a;
}

// Caculate Newton's Second Law of motion
double secondNewton(double m, double a)
{
    double f = m * a;
    return f;
}

int main()
{   
    double dragCoe = 0.4258;
    double density = 0.4135000;
    double velocity = 299;
    double radius = .077445;
    double sArea = (radius * radius) * 4 * 3.14195;
    double mass = 46.7;
    double acceleration = 29.9;

    double drag = dragForce(dragCoe, density, velocity, sArea);
    double area = circleArea(radius);
    double motion = secondNewton(mass, acceleration);

    cout << drag << endl;
    cout << area << endl;
    cout << motion << endl;
}