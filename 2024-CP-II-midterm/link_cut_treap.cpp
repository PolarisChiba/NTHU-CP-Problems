#include <bits/stdc++.h>
#define debug(a) cout << #a << " = " << a << "\n";
using namespace std;

struct node {
  int data, val, sz;
  node *l, *r, *p;
  node(int k) : data(k), val(k), sz(1), l(0), r(0), p(NULL) {}
  void up() {
    sz = 1;
    val = data;
    if (l) sz += l->sz, val = max(val, l->val);
    if (r) sz += r->sz, val = max(val, r->val);
  }
  void down() {}
}*root;
int sz(node *a) { return a ? a->sz : 0; }
node *merge(node *a, node *b) {
  if (!a || !b) return a ? a : b;
  if (rand() % (sz(a) + sz(b)) < sz(a)) {
    a->r = merge(a->r, b);
    a->r->p = a;
    a->up();
    return a;
  } else {
    b->l = merge(a, b->l);
    b->l->p = b;
    b->up();
    return b;
  }
}
void split(node *o, node *&a, node *&b, int k) {
  if (sz(o) <= k) return a = o, b = 0, void();
  if (sz(o->l) + 1 <= k) {
    a = o;
    split(o->r, a->r, b, k - sz(o->l) - 1);
    if (a->r)
        a->r->p = a;
  } else {
    b = o;
    split(o->l, a, b->l, k);
    if (b->l)
        b->l->p = b;
  }
  if (a) a->p = NULL, a->up();
  if (b) b->p = NULL, b->up();
}
node *kth(node *o, int k) {
  if (k <= sz(o->l)) return kth(o->l, k);
  if (k == sz(o->l) + 1) return o;
  return kth(o->r, k - sz(o->l) - 1);
}
int get_rank(node *u) {
    int rnk = sz(u->l) + 1;
    while (u->p != NULL) {
        if (u->p->r == u)
            rnk += sz(u->p->l) + 1;
        u = u->p;
    }
    return rnk;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n - 1; ++ i) {
        int a, b;
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }
    
    vector<node*> in(n), out(n);
    function<void(int, int)> Dfs = [&](int u, int f) -> void {
        in[u] = new node(u);
        root = merge(root, in[u]);
        for (auto &i : v[u]) if (i != f) Dfs(i, u);
        out[u] = new node(u);
        root = merge(root, out[u]);
    };
    Dfs(0, 0);

    int q;
    cin >> q;
    while ( q -- ) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, v;
            cin >> u >> v;
            -- u, -- v;
            int ul = get_rank(in[u]), ur = get_rank(out[u]);
            node *LEF, *L, *M, *R;
            split(root, LEF, R, ur);
            split(LEF, L, M, ul - 1);
            
            node *V = merge(L, R);
            int vrk = get_rank(in[v]);
            node *Vl, *Vr;
            split(V, Vl, Vr, vrk);
            root = merge(merge(Vl, M), Vr);
        } else {
            int p;
            cin >> p;
            -- p;
            int pl = get_rank(in[p]), pr = get_rank(out[p]);
            node *LEF, *L, *M, *R;
            split(root, LEF, R, pr);
            split(LEF, L, M, pl - 1);
            cout << M->val + 1 << "\n";
            root = merge(merge(L, M), R);
        }
    }
}