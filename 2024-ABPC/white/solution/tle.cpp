#include<bits/stdc++.h>
#define debug(a) cout << #a << " = " << a << "\n";
using namespace std;

typedef long long ll;
const int MOD = 1000000007LL;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto &i : v) cin >> i;

	vector<ll> f((1 << n), 0);
	vector<ll> g((1 << n), 1);

	for (int i = 0; i < (1 << n); ++ i) {
		for (int j = 0; j < n; ++ j) {
			if ((i >> j) & 1) {
				f[i] += v[j];
				g[i] = g[i] * v[j] % MOD;
			}
			f[i] %= MOD;
		}
	}
	ll ans = 0;
	for (auto &i : f) ans ^= i;
	for (auto &i : g) ans ^= i;

	cout << ans << "\n";
}
