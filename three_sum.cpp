#include<bits/stdc++.h>
using namespace std;

// Optimized
// TC - O(n*n)
// SC - O(m)

vector<vector<int>> threeSum2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for(int i = 0;i<nums.size()-2;i++) {
        if(i==0 || (i>0 && nums[i] != nums[i-1])) {
            int low = i+1, high = nums.size()-1, sum = 0-nums[i];

            while(low < high) {
                if(nums[low] + nums[high] == sum) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    ans.push_back(temp);

                    while(low < high && nums[low] == nums[low+1]) low++;
                    while(low < high && nums[high] == nums[high-1]) high--;

                    low++; high--;
                }
                else if(nums[low] + nums[high] < sum) low++;
                else high--;
            }
        }
    }
    return ans;
}

// Brute force
// TC - O(n*n*n) 
// SC - O(3*k) // k is number of triplet

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    int n = nums.size();

    for(int i = 0;i<n-2;i++) {
        for(int j = i+1;j<n-1;j++) {
            for(int k = j+1;k<n;k++) {
                temp.clear();
                if(nums[i] + nums[j] + nums[k] == 0) {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                }

                if(temp.size() != 0)
                    ans.push_back(temp);
            }
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum2(arr);
    for(vector<int> &it : ans) {
        for(auto x : it) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
