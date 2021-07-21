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
    int t = 1;
    //cin >> t;

    while (t--) 
        solve();
}

void solve() {
    int k;
    scanf("%d", &k); 

    int n;
    while (k--) {
        scanf("%d", &n); 

        // process
        int memo = 0;
        char res[2000000];
        int p = 2 * n - 2;

        for (int i = 1; i <= n; ++i) {
            memo += i;
            res[p--] = memo % 10 + 0x30;
            memo /= 10;
        }
        for (int i = n - 1; i >= 1; --i) {
            memo += i;
            res[p--] = memo % 10 + 0x30;
            memo /= 10;
        }

        if (memo) {
            printf("%d", memo);
        }

        res[n + n - 1] = 0;
        printf("%s\n", res);
    }
}
