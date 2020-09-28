
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e6;

ll arr[MAX],tree[MAX],st[MAX],en[MAX];
vector<int>vec[MAX],euler_path;
void dfs(int src,int par)
{
    euler_path.push_back(src);
    bool mrk=0;
    for(auto i:vec[src])
    {
        if(i==par)
            continue;
        mrk=1;
        dfs(i,src);
    }
    if(mrk)
        euler_path.push_back(src);
}
void init_euler_path()
{
    dfs(1,0);
    int idx=1;
    for(auto i:euler_path)
    {
        if(st[i]==0)
            st[i]=idx;
        en[i]=idx;
        idx++;
    }
}

int main()
{

    int n,q;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    init_euler_path();

    int sz=euler_path.size()+2;
    for(int i=0; i<euler_path.size(); i++)
        cout << euler_path[i] << " " ;
    cout << endl;



}
