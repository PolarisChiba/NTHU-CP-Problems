#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	registerValidation();
	
	int n = inf.readInt(3, 100000, "n");
	inf.readEoln();
	
	unordered_set<int> s;
	for (int i = 0; i < n; ++ i) {
		s.insert(inf.readInt(1, 1e6, "s"));
		if (i < n - 1)
			inf.readSpace();
		else
			inf.readEoln();
	}
	ensure((int)s.size() == n);

	inf.readEof();

	return 0;
}
