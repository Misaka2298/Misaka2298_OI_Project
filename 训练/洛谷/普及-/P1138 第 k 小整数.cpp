#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;

int n, k;
int val[maxn];

signed main()
{
	cin >> n >>k;
	for(int i = 0 ; i < n ; i++)
		cin >> val[i];
		
	sort(val , val+n);
	
	int cnt = 0, last = 30001;
	for(int i = 0 ; i < n ; i ++)
	{
	 	if(val[i] != last) cnt++;
	 	last = val[i];
	 	if(cnt == k)
	 	{
	 		cout << val[i];
	 		return 0;
	 	}
	}
	cout << "NO RESULT";
	return 0;
}