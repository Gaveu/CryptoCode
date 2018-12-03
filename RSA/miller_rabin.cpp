#include"miller_rabin.h"

long long miller_rabin::OddRandomGen(long long min, long long max)			//生成[min,max)范围的奇随机数
{
	if (min < 0 || max < 0 || min >= max)
	{
		return 0;
	}
	long long r = min + rand() % (max - min);
	while (r % 2 != 1)
	{
		r = min + rand() % (max - min);
	}
	return r;
}

long long miller_rabin::RandomGen(long long min, long long max)		//生成[min,max]范围的随机树
{
	if (min < 0 || max < 0 || min > max)
	{
		return 0;
	}
	long long r = min + rand() % (max - min + 1);

	return r;
}

long long miller_rabin::ModExp(long long b, long long n, long long m) 	//模指运算，计算 b^n (mod m)
{
	long long sum = 1;
	while (n) {
		if (n & 1) {
			sum = (sum * b) % m;
			n--;
		}
		n /= 2;
		b = b * b % m;
	}
	return sum;
}

bool miller_rabin::MillerMain(int k)	//miller算法主函数,取k个2到n-2互不相同的数,来检验类中的n是否为素数
{
	if (k < 0 || n < 2 || k > n - 3)	//传参异常则返回false
	{
		cout << "MillerMain failed: check if 0 < k <= n-3 and n < 2" << endl;
		return false;
	}
	if (2 == n || 3 == n)	//被检验数为2或3时返回true
	{
		return true;
	}

	int times = 0;
	long long tmp;
	bool loopEnd = false;
	pass = false;

	long long *numArr = (long long *)malloc(sizeof(long long) * k);
	if (!numArr)	//空间申请失败则返回false
	{
		return false;
	}

	for (times = 0; times < k;)	//2到n-2范围内互不相同数据的数组初始化
	{
		tmp = RandomGen(2, n - 2);
		for (int j = 0; j < times && loopEnd != true;)
		{
			if (tmp != numArr[j])
			{
				j++;
			}
			else
			{
				loopEnd = true;
			}
		}
		if (loopEnd == true)
		{
			loopEnd = false;
			continue;
		}
		else
		{
			numArr[times] = tmp;
			loopEnd = false;
			times++;
		}
	}

	for (times = 0; times < k; ++times)
	{
		_Miller(numArr[times]);
		if (!pass)
		{
			break;
		}
	}
	free(numArr);
	numArr = nullptr;

	return pass;
}

void miller_rabin::_Miller(long long a)	//miller算法子过程
{
	if (a < 2 || a > n - 2 || m < 1)	//异常处理
	{
		cout << "_Miller failed: a:" << a << "  n:" << n << "  m:" << endl;
		return;
	}
	int j;
	long long b = ModExp(a, m, n);

	if (1 == b || n - 1 == b)
	{
		pass = true;
		return;
	}
	else
	{
		pass = false;
		for (j = 1; j <= t - 1; j++)
		{
			b = ModExp(b, 2, n);
			if (n - 1 == b)
			{
				pass = true;
				return;
			}

		}
	}
}