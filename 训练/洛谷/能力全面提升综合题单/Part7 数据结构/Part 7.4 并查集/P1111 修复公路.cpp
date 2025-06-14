#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, m;
int fa[maxn];

struct task {
    int xx, yy, tt;    
}tasks[maxn]; 

bool cmp(task A, task B) 
{
    return A.tt < B.tt;
}

int find(int x) 
{
    if(x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}

signed main() 
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        fa[i] = i;
    for(int i = 0; i < m; i++)
    {
        cin >> tasks[i].xx >> tasks[i].yy >> tasks[i].tt;
    }
    sort(tasks, tasks + m, cmp);

    int cnt = 1; 
    for(int i = 0; i < m; i++)
    {
        int x = find(tasks[i].xx), y = find(tasks[i].yy);
        if(x != y)
        {
            fa[x] = fa[y];
            cnt++;
            if(cnt == n)
            {  
                cout << tasks[i].tt;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}