#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // optimized
    // TC - O(n)
    // SC - O(n)

    int maxLen2(vector<int>& arr, int n) {
        unordered_map<int, int> mpp;
        int maxi = 0, sum = 0;
        for(int i = 0;i<n;i++) {
            sum += arr[i];
            if(sum == 0) {
                maxi = i+1;
            }
            else {
                if(mpp.find(sum) != mpp.end()) {
                    maxi = max(maxi, i - mpp[sum]);
                }
                else {
                    mpp[sum] = i;
                }
            }
        }
        return maxi;

    }

    // Naive approach
    // TC - O(n*n)
    int maxLen(vector<int>& arr, int n) {
        int maxSub = 0;
        for(int i = 0;i<n;i++) {
            int sum = 0;
            for(int j = i;j<n;j++) {
                sum += arr[j];
                if(sum == 0) {
                    int dis = j-i+1;
                    maxSub = max(maxSub, dis);
                }
            } 
        }
        return maxSub;
    }
    
};


int main() {
    vector<int> arr = {15,-2,2,-8,1,7,10,23};
    int n = arr.size();
    Solution obj;
    cout << obj.maxLen2(arr, n) << "\n";
    return 0;
}
