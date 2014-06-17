// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

#include <locale.h>
#include <stdio.h>

void ShowDebug(void);

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
#ifdef _DEBUG
		ShowDebug();
#endif
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

BOOL WINAPI HandlerRoutine(DWORD dwCtrlType)//  control signal type
{
	if (dwCtrlType == CTRL_CLOSE_EVENT)
	{
		//::SendMessage(NULL, 
	}

	return TRUE;
}

// 
void ShowDebug(void)
{
	AllocConsole();
	SetConsoleTitle(_T("Debug Output"));
	//_tfreopen(_T("CON"), _T("w"), stdout);
	//freopen("CON", "wt", stdout);
	FILE* pf;
	freopen_s(&pf, "CON", "wt", stdout);
	setlocale(LC_ALL, NULL);
	SetConsoleCtrlHandler(HandlerRoutine, TRUE);
}