#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+10;
typedef pair<int,int> PII;

int n , m;
int a[maxn] ,s[maxn];
vector<int>tmp;//离散化后坐标
vector<PII>add,query;
//对于add，first是坐标，second是增量
//对于query，first是l，second是r

int find(int check)
{
	int l = 0 , r = tmp.size()-1;
	while(l<r)
	{
		int mid = (l+r)/2;
		if(tmp[mid] >= check) r = mid;
		else l = mid + 1;
	}
	return l;
}
 
void pre_add(int x,int c)
{
	add.push_back({x,c});
	tmp.push_back(x);
	return;
}

void pre_query(int l,int r)
{
	query.push_back({l,r});
	tmp.push_back(l),tmp.push_back(r);
	return;
}

void AfterPre()
{
	sort(tmp.begin(),tmp.end());
	tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
	return;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0 , x=0 ,c=0 ; i < n ; i++ )
	{
		scanf("%d%d" ,&x,&c);
		pre_add(x,c);
	}
	
	for(int i=0 , l=0 ,r=0 ; i < m ; i++ )
	{
		scanf("%d%d",&l,&r);
		pre_query(l,r);
	}
	
	AfterPre();
	
	for(auto i : add)
	{
		int x = find(i.first);
		a[x] += i.second; 
	}
	
	for(int i = 0 ; i <= tmp.size() ; i++)
	{
		s[i]=s[i-1]+a[i];
	}
	
	for(auto i : query)
	{
		int l = find(i.first) , r=find(i.second);
		cout << s[r]-s[l-1] << endl;
	}
	return 0;
}