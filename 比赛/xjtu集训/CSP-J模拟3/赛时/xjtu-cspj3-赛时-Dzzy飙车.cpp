//T3
//这里是我拉的一坨新鲜的__。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 55, maxk = 1010;
typedef pair<int,int> PII;

int n, m, k, fx[maxk];
char g[maxn][maxn];
bool may[maxn][maxn], guding[maxn][maxn];
string tmp;
PII init;

void update()//上1下2左3右4
{
	queue<PII>q1, q2;
	int tick = 0;
	q1.push(init);
	may[init.first][init.second] = true;
	for(int bb = 0 ; bb < k ; bb++)
	{
		int goal = fx[bb];//方向
		while(true)
		{
			if(tick == 0 && !q1.size())
			{
				for(int i = 0 ; i <= n ; i++)
					for(int j = 0 ; j <= m ; j++)
						guding[i][j] = false;
				tick = 1;
				//cout << 'a';
				break;
			}
			else if(tick == 1 && !q2.size())
			{
				for(int i = 0 ; i <= n ; i++)
					for(int j = 0 ; j <= m ; j++)
						guding[i][j] = false;
				tick = 0;
				//cout << 'a';
				break;
			}
			
			int tx = 0, ty = 0;
			
			if(tick == 0){
				auto t = q1.front();
				q1.pop();
				tx = t.first, ty = t.second;
				//cout << 't' << tick << ' ' << tx << ' ' << ty << "fx" << goal << endl;//debug
				if(!guding[tx][ty])may[tx][ty] = false;
			}
			if(tick == 1){
				auto t = q2.front();
				q2.pop();
				tx = t.first, ty = t.second;
				//cout << 't' << tick << ' ' << tx << ' ' << ty << "fx" << goal << endl;//debug
				if(!guding[tx][ty])may[tx][ty] = false;
			}
			
			 if (goal == 1) 
			 { 
                for (int i = tx - 1; g[i][ty] != 'X'; i--) 
                {
                    may[i][ty] = true; guding[i][ty] = true;
                    if (tick == 0) q2.push({i, ty});
                    else q1.push({i, ty});
                }
            } 
            else if (goal == 2) 
            { 
                for (int i = tx + 1; g[i][ty] != 'X'; i++) 
                {
                    may[i][ty] = true; guding[i][ty] = true;
                    if (tick == 0) q2.push({i, ty});
                    else q1.push({i, ty});
                }
            } 
            else if (goal == 3) 
            { 
                for (int j = ty - 1; g[tx][j] != 'X'; j--) 
                {
                    may[tx][j] = true; guding[tx][j] = true;
                    if (tick == 0) q2.push({tx, j});
                    else q1.push({tx, j});
                }
            } 
            else if (goal == 4) 
            { 
                for (int j = ty + 1; g[tx][j] != 'X'; j++) 
                {
                    may[tx][j] = true; guding[tx][j] = true;
                    if (tick == 0) q2.push({tx, j});
                    else q1.push({tx, j});
                }
            }
				
		}
	}
}

signed main()
{
	cin >> n >> m;
	for(int i = 0 ; i <= n+1 ; i++)
		for(int j = 0 ; j <= m+1 ; j++)
			g[i][j] = 'X';
	
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
		{
			cin >> g[i][j];
			if(g[i][j] == '*')
			{
				init.first = i, init.second = j;
				g[i][j] = '.';
			}
		}
			
	/*
	for(int i = 0 ; i <= n+1 ; i++)//debug
	{
		for(int j = 0 ; j <= m+1 ; j++)
			cout << g[i][j];
		cout << endl;
	}
	*/
	
	
	cin >> k;
	for(int i = 0 ; i < k ; i++)
	{
		cin >> tmp;
		if(tmp == "NORTH")
			fx[i] = 1;
		else if(tmp == "SOUTH")
			fx[i] = 2;
		else if(tmp == "WEST")
			fx[i] = 3;
		else
			fx[i] = 4;
	}
	update();
	
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= n ; j++)
		{
			if(!may[i][j])
				cout << g[i][j];
			else
				cout << '*';
		}
		cout << endl;
	}
}