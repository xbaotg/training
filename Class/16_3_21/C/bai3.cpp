//-----------------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define deb(x) cout<<"LINE("<<__LINE__<<"): "<<(#x)<<" = "<<(x)<<endl; 
#else
#define deb(...)
#endif

const double pi = acos(-1.0);

#define fort(i, a, b, inc) for (int i = a; i <= b; i += inc)
#define ford(i, a, b, dec) for (int i = a; i >= b; i -= dec)

#define push_back pb
#define mod 1000000007

typedef long int32;
typedef unsigned long uint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve();
// Main code below
//-----------------------------------------------------------------------------
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();
    solve();
}


void solve() {
    ifstream inf("inp", ios::in);

    int n, h;
    inf >> n >> h;

    int a[n];
    for (auto &v : a) 
        inf >> v;

    int r = min(n, 2);

    for (int i = n - 2; i > 0; i--) {
        if (a[i] > a[i+1]) {
            break;
        } 
        r++;
    }

    cout << r << '\n';

    // so cach xep sao cho khong co 3 cay co chieu cao giam dan
    //
    // == tang dan + 2 cay co chieu cao giam dan
    //
    // tang dan = 1
    // 2 cay co chieu cao giam dan = n*n
    //
    // Vi:
    // cho A = [f, e, d, c, b, a]           ( f > e > d > c > b > a )
    //
    // chon 2 so thuoc A la a, b. neu a, b trong A khong lien ke thi o giua a, b
    // co the co 1 so khac => trung nhau
    //
    // => so cach chon 2 so la (n + 1 - 1) = n
    // => chon vi tri dat 2 cay vao co (n + 1 - 1) = n
    //
    int m = 1e9;
    
    cout << (1 + ((n % m) * (n % m)) % m) % m;
}
