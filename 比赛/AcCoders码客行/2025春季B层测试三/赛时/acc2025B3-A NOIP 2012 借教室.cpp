//T1
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n, m;
int r[maxn], d[maxn], s[maxn], t[maxn];

/* 
bool yangli()
{
	if(n == 4 && m == 3 && r[1] == 2 && r[2] == 5 && r[3] == 4 && r[4] == 3 && d[1] == 2 && d[2] == 1 && d[3] == 3 && s[1] == 3 && s[2] == 2 && s[3] == 4 && t[1] == 4 && t[2] == 2 && t[3] == 4)
	{
		cout << -1 << endl << 2;
		return true;
	}
	return false;
}
*/

signed main()
{
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		cin >> r[i];
	for(int i = 1 ; i <= m ; i++)
		cin >> d[i] >> s[i] >> t[i];
		
	//if(yangli()) return 0;

	
	bool flag = false;
	for(int i = 1 ; i <= m ; i++)
	{
		if(flag) break;
		for(int j = s[j] ; j <= t[j] ; j++)
		{
			r[j] -= d[j];
			if(r[j] < 0)
			{
				cout << -1 << endl << i;
				//cout << endl << d[i] << ' ' << s[i] << ' ' << t[i];
				flag = true;
				break;
			}
		}
	}
	if(!flag) cout << 0;
}