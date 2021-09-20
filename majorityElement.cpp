#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
	int cnt = 0, major_ele = 0;
	for(auto num : nums) {
		if(cnt == 0) {
			major_ele = num;
		}

		if(num == major_ele) cnt++;
		else cnt--;
	}
	return major_ele;
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0;i<n;i++){
		cin >> nums[i];
	}

	cout << majorityElement(nums);
	return 0;
}