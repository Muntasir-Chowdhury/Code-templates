#include<bits/stdc++.h>
using namespace std;
int cost[100000];
vector< pair <int,int> >vec[100000];
void dijkstra(int src)
{
    priority_queue< pair<int,int> >q;
    q.push(make_pair(0,src));
    cost[src]=0;
    while(!q.empty())
    {
        int pcost=q.top().first*-1;
        int parent=q.top().second;
        q.pop();
        if(pcost>cost[parent])continue;

        for(int i=0; i<vec[parent].size(); i++)
        {
            int chcost=vec[parent][i].first;
            int child=vec[parent][i].second;
            if(cost[child]==-1 || cost[child]>chcost+cost[parent])
            {
                cost[child]=chcost+cost[parent];
                q.push(make_pair(-1*cost[child],child));
            }
        }
    }
}
int main()
{
    int a,b,c,d,n,s,t,m;
    fill(cost,cost+10000,-1);
    int x,y;
    cin>>x>>y;
    while(y--)
    {
        cin>>a>>b>>c;
        vec[a].push_back(make_pair(c,b));
        vec[b].push_back(make_pair(c,a));
    }
    dijkstra(s);
    cout<<cost[t]<<endl;




    return 0;
}
