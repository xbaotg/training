#include <bits/stdc++.h>
using namespace std;

void merge(int* a, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int i = 0, j = 0, k = l;

    int L[n1], R[n2];
    copy_n(a + l, n1, L);
    copy_n(a + m + 1, n2, R);

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }

    while (i < n1) 
        a[k++] = L[i++];
    while (j < n2) 
        a[k++] = R[j++];
}

void mergeSort(int* a, int l, int r) {
    if (l >= r) {
        return;
    }
        
    int m = l + (r - l)/2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);

    merge(a, l, m, r);
}

int main() {
    srand(time(NULL));

    int n;
    cin >> n;

    int a[n];
    for (auto &v : a) v = rand() % 100 + 1, cout << v << " ";
    cout << endl;

    mergeSort(a, 0, n - 1);

    for (auto &v : a) cout << v << " ";
}
