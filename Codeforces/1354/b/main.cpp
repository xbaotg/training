#include <bits/stdc++.h>
using namespace std;

#define fort(i, a, b) for (int i = a; i < b; i++)
#define ford(i, a, b) for (int i = a; i > b; i--)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int MOD = 1000000007;

void solve();

//---------------------------------------------------------------//
//                                                               //
// FB: https://facebook.com/tgbaodeeptry                         //
//                                                               //
// From Viet Nam with Love :D                                    //
//                                                               //  
//---------------------------------------------------------------//

int main() {
    #ifdef _CRUN 
        //freopen("input", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    cin >> t; 
    while (t--)
        solve();
}

void solve() {
    string s;
    cin >> s;

    int cnt[3] = {0, 0, 0};
    for (auto ch : s) cnt[ch - '1']++;

    if (cnt[0] * cnt[1] * cnt[2] == 0) {
        cout << "0\n";
        return;
    }

    int l = 0, r = s.length() - 1;

    while (true) {
        bool changed = false;

        if (cnt[s[l] - '1'] > 1 && (r - l - 1 >= 2)) 
            cnt[s[l] - '1']--, l++, changed = true;
        if (cnt[s[r] - '1'] > 1 && (r - 1 - l >= 2))
            cnt[s[r] - '1']--, r--, changed = true;

        if (!changed) {
            cout << (r - l) + 1 << endl;
            return;
        }
    }

    cout << 3 << endl;
}
