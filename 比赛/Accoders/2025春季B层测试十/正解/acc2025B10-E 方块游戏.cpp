#include <bits/stdc++.h>
using namespace std;
const int maxn = 30010;
#define endl '\n';

int q, undercnt[maxn], rootsize[maxn], fa[maxn];

int find(int x)
{
	if(fa[x] != x)
	{
		int root = find(fa[x]);
		undercnt[x] += undercnt[fa[x]];
		fa[x] = root;
	}
	return fa[x];
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin >> q;
	
	for(int i = 1 ; i <= maxn ; i ++)
	{
		fa[i] = i;
		undercnt[i] = 0;
		rootsize[i] = 1;
	} 
	
	while(q--)
	{
		char opt;
		int x, y;
		cin >> opt >> x;
		if(opt == 'M')
		{
			cin >> y;
			int rootx = find(x);
			int rooty = find(y);
			if(rootx != rooty)
			{
				fa[rootx] = rooty;
				undercnt[rootx] = rootsize[rooty];
				rootsize[rooty] += rootsize[rootx];
			}
		}
		else
		{
			find(x);
			cout << undercnt[x] << endl;
		}
	}
}