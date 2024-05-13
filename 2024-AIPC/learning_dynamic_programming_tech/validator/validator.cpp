#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	registerValidation();
	
	int n = inf.readInt(1, 5000, "n");
	inf.readEoln();
	for (int i = 0; i < n; ++ i) {
		inf.readInt(1, (int)1e9, "w");
		if (i < n - 1)
			inf.readSpace();
		else
			inf.readEoln();
	}

	inf.readEof();

	return 0;
}
