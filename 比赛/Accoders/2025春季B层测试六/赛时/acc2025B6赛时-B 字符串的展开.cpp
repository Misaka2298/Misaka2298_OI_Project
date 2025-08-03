//T2
#include <bits/stdc++.h>
using namespace std;
 
int p1, p2, p3;
string str, waitcout;
 
signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> p1 >> p2 >> p3 >> str;
     
    int strlen = str.length();
    for(int i = 0 ; i < strlen ; i++)
    {
        if(str[i] != '-') cout << str[i];
        else
        {
            if(i == 0 || i == strlen-1 || str[i-1] >= str[i+1])
            {
                cout << str[i];
                continue;
            }
            int l = int(str[i-1]), r = int(str[i+1]);
            if(p1 == 1 && l >= 65 && r <= 90)//p1=1, 大转小
            {
                l += 32;
                r += 32;
            }
             
            if(p1 == 2 && l >= 97 && r <= 122)//p1=2, 小转大
            {
                l -= 32;
                r -= 32;
            }   
             
            //p1 = 3在输出时处理
            for(int j = l+1 ; j < r ; j++)
                for(int k = 0 ; k < p2 ; k++)
                    waitcout += char(j);
            //cout << endl << waitcout << endl;//debug
            int wclen = waitcout.length();
            //bool flag2 = (p1 == 3);//false正常输出，true输出*
            if(p1 != 3)
            {
                if(p3 == 2)
                    for(int j = wclen ; j >= 0 ; j--)
                        cout << waitcout[j];
                else
                    for(int j = 0 ; j < wclen ; j++)
                        cout << waitcout[j];
            }
            else
                for(int j = 0 ; j < wclen ; j++)
                    cout << '*';
            waitcout = "";
        }
    }
}
/*
0  9  a  z   A  Z
48 57 97 122 65 90
downer-32 = upper
abcdefghijklmnopqrstuvwxyz
 
模拟题写起来就是爽口牙
*/