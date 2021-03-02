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

You have two very large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes. Create an algorithm to decide if T2 is a subtree of T1

译文：

有两棵很大的二叉树：T1有上百万个结点，T2有上百个结点。写程序判断T2是否为T1的子树。

解答
我觉得这道题目意欲考察如何在二叉树中结点数量非常巨大的情况下进行快速的查找与匹配， 不过除了常规的暴力法，我暂时想不到什么高效的方法。暴力法就很简单了， 先在T1中找到T2的根结点，然后依次去匹配它们的左右子树即可。

这里要注意的一点是，T1中的结点可能包含多个与T2根结点的值相同的结点。因此， 在T1中查找T2的根结点时，如果找到与T2匹配的子树，则返回真值；否则，还要继续查找， 直到在T1中找到一棵匹配的子树或是T1中的结点都查找完毕


bool match(Node* r1, Node* r2){
    if(r1 == NULL && r2 == NULL) return true;
    else if(r1 == NULL || r2 == NULL) return false;
    else if(r1->key != r2->key) return false;
    else return match(r1->lchild, r2->lchild) && match(r1->rchild, r2->rchild);
}
bool subtree(Node* r1, Node* r2){
    if(r1 == NULL) return false;
    else if(r1->key == r2->key){
        if(match(r1, r2)) return true;
    }
    else return subtree(r1->lchild, r2) || subtree(r1->rchild, r2);
}
bool contain_tree(Node* r1, Node* r2){
    if(r2 == NULL) return true;
    else return subtree(r1, r2);
}
