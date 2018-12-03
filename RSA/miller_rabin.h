#pragma once
#ifndef MILLER_RABIN_H
#define MILLER_RABIN_H

#include<iostream>
#include<vector>
#include<random>
#include<math.h>
#include<time.h>
#include<windows.h>

using namespace std;

class miller_rabin
{
public:

	long long ModExp(long long b, long long n, long long m);	//模指运算，计算 b^n (mod m)
	bool MillerMain(int k);										//miller算法主函数,取k个2到n-2互不相同的数,来检验类中的n是否为素数
	void _Miller(long long a);									//miller算法子过程
	long long OddRandomGen(long long min, long long max);		//生成[min,max)范围的奇随机数
	long long RandomGen(long long min, long long max);			//生成[min,max]范围的随机数


	long long GetN()
	{
		return n;
	}
	void SetN(long long _n)
	{
		if (_n <= 1)
		{
			cout << "check if n > 1!" << endl;
			return;
		}
		t = 0;
		n = _n;
		m = n - 1;
		while (m % 2 != 1 || (n - 1) % m != 0)	//令m为n的最大奇因子
		{
			m--;
		}

		//计算_Miller中需要用到的t
		long long num = n - 1;
		while (num % 2 == 0)
		{
			num >>= 1;
			t++;
		}
	}

	bool GetPass()
	{
		return pass;
	}
	void SetPass(bool _pass)
	{
		pass = _pass;
	}


	miller_rabin(long long _n) : n(_n)
	{
		if (_n <= 1)
		{
			cout << "check if n > 1!" << endl;
			return;
		}
		t = 0;
		n = _n;
		m = n - 1;
		while (m % 2 != 1 || (n - 1) % m != 0)	//令m为n-1的最大奇因子
		{
			m--;
		}

		//计算_Miller中需要用到的t
		long long num = n - 1;
		while (num % 2 == 0)
		{
			num >>= 1;
			t++;
		}

		srand(rd());	//设置随机树种子
	}

	miller_rabin()
	{
		srand(rd());	//设置随机树种子
	}
	~miller_rabin() {}

private:

	bool pass;
	int t;
	long long n;
	long long m;
	random_device rd;

};



#endif // !HEADER_H

