#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	registerValidation();
	
	int n = inf.readInt(1, 100000, "n");
	inf.readSpace();
	int d = inf.readInt(1, 5, "d");
	inf.readSpace();
	inf.readInt(1, d, "k");
	inf.readEoln();

	for (int i = 0; i < d; ++ i) {
		inf.readInt(1, 100, "t");
		if (i < d - 1)
			inf.readSpace();
		else
			inf.readEoln();
	}
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < d; ++ j) {
			inf.readInt(1, (int)1e9, "s");
			if (j < d - 1)
				inf.readSpace();
			else
				inf.readEoln();
		}
	}
	
	inf.readEof();

	return 0;
}
