#include "Func_names.h"

pair<uint64_t, uint64_t> lob(uint64_t p)
{
	uint64_t n = sqrt(p);
	for (int i = 2; i <= n; i++)
	{
		uint64_t d = p / i;
		if (i * d == p)
		{
			cout << p << " isn't prime, here its dividers: " << i << ", " << d << endl;
			return pair(i, d);
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

pair<uint64_t, uint64_t> Pol(uint64_t p)
{

	return pair(1, p);
}

pair<uint64_t, uint64_t> B_M(uint64_t p)
{

	return pair(1, p);
}
