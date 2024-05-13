#include <bits/stdc++.h>
#define debug(a) cout << #a << " = " << a << "\n";
using namespace std;

struct Dsu {
	vector<int> fa;
	Dsu(int n): fa(n) {
		iota(fa.begin(), fa.end(), 0);
	}
	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	inline void unite(int x, int y) {
		fa[find(y)] = find(x);
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	int r1 = -1, r2 = -1;
	vector<vector<int>> v1(n), v2(n);
	for (int i = 0; i < n; ++ i) {
		int p;
		cin >> p;
		-- p;
		if (p == -1) r1 = i;
		else v1[p].push_back(i);
	}
	for (int i = 0; i < n; ++ i) {
		int p;
		cin >> p;
		-- p;
		if (p == -1) r2 = i;
		else v2[p].push_back(i);
	}

	vector<int> ord((n + 1) / 2);
	int now = 0;
	function<void(int)> Dfs2 = [&n, &v2, &ord, &Dfs2, &now](int u) -> void {
		if (0 <= u && u < (n + 1) / 2) ord[u] = now ++;
		for (auto &i : v2[u]) Dfs2(i);
	};
	Dfs2(r2);

	vector<int> rez((n + 1) / 2);
	for (int i = 0; i < (n + 1) / 2; ++ i)
		rez[ord[i]] = i;

	vector<pair<int, int>> z(n, {1e9, -1e9});
	function<void(int)> Dfs1 = [&n, &v1, &ord, &z, &Dfs1](int u) -> void {
		if (0 <= u && u < (n + 1) / 2) {
			z[u] = make_pair(ord[u], ord[u]);
		}
		for (auto &i : v1[u]) {
			Dfs1(i);
			z[u].first = min(z[u].first, z[i].first);
			z[u].second = max(z[u].second, z[i].second);
		}
	};
	Dfs1(r1);

	vector<vector<pair<int, int>>> que(n);
	for (int i = 0; i < n; ++ i) {
		que[rez[z[i].second]].emplace_back(rez[z[i].first], i);
	}

	vector<int> ans(n);
	Dsu dsu(n);
	function<void(int)> Dfs = [&v2, &que, &dsu, &ans, &Dfs](int u) -> void {
		for (auto &i : v2[u]) {
			Dfs(i);
			dsu.unite(u, i);
		}
		for (auto &i : que[u]) {
			ans[i.second] = dsu.find(i.first);
		}
	};
	Dfs(r2);

	for (int i = 0; i < n; ++ i) {
		cout << ans[i] + 1 << " \n"[i == n - 1];
	}

}