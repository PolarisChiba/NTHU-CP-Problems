#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

    int n;
    cin >> n;

    int t = 0;
    for (int i = 1; i <= n; ++ i) {
        int x;
        cin >> x;
        ordered_set.insert({x, ++ t});
        cout << (ordered_set.find_by_order(i / 4))->first << "\n";
    }
}