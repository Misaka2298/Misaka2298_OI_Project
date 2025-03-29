#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10 , maxm = 2e5+10;

int n , m ;
int fa[maxn];
struct Edges{
    int a, b, w;
}edges[maxm];

bool cmp(Edges a, Edges b) {
    return a.w < b.w;
}

int find(int x)
{
	if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

int main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++) fa[i] = i;
	
	int a , b , w;
	for(int i = 0 ; i < m ; i ++)
	{
		cin >> a >> b >> w;
		edges[i] = {a,b,w};
	}
	
	sort(edges , edges + m , cmp);
	
	int res = 0 , cnt = 0;
	for(int i = 0 ; i < m ; i++)
	{
		int a=edges[i].a , b=edges[i].b , w=edges[i].w;
		a = find(a) , b = find(b);
		if(a != b)
		{
			fa[a] = b;
			res += w;
			cnt ++;
		}
	}
	
	if(cnt < n-1) cout << "impossible";
	else cout << res;
	
	return 0;	
}