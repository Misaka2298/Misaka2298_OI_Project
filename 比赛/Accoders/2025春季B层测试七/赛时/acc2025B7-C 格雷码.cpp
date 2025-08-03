//T3
#include <bits/stdc++.h>
using namespace std;
const int maxn = 27, powmaxn = 134217730;//almost 50pts? may be more.

int n, k;
int gc1[powmaxn], gc2[powmaxn], idx1, idx2;

signed main()
{
	//本来想打表的，但是又不想了。
	cin >> n >> k;
	gc1[1] = 2, gc1[2] = 1, idx1 = 2;
	//为了规避前导0，这里把0定义成2吧
	bool flag = false;
	for(int i = 2 ; i <= n ; i++)
	{
		if(i % 2 == 0) flag = true;//维护2
		else flag = false;
		
		if(flag) idx2 = 0;
		else idx1 = 0;
		
		if(!flag)
		{
			for(int j = 1 ; j <= idx2 ; j++)
				gc1[++idx1] = gc2[j] + 2 * pow(10,i-1);
			for(int j = idx2 ; j >= 1 ; j--)
				gc1[++idx1] = gc2[j] + 1 * pow(10,i-1);
		}
		else
		{
			for(int j = 1 ; j <= idx1 ; j++)
				gc2[++idx2] = gc1[j] + 2 * pow(10,i-1);
			for(int j = idx1 ; j >= 1 ; j--)
				gc2[++idx2] = gc1[j] + 1 * pow(10,i-1);
		}
	}
	
	/*
	if(n % 2 == 0)
		for(int i = 1 ; i <= idx2 ; i++)
			cout << gc2[i] << ' ';
	else
		for(int i = 1 ; i <= idx1 ; i++)
			cout << gc1[i] << ' ';
	*/
	k++;//对齐
	string ans;
	if(n % 2 == 0)
	{
		ans = to_string(gc2[k]);
		for(int i = 0 ; i < ans.length() ; i++)
			if(ans[i] == '2') cout << '0';
			else cout << '1';
	}
	else
	{
		ans = to_string(gc1[k]);
		for(int i = 0 ; i < ans.length() ; i++)
			if(ans[i] == '2') cout << '0';
			else cout << '1';
	}
}