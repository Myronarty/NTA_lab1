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
	cout << p;
	return p;
}

pair<uint64_t, uint64_t> SSh(uint64_t p, int tochnist)
{
	for (int i = 0; i < tochnist; i++)
	{
		mt19937_64 gen(random_device{}());
		uniform_int_distribution<uint64_t> distribution(0, numeric_limits<uint64_t>::max());
		uint64_t x = distribution(gen);


	}
	return pair(1, p);
}

pair<uint64_t, uint64_t> Pol(uint64_t p)
{

	return pair(1, p);
}

pair<uint64_t, uint64_t> B_M(uint64_t p)
{

	return pair(1, p);
}
