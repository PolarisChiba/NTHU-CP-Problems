#include<bits/stdc++.h>
#define debug(a) cout << #a << " = " << a << "\n";
using namespace std;

typedef long long ll;
const ll MOD = 1000000007LL;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> v(n);
	for (int i = 0; i < n; ++ i) {
		for (int j = i + 1; j < n; ++ j) {
			int x;
			cin >> x;
			if (x) {
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}

	vector<int> sig(n, 0);
	int now = 0;
	function<void(int)> Dfs = [&sig, &v, &now, &Dfs](int u) -> void {
		sig[u] = now;
		for (auto &i : v[u]) if (!sig[i]) Dfs(i);
	};

	for (int i = 0; i < n; ++ i) {
		if (!sig[i]) {
			++ now;
			Dfs(i);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			ans += (sig[i] == sig[j]);
		}
	}
	cout << ans << "\n";
}
