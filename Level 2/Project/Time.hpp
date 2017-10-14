#ifndef TIME
#define TIME

#include "Functions.hpp"
#include <fstream> // write/read from files


class Time
{
	private:
	int hours;
	int minutes;
	int seconds;
	const std::string TIMEDELIM=":";

	public:
	Time();
	Time(int pHours, int pMinutes, int pSeconds):hours(pHours),minutes(pMinutes),seconds(pSeconds){}
	Time(int getTotalSeconds);
	~Time();
	const int & getHours() const;
	const int & getMinutes() const;
	const int & getSeconds() const;
	const int getTotalSeconds() const;

	const std::string getFormatTime() const;

	void setTime(int tSeconds);
	void setTime(int _hours, int _minutes, int _seconds=0);	
	void setHours(int pHours);
	void setMinutes(int pMinutes);
	void setSeconds(int pSeconds);

	Time operator + (Time time) const;

	const bool operator < (const Time & time) const;
	const bool operator == (const Time & time) const;
	const Time operator = (const Time & time);
};

std::ostream & operator << (std::ostream & os,const Time & time);
std::istream & operator >> (std::istream & is,Time & time);
#endif
