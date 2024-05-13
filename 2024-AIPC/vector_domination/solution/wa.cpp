#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, d, k;
	cin >> n >> d >> k;
	vector<int> t(d);
	for (auto &i : t) cin >> i;
	
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < d; ++ j) {
			int x;
			cin >> x;
			t[j] = max(t[j], x);
		}
	}

	for (auto &i : t)
		cout << i << " ";
	cout << "\n";
}