#include<bits/stdc++.h>
using namespace std;

// Using binary exponentiation
// TC - O(logN)
// SC - O(1)
double myPow2(double x, int n) {
    double ans = 1.0;
    long long copy = n;
    if(copy < 0) copy = -1 * copy;
    while(copy) {
        if(copy%2) {
            ans *= x;
            copy -= 1;
        }
        else {
            x *= x;
            copy /= 2;
        }
    }
    if(n < 0) ans = (double)1.0 / (double)ans;
    return ans;
}
// Brute force
// TC - O(N)
double myPow(double x, int n) {
    double ans = 1.0;
    long long copy = n;
    if(copy < 0) copy = -1 * copy;
    for(int i = 0;i<copy;i++) {
        ans = ans * x;
    }
    if(n < 0) ans = (double)1.0 / (double)ans;
    return ans;
}

int main() {
    cout << myPow2(2.00000, -2);
}

