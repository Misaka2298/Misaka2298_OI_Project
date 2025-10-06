// B - fixed
// expect pts = 100
// expect diff = yellow +, green -
/*
我不要做数学题。。。
样例可真够坑人的
我简直就是 OI 天才
哼哼哼哈哈哈嘿嘿嘿
哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟哔嘟
我没想到opt4这也能卡我一脚
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;

int n;
LL a[maxn], cnt[maxn];
LL precnt[maxn];
LL opt, x;
unordered_set<LL> st;
LL ans;

void sol1()// 对拍通过
{
	for(int i = 1 ; i <= n ; i ++)
	{
		LL u = a[i];
		if(st.find(u) == st.end() && x-u <= 1e6 && x-u >= 1)
		{
			if(u != x-u) ans += cnt[u] * cnt[x-u];
			else ans += cnt[u] * (cnt[u] - 1);
			st.insert(u);
		}
	}
	cout << ans;
}

void sol2()// 对拍通过
{
	for(int i = 1 ; i <= n ; i ++)
	{
		LL u = a[i];
		if(st.find(u) == st.end() && u-x <= 1e6 && u-x >= 1)
		{
			if(u != u-x) ans += cnt[u] * cnt[u-x];
			else ans += cnt[u] * (cnt[u] - 1);
			st.insert(u);
		}
	}
	cout << ans;
}

void sol3()// 对拍通过
{
	for(int i = 1 ; i <= n ; i ++)
	{
		LL u = a[i];
		LL goal = x / u;
		if(st.find(u) == st.end() && goal <= 1e6 && goal >= 1 && x % u == 0)
		{
			if(u != goal) ans += cnt[u] * cnt[goal];
			else ans += cnt[u] * (cnt[u] - 1);
			//cout << u << ' ' << cnt[u] << ' ' << goal << ' ' << cnt[goal] << endl;
			st.insert(u);
		}
	}
	cout << ans;
}

void sol4()// 对拍通过// 你都通过了些什么
{
	for(int i = 1 ; i <= 1e6 ; i ++)
		precnt[i] = precnt[i-1] + cnt[i];
	if(x == 0)// 特判
	{
		LL now = 0;
		for(int i = 1 ; i <= 1e6 ; i ++)
		{
			ans += now * cnt[i];
			now += cnt[i];
		}
		cout << ans;
		exit(0);
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		LL u = a[i];
		LL l = (u/(x+1))+1, r = u/x;
		if(st.find(u) == st.end() && l <= 1e6 && l >= 1 && r <= 1e6 && r >= 1)
		{
			ans += cnt[u] * (precnt[r] - precnt[l-1]);
			if(x == 1)
				ans -= cnt[u];
			st.insert(u);
		} 
	}
	cout << ans;
}


signed main()
{
	//freopen("data.in", "r", stdin);
	//freopen("my.out", "w", stdout);
	freopen("two.in", "r", stdin);
	freopen("two.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
		cnt[a[i]] ++;
	}
	cin >> opt >> x;
	
	if(opt == 1)
		sol1();
	if(opt == 2)
		sol2();
	if(opt == 3)
		sol3();
	if(opt == 4)
		sol4();
}