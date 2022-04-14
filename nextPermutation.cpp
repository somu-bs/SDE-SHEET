#include<bits/stdc++.h>
using namespace std;

// Optimal approach
// TC - O(3*N)
// SC - O(1)
void nextPermutation2(vector<int>& nums) {
    int n = nums.size(), k, l; 
    for(k = n-2;k>=0;k--) {
        if(nums[k] < nums[k+1]) break;
    }
    if(k < 0) {
        reverse(nums.begin(), nums.end());
    }
    else {
        for(l = n-1;l>k;l--) {
            if(nums[l] > nums[k]) break;
        }
        swap(nums[l], nums[k]);
        reverse(nums.begin()+k+1, nums.end());
    }

}

// Brute Force
// TC - O(N)
void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &it : arr) cin >> it;
    nextPermutation2(arr);
    for(auto &it : arr) {
        cout << it << " ";
    }
    cout << "\n";

}
