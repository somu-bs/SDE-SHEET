#include<bits/stdc++.h>
using namespace std;

//Optimal approach : Dutch natioal Flag
// TC - O(N)
// SC - O(1)
void sortColors3(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0;
    int high = n-1;

    while(mid <= high) {
        switch(nums[mid]) {
            case 0:
                swap(nums[low++], nums[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid], nums[high--]);
                break;
        }
    }
}

// Better approach
// TC - O(N)+O(N)
void sortColors2(vector<int>& nums) {
    // variable for counting frequency
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    int n = nums.size();

    for(int i = 0;i<n;i++) {
        if(nums[i]==0) cnt0++;
        else if(nums[i]==1) cnt1++;
        else cnt2++;
    }

    int i = 0;
    while(i < n) {
        while(cnt0 > 0) {
            nums[i] = 0;
            cnt0--;
            i++;
        }
        while(cnt1 > 0) {
            nums[i] = 1;
            cnt1--;
            i++;
        }
        while(cnt2 > 0) {
            nums[i] = 2;
            cnt2--;
            i++;
        }    
    }
}

// Brute force
// TC - O(NlogN)
void sortColors1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}

int main() {
    vector<int> arr = {0, 1, 2, 1, 0, 2};
    sortColors3(arr);
    for(int i = 0;i<arr.size();i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
