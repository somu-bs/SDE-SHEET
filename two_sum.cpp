#include<bits/stdc++.h>
using namespace std;

// Optimal
// TC - O(n)
// SC - O(n)
vector<int> twoSum3(vector<int>& nums, int target) {
    vector<int> ans;
    unordered_map<int, int> mpp;
    for(int i = 0;i<nums.size();i++) {
        if(mpp.find(target - nums[i]) != mpp.end()) {
            ans.push_back(mpp[target - nums[i]]);
            ans.push_back(i);
            break;
        }
        mpp[nums[i]] = i;
    }
    return ans;
}

// Better : sorting
// TC - O(nlogn) + o(n) + o(n)
// SC - O(n)
vector<int> twoSum2(vector<int>& nums, int target) {
    vector<int> ans, copy;
    copy = nums;
    int n1, n2;

    sort(copy.begin(), copy.end());
    int i = 0, j = copy.size()-1;
    while(i < j) {
        if(copy[i] + copy[j] == target) {
            n1 = copy[i];
            n2 = copy[j];
            break;
        }
        else if(copy[i] + copy[j] > target) {
            j--;
        }
        else {
            i++;
        }
    }

    for(int i = 0;i<nums.size();i++) {
        if(nums[i] == n1) {
            ans.push_back(i);
        }
        else if(nums[i] == n2) {
            ans.push_back(i);
        }
    }
    return ans;
}

// Brute force
// TC - O(n*n)
// SC - O(1)

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> ans;
    for(int i = 0;i<n;i++) {
        for(int j = i+1;j<n;j++) {
            if(nums[i] + nums[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
    }
    return ans;
}

int main () {
    vector<int> arr = {3,2,3};
    int target = 6;
    vector<int> ans = twoSum3(arr, target);
    for(auto &it : ans) {
        cout << it << " ";
    }

}
