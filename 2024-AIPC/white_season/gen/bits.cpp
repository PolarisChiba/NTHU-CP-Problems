#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0); cin.tie(0);
	registerGen(argc, argv, 1);

	vector<int> bit_lens;
	for (int i = 1; i < argc; ++ i) 
		bit_lens.push_back(atoi(argv[i]));

	if (bit_lens.size() % 2 == 1u)	
		bit_lens.push_back(0);

	for (size_t i = 0; i < bit_lens.size(); i += 2)
		if (bit_lens[i] < bit_lens[i + 1])
			swap(bit_lens[i], bit_lens[i + 1]);
	
	vector<int> bits(20);
	iota(bits.begin(), bits.end(), 0);
	shuffle(bits.begin(), bits.end());

	vector<vector<int>> assigned_bits(bit_lens.size() / 2);
	auto cur_bit = bits.begin();
	for (size_t i = 0; i * 2 < bit_lens.size(); ++ i) {
		assigned_bits[i] = vector<int>(cur_bit, cur_bit + bit_lens[i * 2]);
		cur_bit += bit_lens[i * 2];
	}
	while (cur_bit != bits.end()) {
		assigned_bits[rnd.next(0, (int)assigned_bits.size() - 1)].push_back(*cur_bit);
		++ cur_bit;
	}

	for (size_t i = 0; i < assigned_bits.size(); ++ i) {
		for (size_t j = i + 1; j < assigned_bits.size(); ++ j) {
			for (auto &k : assigned_bits[i])
				for (auto &l : assigned_bits[j])
					assert(k != l);
		}
	}

	vector<int> testcase;
	auto AddNumber = [&testcase, &assigned_bits, &bit_lens](int i, int offset) -> void {
		vector<int> number(assigned_bits[i].size());
		fill(number.begin(), number.begin() + bit_lens[2 * i + offset], 1);
		do {
			int value = 0;
			for (size_t j = 0; j < number.size(); ++ j)
				value += number[j] * (1 << assigned_bits[i][j]);
			assert(__builtin_popcount(value) == bit_lens[2 * i + offset]);
			if (0 < value && value <= 1e6)
				testcase.push_back(value);
		} while (prev_permutation(number.begin(), number.end()));
	};

	for (size_t i = 0; i * 2 < bit_lens.size(); ++ i) {
		AddNumber(i, 0);
		AddNumber(i, 1);
	}

	shuffle(testcase.begin(), testcase.end());
	testcase.resize(min(testcase.size(), 100000lu));

	cout << testcase.size() << "\n";
	for (auto &i : testcase)
		cout << i << " \n"[i == testcase.back()];

	return 0;
}
