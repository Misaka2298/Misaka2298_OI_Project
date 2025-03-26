//T1
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef pair<int,int> PII;

int n, arr[maxn], cpy[maxn], cnt;

bool isuncurrect[maxn];
int uncurrectcnt, matchcnt;

PII change[maxn];
int idx;

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> arr[i];
		cpy[i] = arr[i];
	}
	
	sort(cpy+1, cpy+1+n);
	
	for(int i = 1 , j = 0 ; i <= n ; i ++) //init
	{
		if(arr[i] != cpy[i])
		{
			isuncurrect[i] = true;
			uncurrectcnt ++;
		}
		
		j = arr[i];
		if(arr[i] == j && arr[j] == i && i != j)
		{
			cnt ++;
			//cout << i << ' ' << j << endl; //debug
			change[idx++] = {min(i,j), max(i,j)};
			swap(arr[i], arr[j]);
		}
	}
	
	if(uncurrectcnt == 0)//cut1
	{
		cout << 0;
		return 0;
	}
	
	for(int i = 1 ; i <= n ; i++)
	{
		if(arr[i] != i)
		{
			int t = 0;//target
			for(int j = n ; j > i ; j --)
				if(arr[j] == i)
				{
					t = j;
					break;
				}
			change[idx++] = {min(i,t),max(i,t)};
			swap(arr[i], arr[t]);
			cnt ++;
			
			int k = arr[t];
			if(arr[k] == t && arr[t] == k && t != k)
			{
				cnt ++;
				change[idx++] = {min(k,t),max(k,t)};
				swap(arr[k],arr[t]);
			}
			
		}
	}
	
	/*
	for(int i = 1 ; i <= n ; i ++)
		cout << arr[i] << ' ';
	cout << endl;
	*/
	
	sort(change , change + idx);
	cout << cnt << endl;
	for(int i = 0 ; i < idx ; i++)
		cout << change[i].first << ' ' << change[i].second << endl;
	
}

/*
1e5, may nlogn?

对于arr[i] == j && arr[j] == i
可认为为一次匹配
交换后不认为会产生新的失配且省交换次数，优先考虑。

对于341259687
matchcnt == 2
似乎不用考虑非match交换产生的新match，但是这样的话似乎答案不唯一。
不管了出题人一定会考虑到的。
今天怎么没有大样例。

试试暴力匹配unmatch
哦好像对了。
*/