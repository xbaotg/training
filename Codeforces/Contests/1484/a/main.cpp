//-----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define deb(x) cout<<"LINE("<<__LINE__<<"): "<<(#x)<<" = "<<(x)<<endl; 
#else
#define deb(...)
#endif

const double pi = acos(-1.0);

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FOD(i, a, b) for (int i = a; i > b; i--)

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

    int t; cin >> t; while(t--) solve();
    //solve();
}


void solve() {
    int a, b;
    cin >> a >> b;

    int r1 = 0, r2 = 0;
    int ta = a, tb = b;

    while (ta && tb) {
        r1 += (ta - 1) + tb;
        ta--, tb--;
    }
    
    while (a && b) {
        r2 += (b - 1) + a;
        a--, b--;
    }

    cout << min(r1, r2) << endl;
}
