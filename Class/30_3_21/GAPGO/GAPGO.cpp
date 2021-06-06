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

int m, n, k;

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t = 1;
    //cin >> t;

    while (t--) 
        solve();
}

int** bfs(int **a, pair<int, int> l) {
    int** res;
    res = new int*[m];

    FOR(i, 0, m)
        res[i] = new int[n];

    queue<pair<pii, int>> q;
    q.push({l, 0});

    while (!q.empty()) {
        auto top = q.front();
        q.pop();

        int r = top.first.first, c = top.first.second;
        int co = top.second;
        
        cout << r << " " << c << endl;

        res[r][c] = co;

        if (r && res[r-1][c] == -1 && a[r-1][c] == 0)
            q.push( { {r-1, c}, co+1 } );
        if (r < m - 1 && res[r+1][c] == -1 && a[r+1][c] == 0)
            q.push( { {r+1, c}, co+1 } );
        if (c && res[r][c-1] == -1 && a[r][c-1] == 0)
            q.push( { {r, c-1}, co+1 } );
        if (c < n - 1 && res[r][c+1] == -1 && a[r][c+1] == 0)
            q.push( { {r, c+1}, co+1 } );
    }

    FOR(i, 0, m)
        FOR(j, 0, n)
            cout << res[i][j] << " " << " \n"[i == m - 1];

    return res;
}

void solve() {
    freopen("input", "r", stdin);

    cin >> m >> n >> k;

    pii r[k];
    FOR(i, 0, k) {
        cin >> r[i].first >> r[i].second;
        r[i].first--;
        r[i].second--;
    }

    int** a;
    a = new int*[m];
    FOR(i, 0, n)
        a[i] = new int[n];

    FOR(i, 0, m) {
        FOR(j, 0, n) {
            cin >> a[i][j];
        }
    }

    for (auto p : r) {
        bfs(a, p);
        break;
    }
}
