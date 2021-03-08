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

You are given a binary tree in which each node contains a value. Design an algorithm to print all paths which sum up to that value. Note that it can be any path in the tree - it does not have to start at the root.

译文：

给定一棵二叉树，每个结点包含一个值。打印出所有满足以下条件的路径： 路径上结点的值加起来等于给定的一个值。注意：这些路径不必从根结点开始。

解答
方案1：如果结点中包含指向父亲结点的指针，那么，只需要去遍历这棵二叉树， 然后从每个结点开始，不断地去累加上它父亲结点的值直到父亲结点为空(这个具有唯一性， 因为每个结点都只有一个父亲结点。也正因为这个唯一性， 可以不另外开额外的空间来保存路径)，如果等于给定的值sum，则打印输出。

void find_sum(Node* head, int sum){
    if(head == NULL) return;
    Node *no = head;
    int tmp = 0;
    for(int i=1; no!=NULL; ++i){
        tmp += no->key;
        if(tmp == sum)
            print(head, i);
        no = no->parent;
    }
    find_sum(head->lchild, sum);
    find_sum(head->rchild, sum);
}

打印输出时，只需要提供当前结点的指针，及累加的层数即可。然后从当前结点开始， 不断保存其父亲结点的值(包含当前结点)直到达到累加层数，然后逆序输出即可

void print(Node* head, int level){
    vector<int> v;
    for(int i=0; i<level; ++i){
        v.push_back(head->key);
        head = head->parent;
    }
    while(!v.empty()){
        cout<<v.back()<<" ";
        v.pop_back();
    }
    cout<<endl;
}


方案2：如果结点中不包含指向父亲结点的指针，则在二叉树从上向下查找路径的过程中， 需要为每一次的路径保存中间结果，累加求和仍然是从下至上的，对应到保存路径的数组， 即是从数组的后面开始累加的，这样能保证遍历到每一条路径

void print2(vector<int> v, int level){
    for(int i=level; i<v.size(); ++i)
        cout<<v.at(i)<<" ";
    cout<<endl;
}
void find_sum2(Node* head, int sum, vector<int> v, int level){
    if(head == NULL) return;
    v.push_back(head->key);
    int tmp = 0;
    for(int i=level; i>-1; --i){
        tmp += v.at(i);
        if(tmp == sum)
            print2(v, i);
    }
    vector<int> v1(v), v2(v);
    find_sum2(head->lchild, sum, v1, level+1);
    find_sum2(head->rchild, sum, v2, level+1);
}
