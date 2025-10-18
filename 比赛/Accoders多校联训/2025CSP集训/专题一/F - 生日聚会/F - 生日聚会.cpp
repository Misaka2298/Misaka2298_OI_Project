// F
// expect pts = 100
// expect diff = yellow
// 真正的难题要来了吗！
// 好像就是一道双指针······
// 没有负数真的是太好了
// 好难调！！！
// 可能是对的吧。

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef pair<int, int> PII;
typedef long long LL;

int n, d;
PII arr[maxn];

signed main()
{
	freopen("data.in", "r", stdin);
	freopen("user.out", "w", stdout);
	cin >> n >> d;
	for(int i = 1 ; i <= n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		arr[i] = {a, b};
	}
	
	sort(arr+1, arr+1+n);
	reverse(arr+1, arr+1+n);
	
	int mx1 = arr[1].first, mn1 = arr[1].first;//区间最大，最小
	int mx2 = 0, mn2 = 0x3f3f3f3f;//区间次大，次小
	LL ans = 0, sum = 0;
	int i = 1, j = 0;
	
	while(i != n || j != n)
	{ 
		if(j < n) j ++;
		int jm = arr[j].first, jfri = arr[j].second;
		if(jm > mx1)
			mx2 = mx1, mx1 = jm;
		else if(jm > mx2 && j != 1)
			mx2 = jm;
			
		if(mn1 > jm)
			mn2 = mn1, mn1 = jm;
		else if(mn2 > jm && j != 1)
			mn2 = jm;
		
		sum += jfri;
		while(mx1 - mn1 > d)
		{
			int im = arr[i].first, ifri = arr[i].second;
			if(i < n && i < j)
				i ++;
			sum -= ifri;
			if(mx1 == im)
				mx1 = mx2, mx2 = 0;
			if(mn1 == im)
				mn1 = mn2, mn2 = 0x3f3f3f3f;
			//cout << i << ' ' << j << endl;
		}
		//ans = max(ans, sum);
		if(sum > ans)
		{
			ans = sum;
		}
		//printf("%d %d %d %d %d %d %lld\n",i ,j ,mx1, mx2, mn1, mn2, sum);
		
	}
	
	cout << ans;
}