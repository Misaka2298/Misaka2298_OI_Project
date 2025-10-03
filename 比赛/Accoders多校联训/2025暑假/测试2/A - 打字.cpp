//T1
//expect pts = 100
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
#define endl '\n'

int n, cnt, ans;
string str;

void check()
{
	if(str.size() == 1 && isupper(str[0]))
	{
		ans ++;
		return;
	}
	if(!isupper(str[0]))
		return;
	
	for(int i = 1 ; i < str.size() ; i ++)
		if(isupper(str[i]))
			return;
	ans ++;
	return;
}

signed main()
{
	freopen("data.in", "r", stdin);
	freopen("user.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); 
	cin >> n;
	while(cnt != n)
	{
		cin >> str;
		
		check();
		 
		char tmp = str[str.size()-1];
		if((tmp == '.') || (tmp == '?') || (tmp == '!'))
		{
			cnt ++;
			//check();
			cout << ans << endl;
			ans = 0;
		}
	}
}