#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5+10, inf = 1e9;
typedef pair<int,int> PII;

int n, m, k;
int fa[maxn], sum;
bool st[maxn];
vector<vector<int>> deled;


int find(int x)
{
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

signed main()
{
	cin >> n >> m;
	deled.resize(n);
	for(int i = 0 ; i < n ; i ++)
		fa[i] = i;
	
	queue<PII>add;
	for(int i = 0 ; i < m ; i ++)
	{
		int a, b;
		cin >> a >> b;
		add.push({a, b});
	}
	cin >> k;
	sum = n-k;
	vector<int>del;
	for(int i = 0 ; i < k ; i ++)
	{
		int a;
		cin >> a;
		st[a] = true;
		del.push_back(a);
	}
	//reverse(del.begin(), del.end());
	
	while(add.size()) 
	{
        auto t = add.front(); add.pop();
        int a = t.first, b = t.second;
        if(st[a] || st[b]) 
        {
            if(st[a]) deled[a].push_back(b);
            if(st[b]) deled[b].push_back(a);
            continue;
        }
        a = find(a); b = find(b);
        if(a != b) 
        {
            fa[b] = a;
            sum--;
        }
    }
	
	vector<int>ans;
	ans.push_back(sum);
	for(int i = k - 1 ; i >= 0 ; i--)
	{
		int goal = del[i];
		sum++;
		st[goal] = false;
		for(int t : deled[goal])
		{
			if(st[t]) continue;
			goal = find(goal) ; t = find(t);
			if(goal != t)
			{
				fa[goal] = t;
				sum--;
			}
		}
		ans.push_back(sum);
	}
	//reverse(ans.begin(), ans.end());
	for(int i = ans.size() - 1 ; i >= 0 ; i --)
		cout << ans[i] << endl;
}