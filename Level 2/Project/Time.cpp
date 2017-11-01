#include "Time.hpp"
#include <sstream>

//------------------------------------------------------------------------------
// default time constructor.
//------------------------------------------------------------------------------

Time::Time()
{
	hours=0;
	minutes=0;
	seconds=0;
}

//------------------------------------------------------------------------------
// implicit constructor takes totalSeconds
//------------------------------------------------------------------------------

Time::Time(int totalSeconds)
{
	setTime(totalSeconds);
}

//------------------------------------------------------------------------------
// implicit constructor takes string in format "hh:mm"
//------------------------------------------------------------------------------

Time::Time(std::string time)
{
	std::istringstream stream(time);
	stream >> *this;
} 

Time::~Time()
{
	//Just good form to include.
}

//------------------------------------------------------------------------------
// Apropriate get-functions
//------------------------------------------------------------------------------

const int & Time::getHours() const
{
	return hours;
}

const int & Time::getMinutes() const
{
	return minutes;
}

const int & Time::getSeconds() const
{
	return seconds;
}


//------------------------------------------------------------------------------
// returns the total time in seconds. used for non-member/friend functions.
//------------------------------------------------------------------------------

const int Time::getTotalSeconds() const
{
	return 	(hours*60+minutes)*60+seconds;
}

//------------------------------------------------------------------------------
// gives a string with the time formatted as requested.
//------------------------------------------------------------------------------

const std::string Time::getFormatTime() const
{
	if (hours==0 && minutes == 0 && seconds == 0)
		return "[hh:mm:ss]";
	std::string time="";
	if (hours!=0)
	{
		time+=std::to_string(hours);
		time+=TIMEDELIM;
		if (minutes<10)
			time+="0";
	}
	if (minutes!=0)
	{
		time+=std::to_string(minutes);
		time+=TIMEDELIM;
		if (seconds<10)
				time+="0";
	}
	time+=std::to_string(seconds);
	return time;
}

//------------------------------------------------------------------------------
// Apropriate set functions
//------------------------------------------------------------------------------

void Time::setHours(int pHours)
{
	hours=pHours;
}

void Time::setMinutes(int pMinutes)
{
	minutes=pMinutes;
}

void Time::setSeconds(int pSeconds)
{
	seconds=pSeconds;
}

//------------------------------------------------------------------------------
// Set time using total seconds, minutes, hours
//------------------------------------------------------------------------------

void Time::setTime(int _hours, int _minutes, int _seconds) 
{
	hours=_hours;
	minutes=_minutes;
	seconds=_seconds;
}

//------------------------------------------------------------------------------
// Set time using total seconds
//------------------------------------------------------------------------------

void Time::setTime(int _seconds)
{
		hours=_seconds/(60*60);
		minutes=(_seconds-hours*(60*60))/60;
		seconds=_seconds-minutes*60-hours*60*60;
}


//------------------------------------------------------------------------------
// operator overloadings
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// overloading addition of two time object
//------------------------------------------------------------------------------

Time Time::operator + (const Time & time) const
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
	if (newHours>23)
	{
		newHours-=24;
	}
	return Time(newHours,newMinutes,newSeconds);
}

void Time::operator += (const Time & time)
{
	*this = *this+time;
}

//------------------------------------------------------------------------------
// overloading subtraction of two time object
//------------------------------------------------------------------------------

Time Time::operator - (const Time & time) const
{
	int newHours = hours-time.hours;
	int newMinutes = minutes-time.minutes;
	int newSeconds = seconds-time.seconds; 

	if (newSeconds<0)
	{
		--newMinutes;
		newSeconds+=60;
	}
	if (newMinutes<0)
	{
		--newHours;
		newMinutes+=60;
	}
	if (newHours<0)
	{
		newHours+=24;
	}
	return Time(newHours,newMinutes,newSeconds);
}


//------------------------------------------------------------------------------
// overloading of equality operator between two time objects
//------------------------------------------------------------------------------

const bool Time::operator == (const Time & time) const
{
	if	(hours==time.hours)
		if (minutes==time.minutes)
			if (seconds==time.seconds)
				return true;
	return false;
}

const bool Time::operator != (const Time & time) const
{
	return !(*this==time);
}

//------------------------------------------------------------------------------
// overloading less than ("<") compare operator between two time objects
//------------------------------------------------------------------------------

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

const bool Time::operator <= (const Time & time) const
{
	return *this<time || *this == time;
}

const bool Time::operator > (const Time & time) const
{
	return !(*this<time) && *this!=time;
}

const bool Time::operator >= (const Time & time) const
{
	return *this > time || *this == time; 
}


//------------------------------------------------------------------------------
// overloading assignment operator to assign a time object from another one
//------------------------------------------------------------------------------

const Time Time::operator = (const Time & time )
{
	hours=time.getHours();
	minutes=time.getMinutes();
	seconds=time.getSeconds();
	return *this;
}

//------------------------------------------------------------------------------
// Non memberfunction overloadings:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Ostream overloading for Time object.
//------------------------------------------------------------------------------

std::ostream & operator << (std::ostream & os,const Time & time)
{
	os << time.getHours() << ':' << time.getMinutes();
	return os;
}

//------------------------------------------------------------------------------
// istream overloading for Time object.
//------------------------------------------------------------------------------

std::istream & operator >> (std::istream & is,Time & time)
{
	
	std::string hours;
	std::getline(is,hours,':');
	unsigned int minutes;
	is >> minutes;
	time.setTime(std::stoi(hours),minutes);
	return is;
}
