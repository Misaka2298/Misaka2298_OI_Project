// Problem: P11361 [NOIP2024] 编辑字符串
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P11361?contestId=217331
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-18 13:17:09

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;

int T;
int n;
char s1[maxn], s2[maxn];
bool st1[maxn], st2[maxn];

void init()
{
	
	memset(s1, 0, sizeof s1);
	memset(s2, 0, sizeof s2);
	memset(st1, 0, sizeof st1);
	memset(st2, 0, sizeof st2);
	
	//s1[n+2] = s2[n+2] = st1[n+2] = st2[n+2] = 0;
	cin >> n >> (s1+1) >> (s2+1);
	
	string tmp;
	cin >> tmp;
	for(int i = 0 ; i < n ; i ++)
		if(tmp[i] == '1')
			st1[i+1] = 1;
	cin >> tmp;
	for(int i = 0 ; i < n ; i ++)
		if(tmp[i] == '1')
			st2[i+1] = 1;
}

void debug(int opt)
{
	if(opt == 1)
	{
		for(int i = 1 ; i <= n ; i ++)
			cout << s1[i];
		cout << endl;
		for(int i = 1 ; i <= n ; i ++)
			cout << s2[i];
		cout << endl;
	}
	if(opt == 2)
	{
		for(int i = 1 ; i <= n ; i ++)
			cout << st1[i];
		cout << endl;
		for(int i = 1 ; i <= n ; i ++)
			cout << st2[i];
		cout << endl;
	}
	cout << endl;
}

void ansout()
{
	LL ans = 0;
	for(int i = 1 ; i <= n ; i ++)
		if(s1[i] == s2[i])
			ans ++;
	cout << ans << endl;
}

void solve()// hope it can accept
{
	for(int i = 1 ; i < n ; i ++)
	{
		// is same
		if(s1[i] == s2[i])
			continue;
		
		// not same
		// but can swap
		if(s1[i+1] == s2[i] && st1[i+1] && st1[i])// swap 1
			swap(s1[i+1], s1[i]);
		else if(s2[i+1] == s1[i] && st2[i+1] && st2[i])
			swap(s2[i+1], s2[i]);
	}
	ansout();
}

bool checkspe1()
{
	for(int i = 1 ; i < n ; i ++)
		if(s1[i] != s1[i+1])
			return false;
	return true;
}

bool checkspe2()
{
	for(int i = 1 ; i <= n ; i ++)
		if(st1[i] != st2[i])
			return false;
	return true;
}

bool checkspe3()
{
	int cnt1 = 0, cnt2 = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(!st1[i])
			cnt1 ++;
		if(!st2[i])
			cnt2 ++;	
	}
	return (cnt1 == cnt2 && cnt1 == 1);
}

void solspe1()
{
	ansout();
}

void solspe2()
{
	for(int i = 1 ; i <= n ; i ++)
	{
		int l = i, r = l;
		if(st1[i])
		{
			while(st1[r+1])
				r ++;
			i = r + 1;
			sort(s1+l, s1+r+1);
			sort(s2+l, s2+r+1);
		}
	}
	ansout();
}

int cnt[4][4][4];//cnt_{i, j, k} = s_i in pos_i:j_cnt
int pos1, pos2;

void spe3_init()
{
	memset(cnt, 0, sizeof cnt);
	
	for(int i = 1 ; i < pos1 ; i ++)
	{
		cnt[1][1][0] += (s1[i] == '0');
		cnt[1][1][1] += (s1[i] == '1');
		cnt[2][1][0] += (s2[i] == '0');
		cnt[2][1][1] += (s2[i] == '1');
	}
	
	for(int i = pos1+1 ; i < pos2 ; i ++)
	{
		cnt[1][2][0] += (s1[i] == '0');
		cnt[1][2][1] += (s1[i] == '1');
		cnt[2][2][0] += (s2[i] == '0');
		cnt[2][2][1] += (s2[i] == '1');
	}
	
	for(int i = pos2+1 ; i <= n ; i ++)
	{
		cnt[1][3][0] += (s1[i] == '0');
		cnt[1][3][1] += (s1[i] == '1');
		cnt[2][3][0] += (s2[i] == '0');
		cnt[2][3][1] += (s2[i] == '1');
	}
}

int getpos(int block, int goal, int scnt)
{
	if(scnt == 1)
	{
		if(block == 1)
			for(int i = 1 ; i < pos1 ; i ++)
				if(s1[i] - '0' == goal)
					return i;
		if(block == 2)
			for(int i = pos1+1 ; i < pos2 ; i ++)
				if(s1[i] - '0' == goal)
					return i;
		if(block == 3)
			for(int i = pos2+1 ; i <= n ; i ++)
				if(s1[i] - '0' == goal)
					return i;
	}
	if(scnt == 2)
	{
		if(block == 1)
			for(int i = 1 ; i < pos1 ; i ++)
				if(s2[i] - '0' == goal)
					return i;
		if(block == 2)
			for(int i = pos1+1 ; i < pos2 ; i ++)
				if(s2[i] - '0' == goal)
					return i;
		if(block == 3)
			for(int i = pos2+1 ; i <= n ; i ++)
				if(s2[i] - '0' == goal)
					return i;
	}
}

//cnt_{i, j, k} = s_i in pos_i:j_cnt

void spe3_swap()
{
	spe3_init();
	
	if(!st1[pos1])//那么st2肯定是pos2
	{
		int num1 = s1[pos1] - '0';
		int pos;
		if(cnt[2][1][num1] > cnt[2][2][num1])
			pos = getpos(1, num1, 2);
		else
			pos = getpos(2, num1, 2);
		swap(s2[pos], s2[pos1]);
		
		int num2 = s2[pos2] - '0';
		pos = 0;
		if(cnt[1][2][num2] > cnt[1][3][num2])
			pos = getpos(2, num2, 1);
		else
			pos = getpos(3, num2, 1);
		swap(s1[pos], s1[pos2]);
	}
	else
	{
		int num1 = s2[pos1] - '0';
		int pos;
		if(cnt[1][1][num1] > cnt[1][2][num1])
			pos = getpos(1, num1, 1);
		else
			pos = getpos(2, num1, 1);
		swap(s1[pos], s1[pos1]);
		
		int num2 = s1[pos2] - '0';
		pos = 0;
		if(cnt[2][2][num2] > cnt[2][3][num2])
			pos = getpos(2, num2, 2);
		else
			pos = getpos(3, num2, 2);
		swap(s2[pos], s2[pos2]);
	}
}

void solspe3()
{
	for(int i = 1 ; i <= n ; i ++)
		if(!st1[i])
			pos1 = i;
	for(int i = 1 ; i <= n ; i ++)
		if(!st2[i])
			pos2 = i;
	if(pos2 < pos1)
		swap(pos2, pos1);
		
	//优先保证不可修改的地方是匹配的
	spe3_swap();
	//debug(1);
	
	sort(s1+1, s1+pos1+1-1);
	sort(s2+1, s2+pos1+1-1);
	
	sort(s1+pos1+1, s1+pos2+1-1);
	sort(s2+pos1+1, s2+pos2+1-1);
	
	sort(s1+pos2+1, s1+n+1);
	sort(s2+pos2+1, s2+n+1);
	
	//debug(1);
	ansout();
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> T ;
	while(T --)
	{
		init();
		
		if(checkspe1())
			solspe1();
		else if(checkspe2())
			solspe2();
		else if(checkspe3())
			solspe3();
		else
			solve();
		
	}
}

/*
1 1
2 3
3 5a
4 7a
5 9a
6 11a
7 13a
8 15a
9 17
10 19

*/