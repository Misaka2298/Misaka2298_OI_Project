#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10 , maxm = 2e5+10;

int n , m ;
int p[maxn];
struct Edges
{
    int a, b, w;

    bool operator< (const Edges &W)const
    {
        return w < W.w;
    }
}edges[maxm];

int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++) p[i] = i;
	
	int a , b , w;
	for(int i = 0 ; i < m ; i ++)
	{
		cin >> a >> b >> w;
		edges[i] = {a,b,w};
	}
	
	sort(edges , edges + m);
	
	int res = 0 , cnt = 0;
	for(int i = 0 ; i < m ; i++)
	{
		int a=edges[i].a , b=edges[i].b , w=edges[i].w;
		a = find(a) , b = find(b);
		if(a != b)
		{
			p[a] = b;
			res += w;
			cnt ++;
		}
	}
	
	if(cnt < n-1) cout << "impossible";
	else cout << res;
	
	return 0;	
}