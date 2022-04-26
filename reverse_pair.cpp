#include<bits/stdc++.h>
using namespace std;

// Optimal
// TC - O(nlogn) + O(N) + O(N)
// SC - O(N)

int merge(vector<int>& nums, int low, int mid, int high) {
    int count = 0;
    int j = mid+1;
    for(int i = low;i<=mid;i++) {
        while(j <= high && nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid+1));
    }
    
    vector<int> temp;
    int left = low, right = mid+1;
    while(left <= mid && right <= high) {
        if(nums[left] <= nums[right]) {
            temp.push_back(nums[left++]);
        }
        else {
            temp.push_back(nums[right++]);
        }
    }
    
    while(left <= mid) {
        temp.push_back(nums[left++]);
    }
    
    while(right <= high) {
        temp.push_back(nums[right++]);
    }
    
    for(int i = low;i<=high;i++) {
        nums[i] = temp[i-low];
    }
    return count;
}

int mergeSort(vector<int>& nums, int low, int high) {
    if(low >= high) return 0;
    int mid = (low+high) / 2;
    int inv = mergeSort(nums, low, mid);
    inv += mergeSort(nums, mid+1, high);
    inv += merge(nums, low, mid, high);
    return inv;
}

int reversePairs2(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size()-1);
}

// Brute force
// TC - O(N*N)
int reversePairs(vector<int>& nums) {
    int n = nums.size();
    int noOfPairs = 0;
    for(int i = 0;i<n;i++) {
        for(int j = i+1;j<n;j++) {
            if(nums[i] > 2 * nums[j]) noOfPairs++;
        }
    }
    return noOfPairs;
}


int main() {
    vector<int> arr{1,3,2,3,1};
    cout<<"The Total Reverse Pairs are: "<<reversePairs2(arr);

}


