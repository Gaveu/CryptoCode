#pragma once
#include<iostream>
#include<string>
#define DE_MAX_LEN 1024


class CaesarCrypto
{
public:
	std::string S = ("Flag{YoShiTo}");	//�洢�ַ�����string����
	void GetMessage();	//����������ȡ�ַ���
	void ShowMessage();	//���������string����Ϣ
	void En_Caesar();	//�Դ���������ȡ���ַ������м��ܣ�����ĸ�ַ������д���
	void De_Caesar();	//�Դ���������ȡ���ַ������б������ܣ�����ĸ�ַ������д���

};


void CaesarCrypto::GetMessage()		//����������ȡ�ַ���
{
	std::cout << "Message?" << std::endl;
	S.clear();
	char ar[DE_MAX_LEN] = { 0 };
	std::cin>>ar;
	S.assign(ar);
}

void CaesarCrypto::ShowMessage()	//���������string����Ϣ
{
	std::cout << S.data() << std::endl;
}

void CaesarCrypto::En_Caesar()		//�Դ���������ȡ���ַ������м��ܣ�����ĸ�ַ������д���
{
	int a;	
	size_t i;
	std::cout << "Message: "<<S.data() << std::endl;
	std::cout << "Key?" << std::endl;
	std::cin >> a;
	if (a < 0)
	{
		return;
	}
	a %= 26;//ƫ������26
	for (i = 0;i < S.length();++i)
	{
		if (S[i] >= 'a'&& S[i] <= 'z')
		{
			S[i] += a;
			if (S[i] > 'z')
			{
				S[i] -= 26;
			}
		}
		else if (S[i] >= 'A'&& S[i] <= 'Z')
		{
			S[i] += a;
			if (S[i] > 'Z')
			{
				S[i] -= 26;
			}
		}
		else
		{
			continue;
		}
	}
	ShowMessage();
}

void CaesarCrypto::De_Caesar()	//�Դ���������ȡ���ַ������б������ܣ�����ĸ�ַ������д���
{
	int key;
	size_t i;
	std::string st_tmp = S;
	for (key = 25; key >= 0; --key)
	{
		for (i = 0; i < st_tmp.length(); ++i)
		{
			if (st_tmp[i] >= 'a'&& S[i] <= 'z')
			{
				++st_tmp[i];
				if (st_tmp[i] > 'z')
				{
					st_tmp[i] -= 26;
				}
			}
			else if (st_tmp[i] >= 'A'&& st_tmp[i] <= 'Z')
			{
				++st_tmp[i];
				if (st_tmp[i] > 'Z')
				{
					st_tmp[i] -= 26;
				}
			}
			else
			{
				continue;
			}
		}
		std::cout << "key = " << key <<':';
		std::cout << st_tmp.data() << std::endl;
		std::cout << std::endl;
	}
}

