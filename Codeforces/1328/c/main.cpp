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
    int n;
    cin >> n;

    string s;
    cin >> s;

    string a = "", b = "";

    FOR(i, 0, n) {
        if (s[i] == '0') a += '0', b += '0';
        if (s[i] == '1')
            if (a < b) { 
                a += '1'; b += '0'; 
            } else {
                a += '0'; b += '1';
            }
        if (s[i] == '2') {
            if (a < b) {
                a += '2'; b += '0';
            } else if (a == b) {
                a += '1'; b += '1';
            } else {
                a += '0'; b += '2';
           }
        }
    }

    cout << a << endl << b << endl;
}
