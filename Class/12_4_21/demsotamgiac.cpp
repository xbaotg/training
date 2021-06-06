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

    int a, b, m, n;
    cin >> a >> b >> m >> n;

    int d[n];
    unordered_map<int, int> ca;

    d[0] = b;
    FOR (i, 1, n) d[i] = (a*d[i-1] + b) % m + 1;
    sort(d, d + n);
    for (auto v : d) {
        if (ca.find(v) == ca.end()) 
            ca[v] = 1;
        else
            ca[v]++;
    }

    set<int> se (d, d + n);
    int loc[20003], c[20003]; 
    int cur = 1;
    c[0] = 0;

    // 2 3 4

    for (auto b = se.begin(); b != se.end(); b++) {
        loc[*b] = distance(se.begin(), b);

        while (cur <= *b) {
            c[cur] = c[cur - 1];
            cur++;
        }

        c[cur++] = distance(se.begin(), b) + 1;
    }

    while (cur <= 20002)
        c[cur] = c[cur-1], cur++;

    int ans = 0;
    int l1 = -1, l2 = -1;

    for (int i = 0; i < n - 1; i++) {
        if (l1 == d[i]) continue;
        l1 = d[i];
        l2 = -1;

        for (int j = i+1; j < n; j++) {
            if (l2 == d[j]) continue;
            l2 = d[j];

            ans += c[d[i] + d[j]] - loc[d[j]];

            if (d[i] == d[j] && ca[d[i]] <= 2)
                ans --;
            if (d[i] != d[j] && ca[d[j]] == 1)
                ans --;
        }
    }


    cout << ans;
}
