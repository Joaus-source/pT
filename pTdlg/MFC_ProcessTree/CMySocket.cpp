//#include "stdafx.h"
//#include "CMySocket.h"
//
//
//CMySocket::CMySocket()
//{
//}
//
//
//CMySocket::~CMySocket()
//{
//}

#include "stdafx.h"
#include "CMySocket.h"
#include "MFC_ProcessTreeDlg.h"

CMySocket::CMySocket()
{
}
CMySocket::~CMySocket()
{
}

//void CMySocket:: OnReceive() {
//	//����涨��һ�η��͵�������಻�ܳ���2048���ֽ�
//	wchar_t s[1024] = { 0 };
//	//������Ϣ
//	Receive(s, sizeof(s));
//	CChatRoomclientDlg *p = (CChatRoomclientDlg*)AfxGetMainWnd();
//	p->OnReceive(s);
//	//CSocket::OnReceive(nErrorCode);
//}


void CMySocket::InitSocket() {
	//��ʼ��
	AfxSocketInit();
	//����socket
	this->Create();
	//����ָ���ĵ�ַ�Ͷ˿�
	this->Connect(L"127.0.0.1", 12345);
}


void CMySocket::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���

	//����涨��һ�η��͵�������಻�ܳ���2048���ֽ�	
	wchar_t s[1100] = { 0 };
	//������Ϣ
	Receive(s, sizeof(s));

	CMFCProcessTreeDlg *p = (CMFCProcessTreeDlg*)AfxGetMainWnd();
	
	p->OnReceive(s);
	//CSocket::OnReceive(nErrorCode);

	CSocket::OnReceive(nErrorCode);
}
