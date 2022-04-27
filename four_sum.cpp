#include<bits/stdc++.h>
using namespace std;

// Optimized
// TC - O(nlogn) + O(n*n*n)
// SC - O(1)
vector<vector<int>> fourSum2(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int siz = nums.size();

    if(nums.empty()) return result;

    sort(nums.begin(), nums.end());
    for(int i = 0;i<siz;i++) {
        for(int j = i+1;j<siz;j++) {
            int last_target = target - nums[i] - nums[j];
            int low = j+1, high = siz-1;

            while(low < high) {
                int two_sum = nums[low] + nums[high];

                if(two_sum == last_target) {
                    vector<int> quadruplet(4, 0);
                    quadruplet[0] = nums[i];
                    quadruplet[1] = nums[j];
                    quadruplet[2] = nums[low];
                    quadruplet[3] = nums[high];
                    result.push_back(quadruplet);

                    while(low < high && nums[low] == quadruplet[2]) low++;
                    while(low < high && nums[high] == quadruplet[3]) high--;
                }
                else if(two_sum < last_target) low++;
                else high--; 
            }
            while(j+1 < siz && nums[j+1] == nums[j]) j++;
        }
        while(i+1 < siz && nums[i+1] == nums[i]) i++;
    }
    return result;
}

// Brute force
// TC - O(nlogn + n*n*n(logn))
// SC - O(m*4)

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> s;

    sort(nums.begin(), nums.end());

    for(int i = 0;i<n-2;i++) {
        for(int j = i+1;j<n-1;j++) {
            for(int k = j+1;k<n;k++) {
                int last_target = target - nums[i] - nums[j] - nums[k];

                if(binary_search(nums.begin()+k+1, nums.end(), last_target)) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    temp.push_back(last_target);
                    s.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

int main() {
    vector<int> arr = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> ans = fourSum2(arr, target);
    for(auto &it : ans) {
        for(auto x : it) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
