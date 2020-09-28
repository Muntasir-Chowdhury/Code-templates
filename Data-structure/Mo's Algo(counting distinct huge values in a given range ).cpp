#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MOD = (int)1e9+7;
const int MAX = 1e6;

int arr[MAX],sz=1000,q,ans[MAX],mp[MAX],init_arr[MAX],num[MAX],it,cnt;
ll L,R;
void array_compression()
{
    sort(init_arr,init_arr+it);
    int cnt=1;
    num[0]=cnt++;
    for(int i=1; i<it; i++)
    {
        if(init_arr[i]!=init_arr[i-1])
            num[i]=cnt++;
        else
            num[i]=num[i-1];
    }
}
int bs(int val)
{
    int l=0,r=it-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(init_arr[mid]==val)
            return num[mid];
        if(init_arr[mid]<val)
            l=mid+1;
        else
            r=mid-1;
    }
}
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
    L=mo[0].lft,R=mo[0].rft;
    for(int i=L; i<=R; i++)
        add(arr[i]);
    ans[mo[0].id]=cnt;
    for(int i=1; i<q; i++)
    {
        ans[mo[i].id]=query(mo[i].lft,mo[i].rgt);
    }
}
int main()
{
   int n;
    cin>>n>>q;
    for(int i=0; i<n; i++)
    {

        scanf("%d",&arr[i]);
        init_arr[i]=arr[i];
    }
    it=n;
    array_compression();
    for(int i=0; i<n; i++)
        arr[i]=bs(arr[i]);
    for(int i=0; i<q; i++)
    {
        int lft,rgt;
        scanf("%d%d",&lft,&rgt);
        mo[i]=tree(lft-1,rgt-1,i);
    }
    sort(mo,mo+q,cmp);
    query_processing();
    for(int i=0; i<q; i++)
        cout<<ans[i]<<endl;
    return 0;
}
