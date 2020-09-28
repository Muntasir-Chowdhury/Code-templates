#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = (int)1e9+7;
const int MAX = 1e6;

vector<int>vec[1000005];
bool visit[1000005];
int connection[1000005];
bool BPM(int node)
{
    int sz=vec[node].size();
    for(int i=0; i<sz; i++)
    {
        int child=vec[node][i];
        if(visit[child]==0)
        {
            visit[child]=1;
            if(connection[child]<0 || BPM(connection[child]))
            {
                connection[child]=node;
                return true;
            }
        }
    }
    return false;
}
int BPM_COUNT(int n)
{
    memset(connection,-1,sizeof(connection));
    int res=0;
    for(int i=0; i<n; i++)
    {

        memset(visit,0,sizeof(visit));
        if(BPM(i))
            res++;

    }
    return res;
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        vec[a].push_back(b);
    }
    cout<<BPM_COUNT(n)<<endl;
    return 0;
}
