//T2
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n;
long long a[maxn], b[maxn], c[maxn];
long long tmp2[maxn*3];
long long tmpall;

signed main()
{
	long long select[maxn];
	
	cin.tie(0);
	cin >> n;
	
	for(int i = 0 , j = 0 ; i < n ; i++ , j+=3)
	{
		cin >> a[i] >> b[i] >> c[i];
		tmp2[j] = a[i];
		tmp2[j+1] = b[i];
		tmp2[j+2] = c[i];
	}
	
	sort(tmp2, tmp2+n*3);
	tmpall = tmp2[n*3/2]; //中位数
	//cout << tmpall << endl;
	
	/*
	for(int i = 0 ; i < n ; i++)
		tmpall += tmp[i];
	tmpall /= double(n);
	tmpall += 0.5;
	*/
	
	long long div[3], cpydiv[3];
	for(int i = 0 ; i < n ; i++)
	{
		div[0] = abs(tmpall - a[i]);
		div[1] = abs(tmpall - b[i]);
		div[2] = abs(tmpall - c[i]);
		
		for(int j = 0 ; j < 3 ; j++)
		{
			cpydiv[j] = div[j];
		}
		sort(cpydiv, cpydiv+3);
		
		for(int j = 0 ; j < 3 ; j++)
		{
			if(cpydiv[0] == div[j])
			{
				if(j == 0) select[i] = a[i];
				if(j == 1) select[i] = b[i];
				if(j == 2) select[i] = c[i];
			}
		}	
	}
	
	
	//for(int i = 0 ; i < n  ; i++)
	//	cout << select[i] << endl;
	
	
	sort(select, select+n);
	long long ans = select[n-1] - select[0];
	cout << ans;
}