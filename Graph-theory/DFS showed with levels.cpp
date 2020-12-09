#include<bits/stdc++.h>
using namespace std;
vector<int>vec[10000],path,dpth[10000];
int n,m,s;
int dis[10000],visit[10000];
void dfs(int src)
{
    if(s==src)dis[src] = 0;
    visit[src] = 1;
    for(int i=0; i<vec[src].size(); i++)
    {
        int child = vec[src][i];
        if(dis[src]+1<dis[child])
        {
            dis[child] = dis[src]+1;
            dfs(child);
        }
    }
}

int main()
{

   cin >> n >> m;
   for(int i=0; i<n; i++)
   {
       dis[i] = INT_MAX;
   }
   for(int i=1; i<=m; i++)
   {
       int a,b;
       cin >> a >> b;
       vec[a].push_back(b);
       vec[b].push_back(a);
   }
   cin >> s;

   dfs(s);
   dpth[0].push_back(s);
   int mx = 0;
   for(int i=0; i<n; i++)
   {
       if(i!=s)
       {
           if(dis[i]!=INT_MAX)
           {
               int level  = dis[i];
               mx = max(mx,level);
               dpth[level].push_back(i);


           }

       }
   }
   printf("Levels:\n");

   for(int i=0; i<=mx; i++)
   {
       printf("Level %d: ",i);
       for(int j=0; j<dpth[i].size(); j++)
       {
           if(!j)cout << dpth[i][j] ;
           else
           cout<< " " << dpth[i][j] ;
       }
       cout << endl;
   }

}
