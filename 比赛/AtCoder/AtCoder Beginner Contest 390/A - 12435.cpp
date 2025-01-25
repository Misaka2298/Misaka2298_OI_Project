#include <bits/stdc++.h>
using namespace std;

int a[6];//输入的数组
int b[6];//用来操作

int main()
{
	for(int i = 1 ; i <= 5 ; i++)
		cin >> a[i];
		
	bool isup = true;//是不是本来就有序（是的话就No）
	for(int i = 1 ; i <= 4 ; i++)
		if(a[i+1]<=a[i]) isup = false;
	
	if(isup)
	{
		cout << "No";
		return 0;
	}
			
	bool flag = false;//是否可行
	for(int i = 1 ; i <= 4 ; i++)
	{
		for(int i = 0 ; i <= 5 ; i++)
			b[i] = a[i];//把原数组复制到操作数组
		
		swap(b[i],b[i+1]);//挨个试一遍相邻交换
		
		bool innerflag = false;//相邻交换后，数组是不是 不是单调递增的
		for(int i = 1 ; i <= 4 ; i++)
			if(b[i+1]<=b[i]) innerflag = true;//不是单调递增，innerflag变为true
		
		if(!innerflag) flag = true; //是单调递增，有可行解（这里其实可以直接break）
	}
	if(flag) cout << "Yes";
	else cout << "No";
	return 0;
}