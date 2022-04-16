#include<bits/stdc++.h>
using namespace std;

// Optimal approach
// TC - O(N)
// SC - O(1)
int maxProfit2(int arr[], int n) {
    int maxPro = 0, minPrice = INT_MAX;

    for(int i = 0;i<n;i++) {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    return maxPro;

}

// Brute force
// TC - O(N*N)
int maxProfit(int arr[], int n) {
    int maxPro = 0;
    for(int i = 0;i<n;i++) {
        for(int j = i+1;j<n;j++) {
            if(arr[j] > arr[i]) {
                maxPro = max(maxPro, arr[j] - arr[i]);
            }
        }
    }
    return maxPro;
}

int main() {
    int arr[] = {7,1,5,3,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxPro = maxProfit2(arr, n);
    cout << maxPro;
}
