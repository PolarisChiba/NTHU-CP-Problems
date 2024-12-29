#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> tree(n);
    for (int i = 0; i < n - 1; ++ i) {
        int a, b, w;
        cin >> a >> b >> w;
        tree[a - 1].emplace_back(b - 1, w);
        tree[b - 1].emplace_back(a - 1, w);
    }

    pair<int, int> far{-1e9, -1};
    vector<int> dis(n, -1e9);
    auto Compute = [&](int u, int pa, auto&& Dfs) -> void {
        if (far.first < dis[u]) {
            far = make_pair(dis[u], u);
        }
        for (auto [child, weight] : tree[u]) {
            if (child == pa) continue;
            dis[child] = dis[u] + weight;
            Dfs(child, u, Dfs);
        }
    };
    
    dis[0] = 0;
    Compute(0, -1, Compute);

    dis.assign(n, -1e9);
    dis[far.second] = 0;
    far.first = -1e9;
    Compute(far.second, -1, Compute);

    cout << far.first << "\n";
}