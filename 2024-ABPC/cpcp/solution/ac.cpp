#include<bits/stdc++.h>
#define debug(a) cout << #a << " = " << a << "\n";
using namespace std;

typedef long long ll;
const ll MOD = 1000000007LL;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n), b(n);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;

	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());

	auto Check = [&a, &b, &k](int t) -> bool {
		ll sum = 0;
		for (int i = 0; i < t; ++ i)
			sum += a[i] * b[i];
		return (sum >= k);
	};

	if (k == 0) {
		cout << "0\n";
		return 0;
	}
	if (!Check(n)) {
		cout << "-1\n";
		return 0;
	}

	int l = 0, r = n;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (Check(mid))
			r = mid;
		else
			l = mid;
	}

	cout << r << "\n";
}
