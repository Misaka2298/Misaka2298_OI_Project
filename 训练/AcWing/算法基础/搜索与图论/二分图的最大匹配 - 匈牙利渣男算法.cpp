#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e5+10 , maxn = 510;

int n1 ,n2 , m;
int e[maxm],ne[maxm],h[maxn],idx;
int match[maxn];
bool st[maxn];

void addedge(int a , int b)
{
	e[idx] = b ,ne[idx] = h[a] , h[a] = idx++;
}

bool find(int x)
{
	for(int i = h[x] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if(!st[j])
		{
			st[j] = true;
			if(match[j] == 0 || find(match[j]))
			{
				match[j] = x;
				return true;
			}
		}
	}
	
	return false;
}

int main()
{
	memset(h , -1 , sizeof h);
	cin >> n1 >> n2 >> m;
	while(m--)
	{
		int a,b;
		cin >> a >> b;
		addedge(a,b);
	}
	
	int res = 0;
	for(int i = 1; i <= n1 ; i++)
	{
		memset(st , false , sizeof st);
		if(find(i)) res ++;
	}
	
	cout << res;
	return 0;
}