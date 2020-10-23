
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
#define LYTEST  1


/************************** 最小子模块 **********************
 
 
 ************************* 最小子模块 ***********************/

//二叉树题集锦
//https://www.cnblogs.com/alantu2018/p/8460958.html

/************************** 题目集合 **********************
 ************************* 题目集合 ***********************/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
           1
        /     \
      2         3
    /  \       /  \
   4    5     6    7

 先序  1 -> 2 -> 4 -> 5 -> 3 -> 6 -> 7
 中序  4 -> 2 -> 5 -> 1 -> 6 -> 3 -> 7
 后序  4 -> 5 -> 2 -> 6 -> 7 -> 3 -> 1
 */

//先序https://www.jianshu.com/p/909de5479e2b
//template <typename T> ;

void PreOrderTraverse (TreeNode *T)
{
    if (T){
        cout << T -> val << " ";
        PreOrderTraverse (T -> left) ;
        PreOrderTraverse (T -> right) ;
    }
}
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

void preOrder(TreeNode *root)
{
    stack<TreeNode*> st;
    while(root||!st.empty()){
    if(root){
        st.push(root);
        cout<<root->val<<' ';
        root=root->left;
    }
    else
    {
        root=st.top();
        st.pop();
        if(root)
            root=root->right;
    }
    }
}

/*
 
 */
void inOrder(TreeNode *root)
{
    stack<TreeNode*> st;
    while(root||!st.empty())
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
        if(!st.empty())
        {
            root=st.top();
            cout<<root->val<<' ';
            st.pop();
            if(root)
                root=root->right;
        }
    }
}
void postOrder(TreeNode *root)
{
    TreeNode *cur;
    TreeNode *pre=NULL;
    stack<TreeNode*> st;
    if(root)
        st.push(root);
    while(!st.empty())
    {
        cur=st.top();
        if(cur->left==NULL&&cur->right==NULL||pre&&(cur->left==pre||cur->right==pre))
        {
            cout<<cur->val<<' ';
            pre=cur;
            st.pop();
        }
        else
        {
            if(cur->right)
            {
                st.push(cur->right);
            }
            if(cur->left)
            {
                st.push(cur->left);
            }
        }
    }
}

/*
 二叉树 dfs
 递归返回数据
 */
void dfs(TreeNode *root,vector<int> &res){
    if(root == nullptr){
        return;
    }
    res.push_back(root->val);
    if(root->left){
        dfs(root->left, res);
    }
    if(root->right){
        dfs(root->right,res);
    }
}

vector<int> check_dfs(TreeNode *node){
    vector<int> res;
    dfs(node,res);
    return res;
}

/*
 二叉树 dfs 非递归实现
 */
void DFS_Iterative(TreeNode* pRoot)
{
    if (pRoot==NULL)
        return;
    
    stack<TreeNode*> S; //栈先进后出
    S.push(pRoot);
    
    while (!S.empty()){
        TreeNode *node=S.top();
        cout<<node->val<<",";
        S.pop();
        
        if (node->right!=NULL){
            S.push(node->right);
        }
        if (node->left!=NULL){
            S.push(node->left);
        }
    }
}

/*
// 用queue实现的BFS
 */
void BFS(TreeNode *pRoot)
{
    if (pRoot==NULL)
        return;
    queue<TreeNode*> Q;
    Q.push(pRoot);
    while(!Q.empty()){
        TreeNode *node = Q.front();
        cout<<node->val<<"->";
        if (node->right!=NULL){
            Q.push(node->left);
        }
        
        if (node->right!=NULL){
            Q.push(node->right);
        }
        Q.pop();
    }
    cout<<endl;
}


/*
 从上到下打印二叉树 bfs
 https://blog.csdn.net/feit2417/article/details/99438445
    1
   / \
  2  3
 / \
4  5
 
 结果：
 1->2->3->4->5
 
 1 入队，1 出队 打印 ，2 3 入队 出队 打印
 队列实现  每个子树的 跟节点 如队列，取出来，打印子节点，如果子节点 还有子树，继续入队列
 */
