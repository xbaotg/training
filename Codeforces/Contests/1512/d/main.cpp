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
    int n, v;
    int64 s = 0;
    cin >> n;

    vector<pii> b(n+2);

    FOR (i, 0, n + 2) {
        cin >> v;
        s += v;
        b[i] = {v, i};
    }

    sort(b.begin(), b.end(), [](pii a, pii b) {
            return a.first > b.first;
    });

    // gia su b[0] = tong
    bool found = false;

    s -= b[0].first;
    // 0 1 2

    FOR (i, 0, n + 2) {
        if (s - b[i].first == b[0].first && b[i].second != b[0].second) {
            found = true;
            FOR (j, 0, n + 2) {
                if (b[j].second != b[i].second && b[j].second != b[0].second) {
                    cout << b[j].first << " ";
                }
            }
            break;
        }
    } 

    if (found) {
        cout << endl;
        return;
    }

    // gia su b[1] = tong => b[0] = x
    if (s - b[1].first == b[1].first) {
        FOR (i, 2, n + 2)
            cout << b[i].first << " ";
        cout << endl;
        return;
    }

    cout << -1 << endl;
}
