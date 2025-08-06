//T1
//define int long long
//C0ns1st is NaiLooooooooooooooooong
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int maxn = 2e5+10;

int n, m;
int ans[maxn];
vector<int> mst[maxn], remst[maxn];
int cnt[maxn];

signed main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        mst[b].push_back(a);
        remst[a].push_back(b);
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (mst[i].size() == 0)
            continue;
        for (int j = 0; j < mst[i].size(); j++)
        {
            int son = i, fa = mst[i][j];
            if (ans[son] == 0)
            {
                ans[son] = fa;
                cnt[fa]++;
            }
        }
    }
    
    int cnt0 = 0;
    for (int i = 1; i <= n; i++)
        if (ans[i] == 0)
            cnt0++;
    
    int target = -1;
    if (cnt0 > 1)
    {
        int mx = -1;
        for (int i = 1; i <= n; i++)
        {
            if (ans[i] == 0)
                mx = max(mx, cnt[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (cnt[i] == mx && ans[i] == 0)
            {
                target = i;
                break;
            }
        }
    }
    
    else
        for (int i = 1; i <= n; i++)
            if (ans[i] == 0)
            {
                target = i;
                break;
            }
    
    for (int i = 1; i <= n; i++)
        if (i != target && ans[i] == 0)
            ans[i] = target;
    
    ans[target] = 0;
    
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
    
    return 0;
}