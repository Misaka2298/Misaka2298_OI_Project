// Wrong Answer
// Problem: A - 数字计数
// Contest: Virtual Judge - 专题训练赛 11
// URL: https://vjudge.net/contest/738493#problem/A
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// Time: 2025-08-11 14:08:55

#include <bits/stdc++.h>
using namespace std;
const int mod = 10;
typedef long long LL;

LL l, r;

LL ans1e3[] = {193, 301, 300, 300, 300, 300, 300, 300, 300, 300};
LL ans1e4[] = {2894, 4001, 4000, 4000, 4000, 4000, 4000, 4000, 4000, 4000};
LL ans1e5[] = {38895, 50001, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000};
LL ans1e6[] = {488896, 600001, 600000, 600000, 600000, 600000, 600000, 600000, 600000, 600000};
LL ans1e7[] = {5888897, 7000001, 7000000, 7000000, 7000000, 7000000, 7000000, 7000000, 7000000, 7000000};
LL ans1e8[] = {68888898, 80000001, 80000000, 80000000, 80000000, 80000000, 80000000, 80000000, 80000000, 80000000};
LL ans1e9[] = {788888899, 900000001, 900000000, 900000000, 900000000, 900000000, 900000000, 900000000, 900000000, 900000000};
LL nowarr[11];//可能爆ll，真不行就查询的时候分别统计一下。//哦，爆不了。


void sol_small_number()
{
	LL lans[11];
	memset(lans, 0, sizeof lans);
	for(int i = 0; i <= r; i ++)
	{	
		LL x = i;
		if(x == 0)
			nowarr[0] ++;
		
		while(x > 0)
		{
			nowarr[x % mod] ++;
			x /= mod;
		}
		
		if(i == l-1)
			for(int j = 0 ; j <= 9 ; j ++)
				lans[j] = nowarr[j];
	}
	
	for(int i = 0 ; i <= 9 ; i ++)
		 cout << nowarr[i] - lans[i] << " "; 
}

LL getstanum(LL x)
{
	if(x < 1e3)
	{
		memset(nowarr, 0, sizeof nowarr);
		return 0;
	}
	if(x >= 1e3 && x < 1e4)
	{
		memcpy(nowarr, ans1e3, sizeof ans1e3);
		return 1e3;
	}
	else if(x >= 1e4 && x < 1e5)
	{
		memcpy(nowarr, ans1e4, sizeof ans1e4);
		return 1e4;
	}
	else if(x >= 1e5 && x < 1e6)
	{
		memcpy(nowarr, ans1e5, sizeof ans1e5);
		return 1e5;
	}
	else if(x >= 1e6 && x < 1e7)
	{
		memcpy(nowarr, ans1e6, sizeof ans1e6);
		return 1e6;
	}
	else if(x >= 1e7 && x < 1e8)
	{
		memcpy(nowarr, ans1e7, sizeof ans1e7);
		return 1e7;
	}
	else if(x >= 1e8 && x < 1e9)
	{
		memcpy(nowarr, ans1e8, sizeof ans1e8);
		return 1e8;
	}
	else if(x >= 1e9)
	{
		memcpy(nowarr, ans1e9, sizeof ans1e9);
		return 1e9;
	}
}

void sol_large_number()
{
	LL lans[11];
	memset(lans, 0, sizeof lans);
	
	LL stanum = getstanum(l);
	if(l != stanum)
		for(LL i = stanum ; i < l ; i ++)//debug: 可能需要处理l-1
		{
			LL x = i;
			while(x > 0)
			{5
				nowarr[x % mod] ++;
				x /= mod;
			}
		}
	memcpy(lans, nowarr, sizeof nowarr);
	
	stanum = getstanum(r);
	if(r != stanum)
		for(LL i = stanum ; i <= r ; i ++)//debug: 可能需要处理l-1
		{
			LL x = i;
			while(x > 0)
			{
				nowarr[x % mod] ++;
				x /= mod;
			}
		}
	
	for(int i = 0 ; i <= 9 ; i ++)
		cout << nowarr[i] - lans[i] << ' ';
}

signed main()
{
	cin >> l >> r;
	
	if(l <= 1e6 && r <= 1e6)
		sol_small_number();
	else
		sol_large_number();
	
	return 0;
	return 114514;
}

//488895 600001 600000 600000 600000 600000 600000 600000 600000 600000








