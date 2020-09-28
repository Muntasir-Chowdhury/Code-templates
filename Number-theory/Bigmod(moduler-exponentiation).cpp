ll Bigmod
(ll a,ll b,ll mod)
{
    ll d=1;
    while(b)
    {
        if(b%2)
            d=(d*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return d;
}

