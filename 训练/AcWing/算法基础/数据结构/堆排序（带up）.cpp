#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
int h[maxn],hsize;

void down(int u)
{
	int t=u;
	if(u*2 <= hsize && h[u*2] < h[t]) t = u*2;
	if (u*2+1 <= hsize && h[u*2+1] < h[t]) t = u*2+1;
	if(u != t) swap(h[u],h[t]) , down(t);
}

void up(int u)
{
	while(u/2!=0 && h[u/2]>h[u])
	{
		swap(h[u/2],h[u]);
		u/=2;
	}
}

int main()
{
	int n ,m;
	scanf("%d%d",&n,&m);
	
	for(int i = 1 ; i <= n ; i++) scanf("%d",&h[i]);
	hsize = n;
	
	for(int i = n/2 ; i!=0 ; i--) down(i);
	
	
	while(m--)
	{
		cout << h[1] << ' ';
		h[1]=h[hsize];
		hsize --;
		down(1);
	}	
	
	return 0;	
}