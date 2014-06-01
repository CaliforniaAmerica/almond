// almond.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "almond.h"
#include "g2log\g2logworker.h"
#include "g2log\g2log.h"

g2LogWorker* pg2log = nullptr;
const int ERRORCODEMAXLENGTH = 256;

extern "C" __declspec(dllexport) void initMod(void)
{
	pg2log = new g2LogWorker("almond", "./log");
	g2::initializeLogging(pg2log);
}

extern "C" __declspec(dllexport) void almondLog(int iLevel, const char* pcFormat, ...)
{
	char*   pArg = NULL;
	char   c;

	pArg = (char*)&pcFormat;
	pArg += sizeof(pcFormat);

	string strLog = "";

	do{
		c = *pcFormat;
		if (c != '%')
		{
			//putchar(c);   //
			strLog += c;
		}
		else
		{
			//
			switch (*++pcFormat)
			{
			case	'n':
			case	'i':
			case	'd':
			{
				//printf("%d", *((int*)pArg));
				int   intDec = *((int*)pArg);
				char* cInt   = new char[ERRORCODEMAXLENGTH];
				memset(cInt, 0, ERRORCODEMAXLENGTH);
				int iRet = _itoa_s(intDec, cInt, ERRORCODEMAXLENGTH, 10);
				LOG_IF(WARNING, (iRet != 0), "last _itoa_s radix %d, return: %d", 10, iRet);
				strLog += cInt;
				delete cInt;
			}
				break;

			case	'f':
			{
				printf("%f\n", *((double*)pArg));
				double dFloat = *((double*)pArg);
				char* cFloat = new char[ERRORCODEMAXLENGTH];
				memset(cFloat, 0, ERRORCODEMAXLENGTH);
				int iRet = _gcvt_s(cFloat, ERRORCODEMAXLENGTH, dFloat, 10);
				LOG_IF(WARNING, (iRet != 0), "last _gcvt_s radix %d, return: %d", 10, iRet);
				strLog += cFloat;
				delete cFloat;
			}
				break;

			case	'p':
			{
				//printf("%p", *((int*)pArg));
				void * pPoint = pArg;
			}
				break;

			case	's':
			{
				//printf("%s", *((int*)pArg));
				/*char* newPc = new char[strlen(pArg)];
				strncpy(newPc, pArg, strlen(pArg));
				strLog += newPc;*/
				string strString = (char*)*((int*)pArg);
				strLog += strString;
			}
				break;

			case	'u':
				//printf("%u", *((int*)pArg));
			{
				unsigned int uiDec = *((unsigned int*)pArg);
				char* cInt = new char[ERRORCODEMAXLENGTH];
				memset(cInt, 0, ERRORCODEMAXLENGTH);
				int iRet = _itoa_s(uiDec, cInt, ERRORCODEMAXLENGTH, 10);
				LOG_IF(WARNING, (iRet != 0), "last _itoa_s radix %d, return: %d", 10, iRet);
				strLog += cInt;
				delete cInt;
			}
				break;

			case	'x':
			case	'X':
			{
				//printf("%#x", *((int*)pArg));
				int IntHex = *((int*)pArg);
				char* cInt = new char[ERRORCODEMAXLENGTH];
				memset(cInt, 0, ERRORCODEMAXLENGTH);
				int iRet = _itoa_s(IntHex, cInt, ERRORCODEMAXLENGTH, 16);
				LOG_IF(WARNING, (iRet != 0), "last _itoa_s radix %d, return: %d", 16, iRet);
				strLog += "0x";
				strLog += cInt;
				delete cInt;
			}
				break;
			default:
				break;
			}
			pArg += sizeof(int);   //等价于原来的va_arg 
		}
		++pcFormat;
	} while (*pcFormat != '\0');
	pArg = NULL;   //等价于va_end 

	switch (iLevel)
	{
	case 3:
		LOG(FATAL) << strLog;
		break;
	case 2:
		LOG(WARNING) << strLog;
		break;
	case 1:
		LOG(INFO) << strLog;
		break;
	case 0:		
	default:
		LOG(DEBUG) << strLog;
		break;
	}

	/*LOG(INFO) << "Simple to use with streaming syntax, easy as ABC or " << 123;
	LOGF(WARNING, "Printf-style syntax is also %s", "available");

	LOGF(FATAL, "This %s is FATAL. After log flush -> Abort()", "message");
	// or using the stream API
	LOG(FATAL) << "This message is FATAL. After log flush -> Abort()";*/
}
