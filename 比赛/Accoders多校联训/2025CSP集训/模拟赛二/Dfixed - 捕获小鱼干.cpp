// D
// expect pts = 100
// expect diff = orange
 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
typedef long long LL;
 
int n, m, web1, web2;
LL s[maxn][maxn], a[maxn][maxn];
LL ans = -0x3f3f3f3f3f3f3f3f;
 
signed main()
{
    freopen("fishing.in", "r", stdin);
    freopen("fishing.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> web1 >> web2;
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= m ; j ++)
            cin >> a[i][j];
 
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= m ; j ++)
            s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
 
    for(int i = web1 ; i <= n ; i ++)
        for(int j = web1 ; j <= m ; j ++)
        {
            LL x = i-web1+1, y = j-web1+1, xx = i, yy = j;
            ans = max(ans, s[xx][yy] - s[x-1][yy] - s[xx][y-1] + s[x-1][y-1]);
        }
 
    for(int i = web2 ; i <= n ; i ++)
        for(int j = web2 ; j <= m ; j ++)
        {
            LL x = i-web2+1, y = j-web2+1, xx = i, yy = j;
            ans = max(ans, s[xx][yy] - s[x-1][yy] - s[xx][y-1] + s[x-1][y-1]);
        }
    cout << ans;
}