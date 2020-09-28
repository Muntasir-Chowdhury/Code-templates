#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
int div[MAX];
void Number_of_Divisors()
{
    for(int i=1; i<=MAX; i++)
    {
        for(int j=i; j<=MAX; j+=i)
        {
            div[j]++;
        }
    }
}

int main()
{
    Number_of_Divisors();
    int t;
    cin >> t;
    while(t--){
    int x;
    cin >> x;

        cout << div[x] << endl;
    }

}
