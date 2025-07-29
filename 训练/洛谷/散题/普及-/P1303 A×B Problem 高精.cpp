#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+10;
int la , lb , lc;
int A[maxn] , B[maxn] , C[maxn];
string a ,b;

void multi()
{
	for(int i = 0 ; i < la ; i ++)
		for(int j = 0 ; j < lb ; j++) 
		{
			C[i+j] += A[i] * B[j];
			C[i+j+1] += C[i+j] / 10;
			C[i+j] %= 10;
		}
	while(C[lc]==0 && lc) lc--;
	return;
}

int main()
{
	cin >> a >> b;
	la = a.size () , lb = b.size() , lc = la+lb;
	for(int i = la-1 ; ~i ; i--) A[la-i-1] = a[i] - '0';
	for(int i = lb-1 ; ~i ; i--) B[lb-i-1] = b[i] - '0';
	
	multi();
	for(int i = lc ; ~i ; i--) cout << C[i];
	return 0;
}