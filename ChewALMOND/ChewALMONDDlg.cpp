
// ChewALMONDDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ChewALMOND.h"
#include "ChewALMONDDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChewALMONDDlg �Ի���
#include "..\almond\almond.h"


CChewALMONDDlg::CChewALMONDDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChewALMONDDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChewALMONDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CChewALMONDDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CChewALMONDDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CChewALMONDDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CChewALMONDDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CChewALMONDDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CChewALMONDDlg ��Ϣ�������

BOOL CChewALMONDDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CChewALMONDDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CChewALMONDDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChewALMONDDlg::OnBnClickedButton1()
{
	initMod();
}


void CChewALMONDDlg::OnBnClickedButton2()
{
	almondLog(1, "char*: %s", "apple");
}


void CChewALMONDDlg::OnBnClickedButton3()
{
	almondLog(2, "int: %d", 42);
}


void CChewALMONDDlg::OnBnClickedButton4()
{
	almondLog(3, "16: %x", 42);
}
