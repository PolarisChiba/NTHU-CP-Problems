#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0); cin.tie(0);
	registerGen(argc, argv, 1);
	
	int n = 100000 - rnd.next(0, 100);
	int d = atoi(argv[1]);
	int k = atoi(argv[2]);

	cout << n << " " << d << " " << k << "\n";

	vector<int> t(d);
	for (auto &i : t) i = rnd.next(1, 100);
	for (int i = 0; i < d; ++ i) {
		cout << t[i] << " \n"[i == d - 1];
	}

	int a = min(atoi(argv[3]), n);
	if (a < 0)
		a = rnd.next(0, n);

	vector<vector<int>> s(n, vector<int>(d));
	int step = (int)(1e9 - 100) / (n + 1);
	int now = step;
	for (int i = 0; i < a; ++ i, now += step) {
		vector<int> r(d);
		fill_n(r.begin(), k, 1);
		shuffle(r.begin(), r.end());
		for (int j = 0; j < d; ++ j) {
			if (r[j])
				s[i][j] = rnd.next(1, min(now, t[j]));
			else
				s[i][j] = rnd.next(1, now);
		}
		for (int j = 0; j < d; ++ j)
			t[j] = max(t[j], s[i][j]);
	}
	for (int i = a; i < n; ++ i) {
		vector<int> r(d);
		fill_n(r.begin(), d - k + 1, 1);
		shuffle(r.begin(), r.end());
		for (int j = 0; j < d; ++ j) {
			if (r[j])
				s[i][j] = rnd.next(t[j] + 1, (int)1e9);
			else
				s[i][j] = rnd.next(1, now);
		}
	}
	shuffle(s.begin(), s.end());
	for (auto &z : s) {
		for (int j = 0; j < d; ++ j)
			cout << z[j] << " \n"[j == d - 1];
	}
}
