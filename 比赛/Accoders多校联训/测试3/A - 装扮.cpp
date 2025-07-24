// T1
// expect pts = 100
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;
#define endl '\n'

LL a_size, b_size, c_size, q;
LL b_in[maxn], b_out[maxn];

signed main()
{
	freopen("cps.in", "r", stdin);
	freopen("cps.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> a_size >> b_size >> c_size >> q;
	
	for(int i = 1 ; i <= b_size ; i ++)
	{
		b_in[i] = a_size;
		b_out[i] = c_size;
	}
	
	while(q--)
	{
		string opt;
		LL x, y;
		cin >> opt >> x >> y;
		if(opt == "CP")
			b_in[y] --;
		else
			b_out[x] --;
	}
	
	LL ans = 0;
	for(int i = 1 ; i <= b_size ; i ++)
		ans += b_in[i] * b_out[i];
	
	cout << ans;
}