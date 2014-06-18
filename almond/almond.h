/*
 * Filename:almond.h	AMLOND is an Asynchronous Logging Mod of NT Dll, base on [g2log]
 * Created : 2014 by lost.Fox L
 */

#ifndef ALMOND
#define ALMOND

#include <iostream>
using namespace std;

/*!
	Initialization
*/
extern "C" __declspec(dllexport) void initMod(void);

/*!
	@brief a light printf like log, use g2log
	@see http://www.codeproject.com/Articles/288827/g-log-An-efficient-asynchronous-logger-using-Cplus

	@param iLevel == 3	FATAL
	@param iLevel == 2	WARNING
	@param iLevel == 1	INFO
	@param iLevel == 0	DEBUG

	@param pcFormat	Format control, 
		support numbers: %d, %x, %f %u; strings: %s; points: %p
	
	@argument Optional arguments. 

	@UNDONE log point

 */
extern "C" __declspec(dllexport) void almondLog(int iLevel, const char* pcFormat, ...);

///test4more format
extern "C" __declspec(dllexport) void alogf(int iLevel, const char* pcFormat, ...);

//TODO log stream

#endif