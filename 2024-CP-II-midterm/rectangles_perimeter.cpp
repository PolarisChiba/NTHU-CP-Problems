#include <bits/stdc++.h>
#define debug(a) cout << #a << " = " << a << "\n";
using namespace std;

typedef long long ll;

struct SegTree {
    int n;
    struct Node {
        int v;
        int c;
        Node *l, *r;
        Node() {
            v = c = 0;
            l = r = 0;
        }
        void pull(int L, int R) {
            if (v) c = R - L + 1;
            else {
                c = 0;
                if (l) c += l->c;
                if (r) c += r->c;
            }
        }
    }*root;
    SegTree(int _n) : n(_n), root(NULL) {}
    void modify(Node* &O, int l, int r, int ql, int qr, int x) {
        if (qr < l || r < ql) return;
        if (O == NULL) O = new Node();
        if (ql <= l && r <= qr) {
            O->v += x;
            O->pull(l, r);
            return;
        }
        int mid = (l + r) >> 1;
        modify(O->l, l, mid, ql, qr, x);
        modify(O->r, mid + 1, r, ql, qr, x);
        O->pull(l, r);
    }
    int query() {
        return (root ? root->c : 0);
    }
    void modify(int ql, int qr, int x) {
        modify(root, 1, n, ql, qr, x);
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<array<ll, 4>> v(n);
    for (auto &i : v) {
        for (auto &j : i)
            cin >> j, j += 1e6 + 1;
    }

    auto Calc = [&](int l, int r, int d, int t, int ql = -1, int qr = -1) -> ll {
        if (ql != -1) {
            for (auto &i : v) {
                i[ql] = 2e6 + 2 - i[ql];
                i[qr] = 2e6 + 2 - i[qr];
            }
        }
        vector<vector<pair<ll, ll>>> z1(2e6 + 2), z2(2e6 + 2);
        for (auto &i : v) {
            z1[i[l]].emplace_back(i[d], i[t] - 1);
            z2[i[r]].emplace_back(i[d], i[t] - 1);
        }
        SegTree seg(2e6 + 2);
        int pre = 0;
        ll sum = 0;
        for (int i = 1; i <= 2e6 + 1; ++ i) {
            for (auto &[d, t] : z1[i]) {
                seg.modify(d, t, 1);
            }
            sum += seg.query() - pre;
            for (auto &[d, t] : z2[i]) {
                seg.modify(d, t, -1);
            }
            pre = seg.query();
        }
        if (ql != -1) {
            for (auto &i : v) {
                i[ql] = 2e6 + 2 - i[ql];
                i[qr] = 2e6 + 2 - i[qr];
            }
        }
        return sum;
    };
    ll ans = Calc(0, 2, 1, 3) + Calc(2, 0, 1, 3, 0, 2) + Calc(1, 3, 0, 2) + Calc(3, 1, 0, 2, 1, 3);
    cout << ans << "\n";

}
