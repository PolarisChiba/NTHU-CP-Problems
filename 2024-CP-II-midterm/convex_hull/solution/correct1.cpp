#include <bits/stdc++.h>
#define debug(a) cout << #a << " = " << a << "\n";
using namespace std;
 
typedef long long ll;
 
int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (auto &[a, b] : v) cin >> a >> b;
 
    sort(v.begin(), v.end());
    vector<pair<ll, ll>> t;
    
    auto cross = [](pair<ll, ll> o, pair<ll, ll> a, pair<ll, ll> b) {
        return (a.first - o.first) * (b.second - o.second) - (a.second - o.second) * (b.first - o.first);
    };
 
    for (auto i : v) {
        while ((int)t.size() >= 2 && cross(t[(int)t.size() - 2], t.back(), i) < 0) t.pop_back();
        t.push_back(i);
    }
    int m = (int)t.size();
    v.pop_back();
    reverse(v.begin(), v.end());
    for (auto i : v) {
        while ((int)t.size() >= m + 1 && cross(t[(int)t.size() - 2], t.back(), i) < 0) t.pop_back();
        t.push_back(i);
    }
 
    t.pop_back();
    
	ll ans = 0;
	for (int i = 0; i < (int)t.size(); ++ i) {
		ans += cross({0, 0}, t[i], t[(i + 1) % (int)t.size()]);
	}

    cout << abs(ans) << "\n";
}