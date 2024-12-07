#include <iostream>
#include "testlib.h"
using namespace std;

const int MAXN = 100'000;
const int MAXA = 1'000'000'000;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int n = MAXN - rnd.next(1, 100);

	cout << n << "\n";
	for (int i = 0; i < n; ++ i) {
		cout << rnd.next(1, MAXA) << "\n";
	}
	
	return 0;
}
