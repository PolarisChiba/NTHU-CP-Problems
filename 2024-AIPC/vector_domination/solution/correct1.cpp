#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, d, k;
	cin >> n >> d >> k;
	vector<int> t(d);
	for (auto &i : t) cin >> i;
	vector<pair<vector<int>, int>> s(n, make_pair(vector<int>(d), 0));
	for (int i = 0; i < n; ++ i) {
		s[i].second = i;
		for (auto &j : s[i].first)
			cin >> j;
	}
	
	vector<vector<pair<vector<int>, int>>> z(d);
	for (int i = 0; i < d; ++ i) {
		z[i] = s;
		sort(z[i].begin(), z[i].end(), [&i](const pair<vector<int>, int> &a, const pair<vector<int>, int> &b) {
			return a.first[i] > b.first[i];
		});
	}

	vector<int> cnt(n, 0);
	while (true) {
		bool ok = false;
		for (int p = 0; p < d; ++ p) {
			while (!z[p].empty() && z[p].back().first[p] <= t[p]) {
				ok = true;
				int id = z[p].back().second;
				cnt[id] ++;
				if (cnt[id] == k) {
					for (int i = 0; i < d; ++ i) {
						t[i] = max(t[i], z[p].back().first[i]);
					}
				}
				z[p].pop_back();
			}
		}
		if (!ok) break;
	}

	for (auto &i : t)
		cout << i << " ";
	cout << "\n";
}