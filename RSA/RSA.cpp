#include "RSA.h"

bool RSA::isPrime(int innum)
{
	if(innum == 0 || innum == 1)
		return false;
	for (int i = 2; i < innum; i++)
	{
		if (innum % i == 0) {
			return  false; 
		}
	}
	return true;
	
}

int RSA::getE(int t)
{
	int tempE;
	int e;
	int tempT=t;
	for (e = 2; e < t; e++)
	{
		tempE = e;
		while (tempE > 0)
		{
			int myTemp;

			myTemp = tempE;
			tempE = tempT % tempE;
			tempT = myTemp;
		}
		if (tempT == 1)
		{
			return e;
		}
		tempT = t;
	}

	return -1;
}


int RSA::getD(int e, int t)
{
	long int d;
	long int k = 1;

	while (1)
	{
		k = k + t;

		if (k % e == 0)
		{
			d = (k / e);
			return d;
		}
	}
}

int RSA::enc(int msg,int n, int e)
{
	int count, res;
	count = msg;
	res = 1;

	for (long int j = 0; j < e; j++)
	{
		res = res * count;
		res = res % n;
	}
	return res;
}

int RSA::dec(int msg, int n, int d)
{
	long int count, res;

	count = msg;
	res = 1;

	for (long int j = 0; j < d; j++)
	{
		res = res * count;
		res = res % n;
	}
	return res;
}

int RSA::funcEuler(int p, int q)
{
	return (p - 1) * (q - 1);
}

int RSA::modpq(int p, int q)
{
	return p*q;
}

int RSA::numcoice()
{
	int num;
	std::cout << "Set prime number :";
	std::cin >> num;
	do {
		if (!isPrime(num)) {
			std::cout << "FAIL";
		}
	} while (!isPrime(num));
	return num;
}
