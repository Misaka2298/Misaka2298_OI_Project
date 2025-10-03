// T2
// expect pts = 100(duipai)
// expect diff = yellow -

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define endl '\n'

int T;
LL ans, n;

int checkdigit(LL x)
{
	int res = 0;
	while(x)
	{
		res ++;
		x /= 10;
	}
	return res;
}

bool check(LL x, int digit)
{
	int first = n / pow(10, digit-1);
	string goal = "";
	for(int i = 1 ; i <= digit ; i ++)
		goal += to_string(first);
	LL g = stoi(goal);
	return x >= g;
}

signed main()
{
	freopen("nums.in", "r", stdin);
	freopen("nums.out", "w", stdout);
	cin >> T;
	while(T --)
	{
		cin >> n;
		ans = 0;
		
		int digit = checkdigit(n);
		ans += (digit-1) * 9;
		
		ans += (n / pow(10, digit-1)) - 1;
		
		
		if(digit != 1 && check(n, digit))
			ans ++;
		if(digit == 1)
			ans ++;//special
		cout << ans << endl;
	}
}