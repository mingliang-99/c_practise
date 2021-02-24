//
//  main.cpp
//  c_erchashu_maxdepth
//
//  Created by mingliang on 2021/2/4.
//

#include <iostream>
#include <math.h>
#include <queue>

/*
 给定一个二叉树，找出其最大深度。
 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 说明: 叶子节点是指没有子节点的节点。
 示例：
 给定二叉树 [3,9,20,null,null,15,7]，
 */
//二叉树先序遍历翻转
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
        int leftDepth = getDepth(node->left);       // 左
        int rightDepth = getDepth(node->right);     // 右
        int depth = 1 + fmax(leftDepth, rightDepth); // 中
        return depth;
    }
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};


class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + fmax(maxDepth(root->left), maxDepth(root->right));
    }
};


class Solution_maxDepth {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 0;
        std::queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = (int)que.size();
            depth++; // 记录深度
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return depth;
    }
};

/*
 多少个节点
 */

class SolutionNodesNum {
private:
    int getNodesNum(TreeNode* cur) {
        if (cur == 0) return 0;
        int leftNum = getNodesNum(cur->left);      // 左
        int rightNum = getNodesNum(cur->right);    // 右
        int treeNum = leftNum + rightNum + 1;      // 中
        return treeNum;
    }
public:
    int countNodes(TreeNode* root) {
        return getNodesNum(root);
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
