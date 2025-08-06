// T3

// T1宝宝，你为何是错在传参的longlong上。
// 我怎么想都没想到是错在longlong上。
// 你让我好生调试啊。我调到昏天黑地了。
// 对不起圈老师，我要在T3狠狠地写#define int long long了。
// 以及, C0ns1st是奶龙。
// 颤抖吧T3，本迷你世界领域宇宙第一泰始皇赢正大玉要来切你了。

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;


#define int long long
#define int long long
#define int long long
#define int long long
#define int long long


//#define return C0ns1st_is_NaiLoong;

int n;
int medicine[maxn];//不知道拼没拼错。
int xorg[maxn][maxn];
int linemax[maxn], linemin[maxn];

signed main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> medicine[i];
		
	memset(linemin, 0x3f, sizeof linemin);
	for(int i = 1; i <= n; i ++)
		linemax[i] = -1e9;
	
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			if(i != j)
			{
				xorg[i][j] = medicine[i] xor medicine[j];
				linemax[i] = max(linemax[i], xorg[i][j]);
				linemin[i] = min(linemin[i], xorg[i][j]);
			}
	
	/*
	for(int i = 1 ; i <= n ; i++)
		cout << linemin[i] << ' ' << linemax[i] << endl;
	*/
	
	int blueans = -1e9, means = 0x3f3f3f3f;
	for(int i = 1 ; i <= n ; i ++)
	{
		blueans = max(blueans, linemin[i]);
		means = min(means, linemax[i]);
	}
		
	cout << blueans << ' ' << means;
	
	return 0;
	//C0ns1st_is_NaiLoong 0;
}