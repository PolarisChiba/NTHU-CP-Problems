#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int SIZE = 200'000;
const int P = 1'000'000'000;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	
    int n = atoi(argv[1]);
    int m = SIZE / n;

    cout << n << " " << m << "\n";
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            cout << rnd.next(-P, P / 100) << " \n"[j == m - 1];
        }
    }
}
