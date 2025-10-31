// J
// expect pts = idk
// expect diff = idk

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;
#define endl '\n'

LL stk[maxn];
int tail;

signed main()
{
	//freopen("exp.in", "r", stdin);
	//freopen("exp.out", "w", stdout);
	LL a;
	cin >> a;
	stk[++tail] = a;
	
	while(true)
	{
		char opt = 0;
		LL num = 0;
		cin >> opt >> num;
		if(num == 0)
			break;
		
		if(opt == '+')
			stk[++tail] = num;
		else
		{
			LL ne = stk[tail] * num;
			stk[tail] = ne;
		}	
	}
	
	while(tail > 1)
	{
		LL a = stk[tail-1], b = stk[tail];
		tail -= 1;
		stk[tail] = a + b;
	}
	
	//cout << stk[1];
	string ans = to_string(stk[1]);
	int len = ans.size() - 4;
	for(int i = max(len, 0) ; i < ans.size() ; i ++)
		cout << ans[i];
}