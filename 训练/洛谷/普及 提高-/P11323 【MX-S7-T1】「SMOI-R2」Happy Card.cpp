#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;

int t , n , v[maxn];
long long sum , cnt1, cnt2 ,cnt3;

signed main()
{
	cin >> t;
	while(t--)
	{
		sum = cnt1 = cnt2 = cnt3 = 0;
		memset(v,0,sizeof v);
		cin >> n;
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> v[i];
			sum += v[i];
			cnt3 += v[i] / 3;
		}
		if(sum/4 < cnt3)
		{
			if (sum % 4 == 1) cout << sum / 4 + 1 << endl;
            else if (sum % 4 ==2) cout << sum / 4 + 1 << endl;
            else if (sum % 4 == 3) cout << sum / 4 + 2 << endl;
            else if (sum % 4 == 0) cout << sum / 4 << endl;
		}
		else if (cnt3 <= sum/4)
		{
			
			for(int i = 1 ; i<=n ; i++)
			{
				if(v[i] % 3 == 1)cnt1++;
				if(v[i] % 3 == 2)cnt2++;
			}
			if(cnt3 <= cnt1) cout << cnt1+cnt2 << endl;
			else if (cnt3 > cnt1) cout << cnt3 + cnt2 - (cnt3 - cnt1) / 2 << endl;
		}
	}
	return 0;
}