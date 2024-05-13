#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0); cin.tie(0);
	registerGen(argc, argv, 1);

	int n = 3e5 - rnd.next(0, 100);
	// int n;
	// cin >> n;
	cout << 2 * n - 1 << "\n";

	vector<int> t2(2 * n - 1);
	t2[0] = -1;
	t2[1] = t2[2] = 0;
	queue<int> parent;
	parent.push(1);
	parent.push(2);
	vector<bool> is_parent(2 * n - 1);
	is_parent[0] = true;
	for (int i = 3; i < 2 * n - 1; i += 2) {
		int p = parent.front();
		parent.pop();
		is_parent[p] = true;
		t2[i] = t2[i + 1] = p;
		parent.push(i);
	}

	vector<vector<int>> v(2 * n - 1);
	for (int i = 1; i < 2 * n - 1; ++ i) v[t2[i]].push_back(i);

	vector<int> leaf;
	vector<int> internal;
	function<void(int)> Dfs = [&](int u) -> void {
		if (v[u].empty()) leaf.push_back(u);
		else internal.push_back(u);
		for (int &i : v[u])
			Dfs(i);
	};
	Dfs(0);
	shuffle(internal.begin(), internal.end());

	vector<int> idx2 = move(leaf);
	idx2.insert(idx2.end(), internal.begin(), internal.end());
	vector<int> ridx2(2 * n - 1);
	for (int i = 0; i < 2 * n - 1; ++ i) ridx2[idx2[i]] = i;
	
	vector<int> t1(2 * n - 1);
	t1[0] = -1;
	int p1 = 0;
	for (int i = 1; i < 2 * n - 1; i += 2, ++ p1) {
		t1[i] = t1[i + 1] = p1;
	}
	vector<int> idx1(2 * n - 1);
	iota(idx1.begin(), idx1.begin() + n, p1);
	iota(idx1.begin() + n, idx1.end(), 0);
	shuffle(idx1.begin() + n, idx1.end());
	for (int i = 1; i + n / 2 < n; i += 2) swap(idx1[i], idx1[i + n / 2]);
	vector<int> ridx1(2 * n - 1);
	for (int i = 0; i < 2 * n - 1; ++ i) ridx1[idx1[i]] = i;

	for (int i = 0; i < 2 * n - 1; ++ i) {
		int p = t1[idx1[i]];
		if (p != -1) p = ridx1[p];
		cout << p + 1 << " \n"[i == 2 * n - 2];
	}
	for (int i = 0; i < 2 * n - 1; ++ i) {
		int p = t2[idx2[i]];
		if (p != -1) p = ridx2[p];
		cout << p + 1 << " \n"[i == 2 * n - 2];
	}


	return 0;
}
