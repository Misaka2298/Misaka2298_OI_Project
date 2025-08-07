// Problem: P11604 [PA 2016] 卡牌 / Gra w karty
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P11604
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-08-07 16:10:44

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, maxm = 2e5+10;

int T, n, m;
//int aout[maxn], bout[maxn];
bool ast[maxn], bst[maxn], rast[maxn], rbst[maxn];
int acnt, bcnt, racnt, rbcnt;

void init()
{
	memset(ast, false, sizeof ast);
	memset(bst, false, sizeof bst);
	memset(rast, false, sizeof rast);
	memset(rbst, false, sizeof rbst);
	acnt = bcnt = racnt = rbcnt = 0;
}

//1 2 5 6 8 9 10 11 13 14 15 17 18 19 20

signed main()
{
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		int a, b;
		char opt;
		init();
		for(int i = 0; i < m; i ++)
		{
			cin >> a >> opt >> b;
			if(opt == '>')
			{
				if(!ast[a])
				{
					ast[a] = 1;
					acnt ++;
				}
				if(!rbst[b])
				{
					rbst[b] = 1;
					rbcnt ++;
				}
			}
			if(opt == '<')
			{
				if(!bst[b])
				{
					bst[b] = 1;
					bcnt ++;
				}
				if(!rast[a])
				{
					rast[a] = 1;
					racnt ++;
				}
			}
		}
		
		//n = max(max(acnt, bcnt), max(racnt, rbcnt));
		//cout << n << ' ' << m << endl;
		//cout << acnt << ' ' << bcnt << ' ' << racnt << ' ' << rbcnt << endl;
		
		if(n > m)
		{
			cout << "REMIS" << endl;
			continue;
		}
		
		if(n == 1)
		{
			if(bcnt)
				cout << "PRZEGRANA" << endl;
			else
				cout << "WYGRANA" << endl;
			continue;
		}
		
		if(acnt <= n-1 && bcnt <= n-1)
		{
			cout << "REMIS" << endl;
			continue;
		}
		
		if(acnt > bcnt)
		{
			cout << "WYGRANA" << endl;
			continue;
		}
		if(bcnt > acnt)
		{
			cout << "PRZEGRANA" << endl;
			continue;
		}
		if(acnt == bcnt)
		{
			cout << "REMIS" << endl;
			continue;
		}
		
	}
}