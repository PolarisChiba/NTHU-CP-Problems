#include <bits/stdc++.h>
#define debug(a) cout << #a << " = " << a << "\n";
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> tree(n);
    for (int i = 0; i < n - 1; ++ i) {
        int a, b, w;
        cin >> a >> b >> w;
        tree[a - 1].emplace_back(b - 1, w);
        tree[b - 1].emplace_back(a - 1, w);
    }
    
    vector<int> f(n, 0);
    auto ComputeBottom = [&](int u, int pa, auto&& Dfs) -> void {
        for (auto [child, weight] : tree[u]) {
            if (child == pa) {
                continue;
            }
            Dfs(child, u, Dfs);
            f[u] = max(f[u], f[child] + weight);
        }
    };
    ComputeBottom(0, -1, ComputeBottom);

    vector<int> g(n, 0);
    auto ComputeTop = [&](int u, int pa, auto&& Dfs) -> void {
        pair<int, int> best{-1e9, -1};
        pair<int, int> secBest{-1e9, -1};
        for (auto [child, weight] : tree[u]) {
            if (child == pa) continue;
            if (best.first < f[child] + weight) {
                secBest = best;
                best = make_pair(f[child] + weight, child);
            } else {
                secBest = min(secBest, make_pair(f[child] + weight, child));
            }
        }
        for (auto [child, weight] : tree[u]) {
            if (child == pa) continue;
            g[child] = max(initializer_list<int>{
                g[child], 
                g[u] + weight, 
                (child == best.second ? secBest.first : best.first) + weight
            });
            Dfs(child, u, Dfs);
        }
    };
    ComputeTop(0, -1, ComputeTop);

    int ans = 0;
    for (int i = 0; i < n; ++ i)
        ans = max(ans, f[i] + g[i]);

    cout << ans << "\n";
}