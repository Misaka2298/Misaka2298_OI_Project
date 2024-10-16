#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int stk[maxn],tail;

int main()
{
	int n, x;
	scanf("%d",&n);
	cout.tie(0);
	while(n--)
	{
		scanf ("%d",&x);
		while(tail!=0 && stk[tail]>=x) tail --;
		if(tail == 0) cout << -1 << " ";
		else cout << stk[tail] << " ";
		stk[++tail] = x; 
	}
	return 0;
}