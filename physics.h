#pragma once
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define  M_PI  3.1415926535897932384626433

class Physics
{
private:
    double dx;
    double dy;
    double ddx;
    double ddy;
    double aRadians;
    double mass = 46.7;
    double distance = 0;
    double lastDistance;
    double altitude = 0;
    double lastAltitude;
    double hangTime = 0;
    double t = 0.5;
    double gravity;
    double drag;
    double dragCoefficient;
    double airDensity;
    double dragY;
    double dragX;
    double radius = 0.077445;
    double totalVelocity;
    double mach;
    double speedRelativeToMach;
    double surfaceArea = calculateAreaOfCircle(radius);
    Ground* ground;
    vector<vector<double>> dragCoefficentList = 
    { 
        {0.3, 0.1629}, {0.5, 0.1659}, {0.7, 0.2031}, {0.89, 0.2597}, {0.92, 0.3010}, {0.96, 0.3287}, {0.980, 0.4002}, {1.0, 0.4258}, 
        {1.02, 0.4335}, {1.06, 0.4483}, {1.24, 0.4064}, {1.53, 0.3663}, {1.99, 0.2897}, {2.87, 0.2297}, {2.89, 0.2306}, {5.0, 0.2656}
    };
    vector<vector<double>> speedOfSoundList = 
    { 
        {0, 340}, {1000, 336}, {2000, 332}, {3000, 328}, {4000, 324}, {5000, 320}, {6000, 316}, {7000, 312}, {8000, 308}, 
        {9000, 303}, {10000, 299}, {15000, 295}, {20000, 295}, {25000, 295}, {30000, 305}, { 40000, 324}
    };
    vector<vector<double>> airDensityList = 
    {
        {0, 1.225}, {1000, 1.112}, {2000, 1.007}, {3000, 0.9093}, {4000, 0.8194}, {5000, 0.7364}, {6000, 0.6601}, {7000, 0.59}, {8000, 0.5258},
        {9000, 0.4671}, {10000, 0.4135}, {15000, 0.1948}, {20000, 0.08891}, {25000, 0.04008}, {30000, 0.01841}, {40000, 0.003996}, {50000, 0.001027},
        {60000, 0.0003097}, {70000, 0.0000828}, {80000, 0.0000185}
    };
    vector<vector<double>> gravityList = 
    {
        {0, 9.807}, {1000, 9.804}, {2000, 9.801}, {3000, 9.797}, {4000, 9.794}, {5000, 9.791}, {6000, 9.788}, 
        {7000, 9.8785}, {8000, 9.782}, {9000, 9.779}, {10000, 9.776}, {15000, 9.761}, {20000, 9.745}, {25000, 9.73} 
    };

    // Convert degrees to radians
    double degreesToRadians(double degrees) 
    {
        return degrees * (M_PI / 180.0);
    }

    // Convert radians to degrees
    double radiansToDegrees(double radians) 
    {
        return radians * (180.0 / M_PI);
    }

    // Calculate the vertical component
    double calculateVerticalComponent(double overallSpeed, double angle) 
    {
        return overallSpeed * cos(angle);
    }

    // Calculate the horizontal component
    double calculateHorizontalComponent(double overallSpeed, double angle) 
    {
        return overallSpeed * sin(angle);
    }

    // Calculate the angle from horizontal and vertical components
    double calculateAngle(double dx, double dy) 
    {
        return atan2(dx, dy);
    }

    // Calculate the overall speed using the Pythagorean theorem
    double calculateOverallSpeed(double dx, double dy) 
    {
        return sqrt(pow(dx, 2) + pow(dy, 2));
    }

    // Perform linear interpolation between two points
    double linearInterpolation(double d0, double r0, double d1, double r1, double d) 
    {
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
        for (int index = 0; index < gravityList.size(); index++)
        {
            if (altitude == gravityList[index][0])
            {
                return gravityList[index][1];
            }
            else if (altitude < gravityList[index][0])
            {
                return linearInterpolation(gravityList[index - 1][0], gravityList[index - 1][1], gravityList[index][0], gravityList[index][1], altitude);
            }
        }
        return gravityList[gravityList.size() - 1][1];
    }

