// Problem: #10004. 「一本通 1.1 例 5」智力大冲浪
// Contest: LibreOJ
// URL: https://loj.ac/p/10004
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-10 15:49:08

#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
typedef pair<int, int> PII;

int m;
int n, maxday;
PII tasks[maxn];
bool st[maxn], cancel[maxn];
int cnt[maxn];

bool cmp(PII a, PII b)
{
	if(a.first != b.first)
		return a.first < b.first;
	return a.second > b.second;
}

signed main()
{
	cin >> m >> n;
	int a[maxn], b[maxn];
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
		maxday = max(maxday, a[i]);
		cnt[a[i]] ++;
	}
		
	for(int i = 1 ; i <= n ; i ++)
		cin >> b[i];
	
	for(int i = 1 ; i <= n ; i ++)
		tasks[i] = {a[i], b[i]};
		
	sort(tasks+1, tasks+1+n, cmp);
	
	//for(auto t : tasks)
		//cout << t.first << ' ' << t.second << endl;

	// cnt_i 是第 i 天前要求完成的任务的剩余
	//int ans = 0, day = 0;
	for(int day = 1 ; day <= maxday ; day ++)
	{
		int lim = -1, sub, pos;
		for(int j = 1 ; j <= n ; j ++)
			if(!st[j] && !cancel[j])
			{
				lim = tasks[j].first, sub = tasks[j].second;
				pos = j;
				break;
			}
		if(lim == -1)
			break;
		if(day == lim)
		{
			if(cnt[lim] == 0)
				continue;
			if(cnt[lim] == 1)
				st[pos] = 1, cnt[lim] --;
			if(cnt[lim] > 1)
			{
				sub = 0;
				for(int j = 1 ; j <= n ; j ++)
					if(tasks[j].first == lim && !st[j] && !cancel[j] && sub < tasks[j].second)
					{
						pos = j;
						sub = tasks[j].second;
					}
				st[pos] = 1;
				cnt[lim] --;
				//cout << pos << endl;
				
				while(cnt[lim] > 0)
				{
					int sub_max = 0, sub_min = 0x3f3f3f3f, mxpos = 0, mnpos = 0;
					for(int j = 1 ; j <= n ; j ++)
						if(tasks[j].first == lim && !cancel[j] && !st[j] && sub_max < tasks[j].second)
						{
							mxpos = j;
							sub_max = tasks[j].second;
						}
					if(sub_max == 0) break;
					for(int j = n ; j >= 1 ; j --)
						if(tasks[j].first < day && st[j] && sub_min > tasks[j].second)
						{
							mnpos = j;
							sub_min = tasks[j].second;
						}
					
					if(sub_min < sub_max)
					{
						st[mnpos] = 0;
						cancel[mnpos] = 1;
						st[mxpos] = 1;
						cnt[lim] --;
					}
					else
					{
						cancel[mxpos] = 1;
						cnt[lim] --;
					}
				}
			}
		}
		else
		{
			int sub_max = 0;
			pos = 0;
			for(int i = 1 ; i <= n ; i ++)
				if(tasks[i].first == lim && sub_max < tasks[i].second)
				{
					pos = i;
					sub_max = tasks[i].second;
				}
			
			st[pos] = 1;
			cnt[tasks[pos].first] --;
		}
				
	}
	
	/*
	for(int i = 1 ; i <= n ; i ++)
		cout << st[i] << ' ';
	cout << endl;
	for(int i = 1 ; i <= n ; i ++)
		cout << cancel[i] << ' ';
	cout << endl;
	*/
	for(int i = 1 ; i <= n ; i ++)
		if(cancel[i] && !st[i])
			m -= tasks[i].second;
	cout << m;
	
	
	
}