#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N = 3000;

int p, v;

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

// each edges is generated randomly and independently
vector<vector<int>> M(N, vector<int>(N));
void edgeRandom(vector<int> &v, int p, int c) {
    for (auto &i : v) {
        for (auto &j : v) {
            if (i == j) continue;
            M[i][j] = (rnd.next(1, p) <= c ? 1 : 0);
        }
    }
}

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

    int p = atoi(argv[1]);
    int c = atoi(argv[2]);
    int d = atoi(argv[3]);

    vector<vector<int>> t = components(d);
    for (auto &i : t) edgeRandom(i, p, c);
	
    cout << N << "\n";
    for (int i = 0; i < N; ++ i) {
        for (int j = i + 1; j < N; ++ j) {
            cout << M[i][j] << " \n"[j == N - 1];
        }
    }
}
