/*第二章2.6
    设计一个算法，通过一趟遍历确定长度为n的单链表中值最大的结点。*/

#include <iostream>
#include "algorithm_1.h"

using namespace std;

ListNode* findMaxNode(ListNode* head) {
    if (!head) return NULL; // 处理空链表情况

    ListNode* maxNode = head;
    ListNode* current = head->next;

    while (current) {
        if (current->data > maxNode->data) {
            maxNode = current; // 更新最大值节点
        }
        current = current->next;
    }
    return maxNode; // 返回最大值节点
}

int main() {
    int arr[] = {3, 5, 2, 8, 1, 4};
    ListNode* head = createLinkedlist_t(arr, 6);

    cout << "Original List: ";
    printList(head);

    ListNode* maxNode = findMaxNode(head);
    if (maxNode) {
        cout << "Max Node Value: " << maxNode->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    // 释放内存
    freeList(head);

    return 0;
}