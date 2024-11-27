#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
const int U = 3e5+10 , T = U-1 , F = U-2;

int c, t;
int n , m;
int v[maxn * 2] , fa[maxn * 2];

int find(int x)
{
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

void uni(int a , int b)
{
	fa[find(a)] = find(b);
	return;
}

signed main()
{
	cin >> c >> t;
	while(t--)
	{
		int ans = 0;
		memset(v,0,sizeof v);
		memset(fa,0,sizeof fa);
		cin >> n >> m;
		for(int i = 1 ; i <= n; i++)
			v[i] = i;
		char opt;
		int x , y;
		while(m--)
		{
			cin >> opt >> x;
			if(opt == '+')
			{
				cin >> y;
				v[x] = v[y];
			}
			if(opt == '-')
			{
				cin >> y;
				v[x] = -v[y];
			}
			if(opt == 'T')
				v[x] = T;
			if(opt == 'F')
				continue;
			if(opt == 'U')
				v[x] = U;
		}
		
		for(int i = 1 ; i <= n*2 ; i++)
			fa[i] = i;
		
		for(int i = 1 ; i <= n ; i++)
		{
			if(abs(v[i]) == U)
				uni(i , i+n);
			else if (abs(v[i]) == T); 
			else if(v[i] > 0)
			{
				uni(v[i] , i);
				uni(v[i]+n , i+n);
			}
			else if(v[i] < 0)
			{
				uni(-v[i] , i+n);
				uni(-v[i]+n , i);
			}
		}
		ans = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			if(find(i) == find(i+n))
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}