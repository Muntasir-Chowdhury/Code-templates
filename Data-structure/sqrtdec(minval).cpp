#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e5+10;
const int inf = 2e9;

int BLOCK_SIZE;
int BLOCK[1005];
int a[MAX];

int getID(int idx)
{
    int id = idx/BLOCK_SIZE;
    return id;
}
void init()
{
    for(int i=0;i<1005;i++)
        BLOCK[i] = inf;
}

void add(int idx,int val)
{
    int id = getID(idx);
    BLOCK[id] = min(BLOCK[id],val);
}
int queryMax(int l,int r)
{
    int lt = getID(l) , rt = getID(r);
    int ret = inf;

    if(lt == rt)
    {
        for(int i=l;i<=r;i++)
            ret = min(ret,a[i]);
        return ret;
    }
    for(int i=l;i<(lt+1)*BLOCK_SIZE;i++)
        ret = min(ret,a[i]);

    for(int i=lt+1;i<rt;i++)
        ret = min(ret,BLOCK[i]);

    for(int i=rt*BLOCK_SIZE;i<=r;i++)
        ret = min(ret,a[i]);

    return ret;

}
int main()
{

    int t,cas=1;

    scanf("%d",&t);

    while(t--)
    {
        int n,q,ty,l,r;

        scanf("%d%d",&n,&q);

        BLOCK_SIZE = sqrt(n);
        init();

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            add(i,a[i]);
        }

        printf("Case %d:\n",cas++);
        while(q--)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",queryMax(l,r));
        }
    }
}
