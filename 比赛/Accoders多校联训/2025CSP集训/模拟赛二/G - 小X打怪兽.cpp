// G
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10, mod = 1e9+7;
 
int n;
int a[maxn];
int ans;
 
signed main()
{
    freopen("data.in", "r", stdin);
    freopen("user.out", "w", stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
 
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = i ; j <= n ; j ++)
        {
            ans = (ans + a[j]) % mod;
        }
    }
    cout << ans;
}
