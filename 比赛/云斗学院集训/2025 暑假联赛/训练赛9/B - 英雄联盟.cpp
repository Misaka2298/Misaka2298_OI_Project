// B
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
#define int long long

int n , vv;
int v[maxn], s[maxn];
int f[maxn];
int sum;

signed main()
{
	cin >> n >> vv;
	for(int i = 1 ; i <= n ; i ++)
		cin >> s[i];
	for(int i = 1 ; i <= n ; i ++)
		cin >> v[i];
	
	for(int i = 1 ; i <= n ; i ++)
		sum += s[i] * v[i];
		
	
	f[0] = 1;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = sum ; j >= 0 ; j --)
			for(int k = 1 ; k<=s[i] && k*v[i]<=j ; k ++)
				f[j] = max(f[j], f[j-k*v[i]]*k);
	
	/*
	for(int i = 1 ; i <= sum ; i ++)
		cout << f[i] << ' ';
	*/
	
	for(int i = 0 ; i <= sum ; i ++)
		if(f[i] >= vv)
		{
			cout << i;
			break;
		}
	
	return 0;
}