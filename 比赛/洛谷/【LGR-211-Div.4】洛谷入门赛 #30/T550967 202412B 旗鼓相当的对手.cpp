#include <bits/stdc++.h>
using namespace std;

int arr[2][5];
int ans;

signed main()
{
	for(int i = 1 ; i <= 2 ; i++)
		for(int j = 1 ; j <= 4 ; j ++)
			cin >> arr[i][j];
	for(int i = 1 ; i <= 4 ; i++)
		for(int j = i ; j <= 4 ; j ++)
			if(((arr[1][i] < arr[1][j] && arr[2][j] < arr[2][i]) || (arr[2][i] < arr[2][j] && arr[1][j] < arr[1][i])) && i != j) ans++;
	cout << ans;
	return 0;
}