#include<bits/stdc++.h>
using namespace std;

// Efficient approach
// TC - O(log(M*N))
// SC - O(1)
bool searchMatrix2(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    // base case
    if(!matrix.size()) return false;

    int low = 0, high = (n*m) - 1;
    while(low <= high) {
        int mid = (low + (high-low) / 2);
        if(matrix[mid/n][mid%n] == target) return true;

        else if(matrix[mid/n][mid%n] < target) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return false;
}

// Naive approach
// TC - O(M*N)
// SC - O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
        
    for(int i = 0;i<m;i++) {
        for(int j = 0;j<n;j++) {
            if(matrix[i][j] == target) return true;
        }
    }

    return false;

}

int main() {
    vector<vector<int>> arr;
    arr = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    if(searchMatrix2(arr, target))
        cout << "True";
    else
        cout << "False";
}
