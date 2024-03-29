#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef long long ll;

const int N = 100'000;
const int P = 1'000'000;
const ll K = 1'000'000'000'000'000'000LL;

int main() {
	registerValidation();

	int n = inf.readInt(1, N, "n");
	inf.readSpace();
	inf.readLong(0, K, "k");
	inf.readEoln();

	for (int _ = 0; _ < 2; ++ _) {
		for (int i = 0; i < n; ++ i) {
			inf.readInt(0, P, "p");
			if (i < n - 1)
				inf.readSpace();
			else
				inf.readEoln();
		}
	}
	inf.readEof();

	return 0;
}
