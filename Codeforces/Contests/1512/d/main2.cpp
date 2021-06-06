// Anik Maji KGEC
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std; 
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deba(a) for(auto x:a) cout<<x<<" " 
#define fr(i,n) for(i=0;i<n;i++) 
#define ll long long
#define pb push_back
#define F first
#define S second
typedef vector<ll>		vl;
const int mod = 1e9+7;
//=======================
ll gcd(ll a,ll b) { if (a == 0) return b; return gcd(b % a, a);}
inline ll lcm(ll a,ll b){ return a / gcd(a, b) * b;}

ll floor(ll n,ll k){
    if(n%k == 0 || n >= 0)return n/k;
    return (n/k)-1;
}
 
ll ceil(ll n,ll k){
    return floor(n+k-1,k);
}

ll pow(ll a, ll b) {
    ll res=1;
    while(b) {
        if(b&1) res=(res*a);
        a=(a*a);
        b>>=1;
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    ll T, i, j, n, m, k;
	cin>>T;
	while(T--)
	{
        cin>>n;
        n+=2;
        ll a[n];
        ll sum=0;
        map<ll,ll> mp;
        fr(i,n){
             cin>>a[i];    
             sum+=a[i];
             mp[a[i]]++;
        }
        //deb(sum);
        ll f=0;
        fr(i,n){
                            //deb(sum)
            mp[a[i]]--;
            sum-=a[i];
            if(sum%2==0){
            ll tmp=sum/2;
            if(mp[tmp]){
                //deb2(a[i],tmp);
                mp[tmp]--;
                f=1;
                for(auto x:mp){
                    while(x.S>0)
                    {
                        cout<<x.F<<" ";
                        x.S--;
                    }
                }
                cout<<"\n";
                break;
            }
            }
            mp[a[i]]++;
            sum+=a[i];
        }
        if(f==0) cout<<"-1\n";
	}
    return 0;
}
