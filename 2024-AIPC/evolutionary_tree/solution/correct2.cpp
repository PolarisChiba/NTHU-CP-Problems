#include <bits/stdc++.h>
#define debug(a) cout << #a << " = " << a << "\n";
using namespace std;

struct Dsu {
	vector<int> fa;
	Dsu(int n = 0): fa(n) {
		iota(fa.begin(), fa.end(), 0);
	}
	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	inline void unite(int x, int y) {
		fa[find(y)] = find(x);
	}
}dsu;

int n;
int r1 = -1, r2 = -1;
vector<int> v1[600000], v2[600000];

int leaf_label[300000];
int cur_label = 0;
void DfsT2(int u) {
	if (2 * u < n + 1) return leaf_label[u] = cur_label ++, void();
	for (auto &i : v2[u])
		DfsT2(i);
}

pair<int, int> mxn[600000];
vector<pair<int, int>> query[300000];
int ans[600000];
void DfsT1(int u) {
	if (2 * u < n + 1) {
		mxn[u] = make_pair(u, u);
		ans[u] = u;
		return;
	}
	mxn[u] = make_pair(-1, -1);
	for (auto &i : v1[u]) {
		DfsT1(i);
		if (mxn[u].first == -1 || leaf_label[mxn[i].first] > leaf_label[mxn[u].first])
			mxn[u].first = mxn[i].first;
		if (mxn[u].second == -1 || leaf_label[mxn[i].second] < leaf_label[mxn[u].second])
			mxn[u].second = mxn[i].second;
	}
	query[mxn[u].first].emplace_back(mxn[u].second, u);
}

void TarjanT2(int u) {
	if (2 * u < n + 1) {
		for (auto &q : query[u]) {
			ans[q.second] = dsu.find(q.first);
		}
	}
	for (auto &i : v2[u]) {
		TarjanT2(i);
		dsu.unite(u, i);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
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

	DfsT2(r2);
	DfsT1(r1);
	dsu = Dsu(n);
	TarjanT2(r2);

	for (int i = 0; i < n; ++ i)
		cout << ans[i] + 1 << " \n"[i == n - 1];
}