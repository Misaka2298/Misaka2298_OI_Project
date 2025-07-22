// A
// Problem: 滑动窗口
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/156/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-07-22 08:37:21

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n, k;
int arr[maxn], q[maxn];
int head, tail;

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> k;
	for(int i = 0 ; i < n ; i ++)
		cin >> arr[i];
	
	head = 0, tail = -1;
	for(int i = 0 ; i < n ; i ++)
	{
		while(head <= tail && arr[i] < arr[q[tail]]) tail --;
		q[++tail] = i;
		if(q[head] < i-k+1) head++;
		if(i >= k-1) cout << arr[q[head]] << ' ';
	}
	
	cout << endl;
	head = 0, tail = -1;
	for(int i = 0 ; i < n ; i ++)
	{
		while(head <= tail && arr[i] > arr[q[tail]]) tail --;
		q[++tail] = i;
		if(q[head] < i-k+1) head++;
		if(i >= k-1) cout << arr[q[head]] << ' ';
	}
}