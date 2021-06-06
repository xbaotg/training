#include <bits/stdc++.h>
using namespace std;

struct PriorityQueue {
    int N;
    int A[1000];

    void build(int i) {
        int l = i << 1, r = (i << 1) + 1;
        int index_new = i;
        
        if (l <= N && A[l] > A[i])
            index_new = l;

        if (r <= N && A[r] > A[index_new])
            index_new = r;  

        if (index_new != i) {
            swap(A[i], A[index_new]);
            build(index_new);
        }
    }

    void run_heap() {
        for (int i = N / 2; i >= 1; i--)
            build(i);
    }

};

int main() {
    PriorityQueue q;

    q.N = 7;

    q.A[1] = 4;
    q.A[2] = 7;
    q.A[3] = 8;
    q.A[4] = 3;
    q.A[5] = 2;
    q.A[6] = 6;
    q.A[7] = 5;


}
