//
//  main.cpp
//  c_erchashu_bianli
//
//  Created by mingliang on 2020/10/23.
//
#include<cstdio>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<sstream>
#include<cstring>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<list>
#include <iostream>
#include <stdio.h>

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
1 先序遍历（PreOrde）
如果二叉树为空，什么也不做。否则：
1）访问根结点；
2）先序遍历左子树；
3）先序遍历右子树。
对应的递归算法如下：
*/

void PreOrderTraverse (TreeNode *T)
{
    if (T){
        std::cout << T -> val << " ";
        PreOrderTraverse (T -> left) ;
        PreOrderTraverse (T -> right) ;
    }
}

/*
2 中序遍历（InOrder）
如果二叉树为空，什么也不做。否则：
1）中序遍历左子树；
2）访问根结点；
3）中序遍历右子树。
对应的递归算法如下
*/

//中序
void InOrderTraverse (TreeNode *T)
{
    if (T)
    {
     InOrderTraverse (T -> left) ;
     cout << T -> val << " ";
     InOrderTraverse (T -> right) ;
    }
}

/*
3 后序遍历（PostOrder）
如果二叉树为空，什么也不做。否则：
1）后序遍历左子树；
2）后序遍历右子树；
3）访问根结点。
对应的递归算法如下：
 */

//后序
void PostOrderTraverse (TreeNode *T)
{
    if (T)
    {
    PostOrderTraverse (T -> left) ;
    PostOrderTraverse (T -> right) ;
    cout << T -> val << " ";
    }
}

/*
 复杂度总结：
 
 不管采用哪种遍历算法，每个结点都访问一次且仅访问一次，故时间复杂度都是(n)。在递归遍历中，递归工作栈的栈深恰好为树的深度，所以在最坏的情况下，二叉树是有n个结点且深度为n的单支树，遍历算法的空间复杂度为O(n)

 */


//先序遍历的非递归算法
/*
 入栈顺序
 第一次入栈后： D B A
 循环出栈：
 第二次入栈：C
 出栈：
 最后一次入栈：E
 出栈：
 
 */
void preOrder(TreeNode *root)
{
    stack<TreeNode*> st;
    while(root||!st.empty()){
    if(root){ // 把 左节点顺序入队打印
        st.push(root);// (1) 节点入栈
        cout<<root->val<<' ';//打印 （1）节点
        root=root->left; //（1）的 左孩子（2）节点 作为根节点，
    }else{ //取最后一个入队的节点的右孩子，如果没有继续取倒数第二个节点的右孩子，取到后最为跟节点
        root=st.top();
        st.pop(); //移除栈顶元素
        if(root) //
            root=root->right;
    }
    }
}




//二叉树遍历  先序 中序 后序
//

/*
         A（1）
        /     \
      B（2）    C（3）
    /   \       /   \
D（4）  null   null   E(5)

 先序  1 -> 2 -> 4 -> 3 -> 5
 中序  4 -> 2 -> 5 -> 1 -> 6 -> 3 -> 7
 后序  4 -> 5 -> 2 -> 6 -> 7 -> 3 -> 1
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
     TreeNode *A = (TreeNode *) malloc(sizeof(TreeNode));
     TreeNode *B = (TreeNode *) malloc(sizeof(TreeNode));
     TreeNode *C = (TreeNode *) malloc(sizeof(TreeNode));
     TreeNode *D = (TreeNode *) malloc(sizeof(TreeNode));
     TreeNode *E = (TreeNode *) malloc(sizeof(TreeNode));
    
     A->val = 1;
     B->val = 2;
     C->val = 3;
     D->val = 4;
     E->val = 5;
    
     A->left = B;
     A->right = C;
     B->left = D;
     B->right = NULL;
     C->left = NULL;
     C->right = E;
     D->left = NULL;
     D->right = NULL;
     E->left = NULL;
     E->right = NULL;
    
     
    preOrder(A);
    
    
    return 0;
}
