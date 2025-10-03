// T1
// expect pts = 100
// expect diff = red

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n;
char s[maxn];
int ne[maxn];

// heidi

signed main()
{
	freopen("delstr.in", "r", stdin);
	freopen("delstr.out", "w", stdout);
	string str;
	cin >> str;
	n = str.size();
	for(int i = 1 ; i <= n ; i ++)
		s[i] = str[i-1];
		
	for(int i = 1 ; i <= n ; i ++)
	{
		if(s[i] == 'h')
			for(int j = i ; j <= n ; j ++)
				if(s[j] == 'e')
					for(int k = j ; k <= n ; k ++)
						if(s[k] == 'i')
							for(int l = k ; l <= n ; l ++)
								if(s[l] == 'd')
									for(int b = l ; b <= n ; b ++)
										if(s[b] == 'i')
										{
											cout << "YES";
											exit(0);
										}
	}
	cout << "NO";
}
