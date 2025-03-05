#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int e[maxn],ne[maxn],head,idx;

void init()
{
	head = -1;
	idx = 0;
}

void add_to_head(int x)//在头结点后插入x
{
	e[idx]=x, ne[idx]=head, head = idx, idx++;
}

void add(int k,int x)//在k-1结点后插入x
{
	k--, e[idx]=x, ne[idx]=ne[k], ne[k]=idx, idx++;
}

void rm(int k)//删除k-1后一个值
{
	k--;
	ne[k]=ne[ne[k]];
}

int main()
{
	int m,x,k;
	char op;
	cin >> m;
	init ();
	while (m--)
	{
		cin >> op;
		if(op == 'H')
		{
			cin >> x;
			add_to_head(x);
		}
		else if(op == 'D')
		{
			cin >>k;
			if (!k) head = ne[head];
			rm(k);
		}
		else if(op == 'I')
		{
			cin >> k >> x;
			add(k,x);
		}
	}
	for(int i=head;i!=-1;i=ne[i]) cout << e[i] << " ";
	return 0;
}