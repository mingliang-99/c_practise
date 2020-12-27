//
//  main.cpp
//  merge-two-sorted-lists
//
//  Created by mingliang on 2020/12/26.
//

#include <iostream>

/*
 题目链接： https://leetcode-cn.com/problems/merge-two-sorted-lists/
 输入：1->2->4, 1->3->4
 输出：1->1->2->3->4->4
 说明：将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
 */

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};


ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2;
    } else if (l2 == nullptr) {
        return l1;
    } else if (l1->val < l2->val) {
        l1->next = mergeTwoLists2(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists2(l1, l2->next);
        return l2;
    }
    return NULL;
}



ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *pre = dummy;
    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            pre->next = l1;
            l1 = l1->next;
        }else{
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
        printf("pre->val = %d \n",pre->val);
    }
    pre->next = l1==NULL ? l2 : l1;
    return dummy->next;
}
//1->2->4
//ListNode *creastTestL1(){
//    ListNode *L1 = new ListNode(1)
//}

ListNode* createList(char *arg, int len){
    if(len == 0){
        return NULL;
    }
    int val;
    ListNode *cur =  new ListNode(0);//创建第一个节点
    ListNode *head = cur;//记录头节点
    if(head == NULL){
        return NULL;
    }
    
    for(int i=0;i<len;i++){
        printf("create idx=%d val[%d] \n",i,arg[i]);
        val = i;
        ListNode *tmp = new ListNode(arg[i]);
        cur->next = tmp;
        cur = tmp;
    }
    return head->next;
}

ListNode* traversalList(ListNode *head){
    ListNode *cur = head;
    if(head == nullptr){
        return nullptr;
    }
    while (cur != nullptr) {
        if(cur){
            printf("check val=%d \n",cur->val);
        }
        cur = cur->next;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World! merge-two-sorted-lists\n";
    char L1Val[3] = {1,2,3};
    char L2Val[3] = {1,2,4};
    
    int L1Len = sizeof(L1Val) / sizeof(L1Val[0]);
    ListNode *L1 = createList(L1Val,L1Len);
    //traversalList(L1);
    
    int L2Len = sizeof(L2Val) / sizeof(L2Val[0]);
    ListNode *L2 = createList(L2Val,L2Len);
    traversalList(L2);
    
    ListNode *Lout = mergeTwoLists(L1,L2);
    traversalList(Lout);
    return 0;
}
