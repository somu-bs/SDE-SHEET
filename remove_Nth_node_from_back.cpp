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
private:
    int findLen(Node* head) {
        int cnt = 0;
        Node* temp = head;
        while(temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
public:

    // TC - O(n)
    // SC - O(1)
    Node* removeNthFromEnd2(Node* head, int n) {
        Node* dummy = new Node(0);
        dummy->next = head;
        Node *slow = dummy, *fast = dummy;
        for(int i = 1;i<=n;i++) {
            fast = fast->next;
        }
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
    // Naive approach
    // TC - O(n) + O(n)
    Node* removeNthFromEnd(Node* head, int n) {
        int len = findLen(head);
        if(head == NULL || head->next == NULL) return NULL;
        if(len == n) {
            return head->next;
            
        }
        Node* temp = head;
        
        int upto = (len - n-1);
        while(upto--) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
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
    head = obj.removeNthFromEnd2(head, 2);
    print(head);
    // cout << "\n";

}
