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
    int n; 
    string s;

    cin >> n;
    cin >> s;

    int bo = 0;
    int res = 0;

    for (auto &ch : s) {
        if (ch == ')') {
            if (bo == 0)
                res++;
            else
                bo--;
        } else
            bo++;
    }

    // open brackets remain. it mean -> no have any close brackets after that. so we can pass it, add move close brackets remain to after them

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}
