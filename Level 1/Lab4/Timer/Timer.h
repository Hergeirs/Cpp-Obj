//######################################################################################################################################
// @author		Mikael Nilsson
//            Per Ekeroot (tillägg rad 21 & 70)
// @version 		0.6
// @date		2012-02-07
// @description		Timer class wrapper for the posix timer functions clock_gettime / gettimeofday and windows QueryPerformance timer. 
//######################################################################################################################################

#ifndef TIMER_H
#define TIMER_H

/*
Windows users just compile!
Linux / Unix users if _POSIX_TIMERS > 0 librt timers (nanoseconds resolution) is used and it requires the librt library, compile using the -lrt option. 
example: g++ main.cpp -lrt
If librt timers is not present in the current system, a timer with microsecond resolution is used insted (does not require any library linking).
If you do not want to use librt timers (and they are present) comment the line below (#define USE_MICRO_TIMER).
*/

//---< Include >------------------------------------------------------------------------------------------------------------------------
# if defined __WIN32__ || defined _WIN32 // __WIN32__  Tillagd av Per Ekeroot
	#include <windows.h>
#else
	#include <unistd.h>
	#include <sys/time.h>
	#include <time.h>
	#if _POSIX_TIMERS > 0	
		#define USE_NANO_TIMER // comment not to use librt timer (nanosecond resolution timer) 
	#endif

#endif

//......................................................................................................................................
#include <cstdlib>
//......................................................................................................................................

//===< Class >==========================================================================================================================
// @description	Timer class wrapper for the posix timer functions clock_gettime / gettimeofday and windows QueryPerformance timer.  	
//--------------------------------------------------------------------------------------------------------------------------------------
class Timer {
public:
	inline void start() {
		#ifdef WIN32
			QueryPerformanceFrequency(&freq);
			QueryPerformanceCounter(&start_time);
		#else
			#ifdef USE_NANO_TIMER
				clock_gettime(CLOCK_REALTIME, &start_time);			
			#else
				gettimeofday(&start_time, NULL);
			#endif
		#endif
	}
	// Returns the number of microseconds that has past since start was called.
	inline double stop() { 
		#ifdef WIN32
				QueryPerformanceCounter(&end_time);
				return double(end_time.QuadPart - start_time.QuadPart)/double(freq.QuadPart)*1000000.0;
		#else
			#ifdef USE_NANO_TIMER
				clock_gettime(CLOCK_REALTIME, &end_time);
				return (1000000.0*(end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec)/1000.0);
			#else
				gettimeofday(&end_time, NULL);
				return (1000000.0*(end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec));
			#endif
		#endif
	}
private:
	# if defined __WIN32__ || defined WIN32 // __WIN32__  Tillagd av Per Ekeroot
		LARGE_INTEGER start_time, end_time, freq;
	#else
		#ifdef USE_NANO_TIMER
			struct timespec start_time, end_time;
		#else		
			struct timeval start_time, end_time;
		#endif
	#endif
};
//______________________________________________________________________________________________________________________________________

#endif 
