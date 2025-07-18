//T6
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
#define endl '\n'

int state[maxn], cuts[maxn], idx=1;
int n, k, q;

signed main()
{
	cin >> n >> k;
	for(int i = 1 ; i <= k+1 ; i++)
		cin >> cuts[i];
	
	for(int i = 1 ; i <= k ; i++)
	{
		int l = cuts[i], r = cuts[i+1]-1;
		for(int j = l ; j <= r ; j++)
			state[j] = idx;
		idx++;
	}
	
	/*
	for(int i = 1 ; i <= n ; i ++)
		cout << state[i];
	cout << endl;
	*/
	
	cin >> q;
	while(q--)
	{
		int st, ed;
		cin >> st >> ed;
		if(st > ed)
			swap(st, ed);
		if(st == ed)
		{
			cout << 1 << endl;
			continue;
		}
		if(state[st] == state[ed])
		{
			cout << 2 << endl;
			continue;
		}
		else
		{
			int use = state[ed] - state[st] + 2;
			if(state[st-1]!=state[st] || state[ed+1]!=state[ed])
				use++;
			if(state[st-1]==state[st] || state[ed+1]==state[ed])
				use--;
			cout << use << endl;
		}
		
	}
}