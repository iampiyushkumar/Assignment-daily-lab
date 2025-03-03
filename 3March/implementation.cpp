#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* curr = &dummy, *nex = &dummy, *pre = &dummy;
    int count = 0;

    while (curr->next) {
        curr = curr->next;
        count++;
    }

    while (count >= k) {
        curr = pre->next;
        nex = curr->next;
        for (int i = 1; i < k; ++i) {
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;
        }
        pre = curr;
        count -= k;
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 3;
    head = reverseKGroup(head, k);
    printList(head);

    return 0;
}