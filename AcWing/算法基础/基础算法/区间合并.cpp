#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
vector<PII> segs;
int n;

void merge(vector<PII> &segs)
{
	int st=-2e9,ed=-2e9;
	vector<PII>ans;
	sort(segs.begin(),segs.end());
	for(auto seg:segs)
	{
		if(ed<seg.first)//当前区间处理完毕，发现新区间
		{
			if(st!=-2e9) ans.push_back({st,ed});
			st=seg.first,ed=seg.second;
		}
		else ed=max(seg.second,ed);
	}
	if(st!=-2e9) ans.push_back({st,ed});
	segs=ans;
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int l,r;
		cin >> l >> r;
		segs.push_back({l,r});
	}
	
	merge(segs);
	cout << segs.size();
	
	return 0;
}
