#include <bits/stdc++.h>
using namespace std;

#define fort(x, a, b) for (int x = a; x <= b; x++)
#define ford(x, a, b) for (int x = a; x >= b; x--)
#define printv(v, sep) if (v.size() - 2 >= 1) fort(i, 0, v.size() - 2) cout << v[i] << sep; cout << v[v.size() - 1];

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>


void solve() {
    int n, k;
    cin >> n >> k;

    // if choose a then can not choose k - a
    //
    // subset, no sum equal k
    // 
    // no choose k
    //
    // choose all numbers > k
    //
    // 1 2 3 4 ... k
    // choose all number >= k / 2
    
    vi ans;
    fort (i, k + 1, n) 
        ans.push_back(i);

    fort (i, ceil(1.0 * k / 2), k - 1) {
        ans.push_back(i);
    }

    if (ans.size()) {
        cout << ans.size() << endl;
        for (auto v : ans) 
            cout << v << " ";
    }
    else
        cout << 0;

    cout << endl;

    // a + b + c + d ... = k
    // 
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}
