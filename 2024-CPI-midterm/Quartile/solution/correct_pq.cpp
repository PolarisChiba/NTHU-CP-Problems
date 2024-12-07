#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        int x;
        cin >> x;
        small.push(x);
        while ((!big.empty() && /* !small.empty() && */ big.top() < small.top()) || small.size() > i / 4 + 1) {
            big.push(small.top());
            small.pop();
        }
        while (small.size() < i / 4 + 1) {
            small.push(big.top());
            big.pop();
        }
        cout << small.top() << "\n";
    }
}