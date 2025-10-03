// T2
// expect pts = 50
// (n^2)logn
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn = 1e5+10;

int a[maxn], b[maxn];
int n;

bool cmp(int aa, int bb)
{
	return aa > bb;
}

signed main()
{
	freopen("mali.in", "r", stdin);
	freopen("mali.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i] >> b[i];
		sort(a+1, a+i+1);
		sort(b+1, b+i+1, cmp);
		
		/*
		for(int j = 1 ; j <= i ; j ++)
			cout << a[j] << ' ';
		cout << endl;
		for(int j = 1 ; j <= i ; j ++)
			cout << b[j] << ' ';
		cout << endl;
		*/
		
		int maxsum = 0;
		for(int j = 1 ; j <= i ; j ++)
			maxsum = max(maxsum, a[j]+b[j]);
		cout << maxsum << endl;
	}
}