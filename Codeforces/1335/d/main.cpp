#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

#ifdef LOCAL
    #define deb(x) cout<<"LINE("<<__LINE__<<"): "<<(#x)<<" = "<<(x)<<endl; 
#else
    #define deb(...)
#endif

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

//-----------------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while (t--) 
        solve();
}

void solve() {
    string s[9];

    for (auto &v : s)
        cin >> v;

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    FOR (i, 0, 3) {
        FOR (j, 0, 3) {
            for (auto x : a) {
                if (s[i+3*j][j+3*i] - '0' != x) {
                    s[i+3*j][j+3*i] = x + '0';
                    break;
                }
            }
        }
    }

    for (auto v : s) 
        cout << v << endl;
}
