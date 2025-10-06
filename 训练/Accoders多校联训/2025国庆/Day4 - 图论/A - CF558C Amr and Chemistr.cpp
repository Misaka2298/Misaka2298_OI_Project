// Problem: CF558C Amr and Chemistry
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF558C
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// Time: 2025-10-05 08:44:56

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef pair<int, int> PII;
typedef long long LL;// 觉得应该开就开了

int n;
int cnt[maxn];// 记录这个数字能被多少原始数字扩展到
LL a[maxn];
LL dist[maxn];// 所有原始数字（注意）到这一个数字的最小操作数。
int vis[maxn], timestamp;// 访问数组与时间戳

void bfs(LL sta)
{
	queue<PII> q;
	q.push({sta, 0});
	timestamp ++;// 给 BFS 一个唯一的编号（时间戳）
	vis[sta] = timestamp;
	cnt[sta] ++;
	
	while(q.size())
	{
		//auto [u, dis] = q.front(); q.pop();
		auto t = q.front(); q.pop();
		int u = t.first, dis = t.second;//dis 为当前这个数被当前原始数字扩展的最小操作数
		for(int i = 0 ; i < 2 ; i ++)// 因为是两个操作
		{
			LL ne = u;
			if(!i) ne *= 2;
			else ne /= 2;
			if(ne >= 1 && ne <= maxn && vis[ne] != timestamp)// 用时间戳来判重
			{
				vis[ne] = timestamp;
				dist[ne] += dis + 1;// 注意是 +=, 因为记录的是"所有"原始数字到这一个数字的最小操作数
				cnt[ne] ++;//ne 可以被这个原始数字搜到
				q.push({ne, dis+1});
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	
	for(int i = 1 ; i <= n ; i ++)
		bfs(a[i]);
		
	LL mn = LLONG_MAX;// 注意！当然你用 INT_MAX 我觉得也不会错就是了。
	for(int i = 1 ; i < maxn ; i ++)
		if(cnt[i] == n)// 数字 i 能被所有 n 个数字扩展到
			mn = min(mn, dist[i]);// 记录最小的操作数
	
	cout << mn;
}