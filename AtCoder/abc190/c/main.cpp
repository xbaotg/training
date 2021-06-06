#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

int n, m, k, a, b;
int r = 0;
vector<pair<int, int>> s;
vector<vector<int>> t;

bool sec[101];

void find(int x) {
    REP(i, 0, 2) {
        bool l = sec[t[x-1][i]];
        sec[t[x - 1][i]] = true;        

        if (x == k) {
            // check
            int c = 0;
            for (pair<int, int> p : s) {
                if (sec[p.first] && sec[p.second]) {
                    c++;
                } 
            }
            r = max(r, c);
        } else {
            find(x + 1);
        }
        sec[t[x-1][i]] = l;
    }
    
}

void solve() {
    cin >> n >> m;
    fill(sec, sec + 101, false);

    REP(i, 0, m) {
        cin >> a >> b;
        s.push_back({a, b});
    }

    cin >> k;

    REP(i, 0, k) {
        cin >> a >> b;
        t.push_back({a, b});
    }

    find(1);
    cout << r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

//    cin >> tests;
//    while (tests--) {
//        solve();
//    }

    solve();

    return 0;
}
