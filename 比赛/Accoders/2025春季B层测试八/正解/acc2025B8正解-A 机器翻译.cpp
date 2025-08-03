//T1正解
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int n, m, S[maxn], ans;
queue<int>q;
bool ismem[1010];

signed main()
{
	cin >> m >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> S[i];
	
	for(int i = 0 ; i < n ; i ++)
	{
		if(!ismem[S[i]])
		{
			ans++;
			q.push(S[i]);
			if(q.size()>m)
			{
				ismem[q.front()] = false;
				q.pop();
			}
			ismem[S[i]] = true;
		}
	}
	cout << ans;
}