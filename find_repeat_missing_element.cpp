#include<bits/stdc++.h>
using namespace std;

// 1st approach (using count sort)

vector<int> find_missing_repeating(vector<int>& array) {
    int n = array.size() + 1;
    vector<int> subs_array(n, 0); // Initialize the substitude array 0 size N+1  
    vector<int> ans; // Initialize answer array
    
    for(int i = 0;i<array.size();i++) {
        subs_array[array[i]]++;
    }
    
    for(int i = 1;i<=array.size();i++) {
        if(subs_array[i] == 0 || subs_array[i] > 1)
            ans.push_back(i);
    }
    return ans;
}


// TC = O(N) + O(N)
// SC = O(N)


// 2nd approach (using math)

vector<int> find_missing_repeating(vector<int> &array) {
    long long int len = array.size();
    
    long long int s = (len*(len+1)) / 2;
    long long int p = (len*(len+1)*(2*len+1)) / 6;
    
    long long int missingElement = 0, repeatingElement = 0;
    
    for(int i = 0;i<array.size();i++) {
        s = s - (long long int)array[i];
        p = p - (long long int)array[i] * (long long int)array[i];
    }
    
    missingElement = (s + (p/s)) / 2;
    repeatingElement = missingElement - s;
    
    vector<int> ans;
    
    ans.push_back(missingElement);
    ans.push_back(repeatingElement);
    
    return ans;
}


// TC = O(N);
// SC = O(1) not using any extra space


// 3rd approach (using XOR)

vector<int> find_missing_repeating(vector<int>& array) {
    int xor1;
    
    int set_bit_no;
    int missingElement = 0, repeatingElement = 0;
    int n = array.size();
    
    xor1 = array[0];
    
    for(int i = 1;i<n;i++) {
        xor1 = xor1 ^ array[i];
    }
    
    for(int i = 1;i<=n;i++) {
        xor1 = xor1 ^ i;
    }
    
    // get the rightmost set bit into set_bit_no
    set_bit_no = xor1 & ~(xor1-1);
    
    // given element into two bucket
    for(int i = 0;i<n;i++) {
        if(array[i] & set_bit_no)
            missingElement = missingElement ^ array[i];
        else
            repeatingElement = repeatingElement ^ array[i];
    }
    
    // sepeate (1..N) into two bucket
    for(int i = 1;i<=n;i++) {
        if(i & set_bit_no)
            missingElement = missingElement ^ i;
        else
            repeatingElement = repeatingElement ^ i;
    }
    
    int x_count = 0;
    for(int i = 0;i<n;i++) {
        if(array[i] == x)
            x_count++;
    }
    
    if(x_count == 0)
        return {y, x};
    
    return {x,y};
}


// TC = O(N)
// SC = O(1)


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
