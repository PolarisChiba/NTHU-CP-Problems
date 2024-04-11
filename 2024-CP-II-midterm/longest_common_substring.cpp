#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int rk[1000009];
int sa[1000009];
int oldrk[2000009];
int cnt[1000009];
int id[1000009];
int height[1000009];
 
int ans[1000009];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    s = a + string(1, 'z' + 1) + b;
    int n = (int)s.size(), m = 300;
    s = "#" + s;

    for (int i = 1; i <= n; ++ i) ++ cnt[rk[i] = s[i]];
    for (int i = 1; i <= m; ++ i) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; -- i) sa[cnt[rk[i]] --] = i;
 
    int p;
    for (int w = 1;; w <<= 1, m = p) {
        p = 0;
        for (int i = n; i > n - w; -- i) id[++ p] = i;
        for (int i = 1; i <= n; ++ i) if (sa[i] > w) id[++ p] = sa[i] - w;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++ i) ++ cnt[rk[id[i]]];
        for (int i = 1; i <= m; ++ i) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; -- i) sa[cnt[rk[id[i]]] --] = id[i];
        memcpy(oldrk, rk, sizeof(rk));
        p = 0;
        for (int i = 1; i <= n; ++ i)
            rk[sa[i]] = (oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) ? p : ++ p;
        if (p == n) break;
    }

    s = s + "?";
    for (int i = 1, k = 0; i <= n; ++ i) {
        if (rk[i] == 1) continue;
        if (k) -- k;
        while (s[i + k] == s[sa[rk[i] - 1] + k]) ++ k;
        height[rk[i]] = k;
    }

    // for (int i = 0; i < (int)s.size(); ++ i) {
    //     cout << s[i] << " \n"[i == (int)s.size() - 1];
    // }
    // for (int i = 0; i <= (int)s.size(); ++ i) {
    //     cout << sa[i] << " \n"[i == (int)s.size()];
    // }
    // for (int i = 0; i <= (int)s.size(); ++ i) {
    //     cout << rk[i] << " \n"[i == (int)s.size()];
    // }
    // for (int i = 0; i <= (int)s.size(); ++ i) {
    //     cout << height[i] << " \n"[i == (int)s.size()];
    // }

    vector<bool> bis(s.size());
    for (int i = 1; s[i] != 'z' + 1; ++ i) {
        bis[rk[i]] = true;
    }
    int now = 0;
    int ans = 0;
    for (int i = 2; i <= (int)s.size(); ++ i) {
        if (bis[i - 1]) now = min(now, height[i]);
        else now = height[i];
        if (bis[i]) {
            ans = max(ans, now);
        }
    }
    for (int i = (int)s.size() - 1; i >= 1; -- i) {
        if (bis[i + 1]) now = min(now, height[i + 1]);
        else now = height[i + 1];
        if (bis[i]) {
            ans = max(ans, now);
        }
    }
    cout << ans << "\n";

}