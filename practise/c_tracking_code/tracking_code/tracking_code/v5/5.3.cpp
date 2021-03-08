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

Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.

译文：

给定一个有序数组(递增)，写程序构建一棵具有最小高度的二叉树。

解答
想要使构建出来的二叉树高度最小，那么对于任意结点， 它的左子树和右子树的结点数量应该相当。比如，当我们将一个数放在根结点， 那么理想情况是，我们把数组中剩下的数对半分，一半放在根结点的左子树， 另一半放在根结点的右子树。我们可以定义不同的规则来决定这些数怎样对半分， 不过最简单的方法就是取得有序数组中中间那个数，然后把小于它的放在它的左子树， 大于它的放在它的右子树。不断地递归操作即可构造这样一棵最小高度二叉树

找到中间节点，对半分

队列已经有序，将其左右等分，然后分别挂在左右子树下面

#include <iostream>
#include <cstring>
#include <cmath>
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
        int mid = (start + end)>>1; //取中间节点
        node[cnt].key = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        create_minimal_tree(head->lchild, head, a, start, mid-1);
        create_minimal_tree(head->rchild, head, a, mid+1, end);
    }
}
int height(Node *head){
    if(head == NULL) return 0;
    return max(height(head->lchild), height(head->rchild)) + 1;
}
int main(){
    init();
    int a[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8
    };
    Node *head = NULL;
    create_minimal_tree(head, NULL, a, 0, 8);
    cout<<height(head)<<endl;
    return 0;
}


}
