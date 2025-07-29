#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
int n;
vector<PII> segs;

void solve(vector<PII> &segs)
{
	long long ans=0;
	sort(segs.begin(),segs.end());
	int st=-214748648,ed=-214748648;//初始化当前区间的起点与终点
	for(auto seg:segs)
	{
		if(ed<seg.first) //发现新区间
		{
			if(st!=-214748648) ans+=ed-st;
			st=seg.first,ed=seg.second;
		}
		else ed=max(ed,seg.second);
	}
	if(st!=-214748648) ans+=ed-st;
	cout << ans;
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int x , y;
		cin >> x >> y;
		segs.push_back({x,y});
	}
	solve(segs);
	return 0;
}