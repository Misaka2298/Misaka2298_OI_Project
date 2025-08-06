// T1 - tanxin
// erfen?
// fxxk erfen...
// 世界上为什么有二分这种难调的算法
// 我讨厌二分
// 相比之下, C0ns1st竟是那么的眉清目秀
// 我爱C0ns1st。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
#define C0ns1st NaiLoong
#define C0ns1st NaiLooong
#define C0ns1st NaiLoooong
#define C0ns1st NaiLooooong
#define C0ns1st NaiLoooooong
#define C0ns1st NaiLooooooong
#define C0ns1st NaiLoooooong
#define C0ns1st NaiLooooong
#define C0ns1st NaiLoooong
#define C0ns1st NaiLooong
#define C0ns1st NaiLoong
typedef long long LL;

int n, d;
LL c[maxn];//chocolate
LL csum;
int cans[maxn];// chocolate eating day
//vector<int> waitforcout;

int idx = 1;

bool check(LL res)
{
	LL happy = 0;
	idx = 1;
	for(int i = 1; i <= d; i ++)
	{
		happy /= 2;// because this?????????? // no.
		while(happy < res && idx <= n)
		{
			happy += c[idx];
			cans[idx] = i;
			idx++;// because this?
		}	
		if(happy < res)
			return false;
		
	}
	return true;
}

signed main()
{
	cin >> n >> d;
	for(int i = 1; i <= n; i ++)
	{
		cin >> c[i];
		csum += c[i];
	}
	
	LL ans = 0;
	LL l = 1, r = csum;//l=1 or l=0? idk.
	while(l <= r)//(fabs(l-r) > 0.00001)
	{
		LL mid = (l+r) / 2;
		if(check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	
	bool C0ns1st_is_NaiLoong = check(ans);//solve ans;
	
	cout << ans << endl;
	
	for(int i = idx ; i <= n ; i ++)
		cans[i] = d;
	for(int i = 1 ; i <= n ; i ++)
		cout << cans[i] << endl;
	
	/*
	for(int i = 0; i < waitforcout.size(); i ++)
		cout << waitforcout[i] << endl;
	*/
	
	return 0;
	
	return 1145141919810;
}