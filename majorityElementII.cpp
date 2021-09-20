#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int>& nums) {
	int n = nums.size();
	int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;
	for(int i = 0;i<n;i++) {
		if(nums[i] == num1) {
			cnt1++;
		}
		else if(nums[i] == num2) {
			cnt2++;
		}
		else if(cnt1 == 0) {
			num1 = nums[i];
			cnt1 = 1;
		}
		else if(cnt2 == 0) {
			num2 = nums[i];
			cnt2 = 1;
		}
		else {
			cnt1--;
			cnt2--;
		}
	}

	vector<int> ans;
	cnt1 = 0, cnt2 = 0;
	for(int i = 0;i<n;i++) {
		if(nums[i] == num1)
			cnt1++;
		else if(nums[i] == num2)
			cnt2++;
	}

	if(cnt1 > n/3)
		ans.push_back(num1);
	if(cnt2 > n/3) 
		ans.push_back(num2);

	return ans;

}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0;i<n;i++){
		cin >> nums[i];
	}

	vector<int> ans = majorityElementII(nums);
	for(int i = 0;i<ans.size();i++) {
		cout << ans[i] <<" ";
	}

	cout << endl;
	return 0;
}