//
//  main.cpp
//  tracking_code
//
//  Created by mingliang on 2021/2/17.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

原文：

Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
EXAMPLE
Input: the node ‘c’ from the linked list a->b->c->d->e Result: nothing is returned, but the new linked list looks like a->b->d->e
译文：
实现一个算法来删除单链表中间的一个结点，只给出指向那个结点的指针。
例子：
输入：指向链表a->b->c->d->e中结点c的指针
结果：不需要返回什么，得到一个新链表：a->b->d->e

如果c指向链表的：1.头结点；2.中间结点。 3.尾结点。4.为空。
   情况1，2属于正常情况，直接将d的数据给c，c的next指针指向d 的next指向所指结点，删除d就OK。情况4为空，直接返回。情况3比较特殊，如果c 指向尾结点，一般会认为直接删除c就ok了，反正c后面也没有结点了，不用担心链表断开。 可是真的是这样吗？代码告诉我们，直接删除c，指向c的那个结点(比如说b)的next指针 并不会为空。也就是说，如果你打印这个链表，它还是会打印出和原来链表长度一样的链表， 而且最后一个元素为0！

关于这一点，原书CTCI中是这么讲的，这正是面试官希望你指出来的。然后， 你可以做一些特殊处理，比如当c是尾结点时，将它的数据设置为一些特殊字符， 这样在打印时就可以不打印它。当然也可以直接不处理这种情况，原书里的代码就是这么做 的。这里，也直接不处理这种情况。代码如下

typedef struct node{
    int data;
    node *next;
}node;

node* init(int a[], int n){
    node *head, *p;
    for(int i=0; i<n; ++i){
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

bool remove(node *c){
    if(c==NULL || c->next==NULL) return false;
    // if(c->next==NULL){//c为最后一个元素时直接删除，不行，最后还是会打印出一个为0的结点，需要特殊处理
    //     delete c;
    //     return;
    // }
    node *q = c->next; //删除当前节点，把后面的节点数据前移动
    c->data = q->data;
    c->next = q->next;
    delete q;
    return true;
}
void print(node *head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    int n = 10;
    int a[] = {
        9, 2, 1, 3, 5, 6, 2, 6, 3, 1
    };
    node *head = init(a, n);
    int cc = 3;
    node *c = head;
    for(int i=1; i<cc; ++i) c = c->next;
    print(head);
    if(remove(c))
        print(head);
    else
        cout<<"failure"<<endl;
    return 0;
}
