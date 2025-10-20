// D
// expect pts = 100
// expect diff = orange+, yellow-

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;

int n;
int a[maxn], b[maxn];
int l[4], r[4];//2's l, r
int ans;

int getoth(int x, int y)
{
	if((x == 1 && y == 2) || (x == 2 && y == 1))
		return 3;
	if((x == 1 && y == 3) || (x == 3 && y == 1))
		return 2;
	if((x == 2 && y == 3) || (x == 3 && y == 2))
		return 1;
}

signed main()
{
	freopen("tsort.in", "r", stdin);
	freopen("tsort.out", "w", stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	memcpy(b, a, sizeof a);
	sort(b+1, b+1+n);
	
	l[1] = 1, r[3] = n;
	
	for(int i = 1 ; i <= n ; i ++)
	{
		if(b[i-1] == 1 && b[i] == 2)
			r[1] = i-1, l[2] = i;
		if(b[i+1] == 3 && b[i] == 2)
			r[2] = i, l[3] = i+1;
	}
	
	//printf("%d %d %d %d %d %d", l[1], r[1], l[2], r[2], l[3], r[3]);
	
	for(int i = 1 ; i <= n ; i ++)
	{
		if(a[i] != b[i])
		{
			bool flag = 0;
			for(int j = l[a[i]] ; j <= r[a[i]] ; j ++)
				if(a[j] == b[i])
				{
					swap(a[i], a[j]);
					flag = 1;
					ans ++;
					//cout << 'a' << ' ' << i << ' ' << j << endl;
					break;
				}
			if(!flag)
			{
				int oth = getoth(a[i], b[i]);
				//cout << oth;
				for(int j = l[oth] ; j <= r[oth] ; j ++)
					if(a[j] == b[i])
					{
						swap(a[i], a[j]);
						flag = 1;
						ans ++;
						break;
						//cout << 'b' << ' ' << i << ' ' << j << endl;
					}
			}
			/*
			for(int i = 1 ; i <= n ; i ++)
				cout << a[i] << ' ';
			cout << endl;
			*/
		}
	}
	cout << ans;
}