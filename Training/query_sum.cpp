#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inf("IDP1104B.INP", ios::in); 
    ofstream outf("IDP1104B.OUT", ios::out); 

    int n; inf >> n;
    int a[n]; for (auto &v : a) inf >> v;
    int q; inf >> q;

    int f[n + 1];
    f[0] = 0;
    for (int i = 0; i < n; i++) f[i + 1] = f[i] + a[i];

    while (q--) {
        int x, y;
        inf >> x >> y;

        outf << f[y] - f[x - 1] << endl;
    }
}
