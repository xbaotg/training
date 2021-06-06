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
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    //int t; cin >> t; while(t--) solve();
    //solve();
    int t;
    cin >> t;
    while (t--) solve();
}


void solve() {
    int n;
    cin >> n;

    int a[n];
    for (auto &v : a) {
        cin >> v;
    }
    
    if (n == 1) {
        cout << "0" << endl;
    } else {
        if (a[1] >= a[0]) {
            int c = a[1] - a[0];
            bool isI = true;

            FOR(i, 1, n) {
                if (a[i] - a[i - 1] == c) {
                    continue;
                } else {
                    isI = false;
                    int preC = c;
                    c = a[i] - a[i-1];
                    int m = a[i-1] + c - a[i];

                    FOR(j, i + 1, n) {
                        if (a[i] != (a[i-1] + c) % m) {
                            cout << "-1" << endl;
                            return;
                        }
                    }

                    cout << m << " " << preC << endl;
                    return;
                }
            }

            cout << "0\n";
        } else {
            //int c = a[1] - a[0];
            cout << "U\n";
        }
    }
}
