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

uint64_t SSh(uint64_t p)
{

	return 1;
}

uint64_t Pol(uint64_t p)
{

	return 1;
}

uint64_t B_M(uint64_t p)
{

	return 1;
}
