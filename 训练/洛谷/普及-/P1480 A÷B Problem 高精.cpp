#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1e3;
typedef long long LL;

int la , lc ;
int b;
int A[maxn] , C[maxn] ;
string a;

void div(int A[] , int b , int C[])
{
	LL r = 0;
	for(int i = la-1 ; ~i ; i --)
	{
		r = r*10 + A[i];
		C[la-i-1] = r/b;
		r %= b;
	}
	reverse(C , C+lc);
	while(lc && C[lc] == 0) lc--;
	return;
}

signed main()
{
	cin >> a >> b;
	lc = la = a.size();
	for(int i = la-1 ; ~i ; i--) A[la-i-1] = a[i] - '0';
	
	div(A,b,C);
	for(int i = lc ; ~i ; i--) cout << C[i];
	return 0;
}