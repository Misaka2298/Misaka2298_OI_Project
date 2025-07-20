//AIGC
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	
	//freopen("set.in", "r", stdin);
    //freopen("set.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    map<int, int> freq;
    long long totalSum = 0;
    for (int num : nums) {
        freq[num]++;
        totalSum += num;
    }

    // C++14 兼容的迭代方式
    long long totalSubsets = 1;
    for (const auto& elem : freq) {
        totalSubsets *= (elem.second + 1);
    }

    long long result = totalSubsets * totalSum / 2;
    cout << result << endl;
    return 0;
}