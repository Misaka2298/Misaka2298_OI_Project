//T3正解
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int maxn = 160;

int n;
PII movies[maxn];

bool cmp(PII a, PII b)
{
	return a.second < b.second;
}

signed main()
{
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> movies[i].first >> movies[i].second;
		
	sort(movies, movies + n, cmp);
	
	int p1, p2, ans;
	p1 = p2 = ans = 0;
	for(int i = 0 ; i < n ; i++)
	{
		int s = movies[i].first, e = movies[i].second;
		if((s >= p1 && p1 > p2) || (s>=p1 && s < p2))
			ans++, p1 = e;
		else if(s >= p2)
			ans++, p2 = e;
	}
	cout << ans;
	
}