// F
// expect pts =
// expect diff =
 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
typedef long long LL;
 
LL n;
 
signed main()
{
    freopen("data.in", "r", stdin);
    freopen("user.out", "w", stdout);
    cin >> n;
    LL mx = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        LL a, b;
        cin >> a >> b;
        mx = max(mx, b - a);
    }
    cout << n * mx;
}