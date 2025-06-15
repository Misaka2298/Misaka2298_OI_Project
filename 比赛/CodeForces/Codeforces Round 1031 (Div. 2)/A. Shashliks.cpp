#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int T, temp;
struct MEAT{
	int need, div;
}meat[2];

bool cmp(MEAT a, MEAT b)
{
	return a.div < b.div;
}

signed main()
{
	cin >> T;
	while(T--)
	{
		int ans = 0;
		cin >> temp;
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		meat[0] = {a, c};
		meat[1] = {b, d};
		
		sort(meat, meat+2, cmp);
		
		for(int i = 0 ; i < 2 ; i++)
		{
			//cout << meat[i].need << ' ' << meat[i].div << endl;
			int tick = max(temp-meat[i].need, 0) / meat[i].div;
			
			
			if(temp >= meat[i].need)
				tick ++;
			ans += tick;
			temp -= tick * meat[i].div;
		}
		
		
		cout << ans << endl;
	}
}