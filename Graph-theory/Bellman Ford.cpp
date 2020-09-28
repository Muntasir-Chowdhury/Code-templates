#include<bits/stdc++.h>
using namespace std;
long long int dist[10000];
vector<pair<int,int> > vec[10000];
void BF(int src,int nodes)
{
    fill(dist,dist+nodes+1,INT_MAX);
    dist[src]=0;
    int i,flg=0,j,k,u,w;
    for(i=1; i<nodes; i++)
        for(j=1; j<=nodes; j++)
            for(k=0; k<vec[j].size(); k++)
            {
                u=vec[j][k].first;
                w=vec[j][k].second;
                if(dist[j]+w<dist[u])
                {
                    dist[u]=dist[j]+w;
                }
            }
    for(j=1; j<=nodes; j++)
        for(k=0; k<vec[j].size(); k++)
        {
            u=vec[j][k].first;
            w=vec[j][k].second;
            if(dist[j]+w<dist[u])
            {
                flg=1;
                dist[u]=dist[j]+w;
            }
        }
    if(flg==1)
    {
        cout<<"not possible";
    }
    else
    {
        for(i=1; i<=nodes; i++)
            cout<<dist[i]<<" ";
    }
}
int main()
{

    int a,b,c,nodes,edges,src;
    cin>>nodes>>edges;
    while(edges--)
    {
        cin>>a>>b>>c;
        vec[a].push_back(make_pair(b,c));
       // graph[b].push_back(make_pair(a,c));
    }
    cin>>src;
    BF(src,nodes);

    return 0;
}
