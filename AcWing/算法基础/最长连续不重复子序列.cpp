#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn],ans;
int main()
{
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	int cnt[maxn]={0};
	for(int i=0,j=0;i<n;i++)
	{
		cnt[a[i]]++; //计数位图自增i遍历过的数，计算数的出现次数
		while(j<i&&cnt[a[i]]>1)
		{
			cnt[a[j]]--;
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout << ans;
	return 0;
}