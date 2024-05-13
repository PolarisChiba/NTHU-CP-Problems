#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0); cin.tie(0);
	registerGen(argc, argv, 1);

	int m = atoi(argv[1]);

	vector<int> b(1e6 + 1, 0);
	vector<int> v;
	for (int i = 1e6; i >= 1 && (int)v.size() < 300; -- i) {
		if (b[i] >= 2) continue;
		if (rnd.next(1, 200) <= m * __builtin_popcount(i)) {
			v.push_back(i);
			for (int j = i; j > 0; j = (j - 1) & i) {
				b[j] += 1 + b[i];
			}
		}
	}
	shuffle(v.begin(), v.end());
	
	cout << v.size() << "\n";
	for (int i = 0; i < (int)v.size(); ++ i) {
		cout << v[i] << " \n"[i == (int)v.size() - 1];
	}

	return 0;
}
