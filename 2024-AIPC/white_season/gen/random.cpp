#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0); cin.tie(0);
	registerGen(argc, argv, 1);
	
	int n = (argc >= 3 ? atoi(argv[2]) : 100000 - rnd.next(1, 100));
	cout << n << endl;

	unordered_set<int> s;
	while ((int)s.size() < n) {
		s.insert(rnd.next(1, (int)1e6));
	}
	vector<int> v(s.begin(), s.end());
	for (int i = 0; i < n; ++ i) {
		cout << v[i] << " \n"[i == n - 1];
	}

	return 0;
}
