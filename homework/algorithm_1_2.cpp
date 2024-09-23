/*第二章2.2
T：将两个非递减的有序链表合并为一个非递增的有序链表。要求结果链表仍使用原来两个链表的存储空间，不另外占用其他的存储空间。表中允许有重复的数据。
解题思路：
1.初始化两个非递减（即同一链表中可能有相同元素）链表。
2.合并有序链表，相同元素接在后面的序列中，使用头插法进行插入。
3.特殊情况的考虑。*/

#include <iostream>
#include "algorithm_1.h"

using namespace std;

ListNode* mergeTodecList(ListNode* la, ListNode* lb){
    ListNode* mergedList = NULL;

    while(la && lb){
        if(la->data <= lb->data){
            ListNode* temp = la->next;
            la->next = mergedList;
            mergedList = la;
            la = temp;
        }
        else{
            ListNode* temp = lb->next;
            lb->next =mergedList;
            mergedList =lb;
            lb = temp;
        }
    }
    while (la) {
        ListNode* temp = la->next;
        la->next = mergedList;
        mergedList = la;
        la = temp;
    }
    while (lb) {
        ListNode* temp = lb->next;
        lb->next = mergedList;
        mergedList = lb;
        lb = temp;
    }

    return mergedList;
}
int main(){
    int arr1[] = {1, 3, 3, 5, 7};
    int arr2[] = {2, 3, 5, 6, 6, 7, 8};
    ListNode* la = createLinkedlist_t(arr1, 5);
    ListNode* lb = createLinkedlist_t(arr2, 7);

    cout << "List A: ";
    printList(la);
    cout << "List B: ";
    printList(lb);

    // 合并链表为非递增有序链表
    ListNode* mergeddecList = mergeTodecList(la, lb);
    cout << "Merged List: ";
    printList(mergeddecList);

    // 释放内存
    freeList(mergeddecList);

    return 0;
}
