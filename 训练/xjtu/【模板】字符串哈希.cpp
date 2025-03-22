#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, base = 13331;
typedef unsigned long long uLL;

int n, m;
string strr;
uLL hashval[maxn];
char str[maxn];

uLL gethash(int length)
{
	//cout << length << endl;
	
	/*
	for(int i = 1 ; i <= length ; i ++)
		cout << str[i];
	cout << endl;
	*/
	
	uLL ans = 0;
	for(int i = 1 ; i <= length ; i++)
		ans = ans * base + str[i];
	return ans;
}

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> strr;
		int len = strr.length();
		for(int j = 1 ; j <= len ; j++)
			str[j] = strr[j-1]; 
		hashval[i] = gethash(len);
	}
	
	/*
	for(int i = 1 ; i <= n ; i ++)
		cout << hashval[i] << endl;
	*/
	
	sort(hashval+1, hashval+n+1);
	
	int ans = 0;
	for(int i = 1 ; i <= n ; i++)
		if(hashval[i] != hashval[i+1]) ans++;
	cout << ans;
}