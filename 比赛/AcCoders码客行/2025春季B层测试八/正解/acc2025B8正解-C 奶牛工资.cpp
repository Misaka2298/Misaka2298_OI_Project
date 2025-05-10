//T3正解
//except pts = 
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
//const int maxn = 1e6;

PII money[22];//1=v, 2=k;
int n, c, tick[22];
bool st[22];

bool cmp(PII a, PII b)
{
	return a.first > b.first;	
}

signed main()
{
	cin >> n >> c;
	int sum = 0;
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> money[i].first >> money[i].second;
		sum += money[i].first * money[i].second;
	}	
	sort(money, money+n, cmp);
	
	int mon = 0;//ans
	while(true)
	{
		int remain = c;
		memset(tick, 0, sizeof tick);
		
		for(int i = 0 ; i < n ; i++)
		{
			if(!money[i].second) continue;
			if(remain <= 0) break;
			
			int use = min(money[i].second, remain/money[i].first);
			remain -= use * money[i].first;
			tick[i] = use;
		}
		
		if(remain > 0)
		{
			for(int i = n-1 ; i >= 0 ; i --)
			{
				if(money[i].second <= tick[i]) continue;
				if(remain <= 0) break;
				
				int need = (remain + money[i].first -1) / money[i].first;
				// remain / money[i].first;
				int use = min(need, money[i].second-tick[i]);
				tick[i] += use;
				remain -= use * money[i].first;
				if(remain <= 0) break;
			}
		}
		
		if(remain > 0)
		{
			//cout << 'a';
			break;
		}
		
		int minest = 1e9;
		for(int i = 0 ; i < n ; i ++)
			if(tick[i])
				minest = min(minest, money[i].second/tick[i]);
			
		mon += minest;
		
		for(int i = 0 ; i <= n ; i ++)
		{
			money[i].second -= tick[i] * minest;
		}
	}
	cout << mon;

}