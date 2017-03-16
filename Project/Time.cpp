#include "Time.hpp"

Time::Time(){hours=0;minutes=0;seconds=0;}

Time::Time(int totalSeconds)
{
	setTime(totalSeconds);
}

Time::~Time()
{
	//
}

const int & Time::getHours() const{return hours;}

const int & Time::getMinutes() const{return minutes;}

const int & Time::getSeconds() const{return seconds;}

const std::string Time::getFormatTime() const
{
	if (hours==0 && minutes == 0 && seconds == 0)
		return "[hh:mm:ss]";
	string time="";
	if (hours!=0)
	{
		time+=toString(hours);
		time+=TIMEDELIM;
		if (minutes<10)
			time+="0";
	}
	if (minutes!=0)
	{
		time+=toString(minutes);
		time+=TIMEDELIM;
		if (seconds<10)
				time+="0";
	}
	time+=toString(seconds);
	return time;
}

void Time::setTime(int tSeconds)
{
	hours=tSeconds/(60*60);
	minutes=(tSeconds-hours*(60*60))/60;
	seconds=tSeconds-minutes*60-hours*60*60;
}

void Time::setHours(int pHours){hours=pHours;}

void Time::setMinutes(int pMinutes){minutes=pMinutes;}

void Time::setSeconds(int pSeconds){seconds=pSeconds;}

Time Time::operator + (Time time) const
{
	int newHours = hours+time.hours;
	int newMinutes = minutes+time.minutes;
	int newSeconds = seconds+time.seconds;

	if (newSeconds>60)
	{
		++newMinutes;
		newSeconds-=60;
	}
	if (newMinutes>60)
	{
		++newHours;
		newMinutes-=60;
	}
	Time result(newHours,newMinutes,newSeconds);
	return result;
}

const bool Time::operator == (const Time & time) const
{
	if	(hours==time.hours)
		if (minutes==time.minutes)
			if (seconds==time.seconds)
				return true;
	return false;
}

const bool Time::operator < (const Time & time) const
{
	if (hours < time.hours)
		return true;
	if (hours == time.hours)
	{
		if (minutes<time.minutes)
			return true;
		if (minutes==time.minutes)
		{
			if (seconds<time.seconds)
				return true;
			if (seconds == time.seconds)
				return false;
		}
	}
	return false;
}

const Time Time::operator = (const Time & time )
{
	hours=time.getHours();
	minutes=time.getMinutes();
	seconds=time.getSeconds();
	return *this;
}

const int Time::getTotalSeconds() const
{
	return 	(hours*60+minutes)*60+seconds;
}

const ostream & operator << (ostream & os,const Time & time)
{
	os << time.getTotalSeconds();
	return os;
}

const istream & operator >> (istream & is,Time & time)
{
	string minutes;
	getline(is,minutes);
	int totalMinutes=toInt(minutes);
	time.setTime(totalMinutes);
	return is;
}
