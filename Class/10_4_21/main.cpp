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

bool ok(int wc[], int tc[], int size) {
    return equal(wc, wc + size, tc);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int g, n, res = 0;
    cin >> g >> n;

    string w, s;
    cin >> w;
    cin.ignore();
    cin >> s;

    int size = 'z' - 'A';
    int wc[size], tc[size];
    memset(wc, 0, sizeof wc);
    memset(tc, 0, sizeof tc);

    for (auto ch : w) wc[ch - 'A']++;
    
    FOR (i, 0, g) tc[s[i] - 'A']++;

    res += ok(wc, tc, size);
    
    FOR (i, g, n) {
        tc[s[i - g] - 'A']--, tc[s[i] - 'A']++;

        if (tc[s[i] - 'A'] == wc[s[i] - 'A'])
            res += ok(wc, tc, size);
    }

    cout << res << endl;
}
