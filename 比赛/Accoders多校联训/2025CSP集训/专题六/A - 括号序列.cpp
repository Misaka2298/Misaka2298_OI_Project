// A
// expect pts = 100
// expect diff = yellow+

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5+10;
const LL mod = 12345678910;
//typedef pair<int, int> PII;

int n;
LL stk[maxn];
int tail;//, timestamp;
int chr[maxn];//, match[maxn];
//LL ans;

signed main()
{	
	freopen("paren.in", "r", stdin);
	freopen("paren.out", "w", stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> chr[i];
		if(chr[i] == 0)
			chr[i] = -1;
		else
			chr[i] = -2;
	}
		
	
	/*
	for(int i = 1 ; i <= n ; i ++)
	{
		int x = chr[i];
		stk[++tail] = {x, ++timestamp};
		
		if(stk[tail].first)
		{
			match[stk[tail].second] = stk[tail-1].second;
			match[stk[tail-1].second] = stk[tail].second;
			tail -= 2;
		}
	}
	
	tail = timestamp = 0;
	*/
	for(int i = 1 ; i <= n ; i ++)
	{
		int x = chr[i];
		stk[++tail] = x;
		if(x == -1)
			continue;
		// x == -2 now
		if(stk[tail-1] == -1)
		{
			tail -= 2;
			stk[++tail] = 1;
		}
		else if(stk[tail-1] > 0)
		{
			LL num = stk[tail-1];
			tail -= 3;
			stk[++tail] = (num % mod * 2 % mod) % mod;
		}
		
		while(stk[tail-1] > 0)
		{
			LL num = (stk[tail-1] % mod + stk[tail] % mod) % mod;
			tail -= 2;
			stk[++tail] = num;
		}
	}
	
	cout << stk[tail];
	
	
	
	
	
}