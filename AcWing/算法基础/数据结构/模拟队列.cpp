#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int q[maxn], tt = -1, hh;//tt为队尾，hh为队头

void push(int x)
{
	q[++tt] = x;
}

void pop()
{
	hh++;
}

int main()
{
	int m,x;
	string opt;
	cin >> m;
	while (m--)
	{
		cin >> opt;
		if(opt == "push") cin >> x, push(x);
		if(opt == "pop") pop();
		if(opt == "empty")
		{
			if(hh>tt) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		if(opt == "query") cout << q[hh] << endl;
	}
	return 0;
}