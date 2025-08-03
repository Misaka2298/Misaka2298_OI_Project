//T3
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
	/*
	for(int i = 0 ; i < n ; i ++)
		match[i] = money[i].first;
	*/
	
	/*
	for(int i = 0 ; i < n ; i ++)
		cout << money[i].first << endl;
	*/
	
	int mon = 0;//ans
	while(sum)
	{
		memset(tick, 0, sizeof tick);
		memset(st, false, sizeof st);
		int wait = c, already = 0;
		for(int i = 0 ; i < n ; i ++)//遍历所有面额，尽量凑齐，且尽量用大的
		{
			if(wait == 0) break;//凑齐了
			if(money[i].second != 0)
			{
				if(money[i].first >= c)
				{
					mon += money[i].second;
					money[i].second = 0;
					sum -= money[i].first * money[i].second;
					already = c;
					//break;
				}
				else//最大面额无法单张凑
				{
					bool flag = false;
					tick[i] = wait / money[i].first;//第i种钱币每次tick[i]张
					if(tick[i] > money[i].second)//第i张余额不够
					{
						//cout << 'a';
						tick[i] = money[i].second;
						st[i] = true;
						for(int j = i ; j >= 0 ; j --)
							if(tick[j])
							{
								tick[j] ++;
								flag = true;
								break;
							}
					}
					//money[i].second -= tick[i];//bu neng zai zhe jian
					wait %= money[i].first;
					if(!st[i]) already += tick[i] * money[i].first;
					
					if(flag)
					{
						already = 0;
						for(int j = i ; j >= 0 ; j --)
						{
							if(!st[i]) already += tick[i] * money[i].first;
						}
					}
					cout << already << endl;
				}
			}
		}
		/*
		bool dont = 0;
		if(already < c)
		{
			already = 0;
			
			memset(tick, 0, sizeof tick);
			for(int i = 0 ; i < n ; i ++)
			{
				if(money[i].second && money[i].first < c)
				{
					tick[i] = wait / money[i].first + 1;
					if(tick[i] > money[i].second)
					{
						dont = true;
						break;
					}
					
				}
			}
		}
		if(dont) break;
		*/
		if(already < c)
		{
			//cout << 'a';
			break;
		}
		
		int minest = 1e9;
		for(int i = 0 ; i <= n ; i ++)
			if(tick[i] && !st[i])
				minest = min(minest, money[i].second/tick[i]);
			
		mon += minest;
		
		for(int i = 0 ; i <= n ; i ++)
		{
			sum -= money[i].first * tick[i] * minest;
			money[i].second -= tick[i] * minest;
		}
		
		
	}
	cout << mon;
}