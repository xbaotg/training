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

    ll t = 1; 
    //cin >> t; 
    while (t--)
        solve();
}

struct Node {
    ll val;
    ll lazy;
};

struct Segment {
    ll n;
    Node* nodes;

    Segment (ll n) {
        this->n = n;
        this->nodes = new Node[4*n + 1];

        Node t = {0, 0};
        fill(nodes, nodes + 4*n + 1, t);
    }

    void down(ll id, ll l, ll r) {
        ll t = nodes[id].lazy;
        ll mid = (l + r) >> 1;
    
        ll t1 = mid - l + 1;
        ll t2 = r - (mid + 1) + 1;

        nodes[id << 1].val += t1 * t;
        nodes[id << 1].lazy += t;
        nodes[id << 1 | 1].val += t2 * t;
        nodes[id << 1 | 1].lazy += t;

        nodes[id].lazy = 0;
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll t) {
        if (r < u || l > v) 
            return;

        if (u <= l && r <= v) {
            nodes[id].val += (r - l + 1) * t;
            nodes[id].lazy += t;

            return;
        }
        
        down(id, l, r);

        ll m = (l + r) >> 1;

        update(id << 1, l, m, u, v, t);
        update(id << 1 | 1, m + 1, r, u, v, t);
        
        nodes[id].val = nodes[id << 1].val + nodes[id << 1 | 1].val;
    }

    ll get(ll id, ll l, ll r, ll u, ll v) {
        if (r < u || l > v)
            return 0;

        if (u <= l && r <= v)
            return nodes[id].val;

        down(id, l, r);

        ll m = (l + r) >> 1;
        return get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v);
    }
};

void solve() {
    ll n, m, k, l, r, d;
    int a[100001];

    vector<tuple<ll, ll, ll>> ms;

    read(n, m, k);
    read(a, (int) n);

    For (i, 1, m) 
        read(l, r, d), ms.ep(l, r, d);

    Segment seg1 (m), seg2 (n);
    while (k--) {
        read(l, r);
        seg1.update(1, 1, m, l, r, 1);
    }

    // segment tree
    For (i, 0, m - 1) {
        tie(l, r, d) = ms[i];
        seg2.update(1, 1, n, l, r, d * seg1.get(1, 1, m, i + 1, i + 1));
    }

    For (i, 0, n - 1) {
        cout << a[i] + seg2.get(1, 1, n, i + 1, i + 1) << " ";
    }
}
