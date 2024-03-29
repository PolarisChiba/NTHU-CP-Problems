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
		for (int j = 0; j < m; ++ j) {
			ll sum = 0;
			for (int k = j; k >= 0; -- k) {
				f[i][j] = max(f[i][j], v[i][j] + sum + f[i - 1][k]);
				sum += v[i - 1][k];
			}
			sum = 0;
			for (int k = j; k < m; ++ k) {
				f[i][j] = max(f[i][j], v[i][j] + sum + f[i - 1][k]);
				sum += v[i - 1][k];
			}
		}
	}
	ll ans = -1e18, sum = 0;
	for (int i = 0; i < m; ++ i) {
		ans = max(ans, sum + f[n - 1][i]);
		sum += v[n - 1][i];
	}
	cout << ans << "\n";
}
