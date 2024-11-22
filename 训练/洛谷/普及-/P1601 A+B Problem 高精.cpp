#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
int A[maxn] , B[maxn] , C[maxn];
int la , lb , lc;

void Add(int A[] , int B[] , int C[])
{
	for(int i = 0 ; i < lc ; i ++)
	{
		C[i] += A[i] + B[i]; //累加
		C[i+1] += C[i]/10;
		C[i] %= 10;
	}
	if(C[lc]) lc++;
	return ;
}

int main()
{
	string a , b;
	cin >> a >> b;
	la = a.size() , lb = b.size() , lc=max(la,lb);
	for(int i = la-1 ; ~i ; i--) A[la-i-1] = a[i] - '0';
	for(int i = lb-1 ; ~i ; i--) B[lb-i-1] = b[i] - '0';
	
	Add(A,B,C);
	for(int i = lc-1 ; ~i ; i--) cout << C[i];
	return 0;
}