// T1

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int a[maxn];
int n, m, k, x;

// (x + (m*pow(10,k))) % n
signed main()
{
	cin >> n >> m >> k >> x;
	
	cout << (x + (int)(m*pow(10,k))) % n;
}

/*
	for(int i = 0 ; i < n ; i ++)
		a[i] = i;//, cout << a[i] << ' ';
	//cout << endl;
	for(int kk = 0 ; kk < pow(10, k) ; kk ++)
	{
		for(int i = 0 ; i < n ; i ++)
		{
			a[i] = (a[i] + m) % n;
			//cout << a[i] << ' ';
		}
		//cout << endl;
	}
	cout << a[x];
*/