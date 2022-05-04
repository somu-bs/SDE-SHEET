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

    // Recursive
    // TC - O(n)
    // SC - O(n) [stack space]
    Node* reverseList2(Node* &head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        Node* newHead = reverseList2(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    // Iterative Solution
    // TC - O(n)
    Node* reverseList(Node* &head) {
        Node* prev = NULL;
        while(head != NULL) {
            Node* nxt = head->next;
            head->next = prev;

            prev = head;
            head = nxt;
        }
        return prev;
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
    head = obj.reverseList2(head);
    print(head);
    // cout << "\n";

}
