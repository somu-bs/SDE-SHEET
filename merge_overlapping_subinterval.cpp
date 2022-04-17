#include<bits/stdc++.h>
using namespace std;

// Optimized
// TC - O(NlogN) + O(N)
// SC - O(N)
vector<vector<int>> merge2(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;

    for(int i = 0;i<n;i++) {
        if(result.empty() || result.back()[1] < intervals[i][0]) {
            vector<int> v = {intervals[i][0], intervals[i][1]};

            result.push_back(v);
        }
        else {
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
    }
    return result;
}


// Brute force
// TC - O(NlogN) + O(N*N)
// SC - O(N)
vector<pair<int, int>> merge(vector<pair<int, int>>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<pair<int, int>> result;

    for(int i = 0;i<n;i++) {
        int start = arr[i].first, end = arr[i].second;

        if(!result.empty()) {
            if(start <= result.back().second) {
                continue;
            }
        }

        for(int j = i+1;j<n;j++) {
            if(arr[j].first <= end) {
                end = arr[j].second;
            }
        }

        result.push_back({start, end});
    }
    return result;
}

int main() {
    vector<vector<int>> arr;
    arr = {{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}};
    vector<vector<int>> ans = merge2(arr);

    for(auto &it : ans) {
        cout << it[0] << " " << it[1] << "\n";
    }
}
