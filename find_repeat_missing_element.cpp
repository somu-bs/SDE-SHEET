#include<bits/stdc++.h>
using namespace std;

// Optimized : XOR
// TC - O(N)
// SC - O(1)
vector<int> find_missing_repeating3(vector<int>& arr) {
    int xor1;
    int set_bit_no;

    int i;
    int x = 0, y = 0;
    int n = arr.size();

    xor1 = arr[0];
    for(int i = 1;i<n;i++) {
        xor1 = xor1 ^ arr[i];
    }

    for(int i = 1;i<=n;i++) {
        xor1 = xor1 ^ i;
    }

    set_bit_no = xor1 & ~(xor1-1);

    for(int i = 0;i<n;i++) {
        if(arr[i] & set_bit_no) {
            x = x^arr[i];
        }
        else {
            y = y^arr[i];
        }
    }

    for(int i = 1;i<=n;i++) {
        if(i & set_bit_no) {
            x = x^i;
        }
        else {
            y = y^i;
        }
    }

    int x_count = 0;
    for(int i = 0;i<n;i++) {
        if(arr[i] == x) x_count++;

    }

    if(x_count == 0) return {y, x};

    return {x, y};
}

// Using Math
// TC - O(N)
// SC - O(1)
vector<int> find_missing_repeating2(vector<int>& arr) {
    long long int len = arr.size();

    long long int s = (len*(len+1)) / 2;
    long long int p = (len*(len+1)*(2*len+1)) / 6;
    int missingNumber = 0, repeatingNumber = 0;

    for(int i = 0;i<len;i++) {
        s -= (long long int)arr[i];
        p -= (long long int)arr[i] * (long long int)arr[i];
    }

    missingNumber = (s + (p/s)) / 2;
    repeatingNumber = missingNumber - s;

    vector<int> ans;
    ans.push_back(repeatingNumber);
    ans.push_back(missingNumber);

    return ans;
}

// Brute force
// TC - O(N) + O(N)
// SC - O(N)
vector<int> find_missing_repeating(vector<int>& arr) {
    vector<int> ans;
    int n = arr.size();
    int freq[n+1] = {0};
    for(int i = 0;i<n;i++) {
        freq[arr[i]]++;
    }

    for(int i = 1;i<=n;i++) {
        if(freq[i] > 1) ans.push_back(i);

        if(freq[i] == 0) ans.push_back(i);
    }
    return ans;
}
int main() {
    vector<int> arr = {1,2,3,2,5};
    vector<int> ans = find_missing_repeating3(arr);
    for(auto &it : ans) {
        cout << it << " ";
    }
}
