#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

#ifdef LOCAL
    #define deb(x) cout<<"LINE("<<__LINE__<<"): "<<(#x)<<" = "<<(x)<<endl; 
#else
    #define deb(...)
#endif

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FOD(i, a, b) for (int i = a; i > b; i--)

#define push_back pb
#define mod 1000000007

typedef long int32;
typedef unsigned long uint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve();

//-----------------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while (t--) 
        solve();
}

void solve() {
    int a = 0, b = 0;
    cin >> a >> b;

    string s;
    cin >> s;

    int n = s.length();
    int count[] = {0, 0};

    int t = a;

    FOR (i, 0, floor(1.0 * n / 2)) {
        if (s[i] != s[n - i - 1]) {
            int c = (s[i] == '?') + (s[n - i - 1] == '?');
            if (c) {
                if (c == 1) {
                    if (s[i] == '?')
                        s[i] = s[n - i - 1];
                    else
                        s[n - i - 1] = s[i];

                    count[s[i] - '0'] += 2;
                }
            } else {
                cout << -1 << endl;
                return;
            }
        } else 
            if (s[i] != '?')
                count[s[i] - '0'] += 2;
    }

    if (n % 2 == 1 && s[n / 2] != '?')
        count[s[n / 2] - '0']++;

    int r0 = t - count[0];
    int r1 = b - count[1];

    
    if (r0 < 0 || r1 < 0) {
        cout << -1 << endl;
        return;
    } 

    if (r0 % 2 == 1 && r1 % 2 == 1) {
        cout << -1 << endl;
        return;
    }

    if (r0 % 2 == 1 || r1 % 2 == 1) {
        if (n % 2 == 1 && s[n / 2] == '?') {
            if (r0 % 2 == 1) {
                s[n / 2] = '0';
                r0--;
            } else {
                s[n / 2] = '1';
                r1--;
            }
        } else {
            cout << -1 << endl;
            return;
        }
    }

    if (r0 % 2 == 0 && r1 % 2 == 0) {
        FOR (i, 0, n / 2) {
            if (s[i] == '?') {
                if (r0) {
                    s[i] = '0';
                    s[n - i - 1] = '0';
                    r0-=2;
                } else {
                    s[i] = '1';
                    s[n - i - 1] = '1';
                    r1-=2;
                }
            }
        }

        cout << s << endl;
    } else
        cout << -1 << endl;
}
