#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e5+10;

struct data
{
    ll prop , sum;
};
data tree[4*MAX];
void update(int l,int r,int L,int R,int pos,ll v)
{
    if(l > R || r < L)
        return;
    else if(l >= L && r <= R)
    {
        tree[pos].prop += v;
        tree[pos].sum += (r-l+1)*v;
        return;
    }

    int left = 2*pos, right = 2*pos+1, mid = (l+r)/2;

    update(l,mid,L,R,left,v);
    update(mid+1,r,L,R,right,v);

    tree[pos].sum = tree[left].sum + tree[right].sum + tree[pos].prop*(r-l+1);
}
ll query(int l,int r,int L,int R,int pos,ll carry)
{
    if(l > R || r < L)
        return 0;
    else if(l >= L && r <= R)
        return tree[pos].sum + (carry*(r-l+1));

    int left = 2*pos, right = 2*pos+1, mid = (l+r)/2;

    ll x = query(l,mid,L,R,left,carry+tree[pos].prop);
    ll y = query(mid+1,r,L,R,right,carry+tree[pos].prop);

    return x+y;
}
void init()
{
    for(int i=0;i<4*MAX;i++)
        tree[i].prop = tree[i].sum = 0;
}
int main()
{
    int t,cse=1;
    cin >> t;
    while(t--)
    {
        init();
          int n,q;
          scanf("%d %d",&n,&q);

          printf("Case %d:\n",cse++);
          while(q--)
          {
              int type;
              scanf("%d",&type);
              if(type)
              {
                   int x,y;
                   scanf("%d %d",&x,&y);
                  printf("%lld\n",query(0,n-1,x,y,1,0));

              }
              else
              {
                  int x,y,v;
                  scanf("%d %d %d",&x,&y,&v);
                    update(0,n-1,x,y,1,1LL*v);
              }
          }
    }
}
