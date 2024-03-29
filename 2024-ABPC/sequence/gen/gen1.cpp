#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N = 100'000;
const int P = 1'000'000;

typedef long long ll;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	
    vector<ll> a(N), b(N);
    for (auto &i : a) i = rnd.next(0, P);
    for (auto &i : b) i = rnd.next(0, P);
    
    ll sum = 0;
    for (int i = 0; i < N; ++ i)
        sum += a[i] * b[i];

    ll k = (argc == 3 ? atoll(argv[2]) : rnd.next(0LL, sum));
    
    cout << N << " " << k << "\n";
    for (int i = 0; i < N; ++ i)
        cout << a[i] << " \n"[i == N - 1];
    for (int i = 0; i < N; ++ i)
        cout << b[i] << " \n"[i == N - 1];
}
