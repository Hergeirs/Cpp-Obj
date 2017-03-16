#ifndef TIME
#define TIME

#include "Functions.hpp"

class Time
{
	private:
	int hours;
	int minutes;
	int seconds;
	const string TIMEDELIM=":";

	public:
	Time();
	Time(int pHours, int pMinutes, int pSeconds):hours(pHours),minutes(pMinutes),seconds(pSeconds){}
	Time(int getTotalSeconds);
	~Time();
	const int & getHours() const;
	const int & getMinutes() const;
	const int & getSeconds() const;
	const int getTotalSeconds() const;

	const string getFormatTime() const;

	void setTime(int tSeconds);
	void setHours(int pHours);
	void setMinutes(int pMinutes);
	void setSeconds(int pSeconds);

	Time operator + (Time time) const;

	const bool operator < (const Time & time) const;
	const bool operator == (const Time & time) const;
	const Time operator = (const Time & time);
};

const ostream & operator << (ostream & os,const Time & time);
const istream & operator >> (istream & is,Time & time);
#endif
