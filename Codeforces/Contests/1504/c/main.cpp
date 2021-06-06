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
    int n;
    string s;

    cin >> n;
    cin >> s;

    int oa = 0, ob = 0;
    int c1 = 0;
    string a = "", b = "";
    vector<int> l;

    FOR (i, 0, n) {
        if (s[i] == '1') {
            if (oa == 0 || ob == 0) {
                oa++, ob++;
                a += "(", b += "(";
            } else {
                oa--, ob--;
                a += ")", b += ")";

                c1++;
                l.push_back(i);
                //cout << "-" << i << endl;
            }
        } else {
            if (oa == 0 && ob == 0) {
                if (c1) {
                    oa+=2, ob+=2, a[l[c1 - 1]] = '(', b[l[c1 - 1]] = '(', l.pop_back(), c1--;
                    if (oa > ob)
                        oa--, ob++, a += ")", b += "(";
                    else
                        ob--, oa++, a += "(", b += ")";
                }
                else {
                    cout << "NO\n"; return;
                }                    
            } else {
                if (oa == 0) 
                    oa++, ob--, a += "(", b += ")";
                else if (ob == 0)
                    ob++, oa--, b += "(", a += ")";
                else {
                    if (oa > ob)
                        oa--, ob++, a += ")", b += "(";
                    else
                        ob--, oa++, a += "(", b += ")";
                }
            }
        }
        //cout << a << " - " << b << " . " << oa << " - " << ob << endl;
    }

    //cout << oa << " " << ob << endl;
    if (oa == 0 && ob == 0) {
        cout << "YES\n";
        cout << a << endl << b << endl;
    } else 
        cout << "NO\n";
}

// (((
// ()
