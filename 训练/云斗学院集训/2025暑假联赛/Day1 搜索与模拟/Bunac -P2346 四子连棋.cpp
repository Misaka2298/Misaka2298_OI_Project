// Problem: P2346 四子连棋
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2346
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-08-03 11:18:52

// 10circle is wmc
// but wo bushi wmc
// I win
// 10circle play arcaea
// but wo bu play
// I double win
// 10circle don't like NaiLoong
// but wo like
// I winwinwinwinwin

#include <bits/stdc++.h>
using namespace std;
const int maxn = 4;
#define endl '\n'

bool win(char c[4][4])
{
	bool b=false;
	if(c[0][0]=='W'&&c[0][1]=='W'&&c[0][2]=='W'&&c[0][3]=='W')  b=true;
	if(c[1][0]=='W'&&c[1][1]=='W'&&c[1][2]=='W'&&c[1][3]=='W')  b=true;
	if(c[2][0]=='W'&&c[2][1]=='W'&&c[2][2]=='W'&&c[2][3]=='W')  b=true;
	if(c[3][0]=='W'&&c[3][1]=='W'&&c[3][2]=='W'&&c[3][3]=='W')  b=true;
	if(c[0][0]=='W'&&c[1][0]=='W'&&c[2][0]=='W'&&c[3][0]=='W')  b=true;
	if(c[0][1]=='W'&&c[1][1]=='W'&&c[2][1]=='W'&&c[3][1]=='W')  b=true;
	if(c[0][2]=='W'&&c[1][2]=='W'&&c[2][2]=='W'&&c[3][2]=='W')  b=true;
	if(c[0][3]=='W'&&c[1][3]=='W'&&c[2][3]=='W'&&c[3][3]=='W')  b=true;
	if(c[0][0]=='W'&&c[1][1]=='W'&&c[2][2]=='W'&&c[3][3]=='W')  b=true;
	if(c[3][0]=='W'&&c[2][1]=='W'&&c[1][2]=='W'&&c[0][3]=='W')  b=true;
	if(c[0][0]=='B'&&c[0][1]=='B'&&c[0][2]=='B'&&c[0][3]=='B')  b=true;
	if(c[1][0]=='B'&&c[1][1]=='B'&&c[1][2]=='B'&&c[1][3]=='B')  b=true;
	if(c[2][0]=='B'&&c[2][1]=='B'&&c[2][2]=='B'&&c[2][3]=='B')  b=true;
	if(c[3][0]=='B'&&c[3][1]=='B'&&c[3][2]=='B'&&c[3][3]=='B')  b=true;
	if(c[0][0]=='B'&&c[1][0]=='B'&&c[2][0]=='B'&&c[3][0]=='B')  b=true;
	if(c[0][1]=='B'&&c[1][1]=='B'&&c[2][1]=='B'&&c[3][1]=='B')  b=true;
	if(c[0][2]=='B'&&c[1][2]=='B'&&c[2][2]=='B'&&c[3][2]=='B')  b=true;
	if(c[0][3]=='B'&&c[1][3]=='B'&&c[2][3]=='B'&&c[3][3]=='B')  b=true;
	if(c[0][0]=='B'&&c[1][1]=='B'&&c[2][2]=='B'&&c[3][3]=='B')  b=true;
	if(c[3][0]=='B'&&c[2][1]=='B'&&c[1][2]=='B'&&c[0][3]=='B')  b=true;
	return b;
}

