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
void link(vector<int> &v) {
    shuffle(v.begin(), v.end());
    for (int i = 0; i < (int)v.size() - 1; ++ i) {
        M[v[i]][v[i + 1]] = M[v[i + 1]][v[i]] = 1;
    }
}

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

    int d = atoi(argv[1]);

    vector<vector<int>> t = components(d);
    for (auto &i : t) link(i);

    cout << N << "\n";
    for (int i = 0; i < N; ++ i) {
        for (int j = i + 1; j < N; ++ j) {
            cout << M[i][j] << " \n"[j == N - 1];
        }
    }
}
