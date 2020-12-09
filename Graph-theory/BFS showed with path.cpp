#include<bits/stdc++.h>
using namespace std;
int dis[10000],path[10000];
vector<int>vec[10000];
int n,m,s;
void bfs()
{
    dis[s] = 0;
    path[s] = s;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
        for(int i=0; i<vec[parent].size(); i++)
        {
            int child = vec[parent][i];
            if(dis[child]>dis[parent]+1)
            {
                dis[child] = dis[parent] + 1;
                path[child] = parent;
                q.push(child);
            }
        }
    }

}

int main()
{

    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
        path[i] = -1;
    }
    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    cin >> s;

    bfs();

    int mx = 0;
    for(int i=0; i<n; i++)
    {
        if(i!=s)
        {
            if(path[i]!=-1)
            {
                int d = i ;
                int road[n+10];
                int k = 0;
                printf("Path from source %d to %d: ",s,i);
                road[k++] = d;
                while(path[d]!=d)
                {
                    road[k++] = path[d];
                    d = path[d];
                }
                for(int j=k-1; j>=0; j--)
                    cout << road[j] << " " ;
                cout << endl;
                cout << endl;
            }
            else
            {
                printf("%d unreachable.\n\n",i);
            }
        }
    }


}


