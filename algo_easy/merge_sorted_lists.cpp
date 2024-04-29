#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    }

    if (list2 == nullptr) {
        return list1;
    }

    ListNode *return_node;
    ListNode *list1_node = list1;
    ListNode *list2_node = list2;

    if (list1_node->val <= list2_node->val) {
        return_node = list1_node;
        list1_node = list1_node->next;
    } else {
        return_node = list2_node;
        list2_node = list2_node->next;
    }

    ListNode *curr_node = return_node;

    while (list1_node != nullptr && list2_node != nullptr) {
        if (list1_node != nullptr && list1_node->val <= list2_node->val) {
            curr_node->next = list1_node;
            list1_node = list1_node->next;
            curr_node = curr_node->next;
            continue;
        }

        if (list2_node != nullptr && list2_node->val <= list1_node->val) {
            curr_node->next = list2_node;
            list2_node = list2_node->next;
            curr_node = curr_node->next;
            continue;
        }
    }

    if (list1_node == nullptr) {
        curr_node->next = list2_node;
    } else {
        curr_node->next = list1_node;
    }

    return return_node;
}

int main() {
    return 0;
}