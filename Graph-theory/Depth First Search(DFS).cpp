#include<bits/stdc++.h>
using namespace std;
int visit[10000],dist[10000];
vector<int> vec[10000];
void dfs(int src)
{
    visit[src] = 1;
    for(int i=0; i<vec[src].size(); i++)
    {
        int node = vec[src][i];
        if(visit[node] == 0)
        {
            dist[node] = dist[src]+1;
            dfs(node);
        }
    }
}
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(1);

}
