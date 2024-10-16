#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

int n,h[maxn],ph[maxn],hp[maxn],sz;//ph[k]=m：第k个插入的数在m   hp[m]=k：位置m是第k个插入的

void heap_swap(int a, int b)
{
	swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
	int t = u;
	if(u*2 <= sz && h[u*2] < h[t]) t = u*2;
	if(u*2+1 <= sz && h[u*2+1] < h[t]) t = u*2+1;
	if(u != t)
	{
		heap_swap(t,u);
		down(t);
	}
}

void up(int u)
{
	while(u/2!=0 && h[u/2] > h[u])
	{
		heap_swap(u/2,u);
		u/=2;
	} 
}

int main()
{
	int m = 0;
	scanf("%d",&n);
	while(n--)
	{
		int x,k;
		char opt[10];
		scanf("%s",opt);
		if(!strcmp(opt,"I")) 
		{
			scanf("%d",&x);
			sz++;
			m++;
			
			ph[m] = x;
			hp[x] = m;
			h[sz] = x;
			up(m);
		}
		else if(!strcmp(opt,"PM")) cout << h[1] << endl;
		else if(!strcmp(opt,"DM"))
		{
			heap_swap(1,sz);
			sz--;
			down(1);
		}
		else if(!strcmp(opt,"D"))
		{
			scanf("%d",&k);
			heap_swap(ph[k] , sz);
			sz --;
			down(ph[k]),up(ph[k]);
		}
		else if(!strcmp(opt,"C"))
		{
			scanf("%d%d",&k,&x);
			k=ph[k];
			h[k] = x;
			up(k) , down(k);
		}
	}
	return 0;
}