#include<bits/stdc++.h>
using namespace std;

int t;
int arr[5];
int may1, may2, may3;
int ans;

signed main()
{
	cin >> t;
	while(t--)
	{
		for(int i = 1 ; i <= 4 ; i++)
			cin >> arr[i];	
		may1 = arr[1] + arr[2];
		may2 = arr[3] - arr[2];
		may3 = arr[4] - arr[3];
		
		//cout << may1 <<' ' << may2 << ' ' << may3 << endl;
		if(may1 == may2 && may1 == may3) cout << 3 << endl;
		else if(((may1 == may2) && (may1 != may3) && (may2 != may3))) cout << 2 << endl;
		else if(((may1 == may3) && (may1 != may2) && (may2 != may3))) cout << 2 << endl;
		else if(((may3 == may2) && (may1 != may3) && (may2 != may1))) cout << 2 << endl;
		else cout << 1 << endl;
		
		//cout << endl;
	}
	//1 2 3 4 5
	//1 2   3 4
	return 0;
}