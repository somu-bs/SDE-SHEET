#include<bits/stdc++.h>
using namespace std;

int arr[5];
int cnt = 0;
int front = 0, rear = 0;

void push(int x) {
	if(cnt == n) return;
	arr[rear%n] = x;
	rear++;
	cnt++;
}

void pop() {
	if(cnt == 0) return;
	arr[front%n] = -1;
	front++;
	cnt--;
}