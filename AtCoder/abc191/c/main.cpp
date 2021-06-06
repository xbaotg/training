#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

void solve() {
    int h, w;
    vector<string> s;

    cin >> h >> w;

    REP(i, 0, h) {
        string t;
        cin >> t;
        s.push_back(t);
    }

    int vertexs = 0;

    REP(i, 1, h - 1) {
        REP(j, 1, w - 1) {
            if (s[i][j] == '#') {
                int c = (s[i-1][j] == '#') + (s[i][j-1] == '#') + (s[i][j+1] == '#') + (s[i+1][j] == '#');
                
                if (c == 4) continue;
                if (c == 1) vertexs += 2;
                if (c == 2) {
                    if (s[i-1][j] != s[i+1][j] && s[i][j-1] != s[i][j+1]) vertexs++;
                }
                if (c == 3) {
                    
                }
            }
        }

    }
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
}
