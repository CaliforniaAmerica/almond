
// ChewALMOND.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CChewALMONDApp: 
// �йش����ʵ�֣������ ChewALMOND.cpp
//

class CChewALMONDApp : public CWinApp
{
public:
	CChewALMONDApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CChewALMONDApp theApp;