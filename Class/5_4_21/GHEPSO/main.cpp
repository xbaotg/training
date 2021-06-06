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

    sort(a, a + n, [](int x, int y) {
        string a = to_string(x);
        string b = to_string(y);

        FOR (i, 0, min(a.length(), b.length())) {
            if (a[i] != b[i])
                return a[i] > b[i];
        }

        return true;
    });

    for (auto v : a)
        cout << v;
}
