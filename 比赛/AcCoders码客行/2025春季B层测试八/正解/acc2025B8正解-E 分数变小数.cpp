//T5正解
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, d, cnt, len;
string ans;
int st[maxn];

signed main()
{
	cin >> n >> d;
	int k = n/d;
	do
	{
		ans = char(k%10+'0') + ans;
		k /= 10;
	}while(k>0);
	ans += ".";
	
	n = n % d;
	
	int lpare = -1;
	do
	{
		if(st[n])
		{
			lpare = st[n];
			break;
		}
		else
			st[n] = ans.size();
		n *= 10;
		k = n / d;
		ans += char(k+'0');
		n = n % d;
	}while(n);
	
	if(lpare != -1)
		ans += ')';
	
	len = ans.size();
	for(int i = 0 ; i < len ; i ++)
	{
		if(i == lpare)
		{
			cout << '(';
			i--;
			lpare = -1;
		}
		else
			cout << ans[i];
		cnt ++;
		if(cnt % 76 == 0) putchar('\n');
	}
}