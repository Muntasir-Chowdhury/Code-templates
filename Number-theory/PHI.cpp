#include<bits/stdc++.h>
using namespace std;
const int Max = 1e5+100;
ll phi[Max];
void phigen(int n)
{
    for(int i=1; i<=n; i++)
    {
        phi[i] = i;
    }
    for(int p=2; p<=n; p++)
    {
        if(phi[p]==p){
            phi[p] = p-1;
            for(int i=2*p; i<=n; i+=p)
            {
                phi[i] = (phi[i]/p)*(p-1) ;
            }
        }
    }
}
int main()
{

}
