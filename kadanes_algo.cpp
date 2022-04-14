#include<bits/stdc++.h>
using namespace std;

// Optimal Solution: Kadane’s Algorithm 
// TC - O(N)
// SC - O(1)
int maxSubArray3(vector<int>& nums, vector<int>& subarray) {
    int n = nums.size();
    int max_sum = INT_MIN, s = 0, cur_sum = 0;
    for(int i = 0;i<n;i++) {
        cur_sum += nums[i];
        if(cur_sum > max_sum) {
            max_sum = cur_sum;
            subarray.clear();
            subarray.push_back(s);
            subarray.push_back(i);
        }
        if(cur_sum < 0) {
            cur_sum = 0;
            s = i+1;
        }

    }
    return max_sum;
}

// Better approach
// TC - O(N*N)
int maxSubArray2(vector<int>& nums, vector<int>& subarray) {
    int n = nums.size();
    int max_sum = INT_MIN;
    for(int i = 0;i<n;i++) { 
        int cur_sum = 0;
        for(int j = i;j<n;j++) {
            cur_sum += nums[j];
            if(cur_sum > max_sum) {
                max_sum = cur_sum;
                subarray.clear();
                subarray.push_back(i);
                subarray.push_back(j);
            }
        }
        
    }
    return max_sum;
}


// Naive approach
// TC - O(N*N*N)
int maxSubArray(vector<int>& nums, vector<int>& subarray) {
    int n = nums.size();
    int max_sum = 0;
    for(int i = 0;i<n;i++) {
        for(int j = i;j<n;j++) {
            int sum = 0;
            for(int k = i;k<=j;k++) {
                sum += nums[k];
            }
            if(sum > max_sum) {
                max_sum = sum;
                subarray.clear();
                subarray.push_back(i);
                subarray.push_back(j);
            }
           
        }

    }
    return max_sum;
}


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &it : arr) cin >> it;
    vector<int> subarray;
    int ans = maxSubArray3(arr, subarray);
    cout << ans << "\n";
    for(int i = subarray[0];i<=subarray[1];i++) {
        cout << arr[i] << " ";
    }
}
