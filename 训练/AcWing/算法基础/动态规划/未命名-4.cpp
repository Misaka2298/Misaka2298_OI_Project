#include <bits/stdc++.h>
using namespace std;

int a[5]={1,2,3,4,5};
int b[5];

signed main()
{
	memcpy(b,a,sizeof a);
	for(int i = 0 ; i < 5 ; i++)
		cout << b[i];
	return 0;
}