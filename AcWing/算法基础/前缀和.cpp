#include  <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn];
long long s[maxn];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	//初始化前缀和,O(n)
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	
	//搜索，O(1)
	while(m--)
	{
		int l,r;
		cin >> l >> r;
		cout << s[r]-s[l-1] <<endl;
	}
	return 0;
}