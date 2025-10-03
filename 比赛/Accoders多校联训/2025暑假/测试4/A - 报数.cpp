// T1
// expect pts = 100
// EZ
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

//int range[]={0, 1,  2,  4,  7, 8,11,13,14}; 
LL delta[] = {0, 13, 12, 10, 7, 6, 3, 1, 0};
LL n;

signed main()
{
	freopen("num.in", "r", stdin);
	freopen("num.out", "w", stdout);
	
	cin >> n;
	LL rangecnt = (n-1) / 8 + 1;//第rangecnt个区间
	LL innercnt = n % 8;//区间内第innercnt位
	if(innercnt == 0)
		innercnt = 8;
	//LL endcnt = rangecnt * 8;//区间内最后一位
	
	//LL startnum = 16 * (rangecnt-1) - (rangecnt-2);//区间内第一位数
	LL endnum = 15 * rangecnt - 1;//区间内最后一位数
	
	cout << endnum - delta[innercnt];
		
}