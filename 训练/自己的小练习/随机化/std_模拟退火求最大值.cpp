#include <bits/stdc++.h>
using namespace std;
int n,a[10005],tans,bans;
double bt=1000,et=1e-5,lt=0.995;//bt为初始温度，et为结束温度，lt为温度系数
int main()
{
	srand(time(0));
	srand(rand());
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
		tans=max(a[i],tans);
	}
	int ans=rand()%n+1;
	int na=a[ans];//初始随机选择一个数作为最优解
	while (bt>et)
	{
		int g=rand()%(min(ans+int(bt)*100,n)-max(ans-int(bt)*100,1)+1)+max(ans-int(bt)*100,1);//根据当前温度来选择合适的遍历范围
		int de=na-a[g];
		if (de<=0)//新的解更优直接更新
		{
			bans=a[g];
			na=a[g];
			ans=g;
		}
		else if(double(rand())<exp(double(-de)/bt)*RAND_MAX) //差的解也有一定概率接受
		{
			na=a[g];
			ans=g;
		}
		bt*=lt;//退火
	}
	cout<<tans<<" "<<bans;
}