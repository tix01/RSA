#pragma once
#include <iostream>
class RSA
{
public:
	bool isPrime(int innum);
	int getE(int t);
	int getD(int e, int t);
	int enc(int msg,int n, int e);
	int dec(int msg,int n, int d);
	int funcEuler(int p, int q);
	int modpq(int p, int q);
	int numcoice();
};

