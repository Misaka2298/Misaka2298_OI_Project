#include <bits/stdc++.h>
using namespace std;

const int maxn =  1e5+10;
int son[maxn][26],cnt[maxn],idx;
char str[maxn];

void insert(char *a)
{
	int p = 0;
	for(int i = 0 ; a[i] ; i++)
	{
		int u = a[i] - 'a';
		if(!son[p][u]) son[p][u] = ++idx;
		p=son[p][u];
	}
	cnt[p] ++;
}

int query(char *a)
{
	int p = 0;
	for(int i = 0 ; a[i] ; i++)
	{
		int u = a[i] - 'a';
		if(!son[p][u]) return 0;
		p=son[p][u];
	}
	return cnt[p];
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char op[2];
        scanf("%s%s", op, str);
        if (*op == 'I') insert(str);
        else printf("%d\n", query(str));
	}
	return 0;
}