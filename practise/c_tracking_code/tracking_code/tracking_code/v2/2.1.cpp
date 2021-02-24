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
/*
 链表中删除重复的项
 
原文：
Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
译文：
从一个未排序的链表中移除重复的项
进一步地，
如果不允许使用临时的缓存，你如何解决这个问题？

 提问：链表是否是无限长，如果不是无限长，可以使用数组标记链表是否重复了；
 
 思路：
 */
typedef struct node{
    int data;
    node *next;
}node;
bool hash[100];

node* init(int a[], int n){
    node *head, *p;
    for(int i=0; i < n; ++i){
        node *nd = new node();
        nd->data = a[i];
        if(i==0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    return head;
}
/*
 空间，节省时间
 */
void removedulicate(node *head){
    if(head==NULL) return;
    node *p=head, *q=head->next;
    hash[head->data] = true;
    while(q){
        if(hash[q->data]){
            node *t = q;
            p->next = q->next;
            q = p->next;
            delete t;
        }
        else{
            hash[q->data] = true;
            p = q; q = q->next;
        }
    }
}

void removedulicate1(node *head){
    if(head==NULL) return;
    node *p, *q, *c=head;
    while(c){
        p=c; q=c->next;
        int d = c->data;
        while(q){
            if(q->data==d){
                node *t = q;
                p->next = q->next;
                q = p->next;
                delete t;
            }
            else{
                p = q; q = q->next;
            }
        }
        c = c->next;
    }
}

void print(node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}
int main(){
    int n = 10;
    int a[] = {
        3, 2, 1, 3, 5, 6, 2, 6, 3, 1
    };
    memset(hash, false, sizeof(hash));
    node *head = init(a, n);
    //removedulicate(head);
    removedulicate1(head);
    print(head);
    return 0;
}
