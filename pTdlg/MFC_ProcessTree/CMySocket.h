#pragma once
//class CMySocket
//{
//public:
//	CMySocket();
//	~CMySocket();
//};

//��Ϣ�շ��࣬��Ҫ�����������ڶԷ���˽����������ӣ��������������������˵����ݽ���ͨ�������ڽ���

#pragma once
//mfc�����Ҫʹ��socket��Ҫ��Ӹ�ͷ�ļ�
#include<afxsock.h>
#include "data.h"

class CMySocket :public CSocket
{
public:
	CMySocket();
	virtual ~CMySocket();
	void InitSocket();
	//��дonreceive�������ڽ��շ���˷��ͻ�������Ϣ
	virtual void OnReceive(int nErrorCode);
};

