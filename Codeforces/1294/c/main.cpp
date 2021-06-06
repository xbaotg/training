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
    // n = 2^a . 3^b ...
    
    int n;
    cin >> n;

    if (n < 24) {
        cout << "NO\n";
        return;
    }

    // let a < b < c
    // minimize a, maximize c

    int a = 0;
    FOR (i, 2, sqrt(n)) 
        if (n % i == 0) {
            a = i, n /= i; 
            break;
        }

    if (!a) {
        cout << "NO\n";
        return;
    }

    FOR (i, 2, sqrt(n) + 1) {
        if (n % i == 0 && n / i != i && i != a) {
            cout << "YES\n";
            cout << a << " " << i << " " << n / i << endl;
            return;
        }
    } 

    cout << "NO\n";
}

