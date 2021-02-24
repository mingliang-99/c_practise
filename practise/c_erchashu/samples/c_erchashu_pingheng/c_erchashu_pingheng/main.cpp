//
//  main.cpp
//  c_erchashu_pingheng
//
//  Created by mingliang on 2021/2/7.
//

#include <iostream>
#include <stack>
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

/*
 平衡二叉树递归，需要计算二叉树的深度
 */
int getDepth(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    int leftDepth = getDepth(node->left);
    if (leftDepth == -1) return -1;
    int rightDepth = getDepth(node->right);
    if (rightDepth == -1) return -1;
    return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + fmax(leftDepth, rightDepth);
}

class Solution {
public:
    // 返回以该节点为根节点的二叉树的高度，如果不是二叉搜索树了则返回-1
    int getDepth(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int leftDepth = getDepth(node->left);
        if (leftDepth == -1) return -1; // 说明左子树已经不是二叉平衡树
        int rightDepth = getDepth(node->right);
        if (rightDepth == -1) return -1; // 说明右子树已经不是二叉平衡树
        return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + fmax(leftDepth, rightDepth);
    }
    bool isBalanced(TreeNode* root) {
        return getDepth(root) == -1 ? false : true;
    }
};


// cur节点的最大深度，就是cur的高度
class Solution_getDepth {
private:
    int getDepth(TreeNode* cur) {
        std::stack<TreeNode*> st;
        if (cur != NULL) st.push(cur);
        int depth = 0; // 记录深度
        int result = 0;
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                st.push(node);                          // 中
                st.push(NULL);
                depth++;
                if (node->right) st.push(node->right);  // 右
                if (node->left) st.push(node->left);    // 左

            } else {
                st.pop();
                node = st.top();
                st.pop();
                depth--;
            }
            result = result > depth ? result : depth;
        }
        return result;
    }

public:
    bool isBalanced(TreeNode* root) {
        std::stack<TreeNode*> st;
        if (root == NULL) return true;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();                       // 中
            st.pop();
            if (abs(getDepth(node->left) - getDepth(node->right)) > 1) {
                return false;
            }
            if (node->right) st.push(node->right);           // 右（空节点不入栈）
            if (node->left) st.push(node->left);             // 左（空节点不入栈）
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
