// c0ns1st is NaiLoooooooooong
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define int long long
#define int long long
#define int long long

const int maxn = 2e5+10;

int n, m, t[maxn], fa[maxn], st[maxn], ans[maxn];

void dfs(int u)
{
    st[u] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (st[i] == 0 && fa[i] == u)
            {
                ans[i] = u;
                dfs(i);
            }
    }
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        t[x]++;
        fa[y] = x;
    }
    int maxn = 0, bh;
    for (int i = 1; i <= n; i++)
    {
        if (t[i] > maxn)
        {
            maxn = t[i];
            bh = i;
        }
    }
    dfs(bh);
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0 && i != bh)
            ans[i] = bh;
        cout << ans[i] << " ";
    }
    return 0;
}
