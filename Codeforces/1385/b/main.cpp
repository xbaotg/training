#include <bits/stdc++.h>
using namespace std;

#define fort(x, a, b) for (int x = a; x <= b; x++)
#define ford(x, a, b) for (int x = a; x >= b; x--)

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>

void solve() {
    int n, v;
    cin >> n;
    int t = 2*n;

    vi res;
    set<int> a;

    while(t--) {
        cin >> v;

        if (a.count(v)) continue;

        a.emplace(v);
        res.push_back(v);
    }

    fort(i, 0, n - 2) {
        cout << res[i] << " ";
    }

    cout << res[res.size() - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();

    //solve();
}
