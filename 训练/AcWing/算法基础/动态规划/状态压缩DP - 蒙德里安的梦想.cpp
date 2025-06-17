#include <bits/stdc++.h>
using namespace std;
const int maxn = 12, maxm = pow(2, 12);

int n, m;
long long f[maxn][maxm];
bool isVaild[maxm];
vector<int> vaild[maxm];

signed main()
{
	while(cin >> n >> m, n||m)
	{
		if(n*m % 2)
		{
			cout << 0 << endl;
			continue;
		}
		for(int i = 0 ; i < 1 << n ; i++)
		{
			int cnt = 0;
			isVaild[i] = true;
			for(int j = 0 ; j < n ; j++)
				if(i >> j & 1)
				{
					if(cnt & 1)
					{
						isVaild[i] = false;
						break;
					}
					cnt = 0;
				}
				else
					cnt++;
			if(cnt & 1) isVaild[i] = false;		
		}
		
		for(int i = 0 ; i < 1 << n ; i ++)
		{
			vaild[i].clear();
			for(int j = 0 ; j < 1 << n ; j++)
				if((i&j)==0 && isVaild[i|j])
					vaild[i].push_back(j);
		}
		
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		for(int i = 1 ; i <= m ; i++)
			for(int j = 0 ; j < 1 << n ; j ++)
				//for(auto k : vaild[j])
				for(int kk = 0 ; kk < vaild.size() ; kk++)
				{
					int k = vaild[kk];
					f[i][j] += f[i-1][k];
				}
					
						
		cout << f[m][0] << endl;
	}
}