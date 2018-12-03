#include "rsa.h"

int main()
{
	long long msg[10] = {124,547,312,46,4541,533,45,984,12,69};	//明文
	long long crypt[10];
	rsa_cal rsa;

	int times = 0;

	//输出明文信息
	cout << "Message:" << endl;
	for (times = 0; times < 10; times++)
	{
		cout << msg[times] << "  ";
	}
	cout << endl;
	cout << endl;

	//明文加密
	cout << "After encrypt:" << endl;
	if (en_success != rsa.setPrime(1399, 139))	//设置初始的素数p和q，检查素性并对类进行初始化
	{
		system("PAUSE");
		return 0;
	}

	for (times = 0; times < 10; times++)
	{
		if(en_success != rsa.encrypt(msg[times], crypt[times]))
		{
			system("PAUSE");
			return 0;
		}
		cout << crypt[times] << "  ";
	}
	cout << endl;
	cout << endl;
	
	//密文解密
	cout << "After decrypt:" << endl;
	for (times = 0; times < 10; times++)
	{
		if (en_success != rsa.decrypt(crypt[times], msg[times]))
		{
			system("PAUSE");
			return 0;
		}
		cout << msg[times] << "  ";
	}
	cout << endl;
	cout << endl;


	system("PAUSE");
	return 0;
}