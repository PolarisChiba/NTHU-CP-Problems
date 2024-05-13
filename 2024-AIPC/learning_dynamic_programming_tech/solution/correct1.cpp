#include <bits/stdc++.h>
#define debug(a) cout << #a << " = " << a << "\n";
using namespace std;
 
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
    cin >> n;
	vector<ll> w(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> w[i], w[i] += w[i - 1];
	
	vector<vector<ll>> f(n + 1, vector<ll>(n + 1, 1e18));
	vector<vector<int>> opt(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++ i) f[i][i] = 0, opt[i][i] = i;
 
    for (int l = 2; l <= n; ++ l) {
        for (int i = 1; l + i - 1 <= n; ++ i) {
            int j = l + i - 1;
            for (int k = opt[i][j - 1]; k <= min(opt[i + 1][j], j - 1); ++ k) {
                if (f[i][k] + f[k + 1][j] + w[j] - w[i - 1] < f[i][j]) {
                    f[i][j] = f[i][k] + f[k + 1][j] + w[j] - w[i - 1];
                    opt[i][j] = k;
                }
            }
        }
    }
    cout << f[1][n] << "\n";
}