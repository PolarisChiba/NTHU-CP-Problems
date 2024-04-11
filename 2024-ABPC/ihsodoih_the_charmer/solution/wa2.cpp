#include<bits/stdc++.h>
#define debug(a) cout << #a << " = " << a << "\n";
using namespace std;

typedef long long ll;
const ll MOD = 1000000007LL;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<ll>> v(n, vector<ll>(m));
	for (auto &i : v) {
		for (auto &j : i) 
			cin >> j;
	}
	
	vector<vector<ll>> f(n, vector<ll>(m, -1e18));
	f[0] = v[0];
	for (int i = 1; i < n; ++ i) {
		ll p = 0;
		for (int j = 0; j < m; ++ j) {
			p = max(p + v[i - 1][j], f[i - 1][j]);
			f[i][j] = v[i][j] + p;
		}
		p = 0;
		for (int j = m - 1; j >= 0; -- j) {
			p = max(p + v[i - 1][j], f[i - 1][j]);
			f[i][j] = max(f[i][j], v[i][j] + p);
		}
	}
	ll ans = -1e18, sum = 0;
	for (int i = 0; i < m; ++ i) {
		ans = max(ans, sum + f[n - 1][i]);
		sum += v[n - 1][i];
	}
	cout << ans << "\n";
}
