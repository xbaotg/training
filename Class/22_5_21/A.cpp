#include <bits/stdc++.h>
using namespace std;

#define fast_io        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FOR(i, a, b)   for (int i = int(a); i <= int(b); i++)
#define FOD(i, a, b)   for (int i = int(a); i >= int(b); i--)
#define SZ(x)          ((int) x.size())
#define ALL(x)         (x).begin(), (x).end()
#define F              first
#define S              second
#define ep             emplace_back

using ll = long long;

template<class T> void read(T &x) { cin >> x; };
template<class T> void read(vector<T> &v, int n) { FOR (i, 0, n - 1) cin >> v[i]; };
template<class T> void read(vector<T> &v, int f, int t) { FOR (i, f, t) cin >> v[i]; };
template<class T> void read(T v[], int n) { FOR(i, 0, n - 1) cin >> v[i]; }; 
template<class H, class... T> void read(H &v, T&... args) { read(v); read(args...); };
//-----------------------------------------------------------------------------

char a[5][5];

void no() {
    cout << "This puzzle has no final configuration.";
    exit(0);
}

void checkUp() {
    FOR (i, 0, 4) {
        // dong dau tien la khoang trong
        if (a[0][i] == ' ') no();

        // khong co 2 dau cach canh nhau
        FOR (j, 0, 3) if (a[j][i] == ' ' && a[j+1][i] == ' ') no();

        // hoan doi
        FOR (j, 1, 4) 
            if (a[j][i] == ' ')
                swap(a[j][i], a[j-1][i]);
    }
}

void checkDown() {
    FOR (i, 0, 4) {
        // dong cuoi la khoang trong
        if (a[4][i] == ' ') no();

        // khong co 2 dau cach canh nhau
        FOR (j, 0, 3) if (a[j][i] == ' ' && a[j+1][i] == ' ') no();

        // hoan doi
        FOD (j, 3, 0) 
            if (a[j][i] == ' ')
                swap(a[j][i], a[j+1][i]);
    }
}

void checkLeft() {
    FOR (i, 0, 4) {
        // cot dau tien la khoang trong
        if (a[i][0] == ' ') no();

        // khong co 2 dau cach canh nhau
        FOR (j, 0, 3) if (a[i][j] == ' ' && a[i][j+1] == ' ') no();

        // hoan doi
        FOR (j, 1, 4) 
            if (a[i][j] == ' ')
                swap(a[i][j], a[i][j-1]);
    }
}

void checkRight() {
    FOR (i, 0, 4) {
        // cot cuoi la khoang trong
        if (a[i][4] == ' ') no();

        // khong co 2 dau cach canh nhau
        FOR (j, 0, 3) if (a[i][j] == ' ' && a[i][j+1] == ' ') no();

        // hoan doi
        FOD (j, 3, 0) 
            if (a[i][j] == ' ')
                swap(a[i][j], a[i][j+1]);
    }
}

int main() {
    fast_io;
    string s;
    
    FOR (i, 0, 4) {
        getline(cin, s);
        cin.ignore(1000, '\n');
        while (s.length() < 5) s += " ";

        FOR (j, 0, 4)
            a[i][j] = s[j];
    }

    string c;
    cin >> c;

    c.pop_back();

    for (auto v : c) {
        if (v == 'A') checkUp();
        if (v == 'B') checkDown();
        if (v == 'L') checkLeft();
        if (v == 'R') checkRight();
    }

    FOR (i, 0, 4)
        FOR (j, 0, 4)
            cout << a[i][j] << " \n"[j == 4];

}
