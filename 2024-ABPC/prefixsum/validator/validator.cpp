#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 26;
const int MAXP = 1'000'000'000;

int main() {
	registerValidation();

	int n = inf.readInt(1, MAXN, "n");
	inf.readEoln();
	for (int i = 1; i <= n; ++ i) {
		inf.readInt(1, MAXP, "p");
		if (i < n) 
			inf.readSpace();
	}
	inf.readEoln();
	inf.readEof();

	return 0;
}
