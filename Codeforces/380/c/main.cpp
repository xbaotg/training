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

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

const int MOD = 1000000007;
const int INF = INT_MAX;

void solve();
template<class T> void read(T &x) { cin >> x; };
template<class T> void read(vector<T> &v, int n) { FOR (i, 0, n - 1) cin >> v[i]; };
template<class T> void read(vector<T> &v, int f, int t) { FOR (i, f, t) cin >> v[i]; };
template<class T> void read(T v[], int n) { FOR(i, 0, n - 1) cin >> v[i]; }; 
template<class H, class... T> void read(H &v, T&... args) { read(v); read(args...); };

int plus_mod(unsigned int a, unsigned int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int minus_mod(unsigned int a, unsigned int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
int mul_mod(unsigned int a, unsigned int b) { return ((a % MOD) * 1LL * (b % MOD)) % MOD; }
int lcm(unsigned int a, unsigned int b) { return a * 1LL * b / __gcd(a, b); }
int gcd(unsigned int a, unsigned int b) { return __gcd(a, b); }

//---------------------------------------------------------------//
//                                                               //
// FB: https://facebook.com/tgbaodeeptry                         //
//                                                               //
// From Viet Nam with Love :D                                    //
//                                                               //  
//---------------------------------------------------------------//

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

struct Node {
    int optimal;
    int open;
    int close;

    Node operator+ (Node b) {
        Node ans;

        int tmp = min(open, b.close);
        ans.optimal = optimal + b.optimal + tmp;
        ans.open = open + b.open - tmp;
        ans.close = close + b.close - tmp;

        return ans;
    }
};

struct Segment {
    string s;
    Node* st;

    Segment(string s) {
        this->s = s;
        st = new Node[4*s.length() + 1];
    }

    Node build(int node, int l, int r) {
        if (l == r) {
            if (s[l] == '(')
                return st[node] = {0, 1, 0};

            return st[node] = {0, 0, 1};
        } 

        int m = (l + r) >> 1;
        return st[node] = build(node<<1, l, m) + build(node<<1|1, m+1, r);
    }

    Node query(int node, int l, int r, int s, int e) {
        if (l > e || r < s) 
            return {0, 0, 0};

        if (s <= l && r <= e)
            return st[node];

        int m = (l + r) >> 1;
        return query(node << 1, l, m, s, e) + query(node << 1 | 1, m + 1, r, s, e);
    }
};

void solve() {
    string s; 
    int n, q;

    read(s, q);
    n = s.length();

    Segment seg(s);
    seg.build(1, 0, n - 1);

    while (q--) {
        int s, e;
        read(s, e);

        s--, e--;
        cout << 2*seg.query(1, 0, n - 1, s, e).optimal << endl;
    }
}
