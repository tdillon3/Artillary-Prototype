
// Class for managing the Display
class Display
{
public:
    // Members for displaying various quantities
    double altitude;  // The altitude to display
    double distance;  // The distance to display
    double time;      // The time to display
    double speed;     // The speed to display

    // Set the display parameters
    void setDisplay(double y, double x, double t)
    {
        // Set altitude, ensuring it's non-negative
        altitude = (y < 0) ? 0 : y;

        // Set distance, ensuring it's non-negative
        distance = (x < 0) ? -x : x;

        // Increment time
        time += t;
    }

    // Calculate the overall speed from the changes in x and y
    void calculateOverallSpeed(double dx, double dy)
    {
        // Compute the speed from the differences in x and y
        speed = sqrt(pow(dx, 2) + pow(dy, 2));

        // Round the speed to one decimal place
        speed = round(speed * 10) / 10;
    }
};