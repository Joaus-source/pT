#pragma once
#pragma once
#include <windows.h>
//��������Ҫ��Ӧ���Զ�����Ϣ
enum UserMessage {
	WM_REGISTER = WM_USER + 1,//ע����Ϣ
	WM_CHATMESSAGE,
	WM_CHATMESSAGEtoChatBox,
	WM_FINDUSER,//����û�������Ϣ
	WM_FINDUSERtoChatBox,

	WM_CHATTOONE,//˽��
	WM_CHATTOONEtoChatBox,//˽�ķ��ؽ��

	WM_HISTORYMSG,//��������¼�Ĺ���
	WM_HISTORYMSGtoChatBox,
	WM_FRIEND,//�Ӻ���
	WM_SHOWFRIEND//��ʾ����
};

typedef enum MessageType {
	RegisterMessage,//ע����Ϣ0
	LoginMessage,//1
	ChatMessage,//2
	FindUser,//3
	GetHistoryMsg,//4
	ChatOne,//5
	Friend,//6
	ShowFriendinfo//7

}MsgType;

//��½����

//˽������

//ע������
typedef struct REGISTER {
	//�û��������볤������Ϊ20�ֽڣ�ʵ�����ݿ�����洢50�ֽڵ���Ϣ
	int namelen;
	int passlen;
	wchar_t user_name[20];
	wchar_t user_pass[20];
	//�����Ա�ΪŮ����ֵΪ0 �Ա�Ϊ�У���Ϊ1
	int user_sex;
}REMSG;


typedef struct LONGIN {
	//�û��������볤������Ϊ20�ֽڣ�ʵ�����ݿ�����洢50�ֽڵ���Ϣ
	int namelen;
	int passlen;
	wchar_t user_name[20];
	wchar_t user_pass[20];
}LOMSG;


typedef struct FRIEND {
	//�û��������볤������Ϊ20�ֽڣ�ʵ�����ݿ�����洢50�ֽڵ���Ϣ
	int namelen1;
	int namelen2;
	wchar_t user_name1[20];
	wchar_t user_name2[20];
}FRIENT;

//Ⱥ����Ϣ����
typedef struct MESSAGECONTENT
{
	MsgType Msg_Type;//��Ϣ����
	HWND hwnd;//���ھ��
	DWORD dwMsgLen;//��Ϣ���ĳ���
	union MyUnion//��Ϣ����
	{
		wchar_t buff[1024];//����ϢΪ������Ϣ
		//��½��Ϣ
		LOMSG lomsg;
		//ע����Ϣ
		REMSG remsg;
		//�Ӻ�����Ϣ
		FRIEND femsg;
	}m_content;
};

//˽����Ϣ����
typedef struct TOONE
{
	MsgType Msg_Type;//��Ϣ����
	wchar_t anotherPerson[10];//˽�Ķ��ֵ��û�����
	DWORD dwMsgLen;//��Ϣ���ĳ���
	union MyUnion//��Ϣ����
	{
		wchar_t buff[1024];//����ϢΪ������Ϣ
		//��½��Ϣ
		LOMSG lomsg;
		//ע����Ϣ
		REMSG remsg;
	}m_content;
};


//�������Ϊȫ�ֱ������棬������ʵ��ֱ����ĳ�����ڷ���Ϣ�Ĺ��ܣ���ʱ����
//extern HWND Dlglog_hWnd;

extern HWND g_ChatHandle;
extern HWND g_LogHandle;