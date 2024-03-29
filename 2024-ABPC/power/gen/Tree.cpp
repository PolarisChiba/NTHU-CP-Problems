#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N = 3000;

vector<vector<int>> components(int d) {
    vector<int> z(d);
    for (auto &i : z) i = rnd.next(1, 100);
    int sum = accumulate(z.begin(), z.end(), 0, plus<int>());
    
    vector<vector<int>> t(d);
    for (int i = 0; i < N; ++ i) {
        int p = rnd.next(1, sum);
        for (int j = 0; j < d; ++ j) {
            p -= z[j];
            if (p <= 0) {
                t[j].push_back(i);
                break;
            }
        }
    }
    return t;
}

vector<vector<int>> M(N, vector<int>(N));
void RandomTree(vector<int> &sig) {
    int n = (int)sig.size();
    if (n <= 1) return;
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
    
    for (auto &i : v) {
        int a = i.first;
        int b = i.second;
        M[sig[a]][sig[b]] = M[sig[b]][sig[a]] = 1;
    }
}

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

    int d = atoi(argv[1]);

    vector<vector<int>> t = components(d);
    for (auto &i : t) RandomTree(i);

    cout << N << "\n";
    for (int i = 0; i < N; ++ i) {
        for (int j = i + 1; j < N; ++ j) {
            cout << M[i][j] << " \n"[j == N - 1];
        }
    }
}
