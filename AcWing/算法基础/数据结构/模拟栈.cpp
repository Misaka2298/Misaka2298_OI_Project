#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int stk[maxn],tt=0;

void push(int x)
{
	stk[++tt]=x;
}

void pop()
{
	tt--;
}

int main()
{
	int m,x;
	string op;
	cin >> m;
	while(m--)
	{
		cin >> op;
		if(op == "push") cin >> x,push(x);
		if(op == "pop") pop();
		if(op == "empty")
		{
			if (tt == 0) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		if(op == "query") cout << stk[tt] << endl;
	}
}