list <TreeNode *> printTopToBottom(TreeNode *pRoot){
    list <TreeNode *> resList ;
    if(pRoot == nullptr){
        return resList;
    }
    queue<TreeNode *> queueNode;
    queueNode.push(pRoot);
    
    while(queueNode.size()){
        TreeNode *node = queueNode.front();
        queueNode.pop();
        
        resList.push_back(node);
        printf("node->val = %d \n",node->val);
        
        if(node->left){
            queueNode.push(node->left);
        }
        
        if(node->right){
            queueNode.push(node->right);
        }
    }
    return resList;
}


//层次遍历
void levelOrder(TreeNode *root)
{
    queue<TreeNode*> q;
    if(root)
        q.push(root);
    int cur=1;
    while(!q.empty())
    {
        int count=0;
        while(cur)
        {
            TreeNode* tmp=q.front();
            cout<<tmp->val<<' ';
            cur--;
            q.pop();
            if(tmp->left)
            {
                q.push(tmp->left);
                count++;
            }
            if(tmp->right)
            {
                q.push(tmp->right);
                count++;
            }
        }
        cout<<endl;
        cur=count;
    }
}

            
/*
 二叉树题目一：
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
 
 例如:
 给定二叉树: [3,9,20,null,null,15,7],
 
 3
 / \
 9  20
 /  \
 15   7
 返回其层次遍历结果：
 
 [
 [3],
 [9,20],
 [15,7]
 ]
 
 */

//在访问过程中，我们只需要将同一层中的节点同时入队列即可。在将该queue中所有元素出队列的同时，将下一层的元素进队列，完成交接

class SolutionlevelOrder {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        queue<TreeNode*> Q;
        TreeNode* p;
        Q.push(root);
        while(Q.empty()==0){
            vector<int> layer;
            int width=Q.size();
            for(int i=0;i<width;i++){
                p=Q.front();
                layer.push_back(p->val);//每一层节点的数值
                Q.pop(); //节点释放
                if(p->left) Q.push(p->left);
                if(p->right) Q.push(p->right);
            }
            res.push_back(layer);//
        }
        return res;
    }
};

//解决方法一 解法一：深度优先搜索（DFS）
/*
 作者：huang-fu-mai-yan
 链接：https://leetcode-cn.com/problems/two-sum/solution/er-cha-shu-ceng-ci-bian-li-c-by-huang-fu-mai-yan/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
class Solutionpre{
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        pre(root,0,res);
        return res;
    }
    void pre(TreeNode *root,int depth,vector<vector<int>> &res)
    {
        if(!root) return;
        if(depth>=res.size())   //说明需要增加一层
            res.push_back(vector<int>{});
        res[depth].push_back(root->val);
        pre(root->left,depth+1,res);
        pre(root->right,depth+1,res);
    }
};





/*
 如何遍历一棵树
 有两种通用的遍历树的策略：
 
 深度优先搜索（DFS）
 
 在这个策略中，我们采用深度作为优先级，以便从跟开始一直到达某个确定的叶子，然后再返回根到达另一个分支。
 
 深度优先搜索策略又可以根据根节点、左孩子和右孩子的相对顺序被细分为先序遍历，中序遍历和后序遍历。
 
 宽度优先搜索（BFS）
 
 我们按照高度顺序一层一层的访问整棵树，高层次的节点将会比低层次的节点先被访问到。
 
 下图中的顶点按照访问的顺序编号，按照 1-2-3-4-5 的顺序来比较不同的策略。
 
 本问题就是用宽度优先搜索遍历来划分层次：[[1], [2, 3], [4, 5]]。
*／
 
 
 
/*
 
  二叉树题目二： 二叉树深度
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 给定一个二叉树，找出其最大深度。
 
 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 
 说明: 叶子节点是指没有子节点的节点。
 
 示例：
 给定二叉树 [3,9,20,null,null,15,7]，
 
 3
 / \
 9  20
 /  \
 15   7
 返回它的最大深度 3 。
 
 */
//解决方法 递归查找 有子树 节点深度加一
class SolutionmaxDepth {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int l = 1+maxDepth(root->left);
        int r = 1+maxDepth(root->right);
        return l>r?l:r;
    }
};

