#include <bits/stdc++.h>
using namespace std;

#define fort(i, a, b) for (int i = a; i < b; i++)
#define ford(i, a, b) for (int i = a; i > b; i--)

typedef long long ll;

void solve();

//---------------------------------------------------------------//
//                                                               //
// FB: https://facebook.com/tgbaodeeptry                         //
//                                                               //
// From Viet Nam :D                                              //
//                                                               //  
//---------------------------------------------------------------//

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    cin >> t; 
    while (t--)
        solve();
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (s == "2020") {
        cout << "YES\n";
    } else {
        if (s.substr(0, 4) == "2020" || s.substr(n - 4, 4) == "2020") {
            cout << "YES\n";
        } else {
            string t = "2020";
            int ca = 0, cb = 0, i = 0, j = n - 1;

            while (i < 4 && t[i] == s[i]) 
                i++, ca++;
            
            while (j >= n - 4 && s[j] == t[4 - (n - j)]) 
                j--, cb++;

            if (ca + cb >= 4) {
                cout << "YES\n";
            } else 
                cout << "NO\n";
        }
    }
}
