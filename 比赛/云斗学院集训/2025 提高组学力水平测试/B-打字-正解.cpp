#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6+10;

int fa1[maxn], fa2[maxn], n, q, node[maxn];

int find1(int x)
{
	if(fa1[x] != x) return fa1[x] = find1(fa1[x]);
	return fa1[x];
}

int find2(int x)
{
	if(fa2[x] != x) return fa2[x] = find2(fa2[x]);
	return fa2[x];
}

bool is_sametype(int a, int b)
{
	return ((int)'a'<=a && (int)'z'>=a && (int)'a'<=b && (int)'z'>=b) || ((int)'A'<=a && (int)'Z'>=a && (int)'A'<=b && (int)'Z'>=b);
}

signed main()
{
	cin >> n >> q;
	string tmp;
	cin >> tmp;
	for(int i = 1 ; i <= n ; i++)
		node[i] = tmp[i-1];
	
	for(int i = 1 ; i <= n ; i++)
		fa1[i] = fa2[i] = i;
	
	while(q--)
	{
		int opt, u, v;
		cin >> opt >> u >> v;
		if(opt == 1)
		{
			int ru = find1(u), rv = find1(v);
			fa1[ru] = rv;
			if(is_sametype(node[u], node[v]))
			{
				ru = find2(u), rv = find2(v);
				fa2[ru] = rv;
			}
		}
		else
		{
			int ru = find1(u), rv = find1(v);
			if(ru != rv)
			{
				cout << "UKE" << endl;
				continue;
			}
			ru = find2(u), rv = find2(v);
			if(ru != rv)
			{
				cout << 1 << endl;
				continue;
			}
			else
				cout << 0 << endl;
		}
	}
}