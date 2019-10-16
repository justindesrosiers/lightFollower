#include "lightFollower.h"

typedef struct SensorReading
{
	int topLeft;
	int topRight;
	int bottomLeft;
	int bottomRight;
};

typedef struct EdgeValues
{
	int top;
	int bottom;
};

static int threshold = 50;
class LightFollower
{	
	private:
		int _angle;
		int _dif;
	public:
		void Follow(SensorReading sensors)
		{
			EdgeValues values = averageReadings(sensors);
			this._dif = abs(values.top - values.bottom);
			
		}
}

static EdgeValues averageReadings(SensorReading reading)
{
	EdgeValues temp;
	temp.top = (reading.topLeft + reading.topRight) / 2;
	temp.bottom = (reading.bottomLeft + reading.bottomRight) / 2;
	return temp;
}