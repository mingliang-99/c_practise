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

Given a binary search tree, design an algorithm which creates a linked list of all the nodes at each depth (i.e., if you have a tree with depth D, you’ll have D linked lists).

译文：

给定一棵二叉查找树，设计算法，将每一层的所有结点构建为一个链表(也就是说， 如果树有D层，那么你将构建出D个链表)

解答
这道题目本质上是个BFS，也就是说，如果已经构建了第i层结点的链表， 那么将此链表中每个结点的左右孩子结点取出，即可构建第i+1层结点的链表。 设结点类型为Node，那么指向每一层链表头结点的类型为list<Node*>， 将每一层头结点指针放到vector中。如果当前层的链表不为空， 那么将该链表的结点依次取出，然后将这些结点的不为空的孩子放入新的链表中



vector<list<Node*> > find_level_linklists(Node *head){
    vector<list<Node*>> res;
    int level = 0;
    list<Node*> li;//链表头
    li.push_back(head);
    res.push_back(li);//
    while(!res[level].empty()){
        list<Node*> layList;//每一层的链表节点，需要把每一层的左节点和右节点都存进来。
        list<Node*>::iterator it;
        for(it=res[level].begin(); it!=res[level].end(); ++it){//一层二叉树有几个节点
            Node *n = *it;
            if(n->lchild) layList.push_back(n->lchild);
            if(n->rchild) layList.push_back(n->rchild);
        }
        ++level;
        res.push_back(layList);
    }
    return res;
}

