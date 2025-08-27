// Problem: 高斯消元解线性方程组
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/885/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-08-26 13:21:32

#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const double eps = 1e-8;

int n;
double a[maxn][maxn];

int gauss()
{
	int c = 0, r = 0;
	for(; c < n ; c ++)
	{
		int t = r;
		for(int i = r ; i < n ; i ++)
			if(fabs(a[i][c]) > fabs(a[t][c]))
				t = i;
		
		if(fabs(a[t][c]) < eps)
			continue;
		
		for(int i = c ; i <= n ; i ++)
			swap(a[t][i], a[r][i]);
		for(int i = n ; i >= c ; i --)
			a[r][i] /= a[r][c];
		for(int i = r+1 ; i < n ; i ++)
			if(fabs(a[i][c]) > eps)
				for(int j = n ; j >= c ; j --)
					a[i][j] -= a[r][j] * a[i][c];
		r ++;
	}
	
	if(r < n)
	{
		for(int i = r ; i < n ; i ++)
			if(fabs(a[i][n]) > eps)
				return 2;//none;
		return 1;// unlimit
	}
	for(int i = n-1 ; i >= 0 ; i --)
		for(int j = i+1 ; j < n ; j ++)	
			a[i][n] -= a[i][j] * a[j][n];
	
	return 0;
}

signed main()
{
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		for(int j = 0 ; j < n+1 ; j ++)
			cin >> a[i][j];
	
	int t = gauss();
	if(t == 2)
		cout << "No solution" << endl;
	else if(t == 1)
		cout << "Infinite group solutions" << endl;
	else
	{
		for(int i = 0 ; i < n ; i ++)
			cout << fixed << setprecision(2) << a[i][n] << endl;
	}
}







