//-----------------------------------------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <limits>
#include <iterator>
#include <numeric>
#include <utility>
#include <math.h>

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

    //int t; scanf("%d", &t); while(t--) solve();
    solve();
}


void solve() {
    int a, b, y = 0;
    cin >> a >> b;

    while (a <= b) {
        a *= 3;
        b *= 2;
        y++;
    }

    cout << y;
}
