/*第二章2.7
    设计一个算法，将链表中的所有结点的链接方向“原地”逆转，即要求仅利用原表的存储空间，换句话说，要求算法的空间复杂度为O（1）。*/

#include <iostream>
#include "algorithm_1.h"

using namespace std;

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL; // 前一个节点
    ListNode* current = head; // 当前节点
    ListNode* nextNode = NULL; // 下一个节点

    while (current) {
        nextNode = current->next; // 保存下一个节点
        current->next = prev; // 反转链接
        prev = current; // 移动 prev 到当前节点
        current = nextNode; // 移动到下一个节点
    }
    return prev; // 返回新的头结点
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedlist_t(arr, 5);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head); // 逆转链表

    cout << "Reversed List: ";
    printList(head);

    // 释放内存
    freeList(head);

    return 0;
}