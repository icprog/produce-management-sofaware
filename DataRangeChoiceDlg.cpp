// DataRangeChoiceDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DataRangeChoiceDlg.h"
#include "afxdialogex.h"
#include "working_parameters.h"


// DataRangeChoiceDlg �Ի���

IMPLEMENT_DYNAMIC(DataRangeChoiceDlg, CDialog)

DataRangeChoiceDlg::DataRangeChoiceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(DataRangeChoiceDlg::IDD, pParent)
{
	InitRadioboxStatus();
}

DataRangeChoiceDlg::~DataRangeChoiceDlg()
{
}

void DataRangeChoiceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_radiobtngrp1);
	DDX_Radio(pDX, IDC_RADIO3, m_radiobtngrp2);
}


BEGIN_MESSAGE_MAP(DataRangeChoiceDlg, CDialog)
	ON_BN_CLICKED(IDC_RADIO1, &DataRangeChoiceDlg::OnBnClickedGroup1Radio)
	ON_BN_CLICKED(IDC_RADIO2, &DataRangeChoiceDlg::OnBnClickedGroup1Radio)

	ON_BN_CLICKED(IDC_RADIO3, &DataRangeChoiceDlg::OnBnClickedGroup2Radio)
	ON_BN_CLICKED(IDC_RADIO4, &DataRangeChoiceDlg::OnBnClickedGroup2Radio)
	ON_BN_CLICKED(IDC_RADIO5, &DataRangeChoiceDlg::OnBnClickedGroup2Radio)
	ON_BN_CLICKED(IDOK, &DataRangeChoiceDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// DataRangeChoiceDlg ��Ϣ�������

void DataRangeChoiceDlg::InitRadioboxStatus()
{
	// �ӿɱ������ļ��ж�ȡ�㳮���������ϴ��ȼ�
	VariableConfigBlock *config = WorkingParameters::GetInstance()->GetCurrentConfigParameters();   //֮ǰ��splash_screen��ʼ����mode.ini��·��
	int waveLevel = config->GetIntParameter(_T("WaveDataLevel"), 1);  //ȡ����Ӧģʽ�µ�����
	if ((waveLevel < 0) || (waveLevel > 1))
	{
		waveLevel = 1;
	}
	m_radiobtngrp1 = waveLevel;
	int imageLevel = config->GetIntParameter(_T("ImageDataLevel"), 2);
	if ((imageLevel < 0) || (imageLevel > 2))
	{
		imageLevel = 2;
	}
	m_radiobtngrp2 = imageLevel;
}

void DataRangeChoiceDlg::OnBnClickedGroup1Radio()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);  //������ ��radio��״ֵ̬���¸������ı���
	switch (m_radiobtngrp1)
	{
	case 0:
	//	MessageBox(L"radio1��ѡ�У�д��ini�ļ�");
		break;
	case 1:
	//	MessageBox(L"radio2��ѡ�У�д��ini�ļ�");
		break;
	default:
		break;
	}
}

void DataRangeChoiceDlg::OnBnClickedGroup2Radio()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);  //������ ��radio��״ֵ̬���¸������ı���
	switch (m_radiobtngrp2)
	{
	case 0:
	//	MessageBox(L"radio3��ѡ�У�д��ini�ļ�");
		break;
	case 1:
	//	MessageBox(L"radio4��ѡ�У�д��ini�ļ�");
		break;
	case 2:
	//	MessageBox(L"radio5��ѡ�У�д��ini�ļ�");
		break;
	default:
		break;
	}
}

void DataRangeChoiceDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	// �ӿɱ������ļ��ж�ȡ�㳮���������ϴ��ȼ�
	VariableConfigBlock *config = WorkingParameters::GetInstance()->GetCurrentConfigParameters();   //֮ǰ��splash_screen��ʼ����mode.ini��·��
	
	if ((m_radiobtngrp1 < 0) || (m_radiobtngrp1 > 1))
	{
		m_radiobtngrp1 = 1;
	}
	config->SetIntParemeter(_T("WaveDataLevel"), m_radiobtngrp1);  //ȡ����Ӧģʽ�µ�����
	if ((m_radiobtngrp2 < 0) || (m_radiobtngrp2 > 2))
	{
		m_radiobtngrp2 = 1;
	}
	config->SetIntParemeter(_T("ImageDataLevel"), m_radiobtngrp2);
	CDialog::OnOK();
}
