#include "stdafx.h"
#include <Windows.h>

//���ļ���ȡ���ڴ���
char* ReadFileToMemory(char* pFilePath)
{
	FILE* pFile;
	fopen_s(&pFile, pFilePath, "rb");
	if (!pFile)
	{
		printf("�ļ���ʧ��\n");
		return 0;
	}
	//��ȡ�ļ���С
	fseek(pFile, 0, SEEK_END);
	int nSize = ftell(pFile);
	char* pBuf = new char[nSize] {};
	//���ļ����ڴ���
	fseek(pFile, 0, SEEK_SET);
	fread(pBuf, nSize, 1, pFile);
	//�ر��ļ�
	fclose(pFile);
	return pBuf;
}

//�ж��Ƿ���PE�ļ�
bool IsPeFile(char* pBuf)
{
	PIMAGE_DOS_HEADER pDos = (PIMAGE_DOS_HEADER)pBuf;
	if (pDos->e_magic != IMAGE_DOS_SIGNATURE)//0x5A4D
	{
		return false;
	}
	//NTͷ
	PIMAGE_NT_HEADERS pNt =
		(PIMAGE_NT_HEADERS)
		(pDos->e_lfanew + pBuf);
	if (pNt->Signature != IMAGE_NT_SIGNATURE) //0x00004550
	{
		return false;
	}
	return true;
}

DWORD RVAtoFOA(DWORD dwRVA, char* pBuf)
{
	//�ҵ�����λ�ã�����Ŀ¼��ĵ�һ��±�0��
	PIMAGE_DOS_HEADER pDos = (PIMAGE_DOS_HEADER)pBuf;
	//NTͷ
	PIMAGE_NT_HEADERS pNt =
		(PIMAGE_NT_HEADERS)
		(pDos->e_lfanew + pBuf);
	//���α��׵�ַ
	PIMAGE_SECTION_HEADER pSec = IMAGE_FIRST_SECTION(pNt);
	//���α��еĸ���
	DWORD dwCount = pNt->FileHeader.NumberOfSections;
	for (int i = 0; i < dwCount; i++)
	{
		if (dwRVA >= pSec->VirtualAddress &&
			dwRVA < (pSec->VirtualAddress + pSec->SizeOfRawData))
		{
			return dwRVA -
				pSec->VirtualAddress + pSec->PointerToRawData;
		}
		//��һ������
		pSec++;
	}
	return 0;
}

