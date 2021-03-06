//
//  main.cpp
//  tracking_code
//
//  Created by mingliang on 2021/2/17.
//

#include <iostream>
#include <string>
#include <vector>
题目
原文：

Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.

译文：

写程序在一棵二叉树中找到两个结点的第一个共同祖先。不允许存储额外的结点。注意： 这里不特指二叉查找树。

解答
  本题的关键应当是在Avoid storing additional nodes in a data structure 这句话上。我的理解是，不允许开额外的空间(比如说一个数组)来存储作为中间变量的结点。 虽然我也怀疑它是不是说不允许在结点数据结构Node中加入额外的东西， 比如说父结点的指针。Anyway，我们先从最简单的入手，再一步步加入限制条件。

如果没有任何限制条件，那我觉得最直观的思路就是把其中一个点的所有祖先(包含它自身) 都放入一个哈希表，然后再一步步查找另一个点的祖先结点， 第一个在哈希表中出现的祖先结点即为题目所求。

Node* first_ancestor(Node* n1, Node* n2){
    if(n1 == NULL || n2 == NULL) return NULL;
    map<Node*, bool> m;
    while(n1){
        m[n1] = true;
        n1 = n1->parent;
    }
    while(n2 && !m[n2]){
        n2 = n2->parent;
    }
    return n2;
}

这里用了一个map来存储中间变量，如果题目不允许开额外的辅助空间，那该如何做呢？ 那就老老实实地一个个地试。不断地取出其中一个结点的父结点， 然后判断这个结点是否也为另一个结点的父结点。代码如下

bool father(Node* n1, Node* n2){
    if(n1 == NULL) return false;
    else if(n1 == n2) return true;
    else return father(n1->lchild, n2) || father(n1->rchild, n2);
}
Node* first_ancestor1(Node* n1, Node* n2){
    if(n1 == NULL || n2 == NULL) return NULL;
    while(n1){
        if(father(n1, n2)) return n1;
        n1 = n1->parent;
    }
    return NULL;
}

让我们把条件再限制地严苛一些，如果数据结构Node中不允许有指向父亲结点的指针， 那么我们又该如何处理？其实也很简单，首先根结点一定为任意两个结点的共同祖先， 从根结点不断往下找，直到找到最后一个这两结点的共同祖先，即为题目所求。代码如下

void first_ancestor2(Node* head, Node* n1, Node* n2, Node* &ans){
    if(head==NULL || n1==NULL || n2==NULL) return;
    if(head && father(head, n1) && father(head, n2)){
        ans = head;
        first_ancestor2(head->lchild, n1, n2, ans);
        first_ancestor2(head->rchild, n1, n2, ans);
    }
}

这里用到了递归，ans最终保存的是这两个结点从根结点算起最后找到的那个祖先。 因为从根结点开始，每次找到满足要求的结点，ans都会被更新


//全部代码
#include <iostream>
#include <map>
#include <cstring>
using namespace std;

const int maxn = 100;
struct Node{
    int key;
    Node *lchild, *rchild, *parent;
};
Node *p, node[maxn];
int cnt;

void init(){
    p = NULL;
    memset(node, '\0', sizeof(node));
    cnt = 0;
}
void create_minimal_tree(Node* &head, Node *parent, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        node[cnt].key = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        create_minimal_tree(head->lchild, head, a, start, mid-1);
        create_minimal_tree(head->rchild, head, a, mid+1, end);
    }
}
Node* first_ancestor(Node* n1, Node* n2){
    if(n1 == NULL || n2 == NULL) return NULL;
    map<Node*, bool> m;
    while(n1){
        m[n1] = true;
        n1 = n1->parent;
    }
    while(n2 && !m[n2]){
        n2 = n2->parent;
    }
    return n2;
}
bool father(Node* n1, Node* n2){
    if(n1 == NULL) return false;
    else if(n1 == n2) return true;
    else return father(n1->lchild, n2) || father(n1->rchild, n2);
}
Node* first_ancestor1(Node* n1, Node* n2){
    if(n1 == NULL || n2 == NULL) return NULL;
    while(n1){
        if(father(n1, n2)) return n1;
        n1 = n1->parent;
    }
    return NULL;
}
void first_ancestor2(Node* head, Node* n1, Node* n2, Node* &ans){
    if(head==NULL || n1==NULL || n2==NULL) return;
    if(head && father(head, n1) && father(head, n2)){
        ans = head;
        first_ancestor2(head->lchild, n1, n2, ans);
        first_ancestor2(head->rchild, n1, n2, ans);
    }
}
Node* search(Node* head, int x){
    if(head == NULL) return NULL;
    else if(x == head->key) return head;
    else if(x <= head->key) search(head->lchild, x);
    else search(head->rchild, x);
}
int main(){
    init();
    int a[] = {
        0, 1, 2, 3, 4, 5, 6
    };
    Node *head = NULL;
    create_minimal_tree(head, NULL, a, 0, 6);
    Node *n1 = search(head, 0);
    Node *n2 = search(head, 4);
    cout<<n1->key<<" "<<n2->key<<endl;
    Node *ans = first_ancestor(n1, n2);
    cout<<ans->key<<endl;
    Node *ans1 = NULL;
    first_ancestor2(head, n1, n2, ans1);
    cout<<ans1->key<<endl;
    return 0;
}

