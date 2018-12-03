#pragma once
#ifndef RSA_H
#define RSA_H

#include<iostream>
#include"miller_rabin.h"

#define DE_PRIMECHECK 10	//Miller_Rabin素数检验测试值的个数

using namespace std;

typedef enum{en_success,en_fail,en_nullptr,en_error,en_true,en_false} RSAStatus;

class rsa_cal : public miller_rabin
{
public:
	

	RSAStatus setPrime(long long p, long long q);			//设置RSA加密类的素数
	RSAStatus checkPrime(long long p);						//对传参进行素性检查
	RSAStatus encrypt(long long msg, long long &crypt);		//对传入的msg进行加密，结果输出到引用crypt
	RSAStatus decrypt(long long crypt, long long &msg);		//对传入的crypt进行加密，结果输出到引用msg
	//long long gcd(long long a, long long b);				//求a和b的最大公约数
	long long ExtGcd(long long a, long long b, long long &s, long long &t);			//扩展欧几里得算法，使得 a*s + b*t = gcd(a,b)

	rsa_cal() {}

	~rsa_cal() {}


private:
	
	long long r;	//r = (p-1)(q-1)
	long long n;	//n = p * q
	long long p;	//素数p
	long long q;	//素数q
	long long e;	//私钥，加密钥
	long long d;	//公钥，解密钥
};


#endif // !RSA_H
