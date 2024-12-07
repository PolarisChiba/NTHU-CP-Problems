#include <iostream>
#include "testlib.h"
using namespace std;

const int MAXN = 100'000;
const int MAXA = 1'000'000'000;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int n = MAXN - rnd.next(1, 100);
	int type = atoi(argv[1]);

	vector<int> v(n);
	generate_n(v.begin(), n, []() { return rnd.next(1, MAXA); });

	if (type) {
		sort(v.begin(), v.end());
	} else {
		sort(v.rbegin(), v.rend());
	}

	cout << n << "\n";
	for (auto i : v) {
		cout << i << "\n";
	}
	
	return 0;
}
