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
    cin >> t; 
    while (t--)
        solve();
}

// 0: excel, 1: another
int type_format(string s) {
    if (s[0] != 'R')
        return 0;

    Fod (i, sz(s) - 1, 1) 
        if (s[i] == 'C') {
            if (isdigit(s[i-1]))
                return 1;
            else
                return 0;
        }

    return 0;
}

int pow(int x, int y) {
    if (y == 0)
        return 1;

    return x * pow(x, y - 1);
}

void solve() {
    string s;
    read(s);

    map<char, int> l_n;
    map<char, int> n_l;

    for (auto ch = 'A'; ch <= 'Z'; ch++) {
        l_n[ch] = ch - 'A' + 1;
        n_l[ch - 'A' + 1] = ch;
    }

    if (type_format(s) == 0) {
        // excel format
        string a = "", b = "";
        for (auto &v : s)
            if (isdigit(v)) 
                b += v;
            else
                a += v;

        int col = 0;

        for (int i = 0; i < sz(a); i++)
            col += pow(26, sz(a) - i - 1) * l_n[a[i]];

        cout << "R" << b << "C" << col << endl;
    } else {
        string a, b;

        Fod (i, sz(s) - 1, 1) 
            if (s[i] == 'C') {
                a = s.substr(1, i - 1);
                b = s.substr(i+1);
                break;
            }

        // RxCy ...
        int col = stoi(b);
        int i = 0;
        string ans = "";

        while (col) {
            int c = col / 26;
            int z = col - c * 26;

            if (z == 0) {
                z = 26;
            }

            ans = string(1, n_l[z]) + ans;

            col = (col - z) / 26;
            ++i;
        }

        cout << ans << a << endl;
    }
}
