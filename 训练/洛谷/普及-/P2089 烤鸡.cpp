#include <bits/stdc++.h>
using namespace std;

const int maxn=5010;

int n;
int ans[15] , sum ,res;
int tmp[8960][11];

void dfs(int u , int sum)
{
	if(sum > n) return ;//剪枝
	
	if(u > 10)
	{
		if(sum == n)
		{
			res++;
			for(int i = 0 ; i<= 10 ;i++)
				tmp[res][i] = ans[i];
		}
		return ;
	}
	
	for (int i = 1; i<=3 ;i++)
	{
		ans[u] = i;
		dfs(u+1 ,sum+i);
	}
}

int main()
{
	scanf("%d",&n);
	if(n<10 || n >30)
	{
		printf("0");
		return 0; 
	} //剪枝？
	dfs(1 , 0);
	
	cout << res <<endl;
	
	for(int i = 1 ; i <= res ; i++)
	{
		for(int j = 1 ; j <=10 ; j++)
			printf("%d ",tmp[i][j]);
		printf("\n");
	}
	
	return 0;
}