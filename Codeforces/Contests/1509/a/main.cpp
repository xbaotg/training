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
    int n, x;
    cin >> n;

    vector<int> odd, even;
    fort(i, 0, n) {
        cin >> x;
        if ((x & 1) == 0)
            even.emplace_back(x);
        else
            odd.emplace_back(x);
    }

    for (auto v : odd)
        cout << v << " ";
    for (auto v : even)
        cout << v << " ";

    cout << endl;
}
