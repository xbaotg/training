#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FOD(i, a, b) for (int i = a; i > b; i--)

typedef long int32;
typedef unsigned long uint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//-----------------------------------------------------------------------------


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("input", "r", stdin);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> row (m, vector<int>(n));

    FOR (i, 0, m)
        FOR (j, 0, n) 
            cin >> row[i][j];

    FOR (i, 0, m)
        sort(row[i].begin(), row[i].end());

    int sr[m][n];

    FOR (i, 0, m) {
        sr[i][0] = row[i][0];
        FOR (j, 1, n)
            sr[i][j] = sr[i][j-1] + row[i][j];
    }

    int X[m][n];

    FOR (i, 0, m) {
        FOR (j, i + 1, m) {
            int ave = round(1.0 * (sr[i][n-1] + sr[j][n-1]) / (2*n));
            int posi = lower_bound(row[i].begin(), row[i].end(), ave) - row[i].begin();
            int posj = lower_bound(row[j].begin(), row[j].end(), ave) - row[j].begin();

            int x = posi*ave - sr[i][posi-1] + sr[i][n-1] - sr[i][posi-1] - (n - posi) * ave;
            x += posj*ave - sr[j][posj-1] + sr[j][n-1] - sr[j][posj-1] - (n - posj) * ave;

            X[i][j] = x;
        }
    }

    int S = 0;

    FOR (i, 0, m - 1)
        FOR (j, i + 1, m) {
            S += X[i][j];
        }

    cout << S;
}
