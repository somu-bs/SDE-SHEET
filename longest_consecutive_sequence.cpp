#include<bits/stdc++.h>
using namespace std;

// Optimized
// TC - O(n)
// SC - O(n)
int longestConsecutive2(vector<int>& nums) {
    set<int> hashSet;
    for(auto it : nums) {
        hashSet.insert(it);
    }

    int longestStreak = 0;
    for(int num : nums) {
        if(!hashSet.count(num-1)) {
            int curNum = num;
            int curStreak = 1;
            while(hashSet.count(curNum+1)) {
                curNum += 1;
                curStreak += 1;
            }
            longestStreak = max(longestStreak, curStreak);
        }
    }
    return longestStreak;
}

// Brute force
// TC - O(nlogn) + O(n)
int longestConsecutive(vector<int>& nums) {
    int length = nums.size();
    sort(nums.begin(), nums.end());

    int answer = 1;
    int prev = nums[0];
    int cur = 1;

    for(int i = 1;i<length;i++) {
        if(nums[i] == prev+1) {
            cur++;
        }
        else if(nums[i] != prev) {
            cur = 1;
        }
        prev = nums[i];
        answer = max(answer, cur);
    }
    return answer;
}
int main() {
    vector<int> arr = {100,4,200,1,3,2};
    int ans = longestConsecutive2(arr);
    cout << ans;
}
