#include <bits/stdc++.h>
using namespace std;

#define fort(x, a, b) for (int x = a; x <= b; x++)
#define ford(x, a, b) for (int x = a; x >= b; x--)
#define printv(v, sep) if (v.size() - 2 >= 1) fort(i, 0, v.size() - 2) cout << v[i] << sep; cout << v[v.size() - 1];

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>

int s(int idx[], int n, int v) {
    int l = 0;
    int r = n - 1;
    int res = n - 1;
    
    while (l <= r) {
        int mid = (l + r) >> 1;

        if (idx[mid] > v) {
            r = mid - 1;
        } else {
            res = mid;
            l = mid + 1;
        }
    }

    return res;
}

void solve() {
    // n
    // a1
    // a1+1->a2
    
    int n, m, v = 1, vt = 0;;
    cin >> n;
    
    int idxS[n];

    fort(i, 0, n-1) {
        cin >> vt;

        idxS[i] = v;
        v += vt;
    }

    cin >> m;
    while (m--) {
        cin >> v;
        cout << s(idxS, n, v) + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();
    solve();
}
