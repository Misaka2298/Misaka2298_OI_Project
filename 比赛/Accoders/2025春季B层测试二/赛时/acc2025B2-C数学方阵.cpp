//T3
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int n, m, k;
int arr[maxn];

signed main()
{
	cin >> n >> m >> k;
	cin.tie(0);
	
	cin.ignore((k-1)*(m*2-1));
	//跳过(k-1)*m*2个字符，k-1是因为不能把k跳过了，*2是因为空格也算字符
	
	for(int i = 0 ; i < m ; i++)
		cin >> arr[i];
	
	/*
	我赛时的方法，如果你不写cin.ignore()的话这样写。
	其实是能过这道题的，毕竟cin.ignore()这个知识点太偏了。
	while(k--)
		for(int i = 0 ; i < m ; i++)
			cin >> arr[i];
	*/
	
	for(int i = 0 ; i <= n ; i ++)
		cout << arr[i];
	cout << endl;
	
		
	int ans = 0, cnt = 0;	
	for(int i = 0 ; i < m ; i++)
	{
		if(arr[i] != 0)
			cnt ++;
		else
			cnt = 0;
		ans = max(ans, cnt);//主播赛时的时候把这一行写else里面了，喜提WA
	}
	cout << ans;
	return 0;
}
