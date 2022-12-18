#include<bits/stdc++.h>
using namespace std;

int arr[5];
int top = -1;

void push(int x) {
	top++;
	arr[top] = x;
}

void pop() {
	top--;
}

int peek() {
	return arr[top];
}

int size() {
	return top+1;
}

bool empty() {
	return (top == -1);
}