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
//深度优先搜索算法
/*
算法思想：
设初始状态时图中所有顶点未被访问，则：
(1):从图中某个顶点出发，访问;然后找到的一个邻接顶点；
(2):从出发，深度优先搜索访问和相邻接且未被访问的所有顶点。
(3):转(1)，直到和相邻接的所有顶点都被访问为止；
(4):继续选取图中未被访问的顶点作为起始顶点，转(1)，直到图中所有顶点都被访问为止
*/


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
 第一组入栈后： D B A （A先入栈，B入栈，D入栈）
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
            if(root)
                cout<<root->val<<' ';//打印 （1）节点
            if(root)
                root=root->left; //（1）的 左孩子（2）节点 作为根节点，
        }else{ //取最后一个入队的节点的右孩子，如果没有继续取倒数第二个节点的右孩子，取到后最为跟节点
            root=st.top();
            st.pop(); //移除栈顶元素
            if(root) //
                root=root->right;
        }
    }
}

void inOrder(TreeNode *root)
{
    stack<TreeNode*> st;
    while(root||!st.empty())
    {
        while(root) //左节点入栈，出栈打印
        {
            st.push(root);
            root=root->left;
        }
        if(!st.empty())
        {
            root=st.top();
            cout<<root->val<<' '; //出栈打印
            st.pop();
            if(root) //右孩子更新，然后入栈，出栈打印
                root=root->right;
        }
    }
}

//后续遍历
//左右节点都存在的时候入栈，没有节点的时候出栈

/*
 //后序  4 -> 2 -> 6 -> 5 -> 3 -> 1
 //结果  D -> B -> F -> E -> C -> A
 
 每个小阶段为循环一次开始
 1.0  A 先入栈
 1.1  查看 A 存在 右孩子，A的右孩子 B 入栈
 1.2  查看 A 存在 左孩子，A的左孩子 C 入栈
 1.3  此时栈为 B -> C -> A
 
 2.0  此时栈顶部为B，查看B 的左孩子和右孩子是否为NULL(左孩子，右孩子都没有的时候出栈)
 2.1  B 的 左孩子D 入栈
 2.2  此时栈为 D-> B -> C -> A
 
 3.1  D 的 左孩子和右孩子都为null ,D 出栈，并且D 设定为pre 节点
 2.2  此时栈为 B -> C -> A  ( 打印 D )
 
 4.1  B 的左孩子为D（pre） ，满足（cur->left==pre），B出栈，B为pre
 4.2  此时栈为 C -> A  ( 打印 D -> B )
 
 5.X  类推A，C 的左右孩子都不为null
 5.1  E 入栈， F入栈
 5.2  此时栈为 F -> E -> C -> A
 
 最后类推出栈打印 D -> B -> F -> E -> C -> A
 */
//第一组入栈后顺序 D -> B -> C -> A //先遍历左子树，左子树
//出栈打印 D -> B
//E 入栈： E -> C -> A
//出栈打印： D -> B -> E -> C -> A 
void postOrder(TreeNode *root)
{
    TreeNode *cur;
    TreeNode *pre=NULL;
    stack<TreeNode*> st;
    if(root){   // A 先入栈
        st.push(root);
    }
    while(!st.empty()){
        cur=st.top();
        if(((cur->left==NULL) && (cur->right==NULL))||(pre&&(cur->left==pre||cur->right==pre))){
            cout<<cur->val<<' ';
            pre=cur;
            st.pop();
        }else{
            if(cur->right){ //左子树存在的时候循环遍历，只到左子树为NULL
                st.push(cur->right);
            }
            if(cur->left){
                st.push(cur->left);
            }
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
D（4）  null   F(6)   E(5)

 先序  1 -> 2 -> 4 -> 3 -> 6 -> 5
 中序  4 -> 2 -> 1 -> 6 -> 3 -> 5
 后序  4 -> 2 -> 6 -> 5 -> 3 -> 1
 
 
 一棵二叉树由根结点、左子树和右子树三部分组成，若规定 D、L、R 分别代表遍历根结点、遍历左子树、遍历右子树，则二叉树的遍历方式有 6 种：DLR、DRL、LDR、LRD、RDL、RLD。由于先遍历左子树和先遍历右子树在算法设计上没有本质区别，所以，只讨论三种方式：
DLR--前序遍历（根在前，从左往右，一棵树的根永远在左子树前面，左子树又永远在右子树前面 ）
LDR--中序遍历（根在中，从左往右，一棵树的左子树永远在根前面，根永远在右子树前面）
LRD--后序遍历（根在后，从左往右，一棵树的左子树永远在右子树前面，右子树永远在根前面）
 
 */


//广度优先搜索算法
/*
算法思想：
设初始状态图中的所有顶点未被访问，则
(1)从图中某个顶点出发，访问；
(2)访问的所有相邻接且未被访问的所有顶点,,,；
(3)以,,,的次序，以依次作为，转(1)；
(4)继续选取图中未被访问顶点作为起始顶点，转(1)，直到图中所有顶点都被访问为止
 
 
 1）首先将A节点插入队列中，queue(A)；
 2）将A节点弹出，同时将A的子结点B、C插入队列中，此时B在队列首部，C在队列尾部，queue(B，C)；
 3）将B节点弹出，同时将B的子结点D、E插入队列中，此时C在队列首部，E在队列尾部，queue(C，D，E)；
 4）将C节点弹出，同时将C的子节点F，G，H插入队列中，此时D在队列首部，H在队列尾部，queue(D，E，F，G，H)；
 5）将D节点弹出，D没有子节点，此时E在队列首部，H在队列尾部，queue(E，F，G，H)；
 */

void BFS(TreeNode *root)
{
    if (root==NULL)
        return;
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        TreeNode *node = Q.front();
        cout<<node->val<<"->";
        Q.pop();
        if (node->left!=NULL){
            Q.push(node->left);
        }
        
        if (node->right!=NULL){
            Q.push(node->right);
        }

    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World! erchashu \n";
    
     TreeNode *A = (TreeNode *) malloc(sizeof(TreeNode));
     TreeNode *B = (TreeNode *) malloc(sizeof(TreeNode));
     TreeNode *C = (TreeNode *) malloc(sizeof(TreeNode));
     TreeNode *D = (TreeNode *) malloc(sizeof(TreeNode));
     TreeNode *E = (TreeNode *) malloc(sizeof(TreeNode));
     TreeNode *F = (TreeNode *) malloc(sizeof(TreeNode));
    
     A->val = 1;
     B->val = 2;
     C->val = 3;
     D->val = 4;
     E->val = 5;
     F->val = 6;
    
     A->left = B;
     A->right = C;
     B->left = D;
     B->right = NULL;
     C->left = F;
     C->right = E;
     D->left = NULL;
     D->right = NULL;
     E->left = NULL;
     E->right = NULL;
     F->left = NULL;
     F->right = NULL;
    
    std::cout << "\nHello, World! erchashu DLR--前序遍历 \n";
   // 先序遍历
   // preOrder(A);
   
    std::cout << "\nHello, World! erchashu LDR--中序遍历\n";
   // 中序
   // inOrder(A);
    
    std::cout << "\nHello, World! erchashu LRD--后序遍历\n";
   // 后序
   // postOrder(A);
    
   //BFS
    BFS(A);
    
    
    return 0;
}
