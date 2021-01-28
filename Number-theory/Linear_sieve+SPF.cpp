#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 9, M = 5e5 + 9;

int spf[N];///smallest prime factor
vector<int> prime;
bool pr[N];
void linear_sieve() {
    for(int i=2;i<N;i++){
        if(spf[i]==0) spf[i]=i,pr[i]=true,prime.push_back(i);
        int sz=prime.size();
        for(int j=0;j<sz&&i*prime[j]<N&&prime[j]<=spf[i];j++) spf[i*prime[j]]=prime[j];
    }
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	linear_sieve();
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
    {
        cout << pr[i] << " " ;
    }


    return 0;
}
