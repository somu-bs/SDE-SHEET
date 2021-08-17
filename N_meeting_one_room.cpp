#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

	int maxMeetings(int start[], int end[], int n) {
		vector<pair<int, int>> dur;

		for (int i = 0;i<n;i++) {
			dur.push_back({start[i], end[i]});
		}

		int cnt = 0, end_time = -1;
		for (auto p : dur) {
			if (p.first > pt) {
				cnt++, pt = p.second;
			}
			else if (p.second < pt) {
				pt = p.second;
			}
		}
		return cnt;
	}
};