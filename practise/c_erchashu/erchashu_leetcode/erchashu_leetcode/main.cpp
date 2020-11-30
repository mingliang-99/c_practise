//
//  main.cpp
//  erchashu_leetcode
//
//  Created by mingliang on 2020/11/9.
//

#include <iostream>
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
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
 题目：从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
 例如:
 给定二叉树: [3,9,20,null,null,15,7]
 3
/ \
9  20
 /  \
15   7
 
 输出： [3,9,20,15,7]
 */

vector<int> printTopToBottom(TreeNode * root){
    vector<int> res = {0};
    queue<TreeNode*> tQ;
    tQ.push(root);
    while (!tQ.empty()) {
        TreeNode* node = tQ.front();
        printf("->%d",node->val);
        res.push_back(node->val);
        tQ.pop();
        if(node->left){
            tQ.push(node->left);
        }
        
        if(node->right){
            tQ.push(node->right);
        }
    }
    return res;
}

/*

 链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
 题目：给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点)
 例如: [3,9,20,null,null,15,7]
 输入：
     3
    / \
    9  20
     /  \
    15   7
 
 输出：
 [
   [3],
   [9,20],
   [15,7]
 ]
 
 */

vector<vector<int>> levelOrder(TreeNode * root){
    vector<vector<int>> res;
    if(!root){
        return res;
    }
    queue<TreeNode*> tQ;
    TreeNode* node;
    tQ.push(root);
    while(!tQ.empty()){
        vector<int> layer;
        size_t layer_nums = tQ.size(); //每一层的数据size
        for(int i=0;i<layer_nums;i++){ //每一个层次的数据入队列
            node = tQ.front();
            layer.push_back(node->val); //每个节点人vector
            tQ.pop();
            if(node->left){
                tQ.push(node->left);
            }
            if(node->right){
                tQ.push(node->right);
            }
        }
        res.push_back(layer);//存数据
   
    }
    return res;
}

/*
 
 链接： https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
 题目：给定一个二叉树，找出其最大深度。
 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 说明: 叶子节点是指没有子节点的节点
 例如: 输入：[3,9,20,null,null,15,7]

 输出： 3

 3
/ \
9  20
 /  \
15   7
 */

//最大深度
int maxDepth(TreeNode* root) {
    if(!root){
        return 0;
    }
    int l = 1 + maxDepth(root->left);
    int r = 1 + maxDepth(root->right);
    return l>r?l:r;
}

//最小深度
int minDepth(TreeNode* root){
    int result = 0;
    if(!root){
        return 0;
    }
    int l = 1+ minDepth(root->left);
    int r = 1+ minDepth(root->right);
    
    if(root->left && root->right){
        result = min(l,r);
    }else{
        result = max(l,r);
    }
    return result;
}


/*
 二叉树最大直径
 链接：https://leetcode-cn.com/problems/diameter-of-binary-tree/
 题目：给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点
 输入：
  1
 / \
2   3
/ \
4   5
 输出：返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]
 
 */

int dfs_height(TreeNode *root, int &distance){
    if(!root){
        return 0;
    }
    
    int left = dfs_height(root->left, distance);
    int right = dfs_height(root->right, distance);
    //max 记录当前的最大之前
    distance = max(left + right, distance);
    return max(left,right) +1;
}

int diameter_of_binary_tree(TreeNode * root){
    int distance = 0;
    dfs_height(root,distance);
    return distance;
}



/*
 链接：https://leetcode-cn.com/problems/invert-binary-tree/
 题目：翻转一棵二叉树
 输入：
   4
 /   \
2     7
/ \   / \
1   3 6   9
 
输出：
  4
 /   \
7     2
/ \   / \
9   6 3   1
 
 */

TreeNode *invert_tree(TreeNode *root){
    if(root == NULL){
        return NULL;
    }
    TreeNode *tmp;
    tmp = invert_tree(root->left);
    root->left = invert_tree(root->right);
    root->right = invert_tree(tmp);
    return tmp;
}


/*
 合并二叉树
 //解决思路：
 //边界条件 有一个结点为空，则返回另一个结点 //对普通非空两个结点r1、r2做处理
 */

TreeNode *mergeTrees(TreeNode* t1, TreeNode* t2){
    if(t1 == NULL){
        return t2;
    }
    if(t2 == NULL){
        return t1;
    }
    int val = t1->val + t2->val;
    TreeNode * new_node = new TreeNode(val);
    
    new_node->left = mergeTrees(t1->left, t2->left);
    new_node->right = mergeTrees(t1->right, t2->right);
    return new_node;
}

/*
 二叉树题目九： 二叉树变成累加树
 
 给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

 提醒一下，二叉搜索树满足下列约束条件：

 节点的左子树仅包含键 小于 节点键的节点。
 节点的右子树仅包含键 大于 节点键的节点。
 左右子树也必须是二叉搜索树

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/convert-bst-to-greater-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class SolutionconvertBST {
public:
     int sum = 0;
     TreeNode *convertBST(TreeNode *root) {
        if (root == nullptr) return nullptr;
        convertBST(root->right);
        //更新累加值
        sum += root->val;
        //改变节点值
        root->val = sum;
        convertBST(root->left);
        return root;
    }
};

/*
 二叉树题目十： 二叉树最大路径和
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/path-sum-iii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 给定一个二叉树，它的每个结点都存放着一个整数值。
 找出路径和等于给定数值的路径总数。
 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
 示例：
 
 root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 10
 /  \
 5   -3
 / \    \
 3   2   11
 / \   \
 3  -2   1
 
 返回 3。和等于 8 的路径有:
 
 1.  5 -> 3
 2.  5 -> 2 -> 1
 3.  -3 -> 11
 */


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
 */

int main(int argc, const char * argv[]) {
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
     C->left = E;
     C->right = F;
     D->left = NULL;
     D->right = NULL;
     E->left = NULL;
     E->right = NULL;
     F->left = NULL;
     F->right = NULL;
    
   //  自上而下打印bfs
   //  printTopToBottom(A);
    
   // 逐层打印
#if 0
    vector<vector<int>> res = levelOrder(A);
    for(int i = 0;i<res.size();i++){
        vector<int> layer = res[i];
        printf("level %d :",i);
        for(int j=0;j<layer.size();j++){
            printf(" %d :",layer[j]);
        }
        printf(" \n");
    }
#endif
    
   // int depth = maxDepth(A);
   // printf(" depth =%d \n",depth);
#if 0
    int height = diameter_of_binary_tree(A);
    printf(" height =%d \n",height);
#endif
    
    
//    invert_tree(A);

    
    
    return 0;
}
