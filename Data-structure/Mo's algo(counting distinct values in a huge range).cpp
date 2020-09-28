
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
int arr[MAX],sz=1000,q,ans[MAX],mp[MAX],num[MAX],it,cnt;
ll L,R;


struct tree
{
    int lft, rgt, id;
    tree() {};
    tree(int lft, int rgt, int id)
        : lft(lft), rgt(rgt), id(id)
    {
    }
} mo[MAX];
bool cmp(tree a,tree b)
{
    if((a.lft/sz)<(b.lft/sz))
        return 1;
    if((a.lft/sz)>(b.lft/sz))
        return 0;
    if(a.rgt<b.rgt)
        return 1;
    else
        return 0;
}
void add(int x)
{
    mp[x]++;
    if(mp[x]==1)
        cnt ++;
}
void del(int x)
{
    mp[x]--;
    if(mp[x]==0)
        cnt--;
}
int query(int l,int r)
{
    while(R < r)
    {
        R++;
        add(arr[R]);
    }
    while(R > r)
    {
        del(arr[R]);
        R--;
    }
    while(L < l)
    {
        del(arr[L]);
        L++;
    }
    while(L > l)
    {
        L--;
        add(arr[L]);
    }
    return cnt;
}
void query_processing()
{
    L=mo[0].lft,R=mo[0].rgt;
    for(int i=L; i<=R; i++)
        add(arr[i]);
    ans[mo[0].id]=cnt;
    for(int i=1; i<q; i++)
    {
        ans[mo[i].id]=query(mo[i].l,mo[i].r);
    }
}
int main()
{

    int n;
    cin>>n>>q;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
           }
    it=n;

    for(int i=0; i<q; i++)
    {
        int l,r;
        cin>>l>>r;
        mo[i]=tree(l-1,r-1,i);
    }
    sort(mo,mo+q,cmp);
    query_processing();
    for(int i=0; i<q; i++)
        cout<<ans[i]<<endl;
    return 0;
}
