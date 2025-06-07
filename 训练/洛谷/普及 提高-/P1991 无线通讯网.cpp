#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;

int k, n;
//double dist[maxn][maxn];
int x[maxn], y[maxn];
int fa[maxn], idx;
vector<double> seledges;

struct Edge{
	int x, y;
	double dis;
}edges[maxn*maxn];

double soldist(int i, int j)
{
	return sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2));
}

int find(int x)
{
	if(x != fa[x]) return fa[x] = find(fa[x]);
	return fa[x];
}

bool edgecmp(Edge a, Edge b)
{
	return a.dis < b.dis;
}

bool doublecmp(double a, double b)
{
	return a > b;
}

signed main()
{
	cin >> k >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> x[i] >> y[i], fa[i] = i;
		
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
	{
		double dist = soldist(i, j);
		edges[++idx] = {i, j, dist};
	} 
	
	
	sort(edges, edges+idx, edgecmp);
	int cnt = 0;
	for(int i = 1 ; i <= idx ; i ++)
	{
		if(cnt == n-1) break;
		int a = edges[i].x, b = edges[i].y;
		double dis = edges[i].dis;
		int ra = find(a), rb = find(b);
		if(ra != rb)
		{
			fa[ra] = rb;
			seledges.push_back(dis);
			cnt++;
		}
	}
	sort(seledges.begin(), seledges.end(), greater<double>());
	
	printf("%.2lf", seledges[k-1]);
	
}