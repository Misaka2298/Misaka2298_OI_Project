//T2正解
#include <bits/stdc++.h>
using namespace std;
const int maxn = 22;

int n;
string nums[maxn];

bool numcmp(string a, string b)
{
	return a+b > b+a;
}

signed main()
{
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> nums[i];
	
	sort(nums, nums+n, numcmp);
	
	if(nums[0] == "0")
	{
		cout << 0;
		exit(0);
	}
	
	 for (int i = 0 ; i < n ; i++)
        cout << nums[i];
}