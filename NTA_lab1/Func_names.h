#pragma once
#include <iostream>
#include <cmath>
#include <unordered_set>
#include <random>
#include <fstream>
#include <vector>
#include <cstdint>

using namespace std;

pair<uint64_t, uint64_t> lob(uint64_t p);

uint64_t gcd(uint64_t x, uint64_t p);

void SSh(uint64_t p, int tochnist, pair<uint64_t, uint64_t> c);

pair<uint64_t, uint64_t> Pol(uint64_t p, uint64_t x_0, vector<unsigned int> f);

pair<uint64_t, uint64_t> B_M(uint64_t p);
