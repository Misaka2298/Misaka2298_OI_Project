// Problem: B. 芙芙的超级矩阵蛋糕
// Contest: Hydro
// URL: https://www.yundouxueyuan.com/p/YDOI2024B?tid=691f86e3b213ea989e320818
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Time: 2025-11-26 15:23:55

// expect pts = <= 20 + 40
// 到底错哪了。

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10, maxm = 1e6+10, spe_maxn = 1e5+10;

int n, m;
int a[maxn][maxn];
struct Node{
	int x, y, num;
}nodes[maxm];
int idx;

void debug(int opt)
{
	if(opt == 1)
	{
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= m ; j ++)
				cout << a[i][j] << ' ';
			cout << endl;
		}
	}
	if(opt == 2)
	{
		for(int i = 1 ; i <= idx ; i ++)
			cout << nodes[i].x << ' ' << nodes[i].y << ' ' << nodes[i].num << endl;
	}
	cout << endl;
}

bool check_spe20()
{
	int xans = 0, yans = 0;
	bool is_spe = 1;
	for(int i = 1 ; i <= n ; i ++)
	{
		bool flag = 1;
		for(int j = 1 ; j <= m ; j ++)
		{
			int num;
			cin >> num;
			nodes[++idx] = {i, j, num};
			if(!num)
				is_spe = 0;
			if(j != 1 && nodes[idx].num < nodes[idx-1].num)
				flag = 0;
		}
		if(flag)
			xans ++;
	}
	
	if(!is_spe)
		return 0;
	
	for(int i = 1 ; i <= m ; i ++)
	{
		int j = i, u = nodes[i].num;
		bool flag = 1;
		while(j <= n * m)
		{
			int ne = nodes[j].num;
			if(ne != u)
			{
				flag = 0;
				break;
			}
			j += m;
		}
		if(flag)
			yans ++;
	}
	cout << xans << ' ' << yans << endl;
	return 1;
}

void init()
{
	for(int i = 1 ; i <= idx ; i ++)
		a[nodes[i].x][nodes[i].y] = nodes[i].num;
}

bool is_mayinc[maxn];// 当前这一行有可能单调不降吗？
bool is_allzero[maxn];// 当前这一行全是成都入吗？
int colmax[maxn];// 当前列的最大值。
bool is_canchange[maxn][maxn];// 这个数是可以被更改的吗？

void init_is_mayinc()
{
	memset(is_mayinc, 1, sizeof is_mayinc);
	for(int i = 1 ; i <= n ; i ++)
	{
		int mx = 0;
		for(int j = 1 ; j <= m ; j ++)
		{
			if(a[i][j] < mx && a[i][j])
			{
				is_mayinc[i] = 0;
				break;
			}
			mx = max(mx, a[i][j]);
		}
	}
}

void init_colmax()
{
	for(int j = 1 ; j <= m ; j ++)
	{
		for(int i = 1 ; i <= n ; i ++)
			colmax[j] = max(colmax[j], a[i][j]);
	}
}

void init_is_allzero()
{
	memset(is_allzero, 1, sizeof is_allzero);
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			if(a[i][j] != 0)
				is_allzero[i] = 0;
}

void fill_num()
{
	for(int x = 1 ; x <= n ; x ++)
		for(int y = 1 ; y <= m ; y ++)
		{
			if(a[x][y] == 0)// base
			{
				if(!is_mayinc[x])// switch 1 - down
				{
					a[x][y] = colmax[y];
					/*
					is_whatever[x][y] = 1;
					for(int i = 1 ; i <= n ; i ++)
						if(is_whatever[i][y])
							a[i][y] = a[x][y];
					*/
				}
				else// switch 1 - up
				{
					if(is_allzero[x])// switch 2 - up
					{
						int linemax = 0;
						for(int j = 1 ; j <= m ; j ++)
						{
							if(colmax[j] >= linemax)
							{
								a[x][j] = colmax[j];
								linemax = max(linemax, a[x][j]);
							}
						}
						for(int j = 1 ; j <= m ; j ++)
						{
							if(!a[x][j])
							{
								if(j != 1) a[x][j] = a[x][j-1];
								if(j == 1) a[x][j] = 1;
								colmax[j] = max(colmax[j], a[x][j]);
								is_canchange[x][j] = 1;
							}
						}
						is_allzero[x] = 0;
					}
					else// switch 2 - down
					{
						int aftermn = 0x3f3f3f3f;// 当前行这个数后最小的值
						for(int j = y+1 ; j <= m ; j ++)
							if(a[x][j])
							{
								aftermn = a[x][j];
								break;
							}
						if(colmax[y])// switch 3 - up
						{
							a[x][y] = max(a[x][y-1], min(aftermn, colmax[y]));
							colmax[y] = max(colmax[y], a[x][y]);		
						}
						else// switch 3 - down
						{
							int beforemx = 0;//这个数往左的最大方块的最大值
							for(int i = 1 ; i <= n ; i ++)
								for(int j = 1 ; j < y ; j ++)
									beforemx = max(beforemx, a[i][j]);
							a[x][y] = min(aftermn, beforemx);
							colmax[y] = max(colmax[y], a[x][y]);
						}
					}
				}
				//debug(1);
			}
		}
		
		/*
		for(int x = 1 ; x <= n ; x ++)
		{
			for(int y = 1 ; y <= m ; y ++)
				if(is_canchange[x][y])
				{
					int before = a[x][y-1], after = a[x][y+1], colnum = a[x][y];
					for(int j = y-1 ; j >= 1 ; j --)
						if(!is_canchange[x][j])
						{
							before = a[x][j];
							break;
						}
					for(int j = y+1 ; j <= m ; j ++)
						if(is_canchange[x][j])
						{
							after = a[x][j];
							break;
						}
					for(int i = 1 ; i <= n ; i ++)
						if(is_canchange[i][y])
						{
							colnum = a[i][y];
							break;
						}
					if(colnum >= before && colnum <= after)
						a[x][y] = colnum;
					is_canchange[x][y] = 0;
				}
		}
		*/
}

void out_ans()
{
	int xans = 0, yans = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		bool flag = 1;
		for(int j = 1 ; j <= m ; j ++)
			if(a[i][j] < a[i][j-1])
				flag = 0;
		if(flag)
			xans ++;
	}
	
	for(int j = 1 ; j <= m ; j ++)
	{
		bool flag = 1;
		for(int i = 1 ; i <= n ; i ++)
			if(a[i][j] != a[1][j])
				flag = 0;
		if(flag)
			yans ++;
	}
	cout << xans << ' ' << yans << endl;
}

void solve()
{
	init_is_mayinc();
	init_colmax();
	init_is_allzero();
	fill_num();
	//debug(1);
	out_ans();
}

signed main()
{
	cin >> n >> m;
	if(check_spe20())// and cin
		return 0;
	init();
	//debug(1);
	solve();
}