class SolutionminDepth {
public:
    int minDepth(TreeNode* root) {
        int result = 0;
        if(!root)return 0;
        int l = 1+minDepth(root->left);
        int r = 1+minDepth(root->right);
        if(root->left != nullptr && root->right != nullptr){
            result = min(l, r);
        }else{
            result = max(l, r);
        }
        return result;
    }
};


/*
 
 题目三： 最大直径
 
 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。
 示例 :
 给定二叉树
 
 1
 / \
 2   3
 / \
 4   5
 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
 
 注意：两结点之间的路径长度是以它们之间边的数目表示。
 */

//mingliang 子模块
class SolutiondiameterOfBinaryTree
{
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        int distance = 0;
        dfs(root, distance);
        return distance;
    }
    
    /**
     * distance 记录以root为根的子树的最大直径，返回树的高度
     */
    int dfs(TreeNode *root, int &distance)
    {
        if (root == nullptr)
            return 0;
        int left = dfs(root->left, distance);
        int right = dfs(root->right, distance);
        //max记录当前的最大直径
        distance = max(left + right, distance);
        //由于我计算的直径是左树高度+右树高度，所以这里返回当前树的高度，以供使用
        return max(left, right) + 1;
    }
};





/*
 题目四 ： 翻转一棵二叉树。
 示例：
 
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
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/invert-binary-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
struct TreeNode* invertTree(struct TreeNode* root){
    
    struct TreeNode* tmpNode;
    
    if(root)
    {
        tmpNode = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = tmpNode;
    }
    return root;
}




/*
 二叉树题目五： 是否是镜像对称的
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/symmetric-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 给定一个二叉树，检查它是否是镜像对称的
 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 1
 / \
 2   2
 / \ / \
 3  4 4  3
 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 
 1
 / \
 2   2
 \   \
 3    3
 */

//解决思路：
//   1. 根结点具有相同的数值。  2.每个树的右子树 和 另一个树的左子树 对称
int isMirror(struct TreeNode* l_root, struct TreeNode* r_root)
{
    if (l_root == NULL && r_root == NULL) return true;
    if (l_root == NULL || r_root == NULL) return false;
    
    return    (l_root->val == r_root->val)   &&
    isMirror(l_root->left,  r_root->right) &&
    isMirror(l_root->right, r_root->left);
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}




/*
  二叉树题目七： 二叉树展开链表

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 给定一个二叉树，原地将它展开为链表。
 
 例如，给定二叉树
 
 1
 / \
 2   5
 / \   \
 3   4   6
 将其展开为：
 
 1
 \
 2
 \
 3
 \
 4
 \
 5
 \
 6
 
 思路：
 
 复杂度：
 
 解决方法：
 
 没有太理解题解，可以将左右子树都变成单链表，然后接起来，不知道是否可行
 
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solutionflatten {
public:
    void flatten(TreeNode* root) {
        if(root == NULL)    return;
        if(root -> left != NULL){
            TreeNode* p = root -> left;
            while(p -> right != NULL)
                p = p -> right;
            p -> right = root -> right;
            root -> right = root -> left;
            root -> left = NULL;
            flatten(root -> right);
        }else{
            flatten(root -> right);
        }
    }
};




/*
 
 二叉树题目八： 合并二叉树


给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

示例 1:

输入: 
    Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
输出: 
合并后的树:
         3
        / \
       4   5
      / \   \ 
     5   4   7
注意: 合并必须从两个树的根节点开始。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-binary-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//作者：hellozhaozheng
//链接：https://leetcode-cn.com/problems/two-sum/solution/biao-biao-zhun-zhun-de-hou-xu-bian-li-dai-ma-jian-/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



//解决思路：
//边界条件 有一个结点为空，则返回另一个结点 //对普通非空两个结点r1、r2做处理

class SolutionmergeTrees {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL){
            return t2;
        } 
        if(t2 == NULL){
            return t1;
        }
        int val = t1->val + t2->val;
        TreeNode* new_tree = new TreeNode(val);//根节点合并
        
        new_tree->left = mergeTrees(t1->left, t2->left); //合并左孩子
        new_tree->right = mergeTrees(t1->right, t2->right); //合并右孩子
        return new_tree;
    }
};

/*

二叉树题目九： 二叉树变成累加树
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-bst-to-greater-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

例如：

输入: 二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13
*/

