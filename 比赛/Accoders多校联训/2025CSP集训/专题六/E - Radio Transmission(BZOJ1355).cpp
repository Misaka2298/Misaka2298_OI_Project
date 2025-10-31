// E
// expect pts = 100
// expect diff = idk, green?

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n;
int ne[maxn];
char p[maxn];

signed main()
{
	freopen("radio.in", "r", stdin);
	freopen("radio.out", "w", stdout);
	cin >> n >> (p+1);
	
	for(int i = 2, j = 0 ; i <= n ; i ++)
	{
		while(j && p[i] != p[j+1])
			j = ne[j];
		if(p[i] == p[j+1])
			j ++;
		ne[i] = j;
	}

	cout << n - ne[n];
}