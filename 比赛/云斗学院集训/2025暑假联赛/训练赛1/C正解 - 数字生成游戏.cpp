// Problem: P1132 数字生成游戏
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1132
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-08-03 19:07:22
// expect pts = 

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

char str[7];
string s;
int m, target, dist[maxn], len;

void bfs(int sta)
{
	memset(dist, -1, sizeof dist);
	dist[sta] = 0;
	queue<int> q;
	q.push(sta);
	while(q.size())
	{
		int t = q.front(); q.pop();
		string tstr = to_string(t);
		int k;
		int tlen = tstr.size();
		for(int i = 0 ; i < tlen ; i ++)
			for(int j = i+1 ; j < tlen ; j ++)
			{
				string u = tstr;
				swap(u[i], u[j]);
				if(dist[k = stoi(u)] == -1)
				{
					q.push(k);
					dist[k] = dist[t] + 1;
				}
			}
		for(int i = 0 ; i < tlen && tlen > 1 ; i ++)
		{
			string u = tstr;
			u.erase(i, 1);
			if(dist[k = stoi(u)] == -1)
			{
				q.push(k);
				dist[k] = dist[t] + 1;
			}
		}
		for(int i = 1 ; i < tlen && tlen != len ; i ++)
			for(char c = tstr[i-1]+1 ; c < tstr[i] ; c ++)
			{
				string u = tstr;
				u.insert(i, 1, c);
				if(dist[k = stoi(u)] == -1)
				{
					q.push(k);
					dist[k] = dist[t] + 1;
				}
			}
	}
}

signed main()
{
	cin >> str >> m;
	s = str, len = s.length();
	bfs(atoi(str));
	
	while(m--)
	{
		cin >> target;
		cout << dist[target] << endl;
	}
}