//T5
//expect pts = [80,100]
#include <bits/stdc++.h>
using namespace std;
const int maxn = 30010;

int n, q;
int fa[maxn], son[maxn];

int findanc(int x)
{
	while(fa[x] != x)
		x = fa[x];
	return x;
}

int findmnson(int x)
{
	while(son[x] != x)
		x = son[x];
	return x;
}


signed main()
{
	for(int i = 1 ; i <= maxn ; i++)
		fa[i] = son[i] = i;
	
	cin >> q;
	while(q--)
	{
		int x, y, xanc, ymnson, ans;
		char opt;
		cin >> opt >> x;
		if(opt == 'M')
		{
			cin >> y;
			xanc = findanc(x), ymnson = findmnson(y);
			fa[xanc] = ymnson;
			son[ymnson] = xanc;
		}
		else 
		{
			ans = 0;
			while(fa[x] != x)
			{
				x = fa[x];
				ans ++;
			}
			cout << ans << endl;
		}
	}
}