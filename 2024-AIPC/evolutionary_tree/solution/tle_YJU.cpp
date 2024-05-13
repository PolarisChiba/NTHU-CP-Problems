#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector,Ofast")
#ifdef DEBUG
    #define debug(fmt, ...) \
            do { fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, \
                                    __LINE__, __func__, __VA_ARGS__); fprintf(stderr, "\n");} while (0)
#else
    #define debug(fmt, ...) void()
#endif
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define pb push_back 
#define mp make_pair
#define fi first
#define se second
#define lwb lower_bound
#define setp setprecision
#define SZ(_a) (ll)(_a).size()
#define SQ(_a) ((_a)*(_a))
#define all(_a) (_a).begin(), (_a).end()
#define chmax(_a, _b) _a = max(_a, _b)
#define chmin(_a, _b) _a = min(_a, _b)

template<class A, class B> inline istream& operator >> (istream& in, pair<A, B>& p) {
    in >> p.fi >> p.se;
    return in;
}

template <class T> inline ostream& operator << (ostream& out, vector<T> v) {
    for (int i = 0;i < SZ(v); ++i) out << v[i] << (i == SZ(v)-1 ? "" : " ");
    return out;
}

template <class A, class B> inline ostream& operator << (ostream& out, pair<A, B> p) {
    out << "(" << p.fi << ", " << p.se << ")";
    return out;
}

template <class A, class B> inline pair<A, B> operator + (pair<A, B> pA, pair<A, B> pB) {
    return make_pair(pA.fi+pB.fi, pA.se+pB.se);
}

template <class A, class B> inline pair<A, B> operator - (pair<A, B> pA, pair<A, B> pB) {
    return make_pair(pA.fi-pB.fi, pA.se-pB.se);
}

template <class A, class B, class C> inline pair<A, B> operator * (pair<A, B> pA, C pB) {
    return make_pair(pA.fi*pB, pA.se*pB);
}



const ll N = 2e6 + 5;
const ll lgN = 22;
const ll MOD = 1e9 + 7;
const ld pi = acos(-1);
const ll INF = (1LL<<60);

ll n, p[N], p2[N], in[N], out[N], ans[N], d[N];
ll t = 0, r1, r2;
vector<ll> u[N], v[N];

void DFS2(ll now) {
    in[now] = t++;
    for (auto i : v[now]) {
        d[i] = d[now]+1;
        DFS2(i);
    }
    out[now] = t++;
}

bool is_sub(ll anc, ll suc) {
    return (in[anc] <= in[suc] && out[suc] <= out[anc]);
}

ll lca(ll a, ll b) {
    if (a == 0 || b == 0) {
        return (a == 0 ? b : a);
    }
    if (d[a] > d[b]) {
        swap(a, b);
    }
    while (!is_sub(a, b)) {
        a = p2[a];
    }
    return a;
}

void DFS1(ll now) {
    for (ll i : u[now]) {
        DFS1(i);
    }
    if (u[now].empty())
        ans[now] = now;
    else
        ans[now] = lca(ans[u[now][0]], ans[u[now][1]]);
}

void solve() {
    cin >> n;
    for (ll i = 1;i <= n; ++i) {
        cin >> p[i];
        if (p[i] == 0)
            r1 = i;
        else {
            u[p[i]].pb(i);
        }
    }
    for (ll i = 1, x;i <= n; ++i) {
        cin >> x;
        if (x != 0) {
            v[x].pb(i);
            p2[i] = x;
        } else {
            r2 = i;
        }
    }
    d[0] = -1;
    DFS2(r2);
    DFS1(r1);
    for (ll i = 1;i <= n; ++i) {
        cout << ans[i] << " \n"[i==n];
    }
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}

/* Don't forget to check:
 * special case (n=1?)
 * array bounds.
 * hash collision
 * MOD in every step
*/



