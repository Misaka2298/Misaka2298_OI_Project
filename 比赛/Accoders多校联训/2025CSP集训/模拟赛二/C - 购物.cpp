// C
// expect pts = 100
// expect diff = idk
#include <bits/stdc++.h>
using namespace std;
const int maxn = 22;
typedef long long LL;
 
LL n, m;
LL a[maxn], b[maxn];
LL ans=0;
 
void dfs(int step, LL sum)
{
    if(step > n)
    {
        if(m >= sum)
            ans ++;
        //ans ++;
        //cout << use << endl;
        return;
    }
    //+a[step]
    sum += a[step];
    dfs(step+1, sum);
    sum -= a[step];
 
    sum += b[step];
    dfs(step+1, sum);
    sum -= b[step];
}
 
signed main()
{
    // 444132073
    freopen("data.in", "r", stdin);
    freopen("user.out", "w", stdout);
    cin >> n >> m;
 
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i] >> b[i];
 
    //cout << abig(m, 111111111) << endl;
 
    //cin >> n;
    dfs(1, 0);
    cout << ans;
}
