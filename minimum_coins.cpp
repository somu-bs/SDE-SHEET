#include<bits/stdc++.h>
using namespace std;

int deno[] = {1,2,5,10,20,50,100,500,1000};
int n = sizeof(deno) / sizeof(deno[0]);

void findMinCoin(int V) {

	sort(deno, deno+n);
	vector<int> ans;

	for (int i = n - 1;i>=0;i--) {
		while (V >= deno[i]) {
			V -= deno[i];
			ans.push_back(deno[i]);
		}
	}

	for (int i = 0;i<ans.size();i++) {
		cout << ans[i] << " ";
	}


}

int main() {

	int v = 100;
	findMinCoin(v);
	return 0;
}