// Problem: #10003. 「一本通 1.1 例 4」加工生产调度
// Contest: LibreOJ
// URL: https://loj.ac/p/10003
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-10 15:20:04

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
typedef pair<int, int> PII;

int n;
vector<int> fst, sec, final;
int a[maxn], b[maxn];
PII tasks[maxn];

bool cmp1(int a, int b)
{
	return tasks[a].first < tasks[b].first;
}

bool cmp2(int a, int b)
{
	return tasks[a].second > tasks[b].second;
}

int soltime()
{
	int mac1 = 0, mac2 = 0;
	for(int i : final)
	{
		int ia = a[i], ib = b[i];
		mac1 += ia;
		if(mac1 > mac2)
			mac2 = mac1;
		mac2 += ib;
	}
	return mac2;
}

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int i = 1 ; i <= n ; i ++)
		cin >> b[i];
	
	for(int i = 1 ; i <= n ; i ++)
	{
		tasks[i] = {a[i], b[i]};
		if(a[i] < b[i])
			fst.push_back(i);
		else
			sec.push_back(i);
	}
	
	sort(fst.begin(), fst.end(), cmp1);
	sort(sec.begin(), sec.end(), cmp2);
	
	for(int i : fst)
		final.push_back(i);
	for(int i : sec)
		final.push_back(i);
	
	cout << soltime() << endl;
		
	for(int i = 0 ; i < final.size()-1 ; i ++)
		cout << final[i] << ' ';
	cout << final[final.size()-1];
	
	
	
	
	
	
	
}