#include<bits/stdc++.h>
using namespace std;
#define MAX          (int)1e6+5
#define ll           unsigned long long
int base = 13331;
ll H[MAX],save[MAX];
void init()
{
    save[0] = 1;
    for(int i=1;i<MAX;i++)
        save[i] = save[i-1]*base;
}
void build_hash(string s)
{
    H[0] = 1;
    for(int i=1;i<s.size();i++)
        H[i] = H[i-1]*base + s[i];
}
ll hash_value(int l,int r)
{
    return H[r]-save[r-l+1]*H[l-1];
}
int main()
{

    string s;
    cin >> s;
    init();
    s = "#"+s;
    build_hash(s);
    ll lft,rght;
    cin >> lft >> rght ;
    cout << hash_value(lft,rght) << endl;
}

