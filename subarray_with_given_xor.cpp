#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // optimized : prefix xor & map
    // TC - O(nlogn)
    // SC - O(n)
    // y ^ k = xorr
    // y = xorr ^ k

    int solve2(vector<int>& arr, int b) {
        int count = 0;
        int xorr = 0;
        map<int, int> freq;
        for(auto &it : arr) {
            xorr = xorr ^ it;

            if(xorr == b) {
                count++;
            }

            if(freq.find(xorr ^ b) != freq.end()) {
                count += freq[xorr ^ b];
            }

            freq[xorr] += 1; 
        }
        return count;
    }

    // Brute force
    // TC - O(n*n)
    
    int solve(vector<int>& arr, int b) {
        int count = 0;
        int n = arr.size();
        for(int i = 0;i<n;i++) {
            int _xor = 0;
            for(int j = i;j<n;j++) {
                _xor ^= arr[j];
                if(_xor == b) count++;
            }
        }
        return count;
    }
    
};


int main() {
    vector<int> A{4,2,2,6,4};
    Solution obj;
    int totalCount= obj.solve2(A, 6);
    cout<<"The total number of subarrays having a given XOR k is "<<totalCount<<endl;
}
