#include <bits/stdc++.h>
using namespace std;

#define fast_io        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define For(i, a, b)   for (int i = int(a); i <= int(b); i++)
#define Fod(i, a, b)   for (int i = int(a); i >= int(b); i--)
#define sz(x)          ((int) x.size())
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
template<class T> void read(vector<T> &v, int n) { For (i, 0, n - 1) cin >> v[i]; };
template<class T> void read(vector<T> &v, int f, int t) { For (i, f, t) cin >> v[i]; };
template<class T> void read(T v[], int n) { For(i, 0, n - 1) cin >> v[i]; }; 
template<class H, class... T> void read(H &v, T&... args) { read(v); read(args...); };

int add_mod(unsigned int a, unsigned int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int sub_mod(unsigned int a, unsigned int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
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

int n, m, k, cd = 0;
int cnt = 0;
int block[502][502];
string s[501];
int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void dfs(int x, int y) {
    for (auto v : d) {
        if (cnt == cd - k) {
            return;
        }

        int cx = x + v[0];
        int cy = y + v[1];

        if (cx == 0 || cy == 0 || cx == n + 1 || cy == m + 1) {
            continue;
        }

        if (block[cx][cy])
            continue;

        if (s[cx-1][cy-1] == '#')
            continue;

        ++cnt;
        block[cx][cy] = true;

        dfs(cx, cy);
    }
}

void solve() {
    read(n, m, k);
    For (i, 0, n - 1)
        read(s[i]);

    memset(block, false, sizeof block);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; j++)
            if (s[i][j] != '.')
                block[i + 1][j + 1] = true;
            else
                ++cd;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.') {
                ++cnt;
                block[i + 1][j + 1] = true;

                dfs(i + 1, j + 1);
                
                // finish
                for (int _i = 0; _i < n; ++_i) {
                    for (int _j = 0; _j < m; ++_j) {
                        if (!block[_i + 1][_j + 1])
                            cout << "X";
                        else
                            cout << s[_i][_j];
                    }

                    cout << endl;
                }

                return;
            }
        }
    }
}
