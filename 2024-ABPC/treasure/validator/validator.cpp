#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int SIZE = 200'000;
const int P = 1'000'000'000;

int main() {
	registerValidation();

	int n = inf.readInt(1, SIZE, "n");
	inf.readSpace();
	int m = inf.readInt(1, SIZE, "m");
	inf.readEoln();
	ensure(n * m <= SIZE);

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			inf.readInt(-P, P, "p");
			if (j < m - 1)
				inf.readSpace();
		}
		inf.readEoln();
	}
	inf.readEof();

	return 0;
}
