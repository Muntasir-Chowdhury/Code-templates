#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
int tree[MAX];
int query(int idx){
       int sum=0;
       while(idx>0){
             sum+=tree[idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update(int idx, int x, int n) //n is the size of the array, x is the number to add
{
       while(idx<=n)
       {
             tree[idx]+=x;
             idx += idx & (-idx);
       }
}

int main()
{
    int n,q;
    cin >> n >> q;
    int ara[n+10];
    for(int i=1; i<=n; i++)
    {
        cin >> ara[i];
        update(i,ara[i],n);
    }
    while(q--)
    {
        int a,b,c;
        cin >> a ;
        if(a==1)
        {
            cin >> b;
            cout << query(b) << endl;
        }
        else
        {
            cin >> b >> c;
            update(b,-1*ara[b],n);
            ara[b] = c;
            update(b,ara[b],n);
        }
    }





}
