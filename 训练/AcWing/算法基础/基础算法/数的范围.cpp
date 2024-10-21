#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,q;
	cin >> n >> q;
	int a[n+5]={0};
	for(int i=0;i<n;i++) cin >> a[i];
	while(q--)
	{
		int check;
		cin >> check;
		int l=0,r=n-1;
		while(l<r)
		{
			//为什么这个是找区间左边界
			int mid=(l+r)/2;
			if(a[mid]>=check) r=mid;
			else l=mid+1;
		}
		if(a[l]!=check) cout << "-1 -1" <<endl;
		else
		{
			cout << l << " " ;
			int l=0,r=n-1;
			while(l<r)
			{
				//为什么这个是找区间右边界
				int mid=(l+r+1)/2;
				if(a[mid]<=check) l=mid;
				else r=mid-1;
			}
			cout << l << endl;
		}
	}
	return 0;
}