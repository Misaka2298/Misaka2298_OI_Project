// Problem: P14507 缺零分治 mexdnc
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P14507
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Time: 2025-11-15 19:25:22

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef long long LL;
typedef pair<LL, LL> PLL;
#define endl '\n'

int T;
int n, m;
PLL nums[maxn];
LL f[maxn], pos[maxn], precnt[maxn], preval[maxn], idx;
LL c[maxn], d[maxn];

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T --)
	{
		cin >> n >> m;
		for(int i = 1 ; i <= n ; i ++)
			cin >> nums[i].first >> nums[i].second;
		//sort(nums+1, nums+1+n);
		for(int i = 1 ; i < n ; i ++)
			if(nums[i+1].first != nums[i].first + 1)
			{
				n = i;
				break;
			}
		
		/* Hint 1 */
		if(nums[1].first != 0)
		{
			while(m --)
			{
				LL req;
				cin >> req;
				if(req != 0)
					cout << -1 << endl;
				else
					cout << 1 << endl;
			}
			continue;
		}
		f[0] = 0x3f3f3f3f;
		for(int i = 1 ; i <= n ; i ++)
		{
			if(nums[i].second < f[i-1])
				f[i] = nums[i].second, pos[i] = i;
			else
				f[i] = f[i-1], pos[i] = pos[i-1];
		}
		
		/* Hint 2 */
		LL del0 = 0, posi = n, res = 0, cnt = 0;
		memset(c, 0, sizeof c);
		memset(d, 0, sizeof d);
		while(posi > 0)
		{
			LL count = f[posi] - del0;//++posi?
			if(count <= 0)
				break;
			cnt ++;
			c[cnt] = posi;
			d[cnt] = count;
			
			res += count * posi;
			del0 += count;
			
			posi = pos[posi] - 1;
		}
		
		preval[0] = precnt[0] = 0;
		for(int i = 1 ; i <= cnt ; i ++)
		{
			preval[i] = preval[i-1] + c[i] * d[i];
			precnt[i] = precnt[i-1] + d[i];
		}
		
		while(m --)
		{
			LL req;
			cin >> req;
			if(req == 0){
				cout << -1 << endl;
				continue;
			}
			if(req > res){
				cout << -1 << endl;
				continue;
			}	
			if(req < c[1] && cnt > 0){
				cout << 2 << endl;
				continue;
			}
			
			int mxpos = upper_bound(preval+1, preval+1+cnt, req) - (preval + 1);
			if(preval[mxpos] == req)
				cout << precnt[mxpos] << endl;
			else
			{
				LL rem = req - preval[mxpos];
				LL extra = (rem + c[mxpos+1] - 1) / c[mxpos+1];
				cout << precnt[mxpos] + extra << endl;
			}
		}
	}
}