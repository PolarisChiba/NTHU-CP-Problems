#include<bits/stdc++.h>
#define debug(a) cout << #a << " = " << a << "\n";
using namespace std;

typedef long long ll;
const int MOD = 1000000007LL;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &i : v) cin >> i;

	vector<int> f((1 << n), 0);
	vector<int> g((1 << n), 1);

	for (int i = 1; i < (1 << n); ++ i) {
		int b = __lg(i & -i);
		f[i] = f[i - (1 << b)] + v[b];
		if (f[i] > MOD) f[i] -= MOD;
		g[i] = g[i - (1 << b)] * v[b] % MOD;
	}
	ll ans = 0;
	for (auto &i : f) ans ^= i;
	for (auto &i : g) ans ^= i;

	cout << ans << "\n";
}
