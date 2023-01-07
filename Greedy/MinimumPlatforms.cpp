// TC - O(2nlog2n) + O(2n)
// SC - O(1)


int findPlatform(int arr[], int dep[], int n) {
    	// Your code here
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    
    	int i = 1, j = 0;
    	int maxVal = 1, platform = 1;
    	while(i < n && j < n) {
    		if(arr[i] <= dep[j]) {
    			platform++;
    			i++;
    		}
    		else {
    			platform--;
    			j++;
    		}
    		maxVal = max(maxVal, platform);
    	}
    	return maxVal;
}
