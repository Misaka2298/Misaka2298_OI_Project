#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int p[maxn],asize[maxn],n,m;//用asize是为了避免关键字冲突

int find(int x)
{
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d%d",&n,&m);
	
	for(int i = 1 ;i <=n ;i++)
	{
		p[i]=i;
		asize[i] = 1;
	}
	
	while(m--)
	{
		char opt[5];
		scanf("%s",opt);
		int a , b;
		if(opt[0] == 'C') 
		{
			scanf ("%d%d",&a,&b);
			if(find(a) == find(b)) continue;
			else asize[find(b)]+=asize[find(a)];
			p[find(a)]=find(b);
		}
		else if(opt[1] == '1')
		{
			scanf ("%d%d",&a,&b);
			if(find(a) == find(b)) cout << "Yes" <<endl;
			else cout << "No" << endl;
		}
		else
		{
			scanf("%d" ,&a);
			cout << asize[find(a)]<<endl;
		}
	}
	return 0;
}