#include<bits/stdc++.h>
using namespace std;

// Optimized
// TC - O(NlogN)
// SC - O(N)
int merge(int arr[], int temp[], int left, int mid, int right) {
    int inv_count = 0;
    int i = left, j = mid;
    int k = left;
    while(i <= mid-1 && j <= right) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];

        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid-i);
        }

    }

    while(i <= mid-1)
        temp[k++] = arr[i++];

    while(j <= right) {
        temp[k++] = arr[j++];
    }

    for(int i = left;i<=right;i++) {
        arr[i] = temp[i];
    }
    return inv_count;
}

int mergeSort(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;

    if(left < right) {
        mid = (left+right) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid+1, right);

        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}

// Brute force
// TC - O(N*N)
// SC - O(1)
long long getInversions(long long *arr, int n) {
    long long cnt = 0;
    for(int i = 0;i<n;i++) {
        for(int j = i+1;j<n;j++) {
            if(arr[i] > arr[j]) cnt++;
        }
    }

    return cnt;
}

int main() {
    int arr[] = {5,3,2,1,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    int ans =  mergeSort(arr, temp, 0, n-1);
    cout << ans;
}
