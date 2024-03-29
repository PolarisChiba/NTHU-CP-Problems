#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int SIZE = 200'000;
const int P = 1'000'000'000;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int n = 1, m = SIZE;
    if (a) swap(n, m);
    int v = (b ? P : -P);
	
    cout << n << " " << m << "\n";
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            cout << v << " \n"[j == m - 1];
        }
    }
}
