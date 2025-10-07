#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
// C
// expect pts = 100
// expect diff = yellow
/*
前缀和套二分吗
我去我二分一遍写过如何呢
Misaka2298简直就是OI大手子
开赛27分钟写过3题，我无敌了
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef long long LL;

int n, q;
LL a[maxn], s[maxn];

bool cmp(LL aa, LL bb)
{
	return aa > bb;
}

signed main()
{
	freopen("sugar.in", "r", stdin);
	freopen("sugar.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	
	sort(a+1, a+1+n, cmp);
	
	for(int i = 1 ; i <= n ; i ++)
		s[i] = s[i-1] + a[i];
	
	while(q --)
	{
		LL check;
		cin >> check;
		if(check > s[n])
		{
			cout << -1 << endl;
			continue;
		}
		LL l = 1, r = n, ans = 0;
		while(l <= r)
		{
			LL mid = (l + r) / 2;
			if(s[mid] >= check)
			{
				r = mid - 1;
				ans = mid;
			}
			else
				l = mid + 1;
		}
		cout << ans << endl;
	}
	
	
}