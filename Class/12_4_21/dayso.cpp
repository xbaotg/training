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

    int n;

    cin >> n;

    int a[n];
    for (auto &v : a) cin >> v;

    unordered_map<int, bool> used;

    FOR (i, 0, n - 1) 
        FOR (j, i + 1, n) {
            used[a[i] + a[j]] = true;
        }

    FOR (i, 0, n) {

    }
}
