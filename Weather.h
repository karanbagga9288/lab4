// Name: KARAN BAGGA
// Student Number: 200449124
#ifndef WEATHER_H_
#define WEATHER_H_
#define MAX_DATE 7
class Weather
{
	char date[MAX_DATE + 1];
	double high;
	double low;

public:
	void setData(const char*, double, double);
	void display() const;
	const char* getDate() const;
	double getLow() const;
};
#endif


