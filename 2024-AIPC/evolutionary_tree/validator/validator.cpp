#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	registerValidation();
	
	int n = inf.readInt(1, (int)3e5 * 2 - 1, "n");
	n = (n + 1) / 2;
	inf.readEoln();

	auto Check = [&n]() -> void {
		int r = -1e9;
		vector<vector<int>> v(2 * n - 1);
		for (int i = 0; i < 2 * n - 1; ++ i) {
			int p = inf.readInt(0, 2 * n - 1, "p") - 1;
			if (i < 2 * n - 2)
				inf.readSpace();
			else
				inf.readEoln();
			if (p != -1) v[p].push_back(i);
			else r = i;
		}
		for (int i = 0; i < n; ++ i)
			ensure(v[i].empty());
		for (int i = n; i < 2 * n - 1; ++ i)
			ensure(v[i].size() == 2u);

		int cnt = 0;
		function<void(int)> Dfs = [&cnt, &v, &Dfs](int u) -> void {
			++ cnt;
			for (auto &i : v[u]) Dfs(i);
		};
		Dfs(r);
		ensure(cnt == 2 * n - 1);
	};

	Check();
	Check();

	inf.readEof();

	return 0;
}
