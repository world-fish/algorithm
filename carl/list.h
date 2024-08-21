#include <vector>
#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

// 单链表
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class List {
public:
    // 203. 移除链表元素
    ListNode *removeElements(ListNode *head, int val) {
        if (head == nullptr) {
            return head;
        }
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }

    // 206. 反转链表
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    // 24. 两两交换链表中的节点
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *prev = dummyHead;
        ListNode *cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            prev->next = cur->next;
            prev = prev->next;
            cur->next = prev->next;
            prev->next = cur;
            prev = prev->next;
            cur = cur->next;
        }
        ListNode *result = dummyHead->next;
        delete dummyHead;
        return result;
    }

    // 19.删除链表的倒数第N个节点
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *fast = dummyHead;
        ListNode *slow = dummyHead;
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }
        fast = fast->next;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        ListNode *result = dummyHead->next;
        delete dummyHead;
        return result;
    }

    // 面试题 02.07. 链表相交
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        while (lenA > lenB) {
            curA = curA->next;
            lenA--;
        }
        while (lenA < lenB) {
            curB = curB->next;
            lenB--;
        }
        while (curA != curB) {
            curA = curA->next;
            curB = curB->next;
        }
        return curA;
    }

    // 142.环形链表II
    ListNode *detectCycle(ListNode *head) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *fast = dummyHead;
        ListNode *slow = dummyHead;
        do {
            if (fast == nullptr || fast->next == nullptr) {
                return NULL;
            }
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        slow = dummyHead;
        do {
            fast = fast->next;
            slow = slow->next;
        } while (fast != slow);
        return fast;
    }

};

// 707. 设计链表
class MyLinkedList {
public:
    int size;
    ListNode *head;

    MyLinkedList() {
        head = new ListNode();
        size = 0;
    }

    int get(int index) {
        if (index > size - 1 || index < 0) {
            return -1;
        }
        ListNode *cur = head;
        for (int i = 0; i <= index; ++i) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        ListNode *cur = new ListNode(val, head->next);
        head->next = cur;
        size++;
    }

    void addAtTail(int val) {
        ListNode *newNode = new ListNode(val);
        ListNode *cur = head;
        for (int i = 0; i < size; ++i) {
            cur = cur->next;
        }
        cur->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        ListNode *newNode = new ListNode(val);
        ListNode *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index > size - 1) {
            return;
        }
        ListNode *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        ListNode *next = cur->next;
        cur->next = next->next;
        size--;
        delete (next);
    }
};