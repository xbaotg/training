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
//-----------------------------------------------------------------------------

void solve() {
    int r = 0, c = 0;
    int x;

    while (++r <= 5) {
        c = 0;
        while (++c <= 5) {
            cin >> x;
            if (x == 1) {
                cout << abs(3 - c) + abs(3 - r) << endl;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //int t; scanf("%d", &t); while(t--) solve();
    solve();
}
