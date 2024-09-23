/*第二章2.8
    设计一个算法，删除递增有序链表中值大于mink且小于maxk的所有元素（mink和maxk是给定的两个参数，其值可以和表中的元素相同，也可以不同）。*/

#include <iostream>
#include "algorithm_1.h"

using namespace std;

// 删除范围内的节点
ListNode* removeInRange(ListNode* head, int mink, int maxk) {
    ListNode* dummy = new ListNode(0); // 创建虚拟头结点
    dummy->next = head; // 连接到原链表
    ListNode* current = dummy; // 从虚拟头结点开始

    while (current->next) {
        if (current->next->data > mink && current->next->data < maxk) {
            // 删除当前节点
            ListNode* temp = current->next;
            current->next = temp->next;
            delete temp; // 释放内存
        } else {
            current = current->next; // 移动到下一个节点
        }
    }

    head = dummy->next; // 更新头结点
    delete dummy; // 释放虚拟头结点
    return head; // 返回新的头结点
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    ListNode* head = createLinkedlist_t(arr, 6);

    cout << "Original List: ";
    printList(head);

    int mink = 3, maxk = 8;
    head = removeInRange(head, mink, maxk); // 删除范围内的节点

    cout << "Modified List: ";
    printList(head);

    // 释放内存
    freeList(head);

    return 0;
}