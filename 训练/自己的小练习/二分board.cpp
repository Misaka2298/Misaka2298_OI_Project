    LL ans = 0;
	LL l = 1, r = csum;//l=1 or l=0? idk.
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