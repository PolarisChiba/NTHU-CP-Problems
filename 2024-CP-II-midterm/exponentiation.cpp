#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    const int mod = 1e9 + 7;

    while (n -- ) {
        long long a;
        int b;
        cin >> a >> b;

        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        cout << res << "\n";
    }
}