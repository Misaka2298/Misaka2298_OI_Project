#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+10,maxm=1e6+10;
char P[maxn],S[maxm];

int main()
{
	int n,m,ne[maxn];
	cin >> n >> P + 1 >> m >> S + 1;
	
	//计算next
	ne[1]=0;
	for(int i=2 , j=0 ; i<=n ;i++)
	{
		while(j!=0 && P[i]!=P[j+1]) j = ne[j];
		if(P[i] == P[j+1]) j++;
		ne[i] = j;
	}
	
	//输出答案
	for(int i=1 , j=0 ; i<=m ;i++)
	{
		while (j!=0 && S[i] != P[j+1]) j=ne[j];
		if(S[i] == P[j+1]) j++;
		if(j == n) cout << i-n << ' ' , j=ne[j];
	}
	return 0;	
	
}