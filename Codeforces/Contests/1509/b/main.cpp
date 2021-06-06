#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define deb(x) cout<<"LINE("<<__LINE__<<"): "<<(#x)<<" = "<<(x)<<endl; 
#else
    #define deb(...)
#endif

const double pi = acos(-1.0);

#define fort(i, a, b) for (int i = a; i < b; i++)
#define ford(i, a, b) for (int i = a; i > b; i--)

void solve();
//-----------------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

#ifndef ONLINE_JUDGE
    //freopen("input", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // TTTMMT
    // M nam giua
    //
    // T truoc M = M
    // T sau M = M
    
    int ct = 0, cm = 0;
    for (auto ch : s) {
        if (ch == 'T') ct++; else cm++;
    }

    if (ct == 2*cm) {
        ct = 0; cm = 0;
        for (auto ch : s) {
            if (ch == 'M') {
                if (cm + 1 > ct) {
                    cout << "NO\n";
                    return;
                }
                cm++;
            } else
                ct++;
        }
        ct = 0, cm = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'M') {
                if (cm + 1 > ct) {
                    cout << "NO\n";
                    return;
                } else
                    cm++;
            } else
                ct++;
        }
        
        cout << "YES\n";
    } else
        cout << "NO\n";
}
