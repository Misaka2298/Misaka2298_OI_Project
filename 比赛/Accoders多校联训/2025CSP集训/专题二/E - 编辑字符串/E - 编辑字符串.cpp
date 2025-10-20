// E
// expect pts = <100
// expect diff = idk

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;

int n;
int idx, mp[maxn];
int ne[maxn];

void init(char *a)
{
	//int fa = 0;
	for(int i = 0 ; a[i] ; i ++)
	{
		idx ++;
		ne[idx] = idx + 1;
		mp[idx] = (int)a[i];
	}
	idx = 1000;
}

void strout()
{
	for(int i = 1 ; i != -1 ; i = ne[i])
	{
		cout << (char)mp[i];
	}
}

void del(char x)
{
	for(int i = 1 ; i != -1 ; i = ne[i])
	{
		if(mp[ne[i]] == (int)x)
		{
			ne[i] = ne[ne[i]];
			break;
		}
	}
}

void insert(char goal, char chr)
{
	int pos = 0;
	for(int i = 1 ; i != -1 ; i = ne[i])
	{
		if(mp[i] == goal)
			pos = i;
	}
	
	for(int i = 1 ; i != -1 ; i = ne[i])
	{
		if(ne[i] == pos)
		{
			idx ++;
			ne[idx] = ne[i];
			ne[i] = idx;
			mp[idx] = (int)chr;
			break;
		}
	}	
}

void change(char x, char y)
{
	for(int i = 1 ; i != -1 ; i = ne[i])
	{
		if(mp[i] == (int)x)
			mp[i] = (int)y;
	}
}

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	memset(ne, -1, sizeof ne);
	char str[maxn];
	gets(str);
	init(str);
	/*
	for(int i = 1 ; i <= 30 ; i ++)
		cout << ne[i] << ' ';
	cout << endl;
	*/
	cin >> n;
	while(n --)
	{
		char opt, x, y;
		cin >> opt >> x;
		if(opt == 'D')
			del(x);
		if(opt == 'I')
			cin >> y, insert(x, y);
		if(opt == 'R')
			cin >> y, change(x, y);
	}
	/*
	for(int i = 1 ; i <= 30 ; i ++)
		cout << ne[i] << ' ';
	*/
	strout();
	
	
	
}