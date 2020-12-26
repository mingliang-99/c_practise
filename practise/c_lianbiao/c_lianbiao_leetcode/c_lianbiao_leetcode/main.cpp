//
//  main.cpp
//  c_lianbiao_leetcode
//
//  Created by mingliang on 2020/12/11.
//

#include <iostream>
struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

//生成测试链表
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

//反转一个链表
/*
 输入  1->   2->  3->4->5
 pre->cur->next
 
 输出 5->4->3->2->1
 */
//链表反转
ListNode* ReverseList2(ListNode* head)
{
    if (head == nullptr){
        return nullptr;
    }
    ListNode* reverseHead = nullptr;
    // 指针1：当前节点
    ListNode* cur = head;
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


/*
 链表是否有环/交叉 快慢指针
 1.执行逻辑
 2.边界条件
 */

bool hasCycle(ListNode *head) {
    if(head == nullptr || head->next == nullptr){
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast) {
        if(fast == nullptr || fast->next == nullptr){
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

/*
 链表题目三： 删除链表倒数n 个节点
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 
 示例：
 
 给定一个链表: 1->2->3->4->5, 和 n = 2.
 
 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 说明：
 
 给定的 n 保证是有效的。
 
 进阶：
 
 你能尝试使用一趟扫描实现吗？
 
 思路 ：
 1.使用两个指针，第一个指针先移动 n+1 ，第二个指针从头开始移动 ，保持固定间隔
 2.第一个指针移动到最后的节点，第二个指针指向最后一个节点开始倒数第n 个节点。
 3.重新链接第二个指针所应用节点的 next 指针的下下个节点
 
 
 时间复杂度 O(n)
 空间复杂度 O(1)
 
 */
#if 1
ListNode *deleteNPoint(ListNode *pHead,int n){
    if(pHead == nullptr || pHead == nullptr){
        return nullptr;
    }
    ListNode *dummy = new ListNode(0);
    dummy->next = pHead;
    ListNode *first = dummy;
    ListNode *second = dummy;
    ListNode *toBeDelete = nullptr;
    
    for(int i=0;i<n-1;i++){
        if(first->next != nullptr){
            first = first->next;
        }else{
            return nullptr;
        }
    }
    printf("first->val = %d",first->val);
    
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }
    
    printf("second->val = %d",second->val);
    
    toBeDelete = second;
    
    printf("toBeDelete->val = %d\n",toBeDelete->val);
    if(second->next != nullptr){
        second->next = second->next->next;
        free(toBeDelete);
        toBeDelete = NULL;

    }
    
    return dummy->next;
}
#endif

//https://www.cnblogs.com/Demrystv/p/9311288.html
//删除单链表中的倒数第K 个节点
ListNode* removeLastKthNodeInSingle(ListNode *head, int lastKth){
    if (head == NULL || lastKth < 1){
        return NULL;
    }

    ListNode *cur = head;
    while (cur != NULL){
        lastKth--;
        cur = cur->next;
    }
    
    if (lastKth == 0){//第一个节点删除
        head = head->next;
    }

    // 可以举例子：1 2 3 4 5 的倒数第4个节点
    if (lastKth < 0){
        cur = head;
        while (++lastKth != 0){
            cur = cur->next;
        }
        cur->next = cur->next->next;
    }
    return head;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
 输入：1->2->4, 1->3->4
 输出：1->1->2->3->4->4
 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
 链接： https://leetcode-cn.com/problems/merge-two-sorted-lists/
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr || l2 == nullptr){
            return nullptr;
        }
        ListNode *dummy = new ListNode(0);

        while(1){
            if(l1 == nullptr && l1 == nullptr){
                break;
            }
            if(l1 && l2){
                if(l1->val >= l2->val){
                    dummy->next = l1;
                    dummy=l1;
                    l1 = l1->next;
                }else{
                    dummy->next = l2;
                    dummy=l2;
                    l2 = l2->next;
                }

            }
        }
        
        
  
        return dummy->next;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    ListNode *text = createList(5);
    ListNode *traver = traversalList(text);
//    ListNode *vert = ReverseList2(traver);
//    ListNode *traver2 = traversalList(vert);
   // ListNode *todel = removeLastKthNodeInSingle(traver,3);
    ListNode *todel = deleteNPoint(traver,4);
    std::cout << "Hello, World!=======\n";
    ListNode *trave3 = traversalList(todel);
    
    
    //合并有序列表
    ListNode *testL1 = new ListNode(1);
    ListNode *L1Node2 = new ListNode(2);
    ListNode *L1Node3 = new ListNode(4);
    
    testL1->next
    cur->next = tmp;
    
    return 0;
}
