#include <iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<sstream>
#include<cstring>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<list>
//
//  main.cpp
//  c_lianbiao
//
//  Created by mingliang on 2020/10/23.
//

/*
 基础数据结构
 */

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

/*
 链表刷题分类
 
 单链表
 1.创建链表
 2.遍历
 3.删除
 4.插入
 */

ListNode* createList(int len){
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
        printf("create val=%d \n",i);
        val = i;
        ListNode *tmp = new ListNode(val);
        cur->next = tmp;
        cur = tmp;
    }
    return head->next;
}

/*
  1. 链表遍历,返回
 */

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

/*
链表删除注意点
 1）链表作为函数出口返回
 2）删除首节点
 3）删除中间节点注意保护
 */
void deleteListNode(ListNode **pHead, int value){
    ListNode *pToBeDelete = nullptr;
    if(pHead == NULL || *pHead == NULL){
        return ;
    }
    //想要删除的节点为第一个节点
    if((*pHead)->val == value){
        pToBeDelete = *pHead;
        *pHead = (*pHead)->next;
    }else{
        ListNode *pNode = *pHead;
        while (pNode->next != nullptr && pNode->next->val != value) {
            pNode = pNode->next;
            if(pNode->next != nullptr && pNode->next->val == value){
                pToBeDelete = pNode->next;
                pNode->next = pNode->next->next;
            }
            
        }
    }
    if(pToBeDelete != nullptr){
        delete pToBeDelete;
        pToBeDelete = nullptr;
    }
}

/*
 链表插入
 */
ListNode *insertListNode(ListNode *pHead, int value, int idx){
    if(pHead == NULL){
        return nullptr;
    }
    ListNode *pCur = pHead;
    ListNode *insertNode = new ListNode(value);
    if(pCur == nullptr){
        pCur = insertNode;
        insertNode->next = nullptr;
        return pHead;
    }
    
    int i = 0;
    while (pCur->next != nullptr) {
        i++;
        pCur = pCur->next;
      //  printf("insert idx %d",i);
        if(i == idx){
            insertNode->next = pCur->next;
            pCur->next = insertNode;
            return pHead;
        }
    }
    return nullptr;
}


#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    printf("create list === \n");
    ListNode * head;
    head =  createList(10);
    traversalList(head);
    
    printf("insert list === head=%p   head->val=%d \n",head,head->val);
    insertListNode(head,61,6);
    traversalList(head);
    return 0;
}
