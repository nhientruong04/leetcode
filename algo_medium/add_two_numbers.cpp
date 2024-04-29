#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    bool remainder = false;

    ListNode *return_node;
    ListNode *l1_node = l1;
    ListNode *l2_node = l2;

    ListNode *curr_node = new ListNode();
    curr_node->val = l1_node->val + l2_node->val;

    if (curr_node->val >= 10) {
        curr_node->val -= 10;
        remainder = true;
    }

    return_node = curr_node;

    l1_node = l1_node->next;
    l2_node = l2_node->next;


    while ((l1_node!=nullptr && l2_node!=nullptr) || remainder) {
        int op1 = 0;
        int op2 = 0;
        ListNode *new_node = new ListNode;
        
        if (l1_node != nullptr) {
            op1 = l1_node->val;
            l1_node = l1_node->next;
        }

        if (l2_node != nullptr) {
            op2 = l2_node->val;
            l2_node = l2_node->next;
        }

        new_node->val = op1 + op2;

        if (remainder) {
            new_node->val++;
            remainder = false;
        } 

        if (new_node->val >= 10) {
            new_node->val -= 10;
            remainder = true;
        }

        curr_node->next = new_node;
        curr_node = new_node;
    }

    if (l1_node == nullptr) {
        curr_node->next = l2_node;
    } 

    if (l2_node == nullptr) {
        curr_node->next = l1_node;
    }


    return return_node;
}

int main() {
    ListNode l1(2);
    ListNode l2(8);
    l1.next = &l2;

    ListNode l4(0);

    ListNode * result_node = addTwoNumbers(&l1, &l4);
    ListNode *curr_node = result_node;
    while (curr_node != nullptr) {
        cout << curr_node->val;
        curr_node = curr_node->next;
    }

    cout << "\n";

    return 0;
}