    double calculateMach(double altitude, double velocity)
    {
        for (int index = 0; index < speedOfSoundList.size(); index++)
        {
            if (altitude == speedOfSoundList[index][0])
            {
                mach = speedOfSoundList[index][1];
                return velocity / mach;
            }
            else if (altitude < speedOfSoundList[index][0])
            {
                mach = linearInterpolation(speedOfSoundList[index - 1][0], speedOfSoundList[index - 1][1], speedOfSoundList[index][0], speedOfSoundList[index][1], altitude);
                return velocity / mach;
            }
        }
        mach = speedOfSoundList[speedOfSoundList.size() - 1][1];
        return velocity / mach;
    }

    double calculateDragCoefficient(double speedRelativeToMach)
    {
        for (int index = 0; index < dragCoefficentList.size(); index++)
        {
            if (speedRelativeToMach == dragCoefficentList[index][0])
            {
                return dragCoefficentList[index][1];
            }
            else if (speedRelativeToMach < dragCoefficentList[index][0])
            {
                if (index == 0)
                {
                    return dragCoefficentList[0][1];
                }
                double dragCoeff = linearInterpolation(dragCoefficentList[index - 1][0], dragCoefficentList[index - 1][1], dragCoefficentList[index][0], dragCoefficentList[index][1], speedRelativeToMach);
                return dragCoeff;
            }
        }
        return dragCoefficentList[dragCoefficentList.size() - 1][1];
    }

    // TODO: create variable density based on altitude
    double calculateAirDensity(double altitude)
    {
        for (int index = 0; index < airDensityList.size(); index++)
        {
            if (altitude == airDensityList[index][0])
            {
                return airDensityList[index][1];
            }
            else if (altitude < airDensityList[index][0])
            {
                return linearInterpolation(airDensityList[index - 1][0], airDensityList[index - 1][1], airDensityList[index][0], airDensityList[index][1], altitude);
            }
        }
        return airDensityList[airDensityList.size()-1][1];
    }

public:
    Physics() {}
    Physics(Ground* groundCopy) {
        ground = groundCopy;
    }
    bool computeDistance()
    {             
        dx = calculateHorizontalComponent(totalVelocity, aRadians);
        dy = calculateVerticalComponent(totalVelocity, aRadians);

        // Calculate the drag at the given altitude
        speedRelativeToMach = calculateMach(altitude, totalVelocity);
        dragCoefficient = calculateDragCoefficient(speedRelativeToMach);
        airDensity = calculateAirDensity(altitude);
        drag = calculateDrag(dragCoefficient, airDensity, totalVelocity, surfaceArea);

        // Convert drag from force to acceleration
        drag = calculateAcceleration(drag, mass);

        // Split the drag into the horizontal and vertical components.
        ddx = calculateHorizontalComponent(drag, aRadians);
        ddy = calculateVerticalComponent(drag, aRadians);

        // Update the altitude
        gravity = calculateGravity(altitude);
        ddy -= gravity;        
        dy = dy + (ddy * t);
        altitude = altitude + (dy * t);

        // Update the distance
        dx = dx + (ddx * t);
        distance = distance + (dx * t);

        // Find the new angle
        aRadians = calculateAngle(dx, dy);
        totalVelocity = calculateOverallSpeed(dx, dy);

        hangTime += t;

        double groundElevation = ground->getElevationMeters(Position(distance, altitude));
        if (altitude - groundElevation < 0) {

            distance = linearInterpolation(lastAltitude, lastDistance, altitude, distance, 0);
            return false;
        }
        return true;
    }
    double GetHorizontalComponent() {
        return dx;
    }
    double GetVerticalComponent() {
        return dy;
    }
    void beginLaunch(double degrees)
    {
        aRadians = degrees;
        totalVelocity = 827;
    }
    void setAltitude(double howitzerHeight) {
        altitude = howitzerHeight;
    }
    void setDistance(double howitzerDistance) {
        distance = howitzerDistance;
    }
    double getAltitude() {
        if (altitude < 0)
            return 0;
        return altitude;
    }
    double getSpeed() {
        return totalVelocity;
    }
    double getDistance() {
        if (distance < 0)
            return distance * -1;
        return distance;
    }
};