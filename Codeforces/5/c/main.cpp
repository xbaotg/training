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

struct Node {
    int open;
    int close;
    int ans;

    Node operator+ (Node b) {
        Node n;
        int t = min(open, b.close);
        
        n.ans = ans + b.ans + t;
        n.open = open + b.open - t;
        n.close = close + b.close - t;
        
        return n;
    }
};

struct SpT {
    string s;
    int n;
    int t;
    Node** table;

    SpT (string s) {
        this->s = s;
        this->n = sz(s);

        this->table = new Node*[n];
        this->t = floor(log2(n));
        For (i, 0, n - 1)
            this->table[i] = new Node[t + 1];
    }

    void build() {
        For (i, 0, n - 1)
            if (s[i] == '(')
                table[i][0] = {1, 0, 0};
            else
                table[i][0] = {0, 1, 0};

        For (j, 1, t) {
            int c = (1 << (j - 1));
            for (int i = 0; i + (1 << j) <= n; ++i) {
                table[i][j] = table[i][j-1] + table[i+c][j-1];
            }
        }
    }

    int query(int l, int r) {
        int ans = 0;
        int open = 0;
        while (l <= r) {
            int len = r - l + 1;
            int p = floor(log2(len));
            int t = min(open, table[l][p].close);

            ans += table[l][p].ans + t;
            open += table[l][p].open - t;

            l += 1 << p;
        }

        return ans;
    }
};

int longest(string s) {
    // let dp is the longest with prefix ends at i
    // if (s[i] == ')') 
    //    it mean: dp[i] = (match open parentheses - i + 1) + dp[(match open parentheses) - 1]

    int dp[sz(s)];
    memset(dp, 0, sizeof dp);

    stack<int> t;
    int ans = 0;

    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == '(')
            t.push(i);
        else {
            if (sz(t) == 0)
                continue;

            dp[i] = i - t.top() + 1 + (t.top() ? dp[t.top() - 1] : 0);
            ans = max(ans, dp[i]);

            t.pop();
        }
    } 

    return ans;
}

void solve() {
    string s;
    read(s);

    int n = sz(s);
    int l = longest(s);
    int ans = 0;

    if (l == 0) {
        cout << "0 1";
        return;
    }

    // Segment Tree
    //Seg seg;
    //seg.s = s;
    //seg.build(1, 0, n - 1);

    //for (int i = 0, j = l - 1; j < n; ++i, ++j) 
        //if (seg.query(1, 0, n - 1, i, j).ans == (l >> 1)) 
            //++ans;

    // SpT
    SpT spt (s);
    spt.build();

    for (int i = 0, j = l - 1; j < n; ++i, ++j) 
        if (spt.query(i, j) == (l >> 1)) 
            ++ans;

    cout << l << " " << ans;
}
