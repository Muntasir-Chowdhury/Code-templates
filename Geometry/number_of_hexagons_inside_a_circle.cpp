#include<bits/stdc++.h>
using namespace std;
#define ll long long
long double area_of_equilitrial_triangle(double a)
{
    long double area = (sqrt(3)/4.0)*a*a ;
    return area;
}
long double Hexagon_Inside_a_Circle(long double area)
{
    return area*6.0;
}
int main()
{
     int arr[10005];
    int n;
    n=10000;
    arr[1] = 1;
    arr[2] = 6 ;
    for(int i=3; i<=n; i++)
    {
        arr[i] = arr[i-1] + 6 ;
    }
    int pref[10005];
    pref[0] = 0;
    for(int i=1; i<=n; i++)
    {
        pref[i] = pref[i-1] + arr[i] ;
    }
    //cout << pref[n] << endl;
    //cout << arr[n] << endl;



   ll t;
   cin >> t;
   while(t--)
   {
       long double r;
       int n;
       cin >> n >> r;
       double aet = area_of_equilitrial_triangle(r);
       double hexa = Hexagon_Inside_a_Circle(aet);

        double tot = (double)hexa/(pref[n]*1.0) ;

        cout << fixed << setprecision(10) << tot << endl;
   }

}

