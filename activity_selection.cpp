#include<bits/stdc++.h>
using namespace std;

int activitySelection(vector<int> start, vector<int> end, int n) {
	vector<pair<int, int>> dur;

	for (int i = 0;i<n;i++) {
		dur.push_back({start[i], end[i]});
	}

	sort(dur.begin(), dur.end());

	int cnt = 0, end_time = -1;
	for (auto p : dur) {
		if (p.first > end_time) {
			cnt++, end_time = p.second;
		}
		else if (p.second < end_time) {
			end_time = p.second;
		}
	}
	return cnt;
}

int main() {
	int t;
	cin >> t;
	while (t-- ){
		int n;
		cin >> n;
		vector<int> start(n), end(n);
		for (int i = 0;i<n;i++) {
			cin >> start[i];
		}
		for (int i = 0;i<n;i++) {
			cin >> end[i];
		}

		cout << activitySelection(start, end, n) << endl;

	}
	return 0;
}