struct board
{
	char c[4][4];
	char h;//last_color
	bool operator < (const board &t) const
	{
		
		if(c[0][0]<t.c[0][0]) return true;
		if(c[0][0]>t.c[0][0]) return false;
		if(c[0][1]<t.c[0][1]) return true;
		if(c[0][1]>t.c[0][1]) return false;
		if(c[0][2]<t.c[0][2]) return true;
		if(c[0][2]>t.c[0][2]) return false;
		if(c[0][3]<t.c[0][3]) return true;
		if(c[0][3]>t.c[0][3]) return false;
		if(c[1][0]<t.c[1][0]) return true;
		if(c[1][0]>t.c[1][0]) return false;
		if(c[1][1]<t.c[1][1]) return true;
		if(c[1][1]>t.c[1][1]) return false;
		if(c[1][2]<t.c[1][2]) return true;
		if(c[1][2]>t.c[1][2]) return false;
		if(c[1][3]<t.c[1][3]) return true;
		if(c[1][3]>t.c[1][3]) return false;
		if(c[2][0]<t.c[2][0]) return true;
		if(c[2][0]>t.c[2][0]) return false;
		if(c[2][1]<t.c[2][1]) return true;
		if(c[2][1]>t.c[2][1]) return false;
		if(c[2][2]<t.c[2][2]) return true;
		if(c[2][2]>t.c[2][2]) return false;
		if(c[2][3]<t.c[2][3]) return true;
		if(c[2][3]>t.c[2][3]) return false;
		if(c[3][0]<t.c[3][0]) return true;
		if(c[3][0]>t.c[3][0]) return false;
		if(c[3][1]<t.c[3][1]) return true;
		if(c[3][1]>t.c[3][1]) return false;
		if(c[3][2]<t.c[3][2]) return true;
		if(c[3][2]>t.c[3][2]) return false;
		if(c[3][3]<t.c[3][3]) return true;
		if(c[3][3]>t.c[3][3]) return false;
		if(h<t.h) return true;
		if(h>t.h) return false;
		return false;
	}
}init;

char change(char c)//B to W || W to B
{
	return c == 'B' ? 'W' : 'B';
}

queue<board> q;
map<board, int> m;//step count

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	for(int i = 0 ; i < 4 ; i ++)
		for(int j = 0 ; j < 4 ; j ++)
			cin >> init.c[i][j];
	
	init.h = 'W';
	m[init] = 0;
	q.push(init);
	init.h = 'B';
	m[init] = 0;
	q.push(init);
	
	if(win(init.c))
	{
		cout << 1;
		exit(0);
	}
	
	//BFS
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int n = m[t];//step;
		char h = t.h;//last
		for(int i = 0 ; i < 4 ; i ++)
			for(int j = 0 ; j < 4 ; j ++)
			{
				if(t.c[i][j]=='O')
				{
					if(i!=0 && t.c[i-1][j] == h)
					{ 
						board l = t;
						l.c[i][j] = h;
						l.c[i-1][j] = 'O';
						l.h = change(h);
						if(win(l.c))
						{
							cout << n+1 << endl;
							return 0;
						}
						if(!m.count(l))
						{
							m[l] = n+1;
							q.push(l);
						}
					}
					if(i != 3 && t.c[i+1][j] == h)
					{
						board l = t;
						l.c[i][j] = h;
						l.c[i+1][j] = 'O';
						l.h = change(h);
						if(win(l.c))
						{
							cout << n+1 << endl;
							return 0;
						}
						if(!m.count(l))
						{
							m[l] = n+1;
							q.push(l);
						}
					}
					if(j != 0 && t.c[i][j-1] == h)
					{
						board l = t;
						l.c[i][j] = h;
						l.c[i][j-1] = 'O';
						l.h = change(h);
						if(win(l.c))
						{
							cout << n+1 << endl;
							return 0;
						}
						if(!m.count(l))
						{
							m[l] = n+1;
							q.push(l);
						}
					}
					if(j != 3 && t.c[i][j+1] == h)
					{
						board l = t;
						l.c[i][j] = h;
						l.c[i][j+1] = 'O';
						l.h = change(h);
						if(win(l.c))
						{
							cout << n+1 << endl;
							return 0;
						}
						if(!m.count(l))
						{
							m[l] = n+1;
							q.push(l);
						}
					}
				}
			}
	}
}
