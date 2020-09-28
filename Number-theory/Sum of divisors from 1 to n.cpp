#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
ll Sum_of_Divisors(ll n)
{
    ll i=1,root,m,k,sum=0;
    root=sqrt(n);
    while(i<=root)
    {
        sum+=(i*(n/i));
        i+=1;
    }
    i=1;
    while(i<=(n/(root+1)))
    {
        m = n/i;
        k =n/(i+1);
        sum+=(i*(m*(m+1)- k* (k+1))/2);
        i += 1;
    }
    return sum;
}
int main()
{

    ll n;
    scanf("%lld",&n);
    printf("%lld\n",Sum_of_Divisors(n)%MOD);


    return 0;
}
