#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int tune;

// 0-based, without shffle labels, rooted at 0, parent[0] = -1
vector<int> BinaryTreeGen(int n) { 
	vector<int> pool(1, 0);
	vector<int> parent(2 * n - 1);
	parent[0] = -1;
	auto push = [&pool](int x) -> void {
		pool.push_back(x);
	};
	auto pop = [&pool]() -> int {
		int s = (int)pool.size();
		if (tune == -1)
			swap(pool[rnd.next(0, s - 1)], pool.back());
		else
			swap(pool[rnd.next(max(0, s - tune), s - 1)], pool.back());
		int x = pool.back();
		pool.pop_back();
		return x;
	};
	for (int i = 1; i < 2 * n - 1; i += 2) {
		int p = pop();
		parent[i] = p;
		parent[i + 1] = p;
		push(i);
		push(i + 1);
	}
	return parent;
}

vector<int> tGen(int n) {
	auto parent = BinaryTreeGen(n);
	vector<int> deg(2 * n - 1);
	for (int i = 1; i < 2 * n - 1; ++ i) {
		deg[parent[i]] ++;
	}

	vector<int> ord1(n);
	vector<int> ord2(n - 1);
	iota(ord1.begin(), ord1.end(), 0);
	iota(ord2.begin(), ord2.end(), n);
	shuffle(ord1.begin(), ord1.end());
	shuffle(ord2.begin(), ord2.end());
	
	vector<int> res(2 * n - 1);
	for (int i = 0; i < 2 * n - 1; ++ i) {
		if (deg[i] == 0) res[i] = ord1.back(), ord1.pop_back();
		else res[i] = ord2.back(), ord2.pop_back();
	}

	vector<int> cop = parent;
	for (int i = 0; i < 2 * n - 1; ++ i) {
		if (cop[i] != -1)
			parent[res[i]] = res[cop[i]];
		else
			parent[res[i]] = -1;
	}
	return parent;
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0); cin.tie(0);
	registerGen(argc, argv, 1);

	tune = (argc >= 3 ? atoi(argv[2]) : -1);

	int n = (strcmp(argv[1], "-1") == 0 ? 7 : 3e5 - rnd.next(0, 100));
	cout << 2 * n - 1 << "\n";

	vector<int> p1 = tGen(n), p2 = tGen(n);
	for (int i = 0; i < 2 * n - 1; ++ i) {
		cout << p1[i] + 1 << " \n"[i == 2 * n - 2];
	}
	for (int i = 0; i < 2 * n - 1; ++ i) {
		cout << p2[i] + 1 << " \n"[i == 2 * n - 2];
	}

	return 0;
}
