//T4
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef pair<int,int> PII;

int n, arr[maxn], q[maxn], head, tail, ans[maxn];
//PII arr[maxn];//first=val, second=id

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> arr[i];//.first;
		//arr[i].second = i;
	}
	
	head = 0 ; tail = -1;//maybe useful//no , it's useful!!!
	for(int i = 1 ; i <= n ; i ++)
	{
		if(arr[q[tail]] < arr[i] && i != 1)
			while(true)
			{
				if(arr[q[head]] < arr[i]) ans[q[head]] = i;
				if(head <= tail) head++;
				else break;
			}
		q[++tail] = i;
		//cout << head << ' ' << tail << endl;//debug
	}
	
	for(int i = 1 ; i <= n ; i++)
	{
		/*
		if(ans[i] == 0)
			for(int j = i ; j <= n ; j++)
				if(arr[j] > arr[i])
				{
					ans[i] = j;
					break;
				}
		*/
		cout << ans[i] << endl;
	}
		
}