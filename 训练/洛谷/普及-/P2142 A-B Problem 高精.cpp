#include <bits/stdc++.h>
using namespace std;
const int maxn = 10090;
int la , lb , lc;
int A[maxn] , B[maxn] , C[maxn] ;
string a , b ;

bool cmp(int A[] , int B[])//比较A是否大于B
{
	if(la != lb) return la > lb;
	for(int i = la-1 ; ~i ; i--)
	{
		if(A[i] != B[i]) return A[i] > B[i];
	}
	return true;
}

void sub() //a-b
{
	for(int i = 0 ; i < lc ; i ++)
	{
		if(A[i] < B[i])
		{
			A[i+1] --;
			A[i] += 10;
		}
		C[i] = A[i] - B[i];
	}
	while(lc && C[lc] == 0) lc--;
}

signed main()
{
	cin >> a >> b;
	la = a.size() , lb = b.size() , lc = max(la,lb);
	for(int i = la-1 ; ~i ; i--) A[la-i-1] = a[i] -'0';
	for(int i = lb-1 ; ~i ; i--) B[lb-i-1] = b[i] -'0';
	
	if(!cmp(A,B))//如果A小于B
	{
		swap(A,B);
		cout << '-';
	}
	

	sub();
	for(int i = lc ; ~i ; i--) cout << C[i];
	return 0;
}