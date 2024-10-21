/*
看来全排序默认已经是有序的了

正解应该是4
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;

int n , m, tmp[maxn] ,cnt;//n,m题意，tmp为全排序生成过程中的每个数字，cnt是全排序个数
bool isused[maxn];//全排序中检测是否用过当前数
string  defnum;//str为全排序后数组，defnum为加之前的数

int find(int check ,string str[])
{
	int l = 0 , r = cnt-1;
	while(l < r)
	{
		int mid = (l+r)/2;
		//cout << stoi(str[mid]) << endl;
		if(stoi(str[mid]) >= check) r = mid;
		else l = mid + 1 ;
	}
	return l+1;
}

void create_dict(int u ,string str[])
{
	if(u == n)
	{
		for(int i = 0 ; i < n ;i++)
		{
			str[cnt] +=to_string(tmp[i]);
		}
		cnt++;
		return;
	}
	
	for(int i = 1 ; i<=n ;i++)
	{
		if(!isused[i])
		{
			isused[i] = true;
			tmp[u]=i;
			create_dict(u+1,str);
			isused[i] = false;
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	int num=0;
	for(int i = 1 ; i <= n ;i++) num *=i;
	string str[num+1];
	for(int i = 0 ,j = 0; i<n ;i++)
	{
		scanf("%d",&j);
		defnum+=to_string(j);
	}
	create_dict(0,str);
	//for(int i = 0 ; i<cnt ;i++) cout << str[i] << endl;
	int ans = m + find(stoi(defnum),str) -1;
	//cout << find(stoi(defnum)) <<endl<< defnum << << endl << ans;
	
	for(int i = 0 ; i<n ;i++)
	{
		cout << str[ans][i] <<" ";
	}
	
	return 0;
}