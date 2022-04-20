#include<bits/stdc++.h>
using namespace std;

// Optimal : Moore's voting algo
// TC - O(N)
// SC - O(1)
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0, candidate = 0;
    for(int i = 0;i<n;i++) {
        if(cnt == 0) {
            candidate = nums[i];
        }
        if(candidate == nums[i]) {
            cnt++;
        }
        else {
            cnt--;
        }
    }
    return candidate;
}

int main() {
    vector<int> arr = {2,2,1,1,1,2,2};
    cout << majorityElement(arr);
}
