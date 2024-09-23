/*第二章2.5
    设计算法将一个带头结点的单链表A分解为两个具有相同结构的链表B和C，其中B表的节点为A表中值小于零的结点，
而C表的结点为A表中值大于零的结点（链表A中的元素为非零整数，要求B和C表利用A表的结点）。
解题思路：1.遍历链表A
        2.结点值大于0，加到C。小于零，加到B。*/

#include <iostream>
#include "algorithm_1.h"

using namespace std;

void splitList(ListNode* head, ListNode*& bHead, ListNode*& cHead) {
    ListNode* pa = head; // 从 A 的头结点开始
    ListNode* bTail = NULL; // B 的尾指针
    ListNode* cTail = NULL; // C 的尾指针

    while (pa) {
        ListNode* nextNode = pa->next; // 保存下一个节点
        if (pa->data < 0) {
            if (!bHead) {
                bHead = pa; // B 链表的头结点
                bTail = bHead; // 更新 B 的尾指针
            } else {
                bTail->next = pa; // 将当前节点添加到 B
                bTail = pa; // 更新 B 的尾指针
            }
        } else {
            if (!cHead) {
                cHead = pa; // C 链表的头结点
                cTail = cHead; // 更新 C 的尾指针
            } else {
                cTail->next = pa; // 将当前节点添加到 C
                cTail = pa; // 更新 C 的尾指针
            }
        }
        pa->next = NULL; // 断开当前节点的链接
        pa = nextNode; // 移动到下一个节点
    }
}

int main() {
    int arr[] = {1, -2, 3, -4, 5, -6};
    ListNode* aHead = createLinkedlist_t(arr, 6);

    cout << "Original List A: ";
    printList(aHead);

    ListNode* bHead = NULL; // B 的头结点
    ListNode* cHead = NULL; // C 的头结点

    splitList(aHead, bHead, cHead);

    cout << "List B (values < 0): ";
    printList(bHead);

    cout << "List C (values > 0): ";
    printList(cHead);

    // 释放内存
    freeList(bHead);
    freeList(cHead);

    return 0;
}