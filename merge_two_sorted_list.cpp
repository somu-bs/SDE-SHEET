class Solution {
public:

    // Inplace method without using extra space
    // TC - O(l1+l2)
    // SC - O(1)
    Node* mergeTwoLists2(Node* list1, Node* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(list1->val > list2->val) {
            ListNode* temp = list1;
            list1 = list2;
            list2 = temp;
        }
        ListNode* res = list1;
        while(list1 != NULL && list2 != NULL) {
            ListNode* tmp = NULL;
            while(list1 != NULL && list1->val <= list2->val) {
                tmp = list1;
                list1 = list1->next;
            }
            tmp->next = list2;
            
            // SWAP
            ListNode *temp = list1;
            list1 = list2;
            list2 = temp;
        }
        return res;
    }

    // Brute force
    // TC - O(n+m)
    // SC - O(n+m)
    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* newNode = new Node();
        Node* dummy = newNode;

        while(list1 && list2) {
            if(list1->data < list2->data) {
                dummy->next = list1;
                list1 = list1->next;
            }
            else {
                dummy->next = list2;
                list2 = list2->next;
            }
            dummy = dummy->next;
        }

        if(list1) dummy->next = list1;
        if(list2) dummy->next = list2;
        return newNode->next;
    }
};
