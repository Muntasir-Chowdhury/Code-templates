#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <ll> primes;
#define MAXP 100005
bool num[MAXP+100];
void sieve()
{

    primes.push_back(2);

    for(ll i=2;i<=MAXP;i+=2)
        num[i]=1;
    for(ll i=3;i<=MAXP;i+=2)
    {
        if(num[i]==0)
        {

                primes.push_back(i);

            for(ll j=i*2 ;j<=MAXP;j+=i)
                num[j]=1;
        }
    }

}
ll phi[200000];

ll lim=100000;

ll arr[400006];

void Numbers_of_relatively_prime()
{
    for(ll i=1;i<=lim;i++) phi[i]=i;

    ll x=primes.size();

    for(ll i=0;i<x;i++)
    {
        ll U=primes[i];

        for(ll j=U;j<=lim;j+=U)
        {
            phi[j]=(phi[j]*(U-1))/U;
        }
    }

}

int main()
{
    sieve();
    Numbers_of_relatively_prime();
     ll xx;
     cin >> xx;
    for(ll i=1; i<=xx; i++)
    {
        cout << phi[i] << ' ' ;
    }
    cout << endl;


}

