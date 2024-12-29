#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100'000;
const int MAXW = 1'000;

// 0-based
vector<pair<int, int>> RandomTree(int n) {
    vector<pair<int, int>> v;

    vector<int> t;
    set<int> s;
    multiset<int> tt;
    for (int i = 1; i <= n - 2; ++ i) t.push_back(rnd.next(0, n - 1));
    for (int i = 0; i < n; ++ i) s.insert(i);
    for (auto i : t) {
        if (s.find(i) != s.end()) s.erase(s.find(i));
        tt.insert(i);
    }
    for (auto i : t) {
        auto it = s.begin();
        v.push_back({*it, i});
        s.erase(it);
        tt.erase(tt.find(i));
        if (tt.find(i) == tt.end())
            s.insert(i);
    }
    v.push_back({*s.begin(), *s.rbegin()});
    return v;
}

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

    ios::sync_with_stdio(0);
    cin.tie(0);

	int n = MAXN - rnd.next(1, 100);

	cout << n << "\n";
    auto tree = RandomTree(n);
	for (auto [a, b] : tree) {
        cout << a + 1 << " " << b + 1 << " " << rnd.next(-MAXW, MAXW) << "\n";
    }
	
	return 0;
}
