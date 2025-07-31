// T3
// expect pts = 
// moni...

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define endl '\n'

int n;
char opt;

//——————————————————————————————————————————————————————————————————————————————

string e_one[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string e_two[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string e_pow10[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string sol_eone(LL num)
{
	return e_one[num];
}

string sol_etwo(LL num)
{
	if(num >= 10 && num <= 19)
		return e_two[num%10];
	if(num < 100 && num > 10 && num%10==0)
		return e_pow10[num/10];
	if(num < 100)
		return e_pow10[num/10] + '-' + e_one[num%10];
}

string sol_ethree(LL num)
{
	string ans = e_one[num/100] + " hundred ";
	if(num%100 <= 9 && num%100 >= 1) ans += sol_eone(num%100);
	else if(num%100 >= 10 && num%100 <= 99) ans += sol_etwo(num%100);
	return ans;
}

string emore_middlesol(LL num)
{
	if(num <= 9)
		return sol_eone(num);
	else if(num >= 10 && num <= 99) 
		return sol_etwo(num);
	else if(num >= 100 && num <= 999)
		return sol_ethree(num);
}

string sol_emore(LL num)
{
	string ans = "";
	LL nownum = 0;
	if(num / (LL)1e9 != (LL)0)
		ans += emore_middlesol(num/(LL)1e9) + " billion ";
	nownum = (num - (num/(LL)1e9)*(LL)1e9) / (LL)1e6;
	if(nownum != (LL)0)
	{
		string tmp = emore_middlesol(nownum);
		if(tmp != "zero")
		{
			if(tmp[tmp.size()-1] != ' ')
				ans += tmp + " million ";
			else
				ans += tmp + "million ";
		}	
	}
	nownum = (num - (num/(LL)1e6)*(LL)1e6) / (LL)1e3;
	if(nownum != (LL)0)
	{
		string tmp = emore_middlesol(nownum);
		if(tmp != "zero")
		{
			if(tmp[tmp.size()-1] != ' ')
				ans += tmp + " thousand ";
			else
				ans += tmp + "thousand ";
		}
	}
	nownum = num - (num/(LL)1e3)*(LL)1e3;
	string tmp = emore_middlesol(nownum);
		if(tmp != "zero")
			ans += tmp;
	return ans;
	
}

void Esol(LL num)
{
	if(num <= 9)
		cout << sol_eone(num) << endl;
	else if(num >= 10 && num <= 99) 
		cout << sol_etwo(num) << endl;
	else if(num >= 100 && num <= 999)
		cout << sol_ethree(num) << endl;
	else
		cout << sol_emore(num) << endl;
}

//                                English
/*——————————————————————————————————————————————————————————————————————————*/
//                               Japanese
//                             F__k Japanese
//                              soooo hard
//                           wo bu xiang xie le
//                  Japanese no space key, I love Japanese

string j_one[] = {"zero", "ichi", "ni", "san", "yon", "go", "roku", "nana", "hachi", "kyuu"};

string sol_jone(LL num)
{
	return j_one[num];
}

string sol_jfour(LL num)
{
	if(num == 300)
		return "sanbyaku";
	if(num == 600)
		return "roppyaku";
	if(num == 800)
		return "happyaku";
	if(num == 3000)
		return "sanzen";
	if(num == 8000)
		return "hassen";
	
	string ans = "";
	LL nownum = 0;
	if(num / (LL)1000 != 0)
	{
		nownum = num / (LL)1000;
		if(nownum == 3)
			ans += "sanzen";
		else if(nownum == 8)
			ans += "hassen";
		else
		{
			if(nownum != 1)
				ans += sol_jone(nownum);
			ans += "sen";
		}
	}
	nownum = (num - (num/(LL)1e3)*(LL)1e3) / (LL)1e2;
	if(nownum != 0)
	{
		if(nownum == 3)
			ans += "sanbyaku";
		else if(nownum == 6)
			ans += "roppyaku";
		else if(nownum == 8)
			ans += "happyaku";
		else
		{
			if(nownum != 1)
				ans += sol_jone(nownum);
			ans += "hyaku";
		}
	}
	nownum = (num - (num/(LL)1e2)*(LL)1e2) / (LL)1e1;
	if(nownum != 0)
	{
		if(nownum != 1)
			ans += sol_jone(nownum);
		ans += "juu";
	}
	nownum = num - (num/(LL)1e1)*(LL)1e1;
	if(nownum != 0)
		ans += sol_jone(nownum);
	return ans;
}

string sol_jmore(LL num)
{
	string ans = "";
	LL nownum = 0;
	if(num / (LL)1e8 != (LL)0)
		ans += sol_jfour(num/(LL)1e8) + "oku";
	nownum = (num - (num/(LL)1e8)*(LL)1e8) / (LL)1e4;
	if(nownum != (LL)0)
	{
		if(nownum == 1000)
			ans += "issenman";
		else
		{
			string tmp = sol_jfour(nownum);
			if(tmp != "zero")
				ans += tmp + "man";
		}
	}
	nownum = num - (num/(LL)1e4)*(LL)1e4;
	ans += sol_jfour(nownum);
	return ans;
	
}

void Jsol(LL num)
{
	if(num <= 9)
		cout << sol_jone(num) << endl;
	if(num >= 10 && num <= 9999)
		cout << sol_jfour(num) << endl;
	else if(num >= 10000)
		cout << sol_jmore(num) << endl;
}

//————————————————————————————————————————————————————————————

signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> opt;
	while(n--)
	{
		LL num;
		cin >> num;
		if(opt == 'E')
			Esol(num);
		else
			Jsol(num);
	}
}