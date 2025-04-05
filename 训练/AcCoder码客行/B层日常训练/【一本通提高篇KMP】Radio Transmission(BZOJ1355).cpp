#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;

int n, ne[maxn];
char P[maxn];

signed main()
{
	cin >> n >> P+1;
	for(int i = 2 , j = 0 ; i <= n ; i++)
	{
		while(j != 0 && P[i] != P[j+1]) j = ne[j];
		if(P[i] == P[j+1]) j++;
		ne[i] = j;
	}
	cout << n - ne[n];
}