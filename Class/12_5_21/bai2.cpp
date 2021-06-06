#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fort(i, a, b) for (int i = int(a); i < int(b); i++)
#define ford(i, a, b) for (int i = int(a) - 1; i >= b; i--)
#define SZ(x) ((int) x.size())
#define ALL(x) (x).begin(), (x).end()
#define F first
#define S second

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
vector<vector<vector<int>>> cal;

void gen() {
    for (auto m : {28, 30, 31}) {
        fort (i, 0, 7) {
            int r = 0, c = i, day = 1;
            vector<vector<int>> d (6, vector<int> (7, 0));

            while (day <= m) {
                d[r][c] = day++;
                if (c == 6)
                    r++, c = 0;
                else
                    c++;
            }

            cal.push_back(d);
        }
    }
}

void print_cal(vector<vector<int>> c) {
    cout << "----------------------" << endl;
    fort (i, 0, c.size()) {
        if (!c[i][0] && !c[i][6])
            break;

        cout << "|";
        fort (j, 0, 7) {
            if (c[i][j] != 0) {
                if (c[i][j] >= 10) 
                    cout << c[i][j];
                else
                    cout << " " << c[i][j];

                cout << "|";
            } else 
                cout << "  |";
        }
        cout << endl;
    }
    cout << "----------------------" << endl;
}

int main() {
    fast_io;

    gen();

    //fort (i, 0, cal.size())
        //cout << i << endl, print_cal(cal[i]);

    for (auto v : cal) {
        [&] {
            fort (i, 0, 4) {
                fort (j, 0, 5) {
                    // kiem tra co chua so 0 
                    bool ok = true;
                    fort (m, 0, 3)
                        fort (n, 0, 3)
                            if (!v[i+m][j+n])
                                ok = false;

                    if (!ok)
                        continue;

                    int s1 = v[i][j] + v[i][j+2] + 2*v[i+1][j+1] + v[i+2][j] + v[i+2][j+2];
                    double s2 = 0;

                    // tong hang, tong cot
                    fort (m, 0, 3)
                        s2 += accumulate(v[i+m].begin() + j, v[i+m].begin() + j + 3, 0);

                    s2 *= 2;
                    s2 /= 3;

                    if (s1 != s2)
                        return;
                }
            }

            print_cal(v);
        }();
    }
}