/*
从BST的最大节点开始自底向上递归，
节点的更新顺序为右->中->左。
创建一个全局变量来保存当前节点需要累加的节点数，当前节点需要累加的节点值sum为上一个节点的val+上一个节点需要累加的sum

作者：zxy0917
链接：https://leetcode-cn.com/problems/two-sum/solution/java-you-gen-zuo-zhong-xu-bian-li-by-zxy0917/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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
 平衡二叉树
 checkHeight 判断左右子树的高度，平衡返回实际高度，不平衡返回-1；
 */
int checkHeight(TreeNode *root)
{
    if(root==NULL)
        return 0;
    int leftHeight=checkHeight(root->left);
    if(leftHeight==-1)
        return -1;
    int rightHeight=checkHeight(root->right);
    if(rightHeight==-1)
        return -1;
    int diff=abs(leftHeight-rightHeight);
    if(diff>1)
        return -1;
    else
        return max(leftHeight,rightHeight)+1;
}

bool isAVL(TreeNode* root)
{
    if(checkHeight(root)==-1)
        return false;
    else
        return true;
}


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

/*
 二叉树最大路径和
 */
int maxPath(TreeNode *root,int &sum)
{
    if(root==NULL)
        return 0;
    int ret;
    int left=maxPath(root->left,sum);
    int right=maxPath(root->right,sum);
    ret=max(root->val,max(left,right)+root->val); // ret = 跟节点 和 max (左节点 或者 右节点 ) + 根节点
    sum=max(sum,max(ret,left+right+root->val)); // max sum (sum , ret ,  左+右+根)
    return ret;
}

int maxPathSum(TreeNode* root)
{
    int sum=0;
    maxPath(root,sum);
    return sum;
}

/*
 作者：vailing
 链接：https://leetcode-cn.com/problems/binary-tree-paths/solution/fu-zhi-chuan-zhi-yu-yin-yong-chuan-zhi-by-vailing/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
  根节点到叶子结点的所有路径
 */

