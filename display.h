
class Display
{
public:
	double altitude;
	double distance;
	double time;
	double speed;

	void setDisplay(double y, double x, double t)
	{
		altitude = y;
		if (altitude < 0)
			altitude = 0;
		distance = x;
		if (distance < 0)
			distance = distance * -1;
		time += t;
	}

	void calculateOverallSpeed(double dx, double dy)
	{
		speed = sqrt(pow(dx, 2) + pow(dy, 2));
		speed = round(speed * 10) / 10;
	}
};