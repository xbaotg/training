#include <bits/stdc++.h>
using namespace std;

string a = "AEASDFG";
string b = "EDFG";

int lcs(int i, int j) {
    if (j < 0 || i < 0) {
        return 0;
    }

    if (a[i] == b[j])
        return 1 + lcs(i-1, j-1);

    return max(lcs(i-1, j), lcs(i, j-1));
}

int main() {
    cout << lcs(a.length() - 1, b.length() - 1);
}
