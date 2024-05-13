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
	void unite(int x, int y) {
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

	vector<vector<int>> p(__lg(n) + 1, vector<int>(n));
	int t = 0;
	vector<int> in(n), out(n);
	p[0][r2] = r2;
	function<void(int)> Dfs = [&](int u) -> void {
		for (int i = 1; i <= __lg(n); ++ i) p[i][u] = p[i - 1][p[i - 1][u]];
		in[u] = ++ t;
		for (auto &i : v2[u]) {
			p[0][i] = u;
			Dfs(i);
		}
		out[u] = ++ t;
	};
	Dfs(r2);
	auto isfa = [&in, &out](int a, int b) -> bool {
		return in[a] <= in[b] && out[b] <= out[a];
	};
	auto Lca = [&](int a, int b) -> int {
		if (isfa(a, b)) return a;
		for (int i = __lg(n); i >= 0; -- i) {
			if (!isfa(p[i][a], b))
				a = p[i][a];
		}
		return p[0][a];
	};

	vector<int> ans(n);
	function<void(int)> Dfs1 = [&](int u) -> void {
		if (0 <= u && u < (n + 1) / 2) {
			ans[u] = u;
		} else {
			Dfs1(v1[u][0]);
			Dfs1(v1[u][1]);
			ans[u] = Lca(ans[v1[u][0]], ans[v1[u][1]]);
		}
	};
	Dfs1(r1);

	for (int i = 0; i < n; ++ i)
		cout << ans[i] + 1 << " \n"[i == n - 1];

}