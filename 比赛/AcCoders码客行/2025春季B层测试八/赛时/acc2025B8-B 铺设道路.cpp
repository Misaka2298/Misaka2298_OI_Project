//T2
//except pts = 70
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, depth[maxn];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	int cnt = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> depth[i];
		if(depth[i] == 0) cnt++;
	}
		
		
	int lzero = 1, day = 0; 
	while(cnt < n)
	{
		int l = 1, r = n, minest = 1e9;
		for(int i = 1 ; i <= n ; i ++)
			 if(depth[i] != 0)
			 {
			 	l = i;
			 	break;
			 }
		for(int i = l ; i <= n ; i ++)
		{
			if(depth[i] != 0) minest = min(minest, depth[i]);
			if(depth[i] == 0)
			{
				r = i-1;
				break;
			}
		}
		
		/*
		for(int i = l ; i <= r ; i ++)
			if(depth[i] == 0)
			{
				cout << "error";
				break;
			}
		*/
		day += minest;
		for(int i = l ; i <= r ; i++)
		{
			depth[i] -= minest;
			//if(depth[i] == 0 && lzero < i) lzero = i;
			if(depth[i] == 0) cnt ++;
		}
		/*
		cnt = 0;//baoli
		for(int i = 1 ; i <= n ; i ++)
			if(depth[i] == 0) cnt ++;
		*/
	}
	cout << day;
		
	
}
/*
	truthly, i think this sol has a lot of bug.
	and this sentence has a lot of wrong.
*/