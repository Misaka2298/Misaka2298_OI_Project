//T1
#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;

long long n, mod, goal, idx;
long long arr[maxn];
long long zys[maxn*4];

void divide(long long x)
{
	for(int i = 2 ; i <= x/i ; i++)
	{
		if(x % i == 0)
		{
			int s = 0;
			while(x % i == 0)
			{
				x /= i;
				zys[idx++] = i;
				s++;
			}
			//cout << i << ' ' << s << endl;
		}
	}
	if(x > 1) zys[idx++] = x;//cout << x << ' '<< 1 << endl;
	//cout << endl;
	return;
}

signed main()
{
	cin >> n >> mod;
	arr[0] = 0; arr[1] = 1;
	for(int i = 2 ; i <= n ; i++)
		arr[i] = 2*arr[i-1] + arr[i-2];
	goal = arr[n] % mod;
	cout << goal << "=";
	
	divide(goal);
	sort(zys, zys+idx);
	
	for(int i = 0 ; i < idx ; i++)
	{
		cout << zys[i];// << ' ';
		if(i != idx-1)
			cout << '*';
	}	
		
		
	/*
	for(int i = 1 ; i <= idx ; i++)
	{
		cout << zys[i];
		if(i != idx-1)
			cout << "*";
	}
	*/
		
		
}
/*
4866752642924153522
*/