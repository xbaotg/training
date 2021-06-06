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

    // n = 2020x + 2021y = 2020(x+y) + y
    //
    // => (n - y) % 2020 == 0
    // => x = (n - y) / 2020 - y
    //
    // y >= 0
    
    int y = n % 2020;
    int x = (n - y) / 2020 - y;

    if (x >= 0 && 2020*x + 2021*y == n)  
        cout << "YES\n";
    else 
        cout << "NO\n";
}
