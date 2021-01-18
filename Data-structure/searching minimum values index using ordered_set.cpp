#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree< int, null_type, less_equal <int>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

const int sz = 1e5 + 5;
int n, a[sz], b[sz];


int main()
{
    ordered_set os;

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++)
    {
        os.insert(a[i]);
        cout << *os.find_by_order(b[i]-1) << endl;
    }



    return 0;
}
