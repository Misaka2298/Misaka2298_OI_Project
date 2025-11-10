// Problem: #10005. 「一本通 1.1 练习 1」数列极差
// Contest: LibreOJ
// URL: https://loj.ac/p/10005
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-10 19:35:42

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n;
priority_queue<int> g_heap;
priority_queue<int, vector<int>, greater<int>> s_heap;

signed main()
{
	cin >> n;
	for(int i = 1, x ; i <= n ; i ++)
	{
		cin >> x;
		g_heap.push(x);
		s_heap.push(x);
	}
	
	while(g_heap.size() > 1)
	{
		int a = g_heap.top(); g_heap.pop();
		int b = g_heap.top(); g_heap.pop();
		
		g_heap.push(a * b + 1);
	}
	
	while(s_heap.size() > 1)
	{
		int a = s_heap.top(); s_heap.pop();
		int b = s_heap.top(); s_heap.pop();
		s_heap.push(a * b + 1);
	}
	
	cout << -(g_heap.top() - s_heap.top());
	
	
}