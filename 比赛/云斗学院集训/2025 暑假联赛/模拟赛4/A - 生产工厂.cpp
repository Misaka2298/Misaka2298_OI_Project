// A
// expect pts = 100
// expect diff = yellow +, green -
// 我这辈子也调不好二分了。
// 我这辈子也调不好二分了！！！！！！！
// 谁发明的二分啊！！！！！！!
// 唉Misaka你就这样吧，你就菜吧

// 哎我草。。。我咋写成ans = r了
// 唉Misaka你就这样吧 你就糖吧
// 这小破题你能调一个点也是这辈子有了

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;
typedef pair<LD, LD> PLD;
#define endl '\n'

int T, n;
PII tickes[maxn];

bool cmp(PII a, PII b)
{
	return a.first < b.first;
}

bool check(LL daily)
{
	__int128 rem = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		LL lastday = tickes[i-1].first;
		LL day = tickes[i].first, req = tickes[i].second;
		LL div = (day - lastday);
		if(div == 0) div = 1;
		rem += div * daily;
		rem -= req;
		if(rem < 0)
			return false;
	}
	return true;
}
/*
4

29 14
67 7
31 82
38 87
*/

signed main()
{
	//freopen("factory.in", "r", stdin);
	//freopen("factory.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> T;
	while(T --)
	{
		cin >> n;
		int maxreq = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> tickes[i].first >> tickes[i].second;
			maxreq = max(maxreq, tickes[i].second);
		}
			
		sort(tickes+1, tickes+1+n, cmp);
		
		LL l = 1, r = maxreq;//maxreq;
		LL ans = 0;

		while(l <= r)// fabs(l-r) > 1e-3)
		{
			LL mid = (l + r) / 2;
			//cout << mid << endl;
			if(check(mid))
			{
				ans = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		
		//cout << endl << endl;
		cout << ans << endl; 
	}
	
}