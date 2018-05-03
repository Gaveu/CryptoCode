#pragma once
#include<iostream>
#include<string>
#define DE_MAX_LEN 1024


class CaesarCrypto
{
public:
	std::string S = ("Flag{YoShiTo}");	//存储字符串的string变量
	void GetMessage();	//从输入流获取字符串
	void ShowMessage();	//从类中输出string内信息
	void En_Caesar();	//对从输入流获取的字符串进行加密（非字母字符不进行处理）
	void De_Caesar();	//对从输入流获取的字符串进行遍历解密（非字母字符不进行处理）

};


void CaesarCrypto::GetMessage()		//从输入流获取字符串
{
	std::cout << "Message?" << std::endl;
	S.clear();
	char ar[DE_MAX_LEN] = { 0 };
	std::cin>>ar;
	S.assign(ar);
}

void CaesarCrypto::ShowMessage()	//从类中输出string内信息
{
	std::cout << S.data() << std::endl;
}

void CaesarCrypto::En_Caesar()		//对从输入流获取的字符串进行加密（非字母字符不进行处理）
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
	a %= 26;//偏移量余26
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

void CaesarCrypto::De_Caesar()	//对从输入流获取的字符串进行遍历解密（非字母字符不进行处理）
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