class Solution {
public:
    void binaryTree(TreeNode* root,string path,vector<string>&res)
    {
        if(root==NULL) return ;
        path.append(to_string(root->val));
        path.append("->");
        //叶子结点
        if(root->left==NULL&&root->right==NULL) {
            path.erase(path.length()-2);
            res.push_back(path);
        }
        binaryTree(root->left,path,res);
        binaryTree(root->right,path,res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string>res;
        binaryTree(root,path,res);
        return res;
    }
};




/*
 所有路径和为给定值
 */

void func(TreeNode *root, int sum, int cur, vector<int> &path, vector<vector<int>> &res)
{
    if(root == NULL)
        return ;
    cur += root->val;
    path.push_back(root->val);
    
    if(cur == sum && root->left == NULL && root->right == NULL)
    {
        res.push_back(path);
    }
    if(root->left != NULL)
    {
        func(root->left, sum, cur, path, res);
    }
    if(root->right != NULL)
    {
        func(root->right, sum, cur, path, res);
    }
    path.pop_back();// 判断左，左没有删除，回溯，判断右
}

vector<vector<int>> findPath(TreeNode *root, int sum)
{
    vector<int> path;
    vector<vector<int>> res;
    if(root == NULL)
    {
        return res;
    }
    
    int cur = 0;
    func(root, sum, cur, path, res);
    return res;
}

/*
 二叉树 先序遍历顺序展开成一个单链表
 */
class Solution_flatten
{
public:
    void flatten(TreeNode *root)
    {
        if(root==NULL)
            return;
        vector<TreeNode*> vec;
        preorder(root,vec);
        TreeNode *tmp=root;
        size_t i;
        for(i=1; i<vec.size(); i++)
        {
            //一定要记得将左指针置为NULL
            tmp->left=NULL;
            tmp->right=vec[i];
            tmp=tmp->right;
        }
        tmp->left=tmp->right=NULL;
    }
    void preorder(TreeNode *root,vector<TreeNode*> &vec)
    {
        stack<TreeNode*> s;
        while(root||!s.empty())
        {
            while(root)
            {
                vec.push_back(root);
                s.push(root);
                root=root->left;
            }
            if(!s.empty())
            {
                root=s.top();
                s.pop();
                root=root->right;
            }
        }
    }
    void createTree(TreeNode *&root)
    {
        int i;
        cin>>i;
        if(i!=0)
        {
            root=new TreeNode(i);
            if(root==NULL)
                return;
            createTree(root->left);
            createTree(root->right);
        }
    }
};



int length(int arr[])
{
    //cout << sizeof(arr[0]) << endl;
    //cout << sizeof(arr) << endl;
    return sizeof(arr) / sizeof(arr[0]);
}

int main(int argc, const char * argv[]) {
    
    
    string result;
    //first
    //vector<int> nums1 = {4,5,6,7,0,1,2};
    //cout << leetcode.search(nums1, 0);
    
    //second 电话号码的字符串组合
    //    SolutionBack *bakc = new SolutionBack();
    //    bakc->letterCombinations("23");
    
    //third 整数转罗马数字
    //    SolutionIntToRoman *third = new SolutionIntToRoman();
    //    resullt = third->intToRoman(1234);
    //    printf("resullt=%s \n ",resullt.c_str());
    
    //four 罗马数字转整数
    
    //    SolutionRomanToInt *four = new SolutionRomanToInt();
    //    four->romanToInt(<#string s#>);
    
    //最长公共前缀
    //    SolutionlongestCommonPrefix *five = new SolutionlongestCommonPrefix();
    //
    //    vector<string> test_vec;
    //    string t1 = "flow";
    //    string t2 = "flower";
    //    string t3 = "flight";
    //    test_vec.push_back(t1);
    //    test_vec.push_back(t2);
    //    test_vec.push_back(t3);
    //
    //    result = five->longestCommonPrefix(test_vec);
    //    printf("result=%s \n ",result.c_str());
    
    
//    // v001400
//    SolutionSearchRange *searchRanger = new SolutionSearchRange();
//    int nums[] = {5,7,7,8,8,10};
//    int nums_length = sizeof(nums) / sizeof(nums[0]) ;
//    int target = 8;
//    int targetRange[] = {-1, -1};
//    searchRanger->SolutionSearchRange::searchRange(nums ,nums_length, target, targetRange);
//
//    //arr_res = searchRanger->SolutionSearchRange::searchRange(nums ,length(nums), target);
//    printf(" %d %d ",targetRange[0],targetRange[1]);
    return 0;
}





//============== 链表操作 合并 断链 ==================
//合并





//==============最有用的子模块，二叉树dfs==================

/**
 * distance 记录以root为根的子树的最大直径，返回树的高度
 */
int dfs(TreeNode *root, int &distance)
{
    if (root == nullptr)
        return 0;
    int left = dfs(root->left, distance);
    int right = dfs(root->right, distance);
    //max记录当前的最大直径
    distance = max(left + right, distance);
    //由于我计算的直径是左树高度+右树高度，所以这里返回当前树的高度，以供使用
    return max(left, right) + 1;
}


/*
 二叉树的路径
 */
class Solution_binaryTree {
public:
    void binaryTree(TreeNode* root,string path,vector<string>&res)
    {
        if(root==NULL) return ;
        path.append(to_string(root->val));
        path.append("->");
        if(root->left==NULL&&root->right==NULL){
            path.erase(path.length()-2);
            res.push_back(path);
        }
        binaryTree(root->left,path,res);
        binaryTree(root->right,path,res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string>res;
        binaryTree(root,path,res);
        return res;
    }
};


/*
 //找到所有路径
 */

vector<vector<int> > allPath;

void findPath(TreeNode* root, vector<int>&path,vector<int> &res){
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->val);
    if (root->left == NULL&&root->right == NULL) //达到了叶子节点
    {
        //printPath(path);//打印路径
        allPath.push_back(path);//保存路径
    }
    if (root->left!=NULL)//左子树
    {
        findPath(root->left, path,res);
    }
    if (root->right!=NULL)//右子树
    {
        findPath(root->right, path,res);
    }
    path.pop_back();//在返回到父节点之前，在路径上删除当前节点
}















