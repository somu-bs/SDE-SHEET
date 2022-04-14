#include<bits/stdc++.h>
using namespace std;

// TC - O(numRows*numRows)
// SC - O(numRows*numRows)
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result(numRows);

    for(int i = 0;i<numRows;i++) {
        result[i].resize(i+1);
        result[i][0] = result[i][i] = 1;
        for(int j = 1;j<i;j++) {
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> ans = generate(n);
    for(vector<int> &val : ans) {
        for(auto it : val) {
            cout << it << " ";
        }
        cout << "\n";
    }

}
