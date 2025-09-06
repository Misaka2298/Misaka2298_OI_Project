// T3
// expect pts = 30 ~ 60
// expect diff = black。
// wtf。。。。。。
// 何意味啊 这个题目
// 问号
// 60分的也不是seg tree
// 那他想让我写啥
// 太神秘了 写个30的O(n*max(k))跑了
// 相信accoders评测机神力能让我曹过去60分

// 哦 好像不是
// 喜报：Misaka大人题又又又读假了

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+10;
typedef long long LL;
#define endl '\n'

int n;
LL arr[maxn];
int opt[maxn];
LL k[maxn];
LL len;

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> opt[i] >> k[i];
		len = max(len, k[i]);
	}
	
	for(int u = 1 ; u <= n ; u ++)
	{
		if(opt[u] == 1)
		{
			for(int i = k[u]+1 ; i <= len ; i ++)
				arr[i] += (int)(log2(i - k[u]));
		}
		else
			cout << arr[k[u]] << endl;
	}
	return 0;
}
