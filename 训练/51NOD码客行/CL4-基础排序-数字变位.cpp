#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	string num;
	cin >> num;
	sort(num.begin(),num.end(),cmp);
	cout << num<<" ";
	reverse(num.begin(),num.end());
	//最大值
	if(num[0]=='0')
	{
		for(int j=0;j<num.size();j++)
		{
			if(num[j]!='0')
			{
				num[0]=num[j];
				num[j]='0';
				break;
			}
		}
	}
	cout << num;
	return 0;
}