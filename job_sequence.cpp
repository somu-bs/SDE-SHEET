#include<bits/stdc++.h>
using namespace std;

struct Job {
	int id;
	int dead;
	int profit;
};

class Solution {
public:

	static bool comparison(Job a, Job b) {
		return (a.profit > b.profit);
	}

	vector<int> JobScheduling(Job arr[], int n) {
		sort(arr, arr+n, comparison);

		int maxi = arr[0].dead;
		for (int i = 1;i<n;i++) {
			maxi = max(maxi, arr[i].dead);
		}

		int slot[maxi + 1];
		for (int i = 0;i<=maxi;i++) {
			slot[i] = -1;
		}

		int countJobs = 0, jobProfit = 0;
		for (int i = 0;i<n;i++) {
			for (int j = arr[i].dead;j>0;j--) {
				if (slot[j] == -1) {
					slot[j] = i;
					countJobs++;
					jobProfit += arr[i].profit;
					break;
				}
			}
		}
		return {countJobs, jobProfit};
	}
};

int main() {
	int t;
	cin >> t;
	while (t-- ) {
		int n;
		cin >> n;
		Job arr[n];

		for (int i = 0;i<n;i++) {
			int x, y, z;
			cin >> x >> y >>z;
			arr[i].id = x;
			arr[i].dead = y;
			arr[i].profit = z;
		}

		Solution obj;
		vector<int> ans = obj.JobScheduling(arr, n);
		cout << ans[0] << " " << ans[1] << endl;
	}
	return 0;
}