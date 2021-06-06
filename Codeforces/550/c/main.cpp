#include <bits/stdc++.h>
using namespace std;

#define fast_io        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FOR(i, a, b)   for (int i = int(a); i <= int(b); i++)
#define FOD(i, a, b)   for (int i = int(a); i >= int(b); i--)
#define SZ(x)          ((int) x.size())
#define ALL(x)         (x).begin(), (x).end()
#define F              first
#define S              second
#define ep             emplace_back
#define pb             push_back

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

const int MOD = 1000000007;

template<class T> void read(T &x) { cin >> x; };
template<class T> void read(vector<T> &v, int n) { FOR (i, 0, n - 1) cin >> v[i]; };
template<class T> void read(vector<T> &v, int f, int t) { FOR (i, f, t) cin >> v[i]; };
template<class T> void read(T v[], int n) { FOR(i, 0, n - 1) cin >> v[i]; }; 
template<class H, class... T> void read(H &v, T&... args) { read(v); read(args...); };

int plus_mod(unsigned int a, unsigned int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int minus_mod(unsigned int a, unsigned int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
int mul_mod(unsigned int a, unsigned int b) { return ((a % MOD) * 1LL * (b % MOD)) % MOD; }
int lcm(unsigned int a, unsigned int b) { return a * 1LL * b / __gcd(a, b); }

void solve();
//-----------------------------------------------------//
//                                                     //
// FB: https://facebook.com/tgbaodeeptry               //
//                                                     //
// From Viet Nam with Love :D                          //
//                                                     //  
//-----------------------------------------------------//

int main() {
    fast_io;

    #ifdef _CRUN 
        //freopen("input", "r", stdin);
    #endif

    int t = 1; 
    //cin >> t; 
    while (t--)
        solve();
}

string s;
int n;
bool dp[101][8]; 
int pre[101][8];

void solve() {
    read(s);
    n = s.length();

    int a[n];
    FOR (i, 0, n - 1)
        a[i] = s[i] - '0';

    memset(dp, false, sizeof dp);
    memset(pre, -1, sizeof pre);

    dp[0][a[0] % 8] = true;
    pre[0][a[0] % 8] = 0;
    
    FOR (i, 1, n-1) {
        dp[i][a[i] % 8] = true;
        pre[i][a[i] % 8] = 0;

        FOR (j, 0, 7) {
            if (dp[i-1][j]) {
                dp[i][j] = true;
                dp[i][(2*j + a[i]) % 8] = true;

                pre[i][j] = j;
                pre[i][(2*j + a[i]) % 8] = j;
            }
        }
    }

    string ans = "";

    FOR (i, 0, n - 1) {
        if (dp[i][0]) {
            if (a[i] % 8 == 0) {
                cout << "YES\n" << a[i];
                return;
            }

            int b = i, c = 0;
            while (b >= 0 && pre[b][c] != -1) {
                if ((2*pre[b][c] + a[b]) % 8 == c) {
                    ans = to_string(a[b]) + ans;
                }

                c = pre[b][c];
                b--;
            }

            break;
        }
    }

    if (ans.size())
        cout << "YES\n" << ans;
    else
        cout << "NO";
}
