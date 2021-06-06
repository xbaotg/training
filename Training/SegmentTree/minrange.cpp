// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;

        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends


/* The functions which 
builds the segment tree */

int construct(int* st, int arr[], int node, int l, int r) {
    if (l == r) {
        return st[node] = arr[l];
    }
    
    int m = (l + r) >> 1;
    return st[node] = min(construct(st, arr, 2*node, l, m), construct(st, arr, 2*node+1, m+1, r)); 
}

int *constructST(int arr[],int n)
{
    int* st = new int[4*n+1];
    construct(st, arr, 1, 0, n - 1);
    return st;
}

int query(int* st, int node, int l, int r, int s, int e) {
    if (s <= l && r <= e) 
        return st[node];
    if (r < s || l > e)
        return INT_MAX;
        
    int m = (l + r) >> 1;
    
    return min(query(st, 2*node, l, m, s, e), query(st, 2*node + 1, m + 1, r, s, e));
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
    return query(st, 1, 0, n - 1, a, b);
}
