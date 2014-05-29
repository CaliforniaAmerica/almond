// almond.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "almond.h"
#include "g2log\g2logworker.h"
#include "g2log\g2log.h"

g2LogWorker* pg2log = nullptr;

extern "C" __declspec(dllexport) void initMod(void)
{
	pg2log = new g2LogWorker("almond", "./log");
	g2::initializeLogging(pg2log);
}

extern "C" __declspec(dllexport) void almondLog(int iLevel, const char* pc, ...)
{
	char*   pArg = NULL;
	char   c;

	pArg = (char*)&pc;
	pArg += sizeof(pc);

	string strLog = "";

	do
	{
		c = *pc;
		if (c != '%')
		{
			//putchar(c);   //照原样输出字符 
			strLog += c;
		}
		else
		{
			//按格式字符输出数据 
			switch (*++pc)
			{
			case 'i':
			case   'd':
			{
				//printf("%d", *((int*)pArg));
				int IntDec = *((int*)pArg);
				//strLog += strArg;
				char* cInt = new char[256];
				_itoa_s(IntDec, cInt, 256, 10);
				strLog += cInt;
			}
				break;
			case   'f':
				printf("%f", *((int*)pArg));
				break;
			case   'p':
				printf("%p", *((int*)pArg));
				break;
			case   's':
			{
				printf("%s", *((int*)pArg));
				/*char* newPc = new char[strlen(pArg)];
				strncpy(newPc, pArg, strlen(pArg));
				strLog += newPc;*/
				string strString = (char*)*((int*)pArg);
				strLog += strString;
			}
				break;
			case   'u':
				printf("%u", *((int*)pArg));
				break;
			case   'x':
			{
				//printf("%#x", *((int*)pArg));
				int IntHex = *((int*)pArg);
				char* cInt = new char[256];
				_itoa_s(IntHex, cInt, 256, 16);
				strLog += cInt;
			}
				break;
			default:
				break;
			}
			pArg += sizeof(int);   //等价于原来的va_arg 
		}
		++pc;
	} while (*pc != '\0');
	pArg = NULL;   //等价于va_end 

	switch (iLevel)
	{
	case 0:
		LOG(INFO) << strLog;
		break;
	default:
		break;
	}

	/*LOG(INFO) << "Simple to use with streaming syntax, easy as ABC or " << 123;
	LOGF(WARNING, "Printf-style syntax is also %s", "available");

	LOGF(FATAL, "This %s is FATAL. After log flush -> Abort()", "message");
	// or using the stream API
	LOG(FATAL) << "This message is FATAL. After log flush -> Abort()";*/
}
