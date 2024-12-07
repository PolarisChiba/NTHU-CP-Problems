#include <iostream>
#include "testlib.h"
using namespace std;

const int MAXN = 100'000;
const int MAXA = 1'000'000'000;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int n = MAXN - rnd.next(1, 100);

	vector<int> v(n / 500);
	generate(v.begin(), v.end(), []() { return rnd.next(1, MAXA); });

	cout << n << "\n";
	for (int i = 0; i < n; ++ i) {
		cout << v[rnd.next(0, (int)v.size() - 1)] << "\n";
	}
	
	return 0;
}
