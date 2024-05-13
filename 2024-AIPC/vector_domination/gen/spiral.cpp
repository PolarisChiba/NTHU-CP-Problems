#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0); cin.tie(0);
	registerGen(argc, argv, 1);
	
	int n = 100000 - rnd.next(0, 100);
	int d = 5;
	int k = atoi(argv[1]);

	cout << n << ' ' << d << ' ' << k << '\n';

	vector<int> t(d);
	for (auto &i : t) 
		i = rnd.next(1, 100);	
	for (int i = 0; i < d; ++ i)
		cout << t[i] << " \n"[i == d - 1];

	vector<vector<int>> vecs(n, vector<int>(d, 0));
	int incLen = rnd.next(0, n);
	const int incVal = (1e9 - 100) / n - 10;
	vector<int> idx(d);
	iota(idx.begin(), idx.end(), 0);
	for (int i = 0; i < incLen; ++ i) {
		auto &vec = vecs[i];
		shuffle(idx.begin(), idx.end());
		for (int j = 0; j < k; ++ j) {
			t[idx[j]] += rnd.next(1, incVal);
			vec[idx[j]] = t[idx[j]];
		}
		for (int j = k; j < d; ++ j) {
			vec[idx[j]] = t[idx[j]] + rnd.next(1 - t[idx[j]], incVal);
			t[idx[j]] = max(t[idx[j]], vec[idx[j]]);
		}
	}
	for (int i = incLen; i < n; ++ i) {
		auto &vec = vecs[i];
		shuffle(idx.begin(), idx.end());
		for (int j = 0; j < k - 1; ++ j) {
			vec[idx[j]] = rnd.next(t[idx[j]], (int)1e9);
		}
		for (int j = k - 1; j < d; ++ j) {
			vec[idx[j]] = rnd.next(1, t[idx[j]]);
		}
	}
	shuffle(vecs.begin(), vecs.end());
	for (auto &vec : vecs) {
		for (int i = 0; i < d; ++ i)
			cout << vec[i] << " \n"[i == d - 1];
	}
}
