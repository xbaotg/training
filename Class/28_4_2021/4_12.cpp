#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fort(i, a, b) for (int i = a; i < b; i++)
#define ford(i, a, b) for (int i = a; i > b; i--)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

const int MOD = 1000000007;
const int INF = INT_MAX;

int plus_mod(unsigned int a, unsigned int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int minus_mod(unsigned int a, unsigned int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
int mul_mod(unsigned int a, unsigned int b) { return ((a % MOD) * 1LL * (b % MOD)) % MOD; }
int lcm(unsigned int a, unsigned int b) { return a * 1LL * b / __gcd(a, b); }
int gcd(unsigned int a, unsigned int b) { return __gcd(a, b); }

//-----------------------------------------------------------------------------
string s;
int m, n;
int r[10];

void f(int i, int c) {
    if (i == n) {
        if (c == m) {
            fort (j, 0, n) {
                if (r[j] > 0)
                    cout << "+";
                if (r[j] < 0) 
                    cout << "-";
                if (r[j] != 0) 
                    cout << (s[j] - '0') * abs(r[j]);
            }
            cout << endl;
        }
        return;
    }

    fort (j, -1, 2) { // tu -1 -> 1
        r[i] = j;
        f(i + 1, c + (s[i] - '0') * j);
    }
}

int main() {
    fast_io;

    cin >> s;
    cin >> m;
    n = s.length();

    f(0, 0);
}
