#include<bits/stdc++.h>
using namespace std;

// Optimal : Boyer moore voting algo
// TC - O(N)
// SC - O(1)
vector<int> majorityElement3(vector<int>& nums) {
    int n = nums.size();
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
    for(int i = 0;i<n;i++) {
        if(nums[i] == num1) count1++;
        else if(nums[i] == num2) count2++;
        else if(count1 == 0) {
            num1 = nums[i];
            count1 = 1;
        }
        else if(count2 == 0) {
            num2 = nums[i];
            count2 = 1;
        }
        else {
            count1--;
            count2--;
        }
    }
    vector<int> ans;
    count1 = 0, count2 = 0;
    for(int i = 0;i<n;i++) {
        if(nums[i] == num1) count1;
        else if(nums[i] == num2) count2++;

    }
    if(count1 > (n/3))
        ans.push_back(num1);
    if(count2 > (n/3))
        ans.push_back(num2);
    return ans;

}

// Better solution
// TC - O(NlogN)
// SC - O(N)
vector < int > majorityElement2(int arr[], int n) {
    vector<int> ans;
    unordered_map<int, int> mp;

    for(int i = 0;i<n;i++) {
        mp[arr[i]]++;
    }

    for(auto it : mp) {
        if(it.second > (n/3)) {
            ans.push_back(it.first);
        }
    }
    return ans;
}

// Brute force
// TC - O(N*N)
vector < int > majorityElement(int arr[], int n) {
  vector < int > ans;
  for (int i = 0; i < n; i++) {
    int cnt = 1;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] == arr[i])
        cnt++;
    }

    if (cnt > (n / 3)) 
      ans.push_back(arr[i]);
  }

  return ans;
}

int main() {
    vector<int> arr = {1,2,2,3,2};
    vector<int> getMajority = majorityElement3(arr);
    for(auto &it : getMajority) {
    cout << it << " ";
    }
}
