// T6
// expect pts = 50+
// expect diff = idk
// may dp?
// 有点假。就这样吧。

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n;
struct Seq{
	int l, r, c;
}seqs[maxn];
bool sel[maxn];
int ans;

bool seqcmp(Seq a, Seq b)
{
	return a.r < b.r;
}

signed main()
{
	freopen("bicolored.in", "r", stdin);
	freopen("bicolored.out", "w", stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		seqs[i] = {a, b, c};
	}
	sort(seqs+1, seqs+1+n, seqcmp);
	
	int lstr = -1e9;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(seqs[i].l > lstr)
		{
			ans ++;
			sel[i] = 1;
			lstr = seqs[i].r;
		}
	}
	
	for(int i = 1 ; i <= n ; i ++)
		if(!sel[i])
		{
			bool flag = 1;
			for(int j = 1 ; j <= n ; j ++)
				if(j != i && !(seqs[j].r < seqs[i].l || seqs[i].r < seqs[j].l) && sel[j] && seqs[i].c == seqs[j].c)
				{
					flag = 0;
					break;
				}
			if(flag)
				sel[i] = 1, ans ++;
		}
	
	cout << ans;
	
	
	
}