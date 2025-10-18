// C
// expect pts = orange+, yellow-
// expect diff = 100
// 简单的差分

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, m;
int jadd[maxn], jdiv[maxn], oadd[maxn], odiv[maxn];
// “减法”的英文是什么来着？

void dbug()
{
	cout << "jadd:";
	for(int i = 1 ; i <= n ; i ++)
		cout << jadd[i] << ' ';
	cout << endl;
	
	cout << "jdiv:";
	for(int i = 1 ; i <= n ; i ++)
		cout << jdiv[i] << ' ';
	cout << endl;
	
	cout << "oadd:";
	for(int i = 1 ; i <= n ; i ++)
		cout << oadd[i] << ' ';
	cout << endl;
	
	cout << "odiv:";
	for(int i = 1 ; i <= n ; i ++)
		cout << odiv[i] << ' ';
	cout << endl;
	
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("list.in", "r", stdin);
	freopen("list.out", "w", stdout);
	cin >> n >> m;
	while(m --)
	{
		int l, r;
		cin >> l >> r;
		if(l % 2 == 0)
		{
			oadd[r+1] -= 1; oadd[l] += 1;
			jdiv[r+1] -= 1; jdiv[l] += 1;
		}
		else
		{
			jadd[r+1] -= 1; jadd[l] += 1;
			odiv[r+1] -= 1; odiv[l] += 1;
		}
	}
	
	for(int i = 1 ; i <= n ; i ++)
	{
		oadd[i] += oadd[i-1]; odiv[i] += odiv[i-1];
		jadd[i] += jadd[i-1]; jdiv[i] += jdiv[i-1];
	}
	
	//dbug();
	
	for(int i = 1 ; i <= n ; i ++)
	{
		if(i % 2 == 0)
			cout << oadd[i] - odiv[i] << ' ';
		else
			cout << jadd[i] - jdiv[i] << ' ';
	}
	
}