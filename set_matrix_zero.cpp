#include<bits/stdc++.h>
using namespace std;

// Optimize the better approach
// TC - O(2*(M*N))
void setZeroes3(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int col0 = 1;

    for(int i = 0;i<rows;i++) {
        if(matrix[i][0] == 0) col0 = 0;
        for(int j = 1;j<cols;j++) {
            if(matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
        } 
    }

    for(int i = rows-1;i>=0;i--) {
        for(int j = cols-1;j>=1;j--) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
        if(col0 == 0) matrix[i][0] = 0;
    }
    
}

// Better Approach => TC - O(N*M + N*M)
// SC - O(N) + O(M)
void setZeroes2(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    vector<int> dummyRow(row, -1), dummyCol(col, -1);
    for(int i = 0;i<row;i++) {
        for(int j = 0;j<col;j++) {
            if(matrix[i][j] == 0) {
                dummyRow[i] = 0;
                dummyCol[j] = 0;
            }
        }
    }

    for(int i = 0;i<row;i++) {
        for(int j = 0;j<col;j++) {
            if(dummyRow[i] == 0 || dummyCol[j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

}
// Brute Force => TC - O((N*M)*(N+M))
void setZeroes1(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    for(int i = 0;i<row;i++) {
        for(int j = 0;j<col;j++) {
            if(matrix[i][j] == 0) {
                int ind = i-1;
                while(ind >= 0) {
                    if(matrix[ind][j] != 0) {
                        matrix[ind][j] = -1;
                    }
                    ind--;
                }

                ind = i+1;
                while(ind < row) {
                    if(matrix[ind][j] != 0) {
                        matrix[ind][j] = -1;
                    }
                    ind++;
                }

                ind  = j-1;
                while(ind >= 0) {
                    if(matrix[i][ind] != 0) {
                        matrix[i][ind] = -1;
                    }
                    ind--;
                }

                ind = j+1;
                while(ind < col) {
                    if(matrix[i][ind] != 0) {
                        matrix[i][ind] = -1;
                    }
                    ind++;
                }
            }
        }
    }

    for(int i = 0;i<row;i++) {
        for(int j = 0;j<col;j++) {
            if(matrix[i][j] <= 0) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> arr;
    arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setZeroes3(arr);
    cout << "The Final Matrix is " << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
          cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
