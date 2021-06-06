#include <bits/stdc++.h>
using namespace std;

#define fort(x, a, b) for (int x = a; x <= b; x++)
#define ford(x, a, b) for (int x = a; x >= b; x--)
#define printv(v, sep) if (v.size() - 2 >= 1) fort(i, 0, v.size() - 2) cout << v[i] << sep; cout << v[v.size() - 1];

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>

unordered_map<char, char> ma;

bool is_right(string s, int hb, int mb) {
    string h = string(1, s[0]) + string(1, s[1]);
    string m = string(1, s[3]) + string(1, s[4]);

    if (stoi(h) >= hb || stoi(m) >= mb)
        return false;

    if (h == "24" && m == "60") 
        return true;

    string ht = "";
    string mt = "";

    if (h[0] == '0' || h[0] == '1' || h[0] == '2' || h[0] == '5' || h[0] == '8') {
        mt = ma[h[0]];
    }
    if (h[1] == '0' || h[1] == '1' || h[1] == '2' || h[1] == '5' || h[1] == '8') {
        mt = ma[h[1]] + mt;
    }
    if (m[0] == '0' || m[0] == '1' || m[0] == '2' || m[0] == '5' || m[0] == '8') {
        ht = ma[m[0]];
    }
    if (m[1] == '0' || m[1] == '1' || m[1] == '2' || m[1] == '5' || m[1] == '8') {
        ht = ma[m[1]] + ht;
    }

    if (ht.length() == 2 && mt.length() == 2) {
        //cout << ht << " - " << mt << endl;
        if (stoi(ht) < hb && stoi(mt) < mb) {
            return true;
        }
    } 

    return false;
}

void solve() {
    ma['0'] = '0';
    ma['1'] = '1';
    ma['2'] = '5';
    ma['5'] = '2';
    ma['8'] = '8';

    int hi, mi;
    cin >> hi >> mi;
    string s;
    cin >> s;

    if (is_right(s, hi, mi)) {
        cout << s << endl;
    } else {
        int h = stoi(string(1, s[0]) + string(1, s[1]));
        int m = stoi(string(1, s[3]) + string(1, s[4]));

        string hs = string(1, s[0]) + string(1, s[1]);
        string ms = string(1, s[3]) + string(1, s[4]);

        while (!is_right(hs + ":" + ms, hi, mi)) {
            if (m < mi) {
                m++;
            } else {
                m = 0;
                h++;
            }

            if (h == hi) {
                cout << "00:00" << endl;
                return;
            }

            if (h < 10)
                hs = "0" + to_string(h);
            else 
                hs = to_string(h);

            if (m < 10) 
                ms = "0" + to_string(m);
            else
                ms = to_string(m);
        }

        cout << hs << ":" << ms << endl;
    }

    // 1 -> 1
    // 2 -> 5
    // 3 -> .
    // 4 -> .
    // 5 -> 2
    // 6 -> .
    // 7 -> .
    // 8 -> 8
    // 9 -> .
    

}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}
