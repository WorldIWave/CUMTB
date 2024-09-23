#ifndef ALGORITHM_1_1
#define ALGORITHM_1_1

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
    ListNode* lb_curr = lb; //遍历lb

    while(pc && lb_curr){
        if(lb_curr->data < pc->data){
            ListNode* lb_next = lb_curr->next;
            if(pc_pre)
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
    if(lb_curr)
        pc_pre->next = lb_curr;
    return la;
}

#endif
