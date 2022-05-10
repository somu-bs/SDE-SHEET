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

Node* getNode(Node* head, int val) {
    while(head->data != val) head = head->next;
    
    return head;
}


class Solution {
public:

    // TC - O(1) SC - O(1)
    void deleteNode(Node* node) {
        if(node->next == NULL) delete node;
        node->data = node->next->data;
        node->next = node->next->next;
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
    Node* t = getNode(head, 4);
    obj.deleteNode(t);
    print(head);
    // cout << "\n";

}
