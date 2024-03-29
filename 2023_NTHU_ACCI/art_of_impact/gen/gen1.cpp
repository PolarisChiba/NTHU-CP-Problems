#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

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

// 0-based
vector<pair<int, int>> RandomSparseConnectedGraph(int n, int m) {
    // n - 1 <= m

    auto v = RandomTree(n);
    set<pair<int, int>> s;
    for (auto i : v) s.insert(i);

    while ((int)v.size() < m) {
        int a = rnd.next(0, n - 1);
        int b = rnd.next(0, n - 1);
        if (a == b || s.find({a, b}) != s.end() || s.find({b, a}) != s.end()) continue;
        
        v.push_back({a, b});
        s.insert({a, b});
    }
    return v;
}

// 0-based
vector<pair<int, int>> RandomDenseConnectedGraph(int n, int m) {
    // n - 1 <= m
    // m close to n*(n-1)/2

    auto v = RandomTree(n);
    set<pair<int, int>> s;
    for (auto i : v) s.insert(i);

    vector<pair<int, int>> u;
    for (int i = 0; i < n; ++ i)
        for (int j = i + 1; j < n; ++ j)
            if (s.find({i, j}) == s.end() && s.find({j, i}) == s.end())
                u.push_back({i, j});

    shuffle(u.begin(), u.end());
    for (int i = n; i <= m; ++ i) v.push_back(u[i - n]);

    return v;
}


int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	println(n, m);

	set<int> s;
	while ((int)s.size() < n) {
		s.insert(rnd.next(1, 1'000'000'000));
	}
	vector<int> p(s.begin(), s.end());
	shuffle(p.begin(), p.end());
	println(p);

    vector<pair<int, int>> v;
    if (m <= 2 * n) {
        v = RandomSparseConnectedGraph(n, m);
    } else {
        v = RandomDenseConnectedGraph(n, m);
	}
	shuffle(v.begin(), v.end());
	for (auto i : v)
		println(i.first + 1, i.second + 1);
}
