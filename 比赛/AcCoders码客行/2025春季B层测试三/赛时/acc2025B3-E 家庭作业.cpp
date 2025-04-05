#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

int n;

signed main()
{
	
	cin >> n;
	PII tasks[n+10];
	//LL goodtask[n+10];
	
	LL limit[n+10], score[n+10];
	LL lim, sco;
	for(LL i = 0 ; i < n ; i++)
	{
		cin >> lim >> sco;
		tasks[i] = {lim,sco};
	}
	sort(tasks , tasks+n);
	for(LL i = 0 ; i < n ; i++)
	{
		limit[i] = tasks[i].first;
		score[i] = tasks[i].second;
		//cout << limit[i] << ' ' << score[i] << endl;
	}
	
	LL day = limit[n-1];
	//cout << day;
	LL ans = 0;
	for(LL i = 1 , j = 0; i <= day ; i++)//i日期,j任务编号
	{
		while(limit[j] < i) j++;
		
		LL mx = 0;
		for(;limit[j] == i;j++)
		{
			mx = max(mx, score[j]);
		}
		//cout << mx << endl;
		//goodtask[i] = mx;
		ans += mx;
	}
	
	cout << ans;
	
	//cout << 15;
}

/*
signed main()
{
	
	cin >> n;
	PII tasks[n+10];
	//LL goodtask[n+10];
	
	LL limit[n+10], score[n+10];
	LL lim, sco;
	for(LL i = 0 ; i < n ; i++)
	{
		cin >> lim >> sco;
		tasks[i] = {lim,sco};
	}
	sort(tasks , tasks+n);
	for(LL i = 0 ; i < n ; i++)
	{
		limit[i] = tasks[i].first;
		score[i] = tasks[i].second;
		//cout << limit[i] << ' ' << score[i] << endl;
	}
	
	LL day = limit[n-1];
	//cout << day;
	LL ans = 0;
	for(LL i = 1 , j = 0; i <= day ; i++)//i日期,j任务编号
	{
		while(limit[j] < i) j++;
		
		LL mx = 0;
		for(;limit[j] == i;j++)
		{
			mx = max(mx, score[j]);
		}
		//cout << mx << endl;
		ans += mx;
	}
	cout << ans;
	
	//cout << 15;
}
*/