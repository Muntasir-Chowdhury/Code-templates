#include<bits/stdc++.h>
using namespace std;
long long vec[1000][1000];
void warshal()
{
    int i,j,k;
    for(i=0; i<1000; i++)
        for(j=0; j<1000; j++)
            if(i==j)
                vec[i][j]=0;
            else
                vec[i][j]=INT_MAX;

    int nodes,edges,a,b,c;
    cin>>nodes>>edges;
    while(edges--)
    {
        cin>>a>>b>>c;
        vec[a][b]=c;
    }
    for(k=1; k<=nodes; k++)
        for(i=1; i<=nodes; i++)
            for(j=1; j<=nodes; j++)
            {
               vec[i][j]=min(vec[i][j],vec[i][k]+vec[k][j]);
            }

    for(i=1; i<=nodes; i++)
    {
        for(j=1; j<=nodes; j++)
            cout<<vec[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    warshal();
}
