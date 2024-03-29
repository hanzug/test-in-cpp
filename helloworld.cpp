#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
public:
    ListNode *head;
    ListNode *tail;
    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
    }
    void append(int val) {
        if (head == nullptr) {
            head = new ListNode(val);
            tail = head;
        } else {
            ListNode *node = new ListNode(val);
            tail->next = node;
            tail = node;
        }
    }

    void deleteNthFromEnd(int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *first = &dummy;
        ListNode *second = &dummy;

        for (int i = 1; i <= n + 1; i++) {
            first = first->next;
        }

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        auto toDelete = second->next;
        second->next = second->next->next;
        delete toDelete;
        head = dummy.next;
    }

    void printList() {
        auto cur = head;
        while (cur) {
            std::cout << cur->val << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    std::cout << "Original list: ";
    list.printList();

    list.deleteNthFromEnd(1);
    std::cout << "After deleting 2nd from end: ";
    list.printList();
    return 0;
}
