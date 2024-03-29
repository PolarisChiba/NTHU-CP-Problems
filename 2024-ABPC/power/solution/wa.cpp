#include<bits/stdc++.h>
#define debug(a) cout << #a << " = " << a << "\n";
using namespace std;

typedef long long ll;
const ll MOD = 1000000007LL;
const int N = 3000;

#define matrix vector<bitset<N>>

int n;

inline void mul(matrix &a, matrix &b) {
    matrix res(n, bitset<N>());
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
            res[i][j] = (a[i] & b[j]).any();
    a = move(res);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

    matrix v(n, bitset<N>());
    for (int i = 0; i < n; ++ i)
        v[i][i] = 1;

	for (int i = 0; i < n; ++ i) {
		for (int j = i + 1; j < n; ++ j) {
            int x;
            cin >> x;
            v[i][j] = v[j][i] = x;
		}
	}

    mul(v, v);
    mul(v, v);
    int ans = 0;
    for (auto &i : v) ans += i.count();
    cout << ans << "\n";
}
