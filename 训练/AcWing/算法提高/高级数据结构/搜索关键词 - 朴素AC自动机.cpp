#include <bits/stdc++.h>
using namespace std;
const int maxlen = 55, maxchr = 1e4+10, maxs = 1e6+10;

char str[maxs];
int n, T;
int cnt[maxlen * maxchr], idx, tr[maxlen*maxchr][27], fail[maxlen*maxchr];

void insert()
{
	int p = 0;
	for(int i = 0 ; str[i] ; i ++)
	{
		int t = str[i] - 'a';
		if(!tr[p][t]) tr[p][t] = ++idx;
		p = tr[p][t];
	}
	cnt[p] ++;
}

void build()
{
	queue<int>q;
	for(int i = 0 ; i < 26 ; i ++)
		if(tr[0][i]) q.push(tr[0][i]);
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		for(int i = 0 ; i < 26 ; i ++)
		{
			int c = tr[t][i];
			if(!c)
				tr[t][i] = tr[fail[t]][i];
			else
			{
				fail[c] = tr[fail[t]][i];
				q.push(c);
			}
			//int j = fail[t];
			/*
			while(fail[t] && !tr[fail[t]][i]) fail[t] = fail[fail[t]];
			if(tr[fail[t]][i]) fail[t] = tr[fail[t]][i];
			fail[c] = fail[t];
			q.push(c);
			*/
		}
	}
}

signed main()
{
	cin >> T;
	while(T--)
	{
		memset(tr, 0, sizeof tr);
		memset(cnt, 0, sizeof cnt);
		memset(fail, 0, sizeof fail);
		idx = 0;
		
		cin >> n;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> str;
			insert();
		}
		
		build();
		
		int res = 0;
		cin >> str;
		for(int i = 0 , j = 0; str[i] ; i++)
		{
			int t = str[i] - 'a';
			while(j && !tr[j][t]) j = fail[j];
			if(tr[j][t]) j = tr[j][t];
			
			int p = j;
			while(p)
			{
				res += cnt[p];
				cnt[p] = 0;
				p = fail[p];
			}
		}
		cout << res << endl;		
	}
}