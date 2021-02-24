//
//  main.cpp
//  c_moban
//
//  Created by mingliang on 2021/2/10.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace::std;

/*
 二分法
 https://github.com/youngyangyang04/leetcode-master.git

 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int left = 0;
        int right = n; // 我们定义target在左闭右开的区间里，[left, right)
        while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle; // target 在左区间，因为是左闭右开的区间，nums[middle]一定不是我们的目标值，所以right = middle，在[left, middle)中继续寻找目标值
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，在 [middle+1, right)中
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值的情况，直接返回下标
            }
        }
        return right;
    }
};


/*
 KMP
 */
void kmp(int* next, const string& s){
    next[0] = -1;
    int j = -1;
    for(int i = 1; i < s.size(); i++){
        while (j >= 0 && s[i] != s[j + 1]) {
            j = next[j];
        }
        if (s[i] == s[j + 1]) {
            j++;
        }
        next[i] = j;
    }
}

/*
 二叉树
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 前序遍历（中左右）
 */
void traversal_pre(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;
    vec.push_back(cur->val);    // 中 ，同时也是处理节点逻辑的地方
    traversal_pre(cur->left, vec);  // 左
    traversal_pre(cur->right, vec); // 右
}
/*
 中序遍历（左中右）
 */

void traversal_mid(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;
    traversal_mid(cur->left, vec);  // 左
    vec.push_back(cur->val);    // 中 ，同时也是处理节点逻辑的地方
    traversal_mid(cur->right, vec); // 右
}

/*
 后序遍历（中左右）
 */
void traversal(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;
    vec.push_back(cur->val);    // 中 ，同时也是处理节点逻辑的地方
    traversal(cur->left, vec);  // 左
    traversal(cur->right, vec); // 右
}

/*
 * 回溯法
 */
/*
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
