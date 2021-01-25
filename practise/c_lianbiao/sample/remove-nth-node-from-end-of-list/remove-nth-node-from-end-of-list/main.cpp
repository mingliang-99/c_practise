//
//  main.cpp
//  remove-nth-node-from-end-of-list
//
//  Created by mingliang on 2020/12/30.
//

#include <iostream>
/*
链接： https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
讲解： https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/
输入: 给定一个链表: 1->2->3->4->5, 和 n = 2.
输出: 当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点,给定的 n 保证是有效的
思路：提供亚节点
 1.暴力解法：
 - 找到链表长度
 - 删除从链表开头起的第（L-n+1）节点
 - 时间复杂度 O（n）
 - 整体复杂度 O(2n) - O(n)
 - 空间复杂度 O（1）
 2.快慢指针
 - 模式识别
   - 涉及链表的特殊位置，使用快慢指针
   - 要删除链表节点，找到前驱
*/
struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

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

ListNode *remove_nth_node_from_end_of_list(ListNode *node, int n){
    if(node == nullptr){
        return nullptr;
    }
    ListNode * first = node;
    ListNode * sec = node;
    while (first!=nullptr) {
        first=first->next;
        n--;
    }
    if(first == nullptr){
        return first->next;
    }
    
    while (first->next!=nullptr) {
        first = first->next;
        sec = sec->next;
    }
    
    sec->next = sec->next->next;
    return node;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    ListNode *node;
    int n = 2;
    node = createList(5);
    ListNode * result = remove_nth_node_from_end_of_list(node,2);
    
    return 0;
}
