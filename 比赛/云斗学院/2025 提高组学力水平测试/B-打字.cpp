//T2
//expect pts = idk.
//1h36min
//except diff: green+, blue-
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
#define endl '\n'

int n, q;
int fa[maxn], node[maxn], uaqfa[maxn], ne[maxn];
bool st[maxn], is_fa[maxn], is_line=true;

int uaqfind(int x)
{
	if(uaqfa[x] != x) return uaqfa[x] = uaqfind(uaqfa[x]);
	return uaqfa[x];
}

bool is_upper(int x)
{
	return (node[x]>=(int)'A' && node[x]<=(int)'Z');
}

bool is_lower(int x)
{
	return (node[x]>=(int)'a' && node[x]<=(int)'z');
}

int LCAcheck(int u, int v)//1 = find, 2 = no, 3 = uke;
{
	memset(st, false, sizeof st);
	bool u_upper = (node[u]>=(int)'A' && node[u]<=(int)'Z');
	
	int ru = uaqfind(u), rv = uaqfind(v);
	if(ru != rv)
		return 3;
		
	int bkpu = u, bkpv = v;
	int root = -1;
	while(u != v)//find path
	{
		st[u] = true; st[v] = true;
		u = fa[u]; v = fa[v];
		if(st[u])
		{
			root = u;
			while(st[fa[u]])
			{
				u = fa[u];
				st[u] = false;
			}
			break;
		}
		if(st[v])
		{
			root = v;
			while(st[fa[v]])
			{
				v = fa[v];
				st[v] = false;
			}
			break;
		}
	}
	if(root == -1) root = u;
	//if(u == v) st[u] = true;
	
	/*
	if(u_upper && (is_lower(u) || is_lower(v)))
			return 1;
		if(!u_upper && (is_upper(u) || is_upper(v)))
			return 1;
	*/
	
	u = bkpu; v = bkpv;
	while(u != root)
	{
		//st[u] = false;
		if(u_upper && is_lower(u))
			return 1;
		if(!u_upper && is_upper(u))
			return 1;
		u = fa[u];
	}
	if(u_upper && is_lower(u))
		return 1;
	if(!u_upper && is_upper(u))
		return 1;
	while(v != root)
	{
		//st[v] = false;
		if(u_upper && is_lower(v))
			return 1;
		if(!u_upper && is_upper(v))
			return 1;
		v = fa[v];
	}
	//st[u] = false; st[v] = false;
	if(u_upper && is_lower(v))
		return 1;
	if(!u_upper && is_upper(v))
		return 1;
	
	//st[fa[u]] = false; st[fa[v]] = false;
	return 2;
}

int linecheck(int u, int v)
{
	bool u_upper = (node[u]>=(int)'A' && node[u]<=(int)'Z');
	
	int ru = uaqfind(u), rv = uaqfind(v);
	if(ru != rv)
		return 3;
		
	bool u_up = false, u_down = false, finded = false;
	int bkpu = u, bkpv = v;
	while(fa[u] != u)
	{
		u = fa[u];
		if(u_upper && is_lower(u))
			u_up = true;
		if(!u_upper && is_upper(u))
			u_up = true;
		if(u == v)
		{
			finded = true;
			break;
		}
	}
	u = bkpu; v = bkpv;
	if(!finded)
	{
		while(fa[v] != v)
		{
			v = fa[v];
			if(u_upper && is_lower(v))
				u_down = true;
			if(!u_upper && is_upper(v))
				u_down = true;
			if(u == v)
			{
				finded = true;
				break;
			}
		}
	}
	if(u_up || u_down)
		return 1;
	return 2;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> q;
	string tmp;
	cin >> tmp;
	for(int i = 1 ; i <= n ; i++)
		node[i] = tmp[i-1];
		
	for(int i = 1 ; i <= n ; i++)
		fa[i] = uaqfa[i] = i;
	
	while(q--)
	{
		int opt, u, v;
		cin >> opt >> u >> v;
		if(opt == 1)
		{
			if(ne[u]) is_line = false;
			ne[u] = v;
			fa[v] = u;
			int ru = uaqfind(u), rv = uaqfind(v);
			uaqfa[ru] = rv;
		}
		else
		{
			int ans;
			if(!is_line) ans = LCAcheck(u, v);
			if(is_line) ans = linecheck(u, v);
			
			if(ans == 1)
				cout << 1 << endl;
			else if(ans == 2)
				cout << 0 << endl;
			else if(ans == 3)
				cout << "UKE" << endl;
		}
		
	}
	//cout << is_line;
}

/*
trie?no.
can't offline.
baoli?
graph is a tree.
LCA???wo mei xue guo ...
uaq????
code is so looong
*/

/*
1 2
1 3
2 4
2 5
3 6
3 7
2 2 4
*/