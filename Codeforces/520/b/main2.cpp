#include <bits/stdc++.h>
using namespace std;

#define fort(x, a, b) for (int x = a; x <= b; x++)
#define ford(x, a, b) for (int x = a; x >= b; x--)
#define printv(v, sep) fort(i, 0, v.size() - 2) cout << v[i] << sep; cout << v[v.size() - 1];

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>

void solve() {
    int n, m;
    cin >> n >> m;

    if (m == n) {
        cout << 0;
        return;
    }

    if (m < n) {
        cout << n - m;
        return;
    }

    // bfs
    bool visited[2*m+1]; // map<int, bool> visited;
    memset(visited, false, 2*m + 1);

    queue<pair<int, int>> q;

    q.push({n, 0});
    visited[n] = true;

    while (q.size()) {
        pair<int, int> p = q.front();
        q.pop();

        if (p.first == m) {
            cout << p.second;
            return;
        }

        visited[p.first] = true;

        if (p.first < m && !visited[p.first * 2])
            q.push({p.first * 2, p.second + 1});
         

        if (p.first > 1 && !visited[p.first - 1])
            q.push({p.first - 1, p.second + 1});
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();

    solve();
}
