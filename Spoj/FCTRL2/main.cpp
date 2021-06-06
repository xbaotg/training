/*
 * Created at: $DATE
 *
 * FB: https://facebook.com/tgbaodeeptry
 * From Viet Nam with Love :D 
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io()      ios_base::sync_with_stdio(false); cin.tie(NULL);
#define For(i, a, b)   for (int i = int(a); i <= int(b); i++)
#define Fod(i, a, b)   for (int i = int(a); i >= int(b); i--)
#define sz(x)          ((int) x.size())

void solve();
/***********************************************************/

string add(string a, string b) {
    while (sz(a) < sz(b)) a = '0' + a;
    while (sz(b) < sz(a)) b = '0' + b;

    string ans = "";
    int du = 0, num;

    for (int i = sz(a) - 1; i >= 0; --i) {
        num = (a[i] - '0' + b[i] - '0') + du;
        du = num > 9;
        num %= 10;

        ans = string(1, num + '0') + ans;
    }

    return du ? "1" + ans : ans;
}

string mul(string a, string b) {
    if (b[0] == '0')
        return "0";

    string ans = "";
    if (sz(b) == 1) {
        For (i, 1, b[0] - '0')
            ans = add(ans, a);
        return ans;
    }

    for (int i = sz(b) - 1; i >= 0; --i) {
        string t = mul(a, string(1, b[i]));
        For (j, i, sz(b) - 2)
            t += '0';

        ans = add(ans, t);
    }

    return ans;
}

string ans[101];

int main() {
    fast_io();

    ans[1] = "1";
    For (i, 2, 100) {
        ans[i] = mul(ans[i-1], to_string(i));
    }

    int t = 1;
    cin >> t; 
    while (t--) solve();
}

void solve() {
    int n;
    cin >> n;

    cout << ans[n] << endl;
}
