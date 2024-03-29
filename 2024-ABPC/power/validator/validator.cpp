#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int SIZE = 3'000;

int main() {
	registerValidation();

	int n = inf.readInt(1, SIZE, "n");
	inf.readEoln();

	for (int i = 0; i < n; ++ i) {
        for (int j = i + 1; j < n; ++ j) {
			inf.readInt(0, 1, "p");
			if (j < n - 1)
				inf.readSpace();
			else 
				inf.readEoln();
		}
	}
	inf.readEof();

	return 0;
}
