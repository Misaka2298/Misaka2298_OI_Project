// T2
// expect pts = 30
// 666还有人翻书。。。是个人物
// 拿西安的题再考一遍意义是?
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n, m;
bool st[maxn];
int ne[maxn]; 

signed main()
{
	freopen("moon.in", "r", stdin);
	freopen("moon.out", "w", stdout);
	cin >> n >> m;
	//m %= n;
	//cout << m << endl;
	for(int i = 1 ; i < n ; i ++)
		ne[i] = i + 1;
	ne[n] = 1;
	
	/*
	for(int i = 1 ; i <= n ; i ++)
		cout << ne[i] << ' ';
	cout << endl;
	*/
	
	int cnt = 0, tick = 0;
	for(int i = 1 ; cnt != n-1 ; i = ne[i])
	{
		if(!st[i])
		{
			tick ++;
		}
		if(tick == m)
		{
			cnt ++;
			tick = 0;
			st[i] = true;
		}
	}
	
	/*
	for(int i = 1 ; i <= n ; i ++)
		cout << st[i] << ' ';
	cout << endl;
	*/
	
	for(int i = 1 ; i <= n ; i ++)
		if(!st[i])
		{
			cout << i;
			return 0;
		}
}