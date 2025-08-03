#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4+10, inf = 0x3f3f3f3f;

int n;
struct Cow{
	int pos, id;
}cows[maxn], windows[maxn];

map<int, int> idCount;
int totalid, nowids;

bool cmp(Cow a, Cow b)
{
	return a.pos < b.pos;
}

signed main()
{
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> cows[i].pos >> cows[i].id;
		if(idCount[cows[i].id] == 0)
			totalid ++;
		idCount[cows[i].id] ++;
	}
	
	sort(cows, cows+n, cmp);
	
	idCount.clear();
	
	int l = 0, r = -1;
	int ans = inf;
	for(int i = 0 ; i < n ; i++)
	{
		if(idCount[cows[i].id] == 0)
			nowids ++;
		idCount[cows[i].id] ++;
		windows[++r] = cows[i];
		
		while(idCount[windows[l].id] > 1)
		{
			idCount[windows[l].id] --;
			l++;
		}
		
		if(nowids == totalid)
			ans = min(ans, windows[r].pos-windows[l].pos);
	}
	cout << ans;
}