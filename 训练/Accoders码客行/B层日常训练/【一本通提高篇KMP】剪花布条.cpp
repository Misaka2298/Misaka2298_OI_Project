#include <bits/stdc++.h>
using namespace std;

int n, m;
string strp, strs;

signed main()
{
	while(true)
	{
		cin >> strs;
		if(strs == "#") break;
		cin >> strp;
		
		
		m = strs.length(); n = strp.length();
		int ne[n+10];
		char P[n+10], S[m+10];
		for(int i = 1 ; i <= n ; i ++)
			P[i] = strp[i-1];
		for(int i = 1 ; i <= m ; i ++)
			S[i] = strs[i-1];
		
			
		ne[1] = 0;
		for(int i = 2 , j = 0 ; i <= n ; i++)
		{
			while(j != 0 && P[i] != P[j+1]) j = ne[j];
			if(P[i] == P[j+1]) j ++;
			ne[i] = j;
		}
		
		int ans = 0;
		for(int i = 1 , j = 0 ; i <= m ; i++)
		{
			while(j != 0 && S[i] != P[j+1]) j = ne[j];
			if(S[i] == P[j+1]) j++;
			if(j == n) ans ++, j = 0;
		}
		cout << ans << endl;
	}
}