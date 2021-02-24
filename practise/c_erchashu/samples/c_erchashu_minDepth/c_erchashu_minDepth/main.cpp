//
//  main.cpp
//  c_erchashu_minDepth
//
//  Created by mingliang on 2021/2/4.
//

#include <iostream>
#include <queue>
/*
 题目：
 给定一个二叉树，找出其最小深度。
 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 说明: 叶子节点是指没有子节点的节点。
 示例:
 给定二叉树 [3,9,20,null,null,15,7],
 */

/*
 思路：
 看完了这篇二叉树：看看这些树的最大深度，再来看看如何求最小深度。
 直觉上好像和求最大深度差不多，其实还是差不少的。
 遍历顺序上依然是后序遍历（因为要比较递归返回之后的结果），但在处理中间节点的逻辑上，最大深度很容易理解，最小深度可有一个误区，如图：
 这就重新审题了，题目中说的是：「最小深度是从根节点到最近叶子节点的最短路径上的节点数量。」，注意是「叶子节点」。
 什么是叶子节点，左右孩子都为空的节点才是叶子节点！
 */
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left);    // 左
        int rightDepth = getDepth(node->right);  // 右
                                                 // 中
        // 当一个左子树为空，右不为空，这时并不是最低点
        if (node->left == NULL && node->right != NULL) {
            return 1 + rightDepth;
        }
        // 当一个右子树为空，左不为空，这时并不是最低点
        if (node->left != NULL && node->right == NULL) {
            return 1 + leftDepth;
        }
        int result = 1 + fmin(leftDepth, rightDepth);
        return result;
    }
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};

/*
 
 */
class SolutionminDepth {
public:

    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 0;
        std::queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            depth++; // 记录最小深度
            int flag = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (!node->left && !node->right) { // 当左右孩子都为空的时候，说明是最低点的一层了，退出
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) break;
        }
        return depth;
    }
};

/*
 * 当前的节点
 */
class SolutioncountNodes {
public:
    int countNodes(TreeNode* root) {
        std::queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        int result = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                result++;   // 记录节点数量
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
