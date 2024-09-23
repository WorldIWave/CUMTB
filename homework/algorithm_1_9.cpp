/*第二章2.9
    已知p指向双向循环链表中的一个结点，其结点结构为data、prior、next三个域，写出算法change（p），交换p所指向的结点及其前驱结点的顺序。*/

#include <iostream>
using namespace std;

struct ListNode {
    int data;          // 数据域
    ListNode* prior;  // 前驱
    ListNode* next;   // 后继
    ListNode(int x) : data(x), prior(NULL), next(NULL) {}
};

// 创建双向循环链表
ListNode* createCircularDoublyLinkedList(int arr[], int length) {
    if (length == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* tail = head;

    for (int i = 1; i < length; i++) {
        ListNode* newNode = new ListNode(arr[i]);
        tail->next = newNode;
        newNode->prior = tail;
        tail = newNode;
    }
    // 形成循环
    tail->next = head;
    head->prior = tail;
    
    return head;
}

// 打印双向循环链表
void printCircularList(ListNode* head) {
    if (!head) return;
    ListNode* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

// 交换 p 所指向的节点及其前驱节点的顺序
void change(ListNode* p) {
    if (p == NULL || p->prior == NULL) {
        return; // 如果 p 为空或没有前驱节点，直接返回
    }

    ListNode* prev = p->prior; // 获取前驱节点

    // 交换 p 和 prev 的链接
    prev->next = p->next; // 前驱的 next 指向 p 的后继
    if (p->next != p) {         // 如果 p 不是唯一节点
        p->next->prior = prev; // 更新 p 的后继的 prior 指向前驱
    }

    p->next = prev;       // p 的 next 指向前驱
    p->prior = prev->prior; // p 的 prior 指向前驱的 prior
    prev->prior->next = p; // 前驱的 prior 的 next 指向 p
    prev->prior = p;      // 前驱的 prior 指向 p

    // 更新 p 和 prev 的 prior 指向
    if (prev->prior == p) {
        prev->prior = p; // 在循环链表中保证 prev 的 prior 更新
    } else {
        p->prior = prev; // 在循环链表中保证 p 的 prior 更新
    }
}

// 释放内存
void freeCircularDoublyLinkedList(ListNode* head) {
    if (!head) return;
    ListNode* current = head;
    ListNode* nextNode;

    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* head = createCircularDoublyLinkedList(arr, 5);

    cout << "Original Circular Doubly Linked List: ";
    printCircularList(head);

    // 选择指向值为 3 的节点进行交换
    ListNode* p = head->next->next; // p 指向值为 3 的节点

    change(p); // 交换 p 和其前驱节点

    cout << "List After Changing Node 3 and its Predecessor: ";
    printCircularList(head);

    // 释放内存
    freeCircularDoublyLinkedList(head);

    return 0;
}
