#include "Func_names.h"

int main()
{
	vector<pair<uint64_t, uint64_t>> a = rozklad(512*9);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i].first << ", " << a[i].second << "\n";
	}
	return 0;
}