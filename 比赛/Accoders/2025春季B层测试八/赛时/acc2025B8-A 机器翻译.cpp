//T1
//except pts = 100
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int n, m;
int S[maxn], mem[maxn], cnt, idx = 1;
bool ismem[maxn];

signed main()
{
	cin >> m >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> S[i];
	
	for(int i = 0 ; i < n ; i ++)
	{
		if(!ismem[S[i]])
		{
			cnt++;
			ismem[S[i]] = true;
			if(idx == m+1)
			{
				idx = 1;
				ismem[mem[idx]] = false;
				ismem[S[i]] = true;
				mem[idx] = S[i];
				idx++;
			}
			else
			{
				ismem[S[i]] = true;
				mem[idx] = S[i];
				idx ++;
			}
				
			//mem[++idx] = S[i];
		}
	}
	cout << cnt;
}