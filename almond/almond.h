/*
 * Filename:almond.h	Asynchronous Logging Mod, O N D
 * Created : 2014 by lost.Fox L
 */

#ifndef ALMOND
#define ALMOND

#include <iostream>
using namespace std;

/*
Initialization
*/
extern "C" __declspec(dllexport) void initMod(void);

extern "C" __declspec(dllexport) void almondLog(int iLevel, const char* pc, ...);

#endif