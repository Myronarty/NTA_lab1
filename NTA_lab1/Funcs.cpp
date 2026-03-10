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

bool Lege(uint64_t x_, uint64_t p)
{
	uint64_t x = x_ % p;

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

uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t m)
{
	uint64_t res = 0;
	a %= m;
	while (b > 0)
	{
		if (b & 1)
		{
			res = (res + a) % m;
		}
		a = (a * 2) % m;
		b >>= 1; // ділимо b на 2
	}
	return res;
}

uint64_t pow_mod(uint64_t x, uint64_t p, uint64_t m) {
	uint64_t rez = 1;
	x %= m;
	while (p > 0) {
		if (p & 1) {
			rez = mul_mod(rez, x, m); // Замість rez = (rez * x) % m
		}
		x = mul_mod(x, x, m);         // Замість x = (x * x) % m
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
	cout << p << " is maybe prime, nothing found ( :) / :( ? )" << endl;
	return pair(1, p);
}

double loog(double x, double base)
{
	return log(x) / log(base);
}

vector<bool> sdvig_po_faze(vector<int64_t>& B, int64_t x, bool& B_smooth)
{
	vector<bool> rez(B.size(), 0);

	if (x < 0)
	{
		rez[0] = 1;
		x = -x;
	}

	for (size_t i = 1; i < B.size(); i++)
	{
		int pow = 0;
		while (x % B[i] == 0)
		{
			pow++;
			x /= B[i];
		}
		rez[i] = pow & 1;
	}

	B_smooth = (x == 1);
	return rez;
}

pair<vector<int64_t>, vector<int64_t>> D_it(int64_t n, int l)
{
	vector<int64_t> b1_values;
	vector<int64_t> b2_values;

	int64_t a0 = sqrt(n);
	int64_t P_i = a0;
	int64_t Q_i = n - a0 * a0;

	int64_t A_prev2 = 1;
	int64_t A_prev1 = a0;

	for (int i = 1; i <= l; i++)
	{
		if (Q_i == 0) break;

		int64_t current_b1 = A_prev1;
		int64_t current_b2 = (i % 2 != 0) ? -Q_i : Q_i;

		b1_values.push_back(current_b1);
		b2_values.push_back(current_b2);

		int64_t q_i = (a0 + P_i) / Q_i;
		int64_t P_next = q_i * Q_i - P_i;
		int64_t Q_next = (n - P_next * P_next) / Q_i;

		int64_t A_i = (mul_mod(q_i, A_prev1, n) + A_prev2) % n;

		P_i = P_next;
		Q_i = Q_next;
		A_prev2 = A_prev1;
		A_prev1 = A_i;
	}

	return pair(b1_values, b2_values);
}

//yes, ai knows linal better than me
vector<vector<int>> solve_gauss_gf2(vector<vector<bool>>& matrix)
{
	int num_rows = matrix.size();
	if (num_rows == 0) return {};
	int num_cols = matrix[0].size();

	vector<vector<bool>> A = matrix;

	vector<vector<bool>> history(num_rows, vector<bool>(num_rows, false));
	for (int i = 0; i < num_rows; i++)
	{
		history[i][i] = true;
	}

	int pivot_row = 0;

	for (int col = 0; col < num_cols && pivot_row < num_rows; col++)
	{
		int sel = pivot_row;
		while (sel < num_rows && !A[sel][col]) sel++;

		if (sel == num_rows) continue;

		swap(A[sel], A[pivot_row]);
		swap(history[sel], history[pivot_row]);

		for (int i = 0; i < num_rows; i++)
		{
			if (i != pivot_row && A[i][col])
			{
				for (int j = 0; j < num_cols; j++)
				{
					A[i][j] = A[i][j] ^ A[pivot_row][j];
				}
				for (int j = 0; j < num_rows; j++)
				{
					history[i][j] = history[i][j] ^ history[pivot_row][j];
				}
			}
		}
		pivot_row++;
	}

	vector<vector<int>> dependencies;

	for (int i = pivot_row; i < num_rows; i++)
	{
		vector<int> dep;
		for (int j = 0; j < num_rows; j++)
		{
			if (history[i][j])
			{
				dep.push_back(j);
			}
		}
		if (!dep.empty())
		{
			dependencies.push_back(dep);
		}
	}

	return dependencies;
}

pair<uint64_t, uint64_t> B_M(uint64_t p)
{
	double L = exp(sqrt(0.5) * sqrt(log(p) * log(log(p))));
	ifstream file("D:/problems/term_6/NTA/lab_1/First10MillionPrimes.txt");

	vector<int64_t> B;
	B.push_back(-1);

	uint64_t current_num;
	while ((file >> current_num) && current_num < L)
	{
		if (Lege(p, current_num))
		{
			B.push_back(current_num);
		}
	}
	file.close();
	auto D_res = D_it(p, int(L));
	vector<int64_t>& b_1 = D_res.first;
	vector<int64_t>& b_2 = D_res.second;

	vector<vector<bool>> s;
	vector<int> smooth_indices;
	for (size_t i = 0; i < b_2.size(); i++)
	{
		bool B_smooth = false;
		vector<bool> s_i = sdvig_po_faze(B, b_2[i], B_smooth);

		if (B_smooth)
		{
			s.push_back(s_i);
			smooth_indices.push_back(i);
		}

		if (s.size() > B.size() + 1)
		{
			break;
		}
	}


	vector<vector<int>> solvs = solve_gauss_gf2(s);

	for (int i = 0; i < solvs.size(); i++)
	{
		int64_t _x = 1;
		int64_t _y = 1;
		vector<int> powers(B.size(), 0);

		for (int row_idx : solvs[i])
		{
			int orig_idx = smooth_indices[row_idx];

			_x = mul_mod(_x, b_1[orig_idx], p);

			int64_t temp = b_2[orig_idx];
			if (temp < 0)
			{
				powers[0]++;
				temp = -temp;
			}

			for (size_t j = 1; j < B.size(); j++)
			{
				while (temp % B[j] == 0)
				{
					powers[j]++;
					temp /= B[j];
				}
			}
		}

		for (size_t j = 1; j < B.size(); j++)
		{
			int _power = powers[j] / 2;
			if (_power > 0)
			{
				int64_t temp = pow_mod(B[j], _power, p);
				_y = mul_mod(_y, temp, p);
			}
		}

		if (_x != _y && _x != (p - _y))
		{
			uint64_t sum_mod = (_x + _y) % p;
			uint64_t diff_mod = (_x > _y) ? (_x - _y) : (p - (_y - _x));

			uint64_t d_1 = gcd(sum_mod, p);
			uint64_t d_2 = gcd(diff_mod, p);

			if (d_1 > 1 && d_1 < p)
			{
				cout << p << " factored! Dividers: " << d_1 << ", " << p / d_1 << endl;
				return pair(d_1, p / d_1);
			}
			if (d_2 > 1 && d_2 < p)
			{
				cout << p << " factored! Dividers: " << d_2 << ", " << p / d_2 << endl;
				return pair(d_2, p / d_2);
			}
		}
	}
	cout << p << " is maybe prime, nothing found ( :) / :( ? )" << endl;
	return pair(1, p);
}


/*pair<uint64_t, uint64_t> B_M(uint64_t p)
{
	double L = exp(sqrt(0.5) * sqrt(log(p)*log(log(p))));
	ifstream file("D:/problems/term_6/NTA/lab_1/First10MillionPrimes.txt");

	vector<int64_t> B;
	B.push_back(-1);

	uint64_t current_num;
	while ((file >> current_num) && current_num < L*2)
	{
		if(Lege(p, current_num))
		{
			B.push_back(current_num);
			cout << current_num << endl;
		}
	}
	file.close();

	auto D_res = D_it(p, L*2);
	vector<int64_t>& b_1 = D_res.first;
	vector<int64_t>& b_2 = D_res.second;

	vector<vector<bool>> s;
	vector<int> smooth_indices;
	for (size_t i = 0; i < b_2.size(); i++)
	{
		bool B_smooth = false;
		vector<bool> s_i = sdvig_po_faze(B, b_2[i], B_smooth);

		if (B_smooth)
		{
			s.push_back(s_i);
			smooth_indices.push_back(i);
		}

		if (s.size() > B.size()+10)
		{
			break;
		}
	}
	cout << "[DEBUG] Зібрано рядків матриці s: " << s.size() << endl;

	vector<vector<int>> solvs = solve_gauss_gf2(s);
	cout << solvs.size() << "      ";
	for (int i = 0; i < solvs.size(); i++)
	{
		int64_t _x = 1;
		int64_t _y = 1;
		vector<int> powers(B.size(), 0);

		for (int row_idx : solvs[i]) {
			int orig_idx = smooth_indices[row_idx];
			_x = mul_mod(_x, (uint64_t)b_1[orig_idx], p);

			// 2. Збираємо степені (важливо: беремо АБСОЛЮТНЕ значення для розкладу)
			int64_t temp = b_2[orig_idx];
			if (temp < 0) {
				powers[0]++; // рахуємо мінуси для Гаусса
				temp = -temp;
			}
			for (size_t j = 1; j < B.size(); j++) {
				while (temp % B[j] == 0) {
					powers[j]++;
					temp /= B[j];
				}
			}
		}

		// 3. Обчислюємо Y
		// j починаємо з 1, бо корінь з (-1)^(2k) це завжди 1 mod p
		for (size_t j = 1; j < B.size(); j++) {
			if (powers[j] > 0) {
				// powers[j] має бути парним завдяки Гауссу
				int64_t _power = powers[j] / 2;
				uint64_t p_pow = pow_mod((uint64_t)B[j], _power, p);
				_y = mul_mod(_y, p_pow, p);
			}
		}

		if (_x != _y && _x != (p - _y))
		{
			// DEBUG 1: Перевірка, що Гаусс дійсно зібрав парні степені
			for (size_t j = 0; j < B.size(); j++) {
				if (powers[j] % 2 != 0) {
					cout << "ПОМИЛКА: Гаусс видав непарний степінь для простого числа B[" << j << "]" << endl;
				}
			}

			// DEBUG 2: Перевірка головної рівності алгоритму (X^2 == Y^2 mod p)
			uint64_t x2 = mul_mod(_x, _x, p);
			uint64_t y2 = mul_mod(_y, _y, p);
			if (x2 != y2) {
				cout << "ПОМИЛКА: X^2 != Y^2 mod p. Проблема у генерації або sdvig_po_faze." << endl;
			}

			// Правильний і безпечний пошук дільників
			uint64_t sum = (_x + _y) % p;
			uint64_t diff = (_x > _y) ? (_x - _y) : (_y - _x); // БЕЗПЕЧНЕ віднімання

			uint64_t d_1 = gcd(sum, p);
			uint64_t d_2 = gcd(diff, p);

			// Перевіряємо кожен дільник ОКРЕМО (достатньо знайти хоча б один)
			if (d_1 > 1 && d_1 < p)
			{
				cout << p << " factored! Dividers: " << d_1 << ", " << p / d_1 << endl;
				return { d_1, p / d_1 };
			}
			if (d_2 > 1 && d_2 < p)
			{
				cout << p << " factored! Dividers: " << d_2 << ", " << p / d_2 << endl;
				return { d_2, p / d_2 };
			}
		}
	}
	cout << p << " is maybe prime, nothing found ( :) / :( ? )" << endl;
	return pair(1, p);
}*/