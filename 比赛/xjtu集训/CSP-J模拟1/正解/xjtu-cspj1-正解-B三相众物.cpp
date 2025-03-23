#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10, inf = 1e9;

int n, attack, times[maxn], ans;

struct yuanpi{
	int atk, id;
}f[maxn];

bool cmp(yuanpi A, yuanpi B)
{
	return A.atk < B.atk;
}

signed main()
{
	cin >> n;
	int idx = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> attack; f[++idx] = yuanpi({attack , i});
		cin >> attack; f[++idx] = yuanpi({attack , i});
		cin >> attack; f[++idx] = yuanpi({attack , i});
	}
	
	sort(f+1, f+idx+1, cmp);
	int ans = inf;
	
	for(int i=1 , l=1 , sum=0 ; i <= idx ; i++)
	{
		if(!times[f[i].id]) sum++;
		times[f[i].id] ++;
		if(sum == n)
		{
			while(times[f[l].id] > 1)
			{
				times[f[l].id] --;
				l++;
			}
			ans = min(ans, f[i].atk - f[l].atk);
		}
	}
	cout << ans;
}