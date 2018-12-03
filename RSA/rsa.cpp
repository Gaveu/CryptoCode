#include "rsa.h"

long long rsa_cal::ExtGcd(long long a, long long b, long long &s, long long &t)	//扩展欧几里得算法，使得 a*s + b*t = gcd(a,b)
{
	if (a < 0 || b < 0)
	{
		cout << "ExtGcd error: a:" << a << " b:" << b << endl;
		return -1;
	}
	if (!b)
	{
		s = 1;
		t = 0;
		return a;
	}

	long long next;
	long long tmp;

	next = ExtGcd(b, a%b, s, t);
	tmp = s;
	s = t;
	t = tmp - a / b * t;
	return next;
}

RSAStatus rsa_cal::setPrime(long long p, long long q)	//设置RSA加密类的素数
{
	if (p <= 1 || q <= 1)
	{
		cout << "setPrime failed: p:" << p << " q:" << q << endl;
		return en_error;
	}

	if (checkPrime(p) != en_true || checkPrime(q) != en_true)
	{
		cout << "setPrime failed: p is not prime number" << endl;
		cout << "p:" << p << endl;
		return en_fail;
	}
	if (checkPrime(q) != en_true)
	{
		cout << "setPrime failed: q is not prime number" << endl;
		cout << "q:" << q << endl;
		return en_fail;
	}


	
	if (p * q < 0)
	{
		cout << "setPrime error: overflow" << endl;
		return en_error;
	}

	long long tmp_r = 0;	//扩展欧几里得计算临时变量
	long long tmp_e = 0;	//加密钥临时变量
	long long tmp_d = 0;	//解密钥临时变量

	this->p = p;
	this->q = q;
	n = p * q;
	r = (p - 1)*(q - 1);
	
	tmp_e = RandomGen(2, r - 1);	//tmp_e取[2,r-1]之间的数
	while (ExtGcd(r, tmp_e, tmp_r, tmp_d) != 1)	//计算 r*tmp_r + tmp_e*tmp_d = gcd(r,tmp_e)
												//若gcd(r,tmp_e)不等于1，则说明不满足条件时说明当前随机数tmp_e不能与r互质，重新取随机数
	{
		tmp_e = RandomGen(2, r - 1);
	}

	e = tmp_e % r;
	
	while (tmp_d < 0)
	{
		tmp_d += r;
	}
	d = tmp_d;

	return en_success;
}

RSAStatus rsa_cal::checkPrime(long long p)	//对传参进行素性检查
{
	if (p <= 1)
	{
		//p<=1视为异常
		cout << "checkPrime failed: p:" << p << endl;
		return en_error;
	}
	if (2 == p || 3 == p)
	{
		//2或3均为素数，返回en_true
		return en_true;
	}


	//Miller_Rabin素性检验
	SetN(p);	//待检验值设为p
	if (MillerMain(DE_PRIMECHECK) == true)	//取DE_PRIMECHECK作为检验个数
	{
		return en_true;
	}
	else
	{
		return en_false;
	}
}

RSAStatus rsa_cal::encrypt(long long msg, long long &crypt)		//对传入的msg进行加密，结果输出到引用crypt
{
	if (msg < 0)
	{
		cout << "encrypt error: msg:" << msg << endl;
		return en_error;
	}

	if (msg >= n)
	{
		cout << "encrypt fail: message shouldn't greater than n" << endl;
		cout << "msg:" << msg << "  n:" << n << endl;
		cout << "please choose any greater prime number " << endl;
		return en_fail;
	}

	long long tmp_c = ModExp(msg, e, n);
	if (tmp_c < 0)
	{
		cout << "encrypt failed: overflow from MoxExp()" << endl;
		return en_fail;
	}
	crypt = tmp_c;
	return en_success;
}

RSAStatus rsa_cal::decrypt(long long crypt, long long &msg)		//对传入的crypt进行加密，结果输出到引用msg
{
	if (crypt < 0)
	{
		cout << "encrypt error: crypt:" << crypt << endl;
		return en_error;
	}

	if (crypt >= n)
	{
		cout << "decrypt fail: cryphertext shouldn't greater than n" << endl;
		cout << "crypt:" << crypt << "  n:" << n << endl;
		cout << "please choose any greater prime number " << endl;
		return en_fail;
	}

	long long tmp_m = ModExp(crypt, d, n);
	if (tmp_m < 0)
	{
		cout << "decrypt failed: overflow from MoxExp()" << endl;
		return en_fail;
	}
	msg = tmp_m;
	return en_success;
}