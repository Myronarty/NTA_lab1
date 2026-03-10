#include "Func_names.h"

pair<uint64_t, uint64_t> lob(uint64_t p)
{
	int n[15] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
	for (int i = 2; i <= 15; i++)
	{
		uint64_t d = p / n[i];
		if (i * d == p)
		{
			cout << p << " isn't prime, here its dividers: " << n[i] << ", " << d << endl;
			return pair(n[i], d);
		}
	}
	cout << p << " isn prime, nothing found ( :) / :( ? )" << endl;
	return pair(1, p);
}

uint64_t gcd(uint64_t x, uint64_t p)
{
	while (x != 0) 
	{
		p %= x;
		swap(x, p);
	}
	//cout << p;
	return p;
}

bool Lege(uint64_t x, uint64_t p)
{
	if (x == 1)
	{
		return 1;
	}

	if (x == 0)
	{
		cout << "p dilutsa na x" << endl;
		return 0;
	}

	if ((x & 3) == 0)
	{
		return Lege(x >> 2, p);
	}

	if ((x & 1) == 0)
	{
		int d = p & 7;
		if (d == 1 || d == 7)
		{
			return Lege(x >> 1, p);
		}
		else
		{
			return !Lege(x >> 1, p);
		}
	}

	if (x < p)
	{
		bool d = ((p & 3) == 3) && ((x & 3) == 3);
		if (d)
		{
			return !Lege(p % x, x);
		}
		else
		{
			return Lege(p % x, x);
		}
	}
}

uint64_t pow_mod(uint64_t x, uint64_t p, uint64_t m)
{
	uint64_t rez = 1;
	while (p > 0) 
	{
		if (p & 1)
		{
			rez *= x;
			rez %= m;
		}
		x *= x;
		x %= m;
		p >>= 1;
	}
	return rez;
}

void SSh(uint64_t p, int tochnist, pair<uint64_t, uint64_t> c)
{
	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<uint64_t> distribution(2, p - 1);
	unordered_set<uint64_t> used_x;

	for (int i = 0; i < tochnist; i++)
	{
		uint64_t x = distribution(gen);
		while (used_x.find(x) != used_x.end())
		{
			x = distribution(gen);
		}
		used_x.insert(x);

		uint64_t d = gcd(x, p);
		if (d > 1)
		{
			cout << p << " isn't prime, here its dividers: " << p / d << ", " << d << endl;
			c = pair(p / d, d);
			return;
		}
		if (Lege(x, p) != pow_mod(x, (p - 1) >> 1, p))
		{
			cout << p << " isn't prime" << endl;
			return;
		}
	}
}

uint64_t func(const vector<unsigned int>& f, uint64_t p, uint64_t x)
{
	uint64_t rez = f[0];
	for (int i = 1; i < f.size(); i++)
	{
		if (f[i] != 0)
		{
			rez = (rez + pow_mod(x, f[i], p)) % p;
		}
	}
	return rez;
}

pair<uint64_t, uint64_t> Pol(uint64_t p, uint64_t x_0, vector<unsigned int> f)
{
	uint64_t x = func(f, p, x_0);
	uint64_t y = func(f, p, func(f, p, x_0));
	bool t = 1;
	while (t)
	{
		if(x > y)
		{
			uint64_t d = gcd(x - y, p);
			if (d > 1)
			{
				cout << p << " isn't prime, here its dividers: " << p / d << ", " << d << endl;
				return pair(d, p / d);
			}
			x = func(f, p, x);
			y = func(f, p, func(f, p, y));
		}
		else if (x < y)
		{
			uint64_t d = gcd(y - x, p);
			if (d > 1)
			{
				cout << p << " isn't prime, here its dividers: " << p / d << ", " << d << endl;
				return pair(d, p / d);
			}
			x = func(f, p, x);
			y = func(f, p, func(f, p, y));
		}
		else
		{
			return Pol(p, x_0 + 1, f);
		}
	}

	return pair(1, p);
}

double loog(double x, double base)
{
	return log(x) / log(base);
}

vector<bool> sdvig_po_faze(int* B, int size, uint64_t x)
{
	vector<bool> rez;
	for (int i = 0; i < size; i++)
	{
		int d = gcd(x, B[i]);
		if (d > 1)
		{
			int k = loog(d, B[i]);
			if (k & 1)
			{
				rez.push_back(1);
			}
			else
			{
				rez.push_back(0);
			}
		}
		else
		{
			rez.push_back(0);
		}
	}
	return rez;
}

pair<uint64_t, uint64_t> B_M(uint64_t p)
{
	
	return pair(1, p);
}
