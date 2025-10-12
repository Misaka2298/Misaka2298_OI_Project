LL ans = 0;
LL l = 1, r = csum;

// 二分查找左边界
	int l = 1, r = n, ans = 0;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(arr[mid] >= check)
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	if(arr[ans] == check)
		cout << ans-1 << ' ';
	else
		cout << -1 << ' ';
	
// 二分查找右边界
	int l = 1, r = n, ans = 0;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(arr[mid] <= check)
			ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	if(arr[ans] == check)
		cout << ans-1 << endl;
	else
		cout << -1 << endl;

// 二分答案
while(l <= r)//(fabs(l-r) > 0.00001)
{
	LL mid = (l+r) / 2;
	if(check(mid))
	{
		ans = mid;
		l = mid + 1;
	}
	else
		r = mid - 1;
}