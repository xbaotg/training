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
    //cin >> t;

    while (t--) 
        solve();
}

void solve() {
    int a, b;
    cin >> a >> b;

    vector<bool> primes(b+1, true);
    primes[1] = false;

    FOR (i, 2, sqrt(b) + 1)
        if (primes[i])
            for (int j = i*i; j <= b; j += i)
                primes[j] = false;

    FOR (i, a, b + 1)
        if (primes[i])
            cout << i << endl;
}
