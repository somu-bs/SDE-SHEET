#include<bits/stdc++.h>
using namespace std;

// Optimized : Combinatorics
// TC - O(m-1) or O(n-1)
// SC - O(1)
int uniquePaths3(int m, int n) {
    int N = m+n-2;
    int R = m-1;
    double ans = 1;
    for(int i = 1;i<=R;i++) {
        ans = ans * (N-R+i) / i;
    }
    return (int)ans;
}


int countPaths2(int i, int j, int m, int n, vector<vector<int>>& dp) {
    if(i == (m-1) && j == (n-1)) return 1;
    if(i>=m || j>=n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    else return dp[i][j] = countPaths2(i+1, j, m, n, dp)
        + countPaths2(i, j+1, m, n, dp);
}

// Dp solution
// TC - O(m*n)
// SC - O(m*n)
int uniquePaths2(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));

    int num = countPaths2(0, 0, m, n, dp);
    if(m==1 && n==1) return num;

    return dp[0][0];
}

int countPaths1(int i, int j, int m, int n) {
    if(i == (m-1) && j == (n-1)) return 1;
    if(i>=m || j>=n) return 0;
    else return countPaths1(i+1, j, m, n) + countPaths1(i, j+1, m, n);
}

// Brute force
// TC - O(2^n)
// SC - O(2^N)
int uniquePaths1(int m, int n) {
    return countPaths1(0, 0, m, n);
}

int main() {
    int ans = uniquePaths3(3,7);
    cout << ans;
}
