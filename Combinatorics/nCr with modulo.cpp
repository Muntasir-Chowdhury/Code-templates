#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, r, t, i, ans, cs=1, up, dwn, fac[1000009];
const ll mod=1000003;

ll bigmod(ll b, ll p){
    if(p==0) return 1;
    ll x=bigmod(b, p/2);
    x=(x*x)%mod;
    if(p%2==1)x=(x*b)%mod;
    return x;
}

int main(){
    fac[0]=1;
    for(i=1; i<=1000000; i++){
        fac[i]=(fac[i-1]*i)%mod;
    }

    cin>>t;
    while(t--){
        cin>>n>>r;
        up=fac[n];
        dwn=(fac[n-r]*fac[r])%mod;
        ans=up*bigmod(dwn, mod-2);
        cout<<"Case "<<cs++<<": "<<ans%mod<<endl;
    }
    return 0;
}
