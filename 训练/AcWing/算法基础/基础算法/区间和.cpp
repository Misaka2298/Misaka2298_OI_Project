#include <bits/stdc++.h>
using namespace std;

const int maxn=3e5+10;
typedef pair<int,int> PII;

int a[maxn],s[maxn];//a为原始数组，s为前缀和
int n,m;
vector<int>tmp;//待离散化的数组
vector<PII>add,query;//添加与求值的操作对

int find(int x)//查询当前操作的坐标在离散化数组中的位置
{
	int l=0,r=tmp.size()-1;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(tmp[mid]>=x) r=mid;
		else l=mid+1;
	}
	return r+1;
}
int main()
{
	cin >> n >> m;
	
	//预处理添加操作
	for(int i = 0;i<n;i++)
	{
		int x,c;
		cin >> x >> c;
		add.push_back({x,c});
		tmp.push_back(x);
	}
	
	//预处理查询操作
	for(int i = 0;i < m;i++)
	{
		int l ,r;
		cin >> l >> r;
		query.push_back({l,r});
		tmp.push_back(l),tmp.push_back(r);
	}
	
	//去重
	sort(tmp.begin(),tmp.end());
	tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
	
	//执行添加操作
	for(auto item:add)
	{
		int x=find(item.first);
		a[x]+=item.second;
	}
	
	//预处理前缀和
	for(int i=0;i<=tmp.size();i++) s[i]=s[i-1]+a[i];
	
	//执行查询操作
	for(auto item:query)
	{
		int l=find(item.first),r=find(item.second);
		cout << s[r]-s[l-1]<<endl;
	}
	return 0;
}