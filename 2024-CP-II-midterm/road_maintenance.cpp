#include <bits/stdc++.h>
using namespace std;

struct MaxFlow {
    struct edge {
        int to, cap, flow, rev;
    };
    vector<edge> G[509];
    int s, t, dis[509], cur[509], n;
 
    int dfs(int u, int cap) {
        if (u == t || cap == 0) return cap;
        for (int &i = cur[u]; i < (int)G[u].size(); ++ i) {
            edge &e = G[u][i];
            if (dis[e.to] == dis[u] + 1 && e.flow != e.cap) {
                int df = dfs(e.to, min(e.cap - e.flow, cap));
                if (df) {
                    e.flow += df;
                    G[e.to][e.rev].flow -= df;
                    return df;
                }
            }
        }
        dis[u] = -1;
        return 0;
    }
 
    bool bfs() {
        fill_n(dis, n, -1);
        queue<int> q;
        q.push(s), dis[s] = 0;
        while (!q.empty()) {
            int tmp = q.front(); q.pop();
            for (auto &u : G[tmp]) {
                if (dis[u.to] == -1 && u.flow != u.cap) {
                    q.push(u.to);
                    dis[u.to] = dis[tmp] + 1;
                }
            }
        }
        return dis[t] != -1;
    }
 
    int maxflow(int _s, int _t) {
        s = _s, t = _t;
        int flow = 0, df;
        while (bfs()) {
            fill_n(cur, n, 0);
            while ((df = dfs(s, 1e9))) flow += df;
        }
        return flow;
    }
 
    void init(int _n) {
        n = _n;
        for(int i = 0; i < n; ++ i) G[i].clear();
    }
 
    void add_edge(int u, int v, int cap) {
        G[u].push_back(edge{v, cap, 0, (int)G[v].size()});
        G[v].push_back(edge{u, 0, 0, (int)G[u].size() - 1});
    }
}dinic;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    dinic.init(n);
    while ( m -- ) {
        int a, b;
        cin >> a >> b;
        dinic.add_edge(a - 1, b - 1, 1);
    }

    cout << max(k + 1 - dinic.maxflow(0, n - 1), 0) << "\n";
}