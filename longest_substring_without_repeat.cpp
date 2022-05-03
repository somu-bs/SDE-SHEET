#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Optimised  Approach 2
    // TC - O(n)
    // SC - O(n)
    int lengthOfLongestSubstring3(string s) {
        int n = s.size();
        int length = INT_MIN;
        int left = 0, right = 0;
        vector<int> mpp(256, -1);

        while(right < n) {
            if(mpp[s[right]] != -1) {
                left = max(mpp[s[right]] +1, left);
            }
            mpp[s[right]] = right;
            int getLen = right-left+1;
            length = max(length, getLen);
            right++;
        }
        return length;
    }
    // Optimised  Approach 1
    // TC - O(2*n)
    // SC - o(n)
    int lengthOfLongestSubstring2(string s) {
        int n = s.size();
        int length = INT_MIN;
        int left = 0, right = 0;
        unordered_set<int> st;

        while(right < n) {
            if(st.find(s[right]) != st.end()) {
                while(left < right && st.find(s[right]) != st.end()) {
                    st.erase(s[left]);
                    left++;
                }
                
            }
            st.insert(s[right]);
            int getLen = right-left+1;
            length = max(length, getLen);
            right++;
        }
        return length;

    }

    // naive approach
    // TC - O(n*n)
    // SC - O(n)
    int lengthOfLongestSubstring(string s) {
        int maxLen = INT_MIN;
        int n = s.size();
        for(int i = 0;i<n;i++) {
            unordered_set<int> st;
            for(int j = i;j<n;j++) {
                if(st.find(s[j]) != st.end()) {
                    maxLen = max(maxLen, j-i);
                    break;
                }
                st.insert(s[j]);
            }
        }
        return maxLen;
    }
};


int main() {
    Solution obj;
    string str = "takeUforward";
    cout << "The length of the longest substring without repeating characters is " << 
    obj.lengthOfLongestSubstring3(str);
    return 0;
}
