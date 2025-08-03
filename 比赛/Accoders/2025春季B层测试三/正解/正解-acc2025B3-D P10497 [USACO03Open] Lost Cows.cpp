#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;

int n, a[maxn];
bool st[maxn];
vector<int>ans;

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ;i ++)
		cin >> a[i];
	
	for(int i = n ; i > 0 ; i --)
	{
		int tick = 0;
		for(int j = 1 ; j <= n ; j ++)
			if(!st[j])
			{
				tick++;
				if(tick == a[i] + 1)
				{
					st[j] = true;
					ans.push_back(j);
					break;
				}
			}
	}
	reverse(ans.begin(), ans.end());
	for(auto res : ans)
		cout << res << ' ';
}