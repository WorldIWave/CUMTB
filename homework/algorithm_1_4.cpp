/*第二章2.4
    已知两个链表A和B分别表示两个集合，其元素递增排列。请设计算法求出两个集合A和B的差集（即仅由在A中出现而不再B中出现的元素所构成的集合），
并以同样的形式存储，同时返回该集合的元素个数。*/

#include <iostream>
#include "algorithm_1.h"

using namespace std;

int differenceOfSets(ListNode*& la, ListNode* lb) {
    ListNode* pa = la;
    ListNode* pb = lb;
    ListNode* prev = NULL;

    while (pa) {
        if (pb == NULL || pa->data < pb->data) {
            prev = pa;  // 记录当前节点
            pa = pa->next;
        } else if (pa->data == pb->data) {
            // 在 B 中找到相同元素，删除当前 pa
            if (prev) {
                prev->next = pa->next;
            } else {
                la = pa->next; // 删除头节点
            }
            ListNode* temp = pa;
            pa = pa->next;
            delete temp;
        } else {
            // B 的元素小于 A 的当前元素，继续移动 B
            pb = pb->next;
        }
    }

    // 统计剩余的元素个数
    int count = 0;
    pa = la;
    while (pa) {
        count++;
        pa = pa->next;
    }
    return count;
}

int main() {
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {3, 5, 7, 8};
    ListNode* la = createLinkedlist_t(arr1, 5);
    ListNode* lb = createLinkedlist_t(arr2, 4);

    cout << "List A: ";
    printList(la);
    cout << "List B: ";
    printList(lb);

    int count = differenceOfSets(la, lb);
    cout << "Difference (A - B): ";
    printList(la);
    cout << "Count of elements in the difference: " << count << endl;

    // 释放内存
    freeList(la);
    freeList(lb);

    return 0;
}