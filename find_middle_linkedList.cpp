#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;

    }
    cout << "\n";
}


class Solution {
public:

    // Tortoise-Hare-Approach
    // TC - O(n)
    Node* middleNode2(Node* head) {
        Node *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Naive approach
    // TC - O(n)
    Node* middleNode(Node* head) {
        int n = 0;
        Node* temp = head;
        while(temp) {
            n++;
            temp = temp->next;
        }
        temp = head;
        for(int i = 0;i<n/2;i++) {
            temp = temp->next;
        }
        return temp;
    }
};

int main() {
    Node *head = NULL, *tail = NULL;
    int n, firstData, nextData;
    cin >> n;
    cin >> firstData;
    head = new Node(firstData);
    tail = head;

    for(int i = 1;i<n;i++) {
        cin >> nextData;
        tail->next = new Node(nextData);
        tail = tail->next;
    }


    Solution obj;
    head = obj.middleNode2(head);
    print(head);
    // cout << "\n";

}
