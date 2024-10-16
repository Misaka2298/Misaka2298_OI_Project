#include <bits/stdc++.h>
using namespace std;
int tmp[9][13]={0};
bool isused[9][13]={false};
void sol(int in,int cur)
{
	if(cur==in)
	{
		for(int i=1;i<=in;i++)
			for(int j=0;j<in;j++)
				cout << tmp[j][i] << " ";
		cout << endl;
		return;
	}
	else
	{
		for(int j=1;j<=in;j++)
		{
			if(isused[j]==false)//在当前栈中是否被调用过？
			{
				tmp[cur]=j;
				isused[j]=true;
				sol(in,cur+1);
				//cout << tmp[j];//debug
			}
			else continue;
		}
	}
}
int main()
{
	int in;
	cin >> in;
	sol(in,1);
	return 0;
}