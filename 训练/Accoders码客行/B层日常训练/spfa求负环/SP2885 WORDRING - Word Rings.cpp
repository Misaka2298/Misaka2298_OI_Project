#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;
typedef long double LD;

int n;
LL e[maxn], ne[maxn], h[maxn], idx, st[maxn];
LD w[maxn], dist[maxn];
bool has_cycle;

LL maxedge;

void addedge(LL a, LL b, LD c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void spfa(LL u, LL sta, LD avg)
{
	if(has_cycle)
		return;
	st[u] = sta;
	for(LL i = h[u] ; i != -1 ; i = ne[i])
	{
		LL j = e[i];
		LD newdist = dist[u] + w[i] - avg;
		if(dist[j] < newdist)
		{
			dist[j] = newdist;
			if(dist[j] > maxedge)
			{
				has_cycle = 1;
				return;
			}
			
			if(!st[j])
				spfa(j, sta, avg);
				
			if(has_cycle)
				return;
			else if(st[j] == sta)
			{
				has_cycle = 1;
				return;
			}
		}
	}
	st[u] = 0;
}

bool check(LD avg)
{
	has_cycle = 0;
	memset(st, 0, sizeof st);
	memset(dist, 0, sizeof dist);
	
	for(int i = 1 ; i <= 702 ; i ++)
	{
		spfa(i, i, avg);
		if(has_cycle) break;
	}
	return has_cycle;
}

void init()
{
	idx = maxedge = 0;
	memset(e, 0, sizeof e);
	memset(ne, 0, sizeof ne);
	memset(h, -1, sizeof h);
	memset(w, 0, sizeof w);
	memset(st, 0, sizeof st);
}

signed main()
{
	while(cin >> n && n)
	{
		init();
		for(int i = 0 ; i < n ; i++)
		{
			string str;
			cin >> str;
			LL len = str.size();
			
			maxedge = max(maxedge, len);
			
			LL a = (str[0]-'a'+1)*26 + str[1]-'a'+1;
			LL b = (str[len-2]-'a'+1)*26 + str[len-1]-'a'+1;
			
			addedge(a, b, (LD)len);
		}
		maxedge *= n;
		
		LD l = 1, r = 1000, ans = -1, EPS = 1e-4;
		while(l+EPS < r)
		{
			LD mid = (l+r)/2.0;
			if(check(mid))
				l = ans = mid;
			else
				r = mid;
		}
		if(ans == -1)
			cout << "No solution." << endl;
		else
			cout << fixed << setprecision(2) << ans << endl;
	}
}