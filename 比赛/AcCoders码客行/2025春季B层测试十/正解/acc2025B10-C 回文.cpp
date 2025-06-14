#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;

int n, cnt[500];

signed main()
{
	string tmp;
	cin >> tmp;
	n = tmp.size();
	for(int i = 0 ; i < n ; i ++)
	{
		char chrtmp;
		chrtmp = tmp[i];
		cnt[(int)chrtmp] ++;
	}
	
	bool isOdd = (n%2!=0);
	
	deque<int> wait;
	for(int i = char('a') ; i <= char('z') ; i ++)
	{
		if(cnt[i] % 2 != 0)
		{
			wait.push_back(i);
		}
	}
	
	int mid = -1;
	while(wait.size())
	{
		int l = wait.front(); int r = wait.back();
		if(l == r)
		{
			mid = l;
			break;
		}
		wait.pop_front(), wait.pop_back();
		cnt[l] ++, cnt[r]--;
	}

	/*
	for(int i = char('a') ; i <= char('z') ; i ++)
		cout << cnt[i] << ' ';
	cout << endl;
	*/
	
	
	if(isOdd) cnt[mid] --;
	for(int i = char('a') ; i <= char('z') ; i ++)
	{
		cnt[i] /= 2;
		for(int j = 0 ; j < cnt[i] ; j++)
			cout << char(i);
	}
	
	if(isOdd) cout << char(mid);
	
	/*
	cout << endl;
	for(int i = char('a') ; i <= char('z') ; i ++)
		cout << cnt[i] << ' ';
	cout << endl;
	*/
	
	for(int i = char('z') ; i >= char('a') ; i --)
	{
		for(int j = 0 ; j < cnt[i] ; j++)
			cout << char(i);
	}
		
}