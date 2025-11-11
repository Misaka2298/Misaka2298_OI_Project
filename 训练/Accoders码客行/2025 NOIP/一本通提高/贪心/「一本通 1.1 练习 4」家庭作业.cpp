// Problem: #10008. 「一本通 1.1 练习 4」家庭作业
// Contest: LibreOJ
// URL: https://loj.ac/p/10008
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-11 13:58:55

#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;

int n;
LL sum;
struct Task{
	int lim, rew;
}tasks[maxn];
priority_queue<int, vector<int>, greater<int>> heap;

bool cmp(Task a, Task b)
{
	return a.lim < b.lim;
}

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> tasks[i].lim >> tasks[i].rew, sum += tasks[i].rew;
	
	sort(tasks+1, tasks+1+n, cmp);
	int day = tasks[1].lim;
	LL ans = 0;
	
	for(int i = 1 ; i <= n ; i ++)
	{
		if(day < tasks[i].lim)
		{
			while(day < heap.size())
			{
				ans += heap.top();
				heap.pop();
			}
			day = tasks[i].lim;
		}
		heap.push(tasks[i].rew);
	}
	
	while(day < heap.size())
	{
		ans += heap.top();
		heap.pop();
	}
	
	cout << sum - ans;
}