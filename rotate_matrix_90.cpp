#include<bits/stdc++.h>
using namespace std;

// Optimized
// TC - O(N*N) + O(N*N)
// SC - O(1)
void rotate2(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // Transpose the matrix
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<i;j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for(int i = 0;i<n;i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// Brute force
// TC - O(N*N)
// SC - O(N*N)
vector<vector<int>> rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dummy(n, vector<int>(n, 0));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            dummy[j][n-i-1] = matrix[i][j];
        }
    }
    return dummy;

}

int main() {
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate2(arr);
    cout << "rotate matrix" << "\n";
    for(int i = 0;i<arr.size();i++) {
        for(int j = 0;j<arr[0].size();j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
