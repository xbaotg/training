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
    int n, x;
    cin >> n;

    map<int, int> m;
    FOR (i, 0, n) {
        cin >> x;
        if (m.find(x) == m.end()) 
            m[x] = 0;
        m[x]++;
    }

    priority_queue<int> q;
    for (auto p : m)
        q.push(p.second);

    int r = n;

    while (q.size() >= 2) {
        int t1 = q.top();
        q.pop();
        int t2 = q.top();
        q.pop();

        t1--, t2--, r -= 2;
        if (t1)
            q.push(t1);
        if (t2)
            q.push(t2);
    }

    // (N / 2) * (4*logN)
    //
    // N logN

    cout << r << endl;
}
