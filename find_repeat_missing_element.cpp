#include<bits/stdc++.h>
using namespace std;

int *findTwoElement(int *arr, int n) {
	int a, b;

	// Repeating number
	for(int a = 0;i<n;i++) {
		if(arr[abs(arr[i])-1]<0) {
			a = abs(arr[i]);
		}
		else{
			arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
		}
	}

	// Missing number
	for(int i = 0;i<n;i++) {
		if(arr[i] > 0) {
			b = i+1;
			break;
		}
	}

	int *v = new arr[2];
	v[0] = a;
	v[1] = b;
	return v;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0;i<n;i++) {
			cin >> a[i];
		}

		auto ans = findTwoElement(arr, n) << endl;
		cout << ans[0] << " " << ans[1] << endl;
	}
	return 0;
}