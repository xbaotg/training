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

    int r = n;
    int ma = 0;
    int me = 0;
    int x;
    set<int> a;
    
    fort(i, 0, n - 1) {
        cin >> x;
        a.emplace(x);
        ma = max(ma, x);
    }

    fort (i, 0, ma + 1) 
        if (a.find(i) == a.end()) {
            me = i;
            break;
        }

    if (me > ma) {
        cout << r + k << endl;
        return;
    }

    while (k--) {
        int c = ceil((ma + me) * 1.0 / 2);

        // found
        if (a.find(c) != a.end()) {
            break;
        } 

        r++;
        a.emplace(c);

        if (c > ma) 
            ma = c;

        if (c == me) {
            fort (i, me, ma + 1) 
                if (a.find(i) == a.end()) {
                    me = i;
                    break;
                }
        }

        if (me > ma) {
            r += k;
            break;
        }
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}
