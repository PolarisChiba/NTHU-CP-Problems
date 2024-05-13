#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0); cin.tie(0);
	registerGen(argc, argv, 1);

	int n = 5000 - rnd.next(1, 30);
	cout << n << "\n";

	for (int i = 0; i < n; ++ i) {
		cout << rnd.next(1, (int)1e9) << " \n"[i == n - 1];
	}

	return 0;
}
