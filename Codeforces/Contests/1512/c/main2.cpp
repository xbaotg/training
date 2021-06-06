#include <bits/stdc++.h>
#include<sstream>
#include<string>
#include<vector>
#include <set>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define ll long long
#define ff first
#define ss second
long long M=1000000007;
using namespace std;
ll fact[10000];
ll power(ll x, unsigned ll y, unsigned ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y / 2, m) % m; 
    p = (p * p) % m; 
  
    return (y % 2 == 0) ? p : (x * p) % m; 
} 
unsigned long long modInverse(unsigned long long n,  
                                            ll p)
{
    return power(n, p - 2, p);
}
unsigned long long nCrModPFermat(unsigned long long n,
                                 ll r, ll p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
    return (fact[n] * modInverse(fact[r], p) % p
            * modInverse(fact[n - r], p) % p)
           % p;
}
int32_t main()
{
  IOS
  ll t;
  cin>>t;
  while(t--)
  {
     ll a,b;
     cin>>a>>b;
     ll n=a+b;
     string s;
     cin>>s;
     ll z=0,o=0;
     for(ll i=0;i<n;i++)
     {
         if(s[i]=='0')z++;
         else if(s[i]=='1')o++;
     }
     if(z>a || o>b)
     {
         cout<<"-1"<<endl;
         continue;
     }
     ll l=0,r=n-1,flag=0;
     while(l<=r)
     {
         
         if(s[l]!='?')
         {
             if(s[r]=='?')
             {
                 if(s[l]=='0')
                 {
                     if(z<a)
                     {
                         s[r]='0';
                         z++;
                     }
                     else 
                     {
                         flag=1;
                         break;
                     }
                 }
                 else if(s[l]=='1')
                 {
                     if(o<b)
                     {
                         s[r]='1';
                         o++;
                     }
                     else 
                     {
                         flag=1;
                         break;
                     }
                 }
             }
             else if(s[l]!=s[r])
             {
                flag=1;
                break;
             }
         }
         else if(s[r]!='?')
         {
             if(s[l]=='?')
             {
                 if(s[r]=='0')
                 {
                     if(z<a)
                     {
                         s[l]='0';
                         z++;
                     }
                     else 
                     {
                         flag=1;
                         break;
                     }
                 }
                 else if(s[r]=='1')
                 {
                     if(o<b)
                     {
                         s[l]='1';
                         o++;
                     }
                     else 
                     {
                         flag=1;
                         break;
                     }
                 }
             }
             else if(s[l]!=s[r])
             {
                flag=1;
                break;
             }
         }
         l++;
         r--;
     }
     if(flag==1)
     {
         cout<<"-1"<<endl;
         continue;
     }
     l=0,r=n-1;
     while(l<=r)
     {
         if(l==r)
         {
             if(s[l]=='?')
             {
                 if(z<a)
                 {
                     s[l]='0';
                     z++;
                 }
                 else if(o<b)
                 {
                     s[l]='1';
                     o++;
                 }
                 else
                 {
                     flag=1;
                     break;
                 }
             }
         }
         else if(s[l]==s[r] && s[l]=='?')
         {
             if(z+1<a)
             {
                 s[l]='0';
                 s[r]='0';
                 z+=2;
             }
             else if(o+1<b)
             {
                 s[l]='1';
                 s[r]='1';
                 o+=2;
             }
             else 
             {
                 flag=1;
                 break;
             }
         }
         l++;
         r--;
     }
     if(z!=a || o!=b)
     {
         cout<<"-1"<<endl;
         continue;
     }
     l=0,r=n-1;
     while(l<=r)
     {
         if(s[l]!=s[r])
         {
             flag=1;
             break;
         }
         else if(s[l]=='?' || s[r]=='?')
         {
             flag=1;
             break;
         }
         l++;
         r--;
     }
     ll z1=0,o1=0;
     for(ll i=0;i<n;i++)
     {
         if(s[i]=='0')z1++;
         else if(s[i]=='1')o1++;
     }
     if(flag==1 || z1!=a || o1!=b)
     {
         cout<<"-1"<<endl;
     }
     else cout<<s<<endl;
  }
  return 0;
}
