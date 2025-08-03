//T2
//expect pts = 100?
#include <bits/stdc++.h>
using namespace std;
const int maxn = 22;
typedef long long LL;
typedef pair<LL, LL> PLL;

LL n;
LL maxtick, tick[maxn];
PLL num[maxn];//1=ChangedNum, 2=VanilaNum;
LL zerotick;

bool numcmp(PLL a, PLL b)
{
	return a.first > b.first;
}

signed main()
{
	cin >> n;
	//maxtick = 0;
	for(int i = 0 ; i < n ; i++)
	{
		LL number;
		cin >> number;
		if(number == 0)
			zerotick ++;
		
		num[i].first = num[i].second = number;
		tick[i] = to_string(number).size();
		maxtick = max(maxtick, tick[i]);
	}
	
	
	if(zerotick == n)
	{
		cout << 0;
		exit(0);
	}
	
	for(int i = 0 ; i < n ; i++)
		if(tick[i] != maxtick)
			num[i].first *= pow(10, maxtick-tick[i]);
	
	sort(num, num+n, numcmp);
	for(int i = 0 ; i < n ; i ++)
		cout << num[i].second;
}