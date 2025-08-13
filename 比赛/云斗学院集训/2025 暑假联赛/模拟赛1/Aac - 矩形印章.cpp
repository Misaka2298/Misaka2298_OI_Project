// A-ac
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
typedef pair<int, int> PII;

int T;
int n, m, a, b;
int fsti, fstj;
bool g[maxn][maxn];
vector<PII> s;

void init()
{
	memset(g, 0, sizeof g);
	s.resize(0);
}

bool check(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

bool solve()
{
	char tmp;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
		{
			cin >> tmp;
			if(tmp == 'x')
				g[i][j] = 1;
		}
			
			
	bool flag = false;
	for(int i = 1 ; i <= a ; i ++)
		for(int j = 1 ; j <= b ; j ++)
		{
			cin >> tmp;
			if(tmp == 'x')
			{
				if(!flag)
					fsti = i, fstj = j;
				flag = 1;
				s.push_back({i - fsti, j - fstj});//相对位置
			}
		} 
	if(!flag)
		return 0;
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			if(g[i][j])
				for(auto ink : s)
				{
					int x = ink.first + i, y = ink.second + j;
					if(!g[x][y] || !check(x, y))
						return 0;
					g[x][y] = 0;
				}
	return 1;
}

signed main()
{
	freopen("seal.in", "r", stdin);
	freopen("seal.out", "w", stdout);
	cin >> T;
	while(T --)
	{
		init();
		cin >> n >> m >> a >> b;
		
		if(solve())
			cout << "TAK" << endl;
		else
			cout << "NIE" << endl;
		
	}
}