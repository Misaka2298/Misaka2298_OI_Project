// I
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef long long LL;
#define endl '\n'
typedef pair<int, int> PII;

LL T, n;
LL k;
char str[maxn];
LL range0cnt;

void init()
{
	range0cnt = 0;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> T;
	while(T--)
	{
		init();
		
		cin >> n >> k;
		LL last0 = 0, length = 0;//最后一个0的位置，最后一个0区间的长度
		bool flag = false;
		queue<PII> q;
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> str[i];
				
			if(str[i] == '0' && !flag)
				length = i;
			if(str[i] == '0')
				flag = true, last0 = i;
			if((str[i] == '1' || i == n) && flag)
			{
				flag = false;
				length = i - length;
				range0cnt ++;
			}
				
		}
		if(str[n] == '0')//统计误差特判修正
			length ++;
		
		if(k >= range0cnt)//特殊情况
		{
			k -= range0cnt;
			if(k % 2 != 0)
			{
				for(int i = 1 ; i < n ; i ++)
					cout << 1;
				cout << 0;
			}
			else
			{
				for(int i = 1 ; i <= n ; i ++)
					cout << 1;
			}
			cout << endl;
			continue;
		}
		flag = false;//复用
		for(int i = 1 ; i <= n ; i ++)
		{
			
			if(str[i] == '1')
			{
				cout << 1;
				if(flag)
				{
					flag = false;
					k--;
				}
			}		
			else
			{
				if(k > 0)
				{
					flag = true;
					cout << '1';
				}
				else
					cout << '0';
			}
		}
		cout << endl;
	}
	return 0;
}