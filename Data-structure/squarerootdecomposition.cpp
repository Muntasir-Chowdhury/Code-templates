#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e5+10;

int ROOT_SIZE;
int BLOCK[1005];
int a[MAX];

int getID(int idx)
{
    int id = idx/ ROOT_SIZE;
    return id;
}
void init()
{
    for(int i=0;i<1005;i++)
        BLOCK[i] = 0;
}
void del(int idx)
{
    int id = getID(idx);
    BLOCK[id] -= a[idx];
    a[idx] = 0;
}
void add(int idx,int val)
{
    int id = getID(idx);
    BLOCK[id] += val;
}
int query(int l,int r)
{
    int lt = getID(l) , rt = getID(r);
    int ret = 0;

    if(lt == rt)
    {
        for(int i=l;i<=r;i++)
            ret += a[i];
        return ret;
    }
    for(int i=l;i<(lt+1)*ROOT_SIZE;i++)
        ret += a[i];

    for(int i=lt+1;i<rt;i++)
        ret += BLOCK[i];

    for(int i=rt*ROOT_SIZE;i<=r;i++)
        ret += a[i];

    return ret;

}

int main()
{

    int t,cas=1;

    scanf("%d",&t);

    while(t--)
    {
        int n,q,ty,l,r,v;

        scanf("%d%d",&n,&q);

        ROOT_SIZE = sqrt(n);
        init();

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            add(i,a[i]);
        }

        printf("Case %d:\n",cas++);
        while(q--)
        {
            scanf("%d",&ty);

            if(ty == 1)
            {
                scanf("%d",&l);
                printf("%d\n",a[l+1]);
                del(l+1);
            }
            else if(ty == 2)
            {
                scanf("%d%d",&l,&v);
                a[l+1] += v;
                add(l+1,v);
            }
            else
            {
                scanf("%d%d",&l,&r);
                printf("%d\n",query(l+1,r+1));
            }
        }
    }
}
