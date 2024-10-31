#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;
int q[maxn],arr[maxn],head=0,tail=-1;

int main()
{
	int n , k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
	
	//维护一个单调递增队列，求长度为k的滑动窗口的最小值（head）
	for(int i=0; i < n; i++)
	{
		
		while(head<=tail && arr[i]<=arr[q[tail]]) tail--;//如果新元素<=队尾，队尾出列，直到队尾是队内最大值
		q[++tail] = i; // 新元素无条件队尾入列
		if(q[head] < i-k+1) head ++;//如果队头滑出窗口，队头出列
		if(i>=k-1) printf("%d ",arr[q[head]]);//输出窗口内最值，但前提是窗口已经完全进入过数列
	}
	cout << endl;
	head = 0 , tail = -1;//清空队列
	//维护一个单调递减队列，求长度为k的滑动窗口的最大值（head）
	for(int i=0; i < n; i++)
	{
		
		while(head<=tail && arr[i]>=arr[q[tail]]) tail--;//如果新元素>=队尾，队尾出列，直到队尾是队内最小值
		q[++tail] = i; // 新元素无条件队尾入列
		if(q[head] < i-k+1) head ++;//如果队头滑出窗口，队头出列
		if(i>=k-1) printf("%d ",arr[q[head]]);//输出窗口内最值，但前提是窗口已经完全进入过数列
	}
	return 0;
}