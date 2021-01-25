//
//  main.cpp
//  reverse-linked-list
//
//  Created by mingliang on 2020/12/29.
//

#include <iostream>

/*
 题目链接： https://leetcode-cn.com/problems/reverse-linked-list/
 讲解：https://leetcode-cn.com/problems/reverse-linked-list/solution/tu-jie-fan-zhuan-lian-biao-c-by-vin-18/
 输入: 1->2->3->4->5->NULL
 输出: 5->4->3->2->1->NULL
 说明：反转一个单链表
 思路：使用一个三个节点
      pre cur next
      NULL   1   2
 
 tobeRevert = NULL;
 cur->next = pre //1->NULL
 pre = cur; //节点向下平移
 cur = next;


 
 */

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};


ListNode * reverse_linked_list(ListNode *node){
    if (node == nullptr){
        return nullptr;
    }
    ListNode* reverseHead = nullptr;
    // 指针1：当前节点
    ListNode* cur = node;
    // 指针2：当前节点的前一个节点
    ListNode* pre = nullptr;

    while(cur != nullptr){
        // 指针3：当前节点的后一个节点
        ListNode* next = cur->next;
        if(next == nullptr){
            reverseHead = cur;
        }
        // 将当前节点的后一个节点指向前一个节点
        cur->next = pre; // 1-> null ;
        // 将前一个节点指向当前节点
        pre = cur; // pre = 1;
        // 将当前节点指向后一个节点
        cur = next; // cur = 2;
    }
    return reverseHead;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
