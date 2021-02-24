//
//  main.cpp
//  tracking_code
//
//  Created by mingliang on 2021/2/17.
//

#include <iostream>
#include <string>
#include <vector>

using namespace::std;
原文：

Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.

DEFINITION

Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list.

EXAMPLE

Input: A -> B -> C -> D -> E -> C [the same C as earlier]

Output: C

译文：

给定一个循环链表，实现一个算法返回这个环的开始结点。

定义：

循环链表：链表中一个结点的指针指向先前已经出现的结点，导致链表中出现环。

例子：

输入：A -> B -> C -> D -> E -> C [结点C在之前已经出现过]

输出：结点C


#include <iostream>
#include <map>
using namespace std;

typedef struct node{
    int data;
    node *next;
}node;

node* init(int a[], int n, int m){
    node *head, *p, *q;
    for(int i=0; i<n; ++i){
        node *nd = new node();
        nd->data = a[i];
        if(i==m) q = nd;
        if(i==0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    p->next = q;
    return head;
}

node* loopstart(node *head){
    if(head==NULL) return NULL;
    node *fast = head, *slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow) break;
    }
    if(!fast || !fast->next) return NULL;
    slow = head;
    while(fast!=slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

struct ListNode {
    int val;
    int num;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class SolutionhasCycle {
public:
    bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
    }
    
};

map<node*, bool> hash;
node* loopstart1(node *head){
    while(head){
        if(hash[head]) return head;
        else{
            hash[head] = true;
            head = head->next;
        }
    }
    return head;
}
int main(){
    int n = 10, m = 9;// m<n
    int a[] = {
        3, 2, 1, 3, 5, 6, 2, 6, 3, 1
    };
    node *head = init(a, n, m);
    //node *p = loopstart(head);
    node *p = loopstart1(head);
    if(p)
        cout<<p->data<<endl;
    return 0;
}
