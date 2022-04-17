#include<bits/stdc++.h>
using namespace std;

// Optimized : Gap method
// TC - O(logN)
// SC - O(1)
void merge3(int ar1[], int ar2[], int n, int m) {
    int gap = ceil((float)(n+m)/2);
    while(gap > 0) {
        int i = 0;
        int j = gap;
        while(j < (n+m)) {
            if(j < n && ar1[i] > ar1[j]) {
                swap(ar1[i], ar1[j]);
            }
            else if(j >= n && i < n && ar1[i] > ar2[j-n]) {
                swap(ar1[i], ar2[j-n]);
            }
            else if(j >= n && i >= n && ar2[i-n] > ar2[j-n]) {
                swap(ar2[i-n], ar2[j-n]);
            }
            j++;
            i++;
        }
        if(gap == 1) gap = 0;
        else gap = ceil((float) gap / 2);
    }
}

// Without extra space
// TC - O(N*M)
// SC - O(1)
void merge2(int ar1[], int ar2[], int n, int m) {
    int k;
    for(int i = 0;i<n;i++) {
        if(ar1[i] > ar2[0]) {
            int temp = ar1[i];
            ar1[i] = ar2[0];
            ar2[0] = temp;
        }

        int first = ar2[0];
        for(k = 1;k<m && ar2[k] < first;k++) {
            ar2[k-1] = ar2[k];
        }
        ar2[k-1] = first;
    }
}


// Brute force
// TC - O(NlogN) + O(N) + O(N)
// SC - O(N+M)
void merge(int ar1[], int ar2[], int n, int m) {
    int ar3[n+m];
    int k = 0;

    for(int i = 0;i<n;i++) {
        ar3[k++] = ar1[i];
    }

    for(int i = 0;i<m;i++) {
        ar3[k++] = ar2[i];
    }

    sort(ar3, ar3+n+m);
    k = 0;

    for(int i = 0;i<n;i++) {
        ar1[i] = ar3[k++];
    }

    for(int i = 0;i<m;i++) {
        ar2[i] = ar3[k++];
    }
}

int main() {
    int arr1[] = {1,4,7,8,10};
    int arr2[] = {2,3,9};
    cout<<"Before merge:"<<endl;
    for (int i = 0; i < 5; i++) {
      cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 3; i++) {
      cout<<arr2[i]<<" ";
    }
    cout<<endl;
    merge3(arr1, arr2, 5, 3);
    cout<<"After merge:"<<endl;
    for (int i = 0; i <5; i++) {
      cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 3; i++) {
      cout<<arr2[i]<<" ";
    }

}
