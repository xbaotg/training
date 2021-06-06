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
    freopen("input", "r", stdin);

    int n;

    cin >> n;
    cin.ignore();

    vector<pair<string, double>> d (n);
    vector<string> names;

    for (auto &v : d) {
        getline(cin, v.first), cin >> v.second, cin.ignore();
        names.emplace_back(v.first);
    }

    // 
    cout << "Cau A: " << endl;

    auto split = [](string s) {
        vector<string> res;
        s += " ";

        int idx = 0, l;
        while ((l = s.find(" ", idx)) != -1) {
            string t = s.substr(idx, l - idx);
            if (t != " ") 
                res.emplace_back(t);
            idx = l + 1;
        }
        return res;
    };

    sort(names.begin(), names.end(), [&split](string a, string b) {
        auto spA = split(a);
        auto spB = split(b);

        int na = spA.size() - 1;
        int nb = spB.size() - 1;

        if (spA[na] != spB[nb])
            return spA[na] < spB[nb];
        else {
            FOR(i, 0, min(na, nb) - 1) 
                if (spA[i] != spB[i])
                    return spA[i] < spB[i];

            return na <= nb;
        }
    });

    for (string s : names)
        cout << s << endl;


    cout << "---------------------\n";
    cout << "Cau B: " << endl;

    set<string> s;
    for (auto v : names) {
        auto sp = split(v);
        s.emplace(sp[sp.size() - 1]);
    }

    cout << s.size() << endl;

    for (string v : s)
        cout << v << endl;


    cout << "---------------------\n";
    cout << "Cau C: " << endl;

    sort(d.begin(), d.end(), [](pair<string, double> a, pair<string, double> b) {
        return a.second > b.second;
    });

    FOR (i, 0, min(3, (int) d.size())) {
        cout << d[i].first << endl;
    }
}
