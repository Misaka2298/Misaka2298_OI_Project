// T3-normal
/*
听说在这里写名言就会被10circle翻牌

我的舍友邹颂腾说他要喜欢一辈子奶龙，望周知。

我不玩舞萌dx

我要写#define int long long
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
typedef pair<int, int> PII;

int n, m;
char g[maxn][maxn];

bool isfirstx = true;
PII firstx, secondx;
bool flag = true;//左下右上构型

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
		{
			cin >> g[i][j];
			if(isfirstx && g[i][j] == 'x')
			{
				firstx.first = i, firstx.second = j;
				isfirstx = false;
			}
		}
	
	int llen = 0, rlen = 0;
	for(int i = firstx.second ; i <= m ; i ++)
	{
		if(g[firstx.first][i] == 'x')
			llen ++;
		else
			break;
	}
	for(int i = firstx.first ; i <= n ; i ++)
	{
		if(g[i][firstx.second] == 'x')
			rlen ++;
		else
			break;
	}
	cout << firstx.first << ' ' << firstx.second << ' ' << min(llen, rlen) << endl;
	
	bool firstsearch = false;
	for(int j = 1 ; j <= m && !firstsearch ; j ++)
		for(int i = 1 ; i <= n && !firstsearch ; i ++)
			if(g[i][j] == 'x')
			{
				secondx.first = i, secondx.second = j;
				if(i == firstx.first && j == firstx.second)
					flag = false;
				firstsearch = true;
			}

	if(flag)
	{
		int llen = 0, rlen = 0;
		for(int i = secondx.second ; i <= m ; i ++)
		{
			if(g[secondx.first][i] == 'x')
				llen ++;
			else
				break;
		}
		for(int i = secondx.first ; i <= n ; i ++)
		{
			if(g[i][secondx.second] == 'x')
				rlen ++;
			else
				break;
		}
		cout << secondx.first << ' ' << secondx.second << ' ' << min(llen, rlen) << endl;
	}
	else
	{
		bool innerflag = true;
		for(int i = n ; i >= 1 && innerflag ; i --)
			for(int j = m ; j >= 1 && innerflag ; j --)
				if(g[i][j] == 'x')
				{
					secondx.first = i, secondx.second = j;
					innerflag = false;
				}
				
		int llen = 0, rlen = 0;
		for(int i = secondx.second ; i >= 1 ; i --)
		{
			if(g[secondx.first][i] == 'x')
				llen ++;
			else
				break;
		}
		for(int i = secondx.first ; i >= 1 ; i --)
		{
			if(g[i][secondx.second] == 'x')
				rlen ++;
			else
				break;
		}
		int reallen = min(llen, rlen);
		cout << secondx.first-reallen+1 << ' ' << secondx.second-reallen+1 << ' ' << reallen << endl;
				
	}
		
}