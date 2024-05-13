#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	vector<bool> b((1 << 20), false);
	vector<int> f((1 << 20), 0), g((1 << 20), 0);
	for (int i = 0; i < n; ++ i) {
		int x;
		cin >> x;
		b[x] = true;
		f[x] = g[((1 << 20) - 1) ^ x] = 1;
	}
	for (int i = 1; i < (1 << 20); ++ i) {
		for (int j = 0; j < 20; ++ j) {
			if ((i >> j) & 1) {
				f[i] += f[i ^ (1 << j)];
				g[i] += g[i ^ (1 << j)];
			}
		}
		f[i] = min(f[i], 2);
		g[i] = min(g[i], 2);
	}
	for (int i = 0; i < (1 << 20); ++ i) {
		if (b[i] && f[i] >= 2 && g[((1 << 20) - 1) ^ i] >= 2) {
			return cout << "love triangle\n", 0;
		}
	}
	cout << "peace\n";
}