/*
还好我是高中生不然题干估计都看不懂hhhhhhh
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int t,n,m,l,maxv;
int d[maxn],v[maxn],a[maxn],p[maxn];
bool isspecialA = true , isspecialB = true , isspecialC = true;
int ans,canclose;
bool specialAlastcanclose = true;
bool specialBlastcanclose = true;

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        ans = 0 , canclose = 0;
        bool isclose[maxn]={false};
        scanf("%d%d%d%d",&n,&m,&l,&maxv);
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
            if(a[i] != 0) isspecialA = false;
            if(a[i] <= 0) isspecialB = false;
            if(a[i] >= 0) isspecialC = false;
        }
        for(int i = 0 ; i < m ; i++) scanf("%d",&p[i]);
        //cout <<isspecialA << " " << isspecialB << endl;
        ///*
        if(isspecialA)//所有车都是匀速
        {
            for(int i = 0 ; i < n ; i++)
            {
                if(v[i] <= maxv) continue;
                else
                {
                    if(p[m-1] >= d[i])
                    {
                        specialAlastcanclose = false;
                        ans++;
                    }

                }
            }
            if(specialAlastcanclose) canclose = m;
            else canclose = m-1;
            if(ans == 0) canclose = m;
            printf("%d %d\n",ans,canclose);
        }

        if(isspecialB)//所有车都是匀加
        {
            for(int i = 0 ; i < n ; i++ )
            {
                if(p[m-1] < d[i]) continue;//车辆不在摄像头范围内
                else//p[m-1] >= d[i]
                {
                    if(v[i]>maxv)
                    {
                        ans++;
                        specialBlastcanclose = false;
                    }
                    else//v[i]<=maxv
                    {
                        int lastdist = p[m-1]-d[i];
                        int thismaxv = v[i]*v[i] + 2*a[i]*lastdist;
                        if(thismaxv - maxv * maxv > 0.00001)
                        {
                            ans++;
                            specialBlastcanclose = false;
                        }
                    }
                }
            }
            if(specialBlastcanclose) canclose = m;
            else canclose = m-1;
            if(ans == 0)canclose = m;
            printf("%d %d\n",ans,canclose);
        }
//*/
    }
    return 0;
}

//收卷前10min做完特殊B，什么实力
