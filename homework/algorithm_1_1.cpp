/*第二章2.1
T：将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来两个链表的存储空间，不另外占用其他的存储空间。表中不允许有重复的数据。
解题思路：
1.初始化两个递增的有序链表。
2.pc指针从la的头节点开始，依次遍历la，每次移动后都比较pc指向的la和lb的值，
    如果lb的值小于此时la的值，则把lb插入到pc-1；
    如果lb的值大于la的值，则遍历下一个la；
    如果lb的值=la，不进行插入操作，但是下一次比较的lb往后移一个元素。
3.特殊情况和错误情况的考虑。*/

#include<iostream>

using namespace std;

//链表结点
struct ListNode{
    int data; //数据域
    ListNode* next;
    ListNode(int x): data(x), next(NULL) {}
};
//初始化链表，后插法
ListNode* createLinkedlist_t(int arr[], int length){
    if(length == 0) 
        return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* tail = head;

    for(int i = 1; i < length; i++){
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }
    return head;
}
//释放内存
void freeList(ListNode* head){
    while(head){
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

//打印链表
void printList(ListNode* head){
    while (head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

//合并递增有序链表，使用原存储，重复元素不插入
ListNode* mergeincLists(ListNode* la, ListNode* lb){
    //检查是否是空链表，如果是，返回另外一个链表
    if(!la) return lb;
    if(!lb) return la;

    ListNode* pc = la; //遍历la的指针
    ListNode* pc_pre = NULL; //pc的前一项，便于插入
    ListNode* lb_curr = lb; //遍历lb的指针

    while(pc && lb_curr){
        if(lb_curr->data < pc->data){
            ListNode* lb_next = lb_curr->next;
            if(pc_pre)//判断是否是表头
                pc_pre->next = lb_curr;
            else
                la = lb_curr;
            lb_curr->next = pc;
            pc_pre = lb_curr;
            lb_curr = lb_next;
        }
        else if (lb_curr->data == pc->data){
            lb_curr = lb_curr->next;
            pc_pre = pc;
            pc = pc->next;
        }
        else{
            pc_pre = pc;
            pc = pc->next;
        }
    }
    if(lb_curr) //如果有剩余，全部接在后面
        pc_pre->next = lb_curr;
    return la;
}

int main() 
{
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 3, 4, 7};
    ListNode* la = createLinkedlist_t(arr1, 3);
    ListNode* lb = createLinkedlist_t(arr2, 4);

    cout << "List A: ";
    printList(la);
    cout << "List B: ";
    printList(lb);

    ListNode* mergedList = mergeincLists(la, lb);
    cout << "merged List: ";
    printList(mergedList);
    freeList(mergedList);
    
    return 0;
}
