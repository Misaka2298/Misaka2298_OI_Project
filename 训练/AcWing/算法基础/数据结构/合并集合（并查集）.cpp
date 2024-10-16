#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int p[maxn];

int find(int x)
{
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	int n , m;
	scanf("%d%d",&n,&m);
	for(int i = 0 ;i < n ;i++) p[i] = i;
	
	char opt[2];
	while(m--)
	{
		int a , b;
		scanf("%s%d%d",opt,&a,&b);
		if(opt[0] == 'M') p[find(a)]=find(b);
		else{
			if(find(a) == find(b)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}