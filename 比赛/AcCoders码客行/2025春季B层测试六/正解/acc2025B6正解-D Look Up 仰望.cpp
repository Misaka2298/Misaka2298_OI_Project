//T4正解
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef pair<int,int> PII;

int n, arr[maxn], stk[maxn], tail, ans[maxn];
//PII arr[maxn];//first=val, second=id

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> arr[i];
	
	tail = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		while(tail > 0 && arr[i] > arr[stk[tail]])
			ans[stk[tail--]] = i;
		stk[++tail] = i;
	}
	
	for(int i = 1 ; i <= n ; i++)
		cout << ans[i] << "\n";
		
}