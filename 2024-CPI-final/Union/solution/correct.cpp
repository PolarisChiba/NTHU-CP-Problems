#include <bits/stdc++.h>
#define debug(a) cout << #a << " = " << a << "\n";
using namespace std;
 
typedef long long ll;
const ll MOD = 1000000007LL;
const int N = 1000000;
 
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    SegTree seg = SegTree(2 * N + 9);

    while ( n -- ) {
        int x1, x2, val;
        cin >> x1 >> x2 >> val;
        seg.modify(x1 + N + 1, x2 + N + 1 - 1, val);
        cout << seg.query() << "\n";
    }
}