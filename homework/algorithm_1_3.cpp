/*第二章2.3
T：已知两个链表A和B分别表示两个集合，其元素递增排列。请设计一个算法，用于求出A与B的交集，并存放在A链表中。
解题思路：
1.初始化两个递增链表。
2.遍历两个链表，相同值保留，不同值进行链表的删除操作。
3.特殊情况的考虑。*/
#include <iostream>
#include "algorithm_1.h"

using namespace std;

ListNode* findIntersection(ListNode* la, ListNode* lb) {
    ListNode* pa = la;
    ListNode* pb = lb;
    ListNode* pa_pre = NULL;

    // 遍历链表A和链表B
    while (pa && pb) {
        if (pa->data < pb->data) {
            // 删除链表A中不在B中的元素
            ListNode* temp = pa;
            pa = pa->next;
            if (pa_pre) {
                pa_pre->next = pa;
            } else {
                la = pa;  // 处理头节点删除的情况
            }
            delete temp;
        } else if (pa->data > pb->data) {
            // B元素大于A，移动B指针
            pb = pb->next;
        } else {
            // A和B的当前元素相等，保留该元素
            pa_pre = pa;
            pa = pa->next;
            pb = pb->next;
        }
    }

    // 删除链表A中剩余的元素
    while (pa) {
        ListNode* temp = pa;
        pa = pa->next;
        if (pa_pre) {
            pa_pre->next = pa;
        } else {
            la = pa;  // 处理头节点删除的情况
        }
        delete temp;
    }

    return la;
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

    // 求交集，结果存放在 la 中
    ListNode* Intersec = findIntersection(la, lb);
    cout << "Intersection: ";
    printList(Intersec);

    freeList(Intersec);
    freeList(lb);

    return 0;
}