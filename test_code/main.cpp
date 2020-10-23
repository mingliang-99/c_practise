//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************／

/*
 
 用法：vector
 用法：queue
 */


/*
 
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


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
 
 方法 1：递归
 算法
 
 最简单的解法就是递归，首先确认树非空，然后调用递归函数 helper(node, level)，参数是当前节点和节点的层次。程序过程如下：
 
 输出列表称为 levels，当前最高层数就是列表的长度 len(levels)。比较访问节点所在的层次 level 和当前最高层次 len(levels) 的大小，如果前者更大就向 levels 添加一个空列表。
 将当前节点插入到对应层的列表 levels[level] 中。
 递归非空的孩子节点：helper(node.left / node.right, level + 1)。
 实现
 
 
 1 / 15
 PythonJava
 class Solution:
 def levelOrder(self, root):
 """
 :type root: TreeNode
 :rtype: List[List[int]]
 """
 levels = []
 if not root:
 return levels
 
 def helper(node, level):
 # start the current level
 if len(levels) == level:
 levels.append([])
 
 # append the current node value
 levels[level].append(node.val)
 
 # process child nodes for the next level
 if node.left:
 helper(node.left, level + 1)
 if node.right:
 helper(node.right, level + 1)
 
 helper(root, 0)
 return levels
 复杂度分析
 
 时间复杂度：O(N)O(N)，因为每个节点恰好会被运算一次。
 空间复杂度：O(N)O(N)，保存输出结果的数组包含 N 个节点的值。
 方法 2：迭代
 算法
 
 上面的递归方法也可以写成迭代的形式。
 
 我们将树上顶点按照层次依次放入队列结构中，队列中元素满足 FIFO（先进先出）的原则。在 Java 中可以使用 Queue 接口中的 LinkedList实现。在 Python 中如果使用 Queue 结构，但因为它是为多线程之间安全交换而设计的，所以使用了锁，会导致性能不佳。因此在 Python 中可以使用 deque 的 append() 和 popleft() 函数来快速实现队列的功能。
 
 第 0 层只包含根节点 root ，算法实现如下：
 
 初始化队列只包含一个节点 root 和层次编号 0 ： level = 0。
 当队列非空的时候：
 在输出结果 levels 中插入一个空列表，开始当前层的算法。
 计算当前层有多少个元素：等于队列的长度。
 将这些元素从队列中弹出，并加入 levels 当前层的空列表中。
 将他们的孩子节点作为下一层压入队列中。
 进入下一层 level++。
 实现
 
 PythonJava
 from collections import deque
 class Solution:
 def levelOrder(self, root):
 """
 :type root: TreeNode
 :rtype: List[List[int]]
 """
 levels = []
 if not root:
 return levels
 
 level = 0
 queue = deque([root,])
 while queue:
 # start the current level
 levels.append([])
 # number of elements in the current level
 level_length = len(queue)
 
 for i in range(level_length):
 node = queue.popleft()
 # fulfill the current level
 levels[level].append(node.val)
 
 # add child nodes of the current level
 # in the queue for the next level
 if node.left:
 queue.append(node.left)
 if node.right:
 queue.append(node.right)
 
 # go to next level
 level += 1
 
 return levels
 复杂度分析
 
 时间复杂度：O(N)O(N)，因为每个节点恰好会被运算一次。
 空间复杂度：O(N)O(N)，保存输出结果的数组包含 N 个节点的值。
 
 
 */



/*
 
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


/*
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 编写一个程序，找到两个单链表相交的起始节点。
 如下面的两个链表：
 在节点 c1 开始相交。
 示例 1：
 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
 输出：Reference of the node with value = 8
 输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
  
 
 示例 2：
 输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
 输出：Reference of the node with value = 2
 输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
  
 
 示例 3：
 输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
 输出：null
 输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
 解释：这两个链表不相交，因此返回 null。
  
 
 注意：
 
 如果两个链表没有交点，返回 null.
 在返回结果后，两个链表仍须保持原有的结构。
 可假定整个链表结构中没有循环。
 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
 
 
 解决思路：
 分别计算两两链表的长度
 较长的链表指针先走多的步数
 遍历查找相同链表
 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
 
 */

class SolutionIntersectionNode {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)
            return NULL;
        ListNode* nodeA=headA;
        ListNode* nodeB=headB;
        //计算两链表的长度
        int lenA=0,lenB=0;
        while(nodeA){
            lenA++;
            nodeA=nodeA->next;
        }
        while(nodeB){
            lenB++;
            nodeB=nodeB->next;
        }
        //快指针先走较长链表多的步数
        int first=(lenA>lenB)?(lenA-lenB):(lenB-lenA);
        if(lenA>=lenB)
        {
            for(int i=0;i<first;i++)
                headA=headA->next;
        }
        else
            for(int i=0;i<first;i++)
                headB=headB->next;
        //查找相同链表，两指针相遇结束循环
        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};

/*
 这种算法NewBee：
 
 1.组合成两个新的链表 两个链表 A + B   和 B + A 这样链表长度相同
 2.遍历链表里面有相同的节点，证明链表相交
 
 利用双指针求解，可以加一个trick，就是当一个链表为空的时候指向另一个链表的头部，这样可以看做两个相同长度的链表，都从起始位置出发，找到相同元素的问题，代码如下：
 作者：Tangzixia
 链接：https://leetcode-cn.com/problems/two-sum/solution/xiang-jiao-lian-biao-by-tangzixia/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class SolutionIntersectionNode2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode *p=headA,*q=headB;
        while(p!=q){
            p=p?p->next:headB; // 遍历A 链表，当A 链表null 时候，继续遍历B 链表
            q=q?q->next:headA; // 遍历B 链表，当A 链表null 时候，继续遍历A 链表
        }
        return p;
    }
};


/*
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/min-stack
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 
 push(x) -- 将元素 x 推入栈中。
 pop() -- 删除栈顶的元素。
 top() -- 获取栈顶元素。
 getMin() -- 检索栈中的最小元素。
 示例:
 
 MinStack minStack = new MinStack();
 minStack.push(-2);
 minStack.push(0);
 minStack.push(-3);
 minStack.getMin();   --> 返回 -3.
 minStack.pop();
 minStack.top();      --> 返回 0.
 minStack.getMin();   --> 返回 -2.
 
 解题思路：
 
 参考1718ZhangYQ的题解“Python[数据栈+辅助栈]”，设计了主栈和辅助栈，辅助栈中存放的是每个位置所对应的栈内的最小值，因此pop()和getMin()可以直接得到，当push()的时候，判断msta.top()和元素x的关系，进而决定该加入哪个元素，实现如下：
 
 作者：Tangzixia
 链接：https://leetcode-cn.com/problems/two-sum/solution/zui-xiao-zhan-by-tangzixia/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 
 */

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if(msta.empty()){
            msta.push(x); //辅助栈为null,压栈第一个元素
        }else{ // 目的入栈的元素最小值
            if(msta.top()<=x) msta.push(msta.top()); // 压栈的元素 如果 大于 栈顶的元素，将栈顶的元素重新压入栈中
            else msta.push(x);
        }
        sta.push(x);
    }
    
    void pop() {
        if(sta.empty()) return;
        msta.pop();
        sta.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return msta.top();
    }
private:
    stack<int> sta;  //标准栈
    stack<int> msta;  // 辅助栈 记录最小数值
};



/*
 经典 投票法
 
 https://leetcode-cn.com/problems/majority-element/solution/pai-xu-ha-xi-tou-piao-by-haydenmiao/
 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 
 你可以假设数组是非空的，并且给定的数组总是存在众数。
 
 示例 1:
 
 输入: [3,2,3]
 输出: 3
 示例 2:
 
 输入: [2,2,1,1,1,2,2]
 输出: 2
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/majority-element
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class SolutionmajorityElement {
public:
    int majorityElement(vector<int>& nums) {
        /*//排序：中间元素 先对数组排序，然后取中间位置的元素，再对数据扫描一趟来判断此元素是否为多数元素。时间复杂度O(nlog(n))，空间复杂度O(1)
         sort(nums.begin(),nums.end());
         return nums[nums.size()/2];
         */
        /*//哈希表。使用一个hash表，对数组进行一趟扫描统计每个元素出现的次数，即可得到多数元素。时间复杂度O(n)，空间复杂度O(n)
         map<int,int> mp;
         for(int i=0;i<nums.size();i++)
         mp[nums[i]]=0;
         for(int i=0;i<nums.size();i++)
         {
         mp[nums[i]]++;
         if(mp[nums[i]]>nums.size()/2)
         return nums[i];
         }
         return -1;
         */
        //投票法：相同计数器加1，不相同计数器减1，最终剩下的数为众数
        int count=0;
        int n;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
                n=nums[i];
            if(n == nums[i]){
                count += 1;
            }  else {
                count -= 1;
            }
            //count+=(n==nums[i])?1:-1;
        }
        return n;
        
    }
};

/*
 
 动态规划：
 最优子结构
 子问题重叠
 边界
 子问题独立
 
 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 
 示例 1:
 
 输入: [1,2,3,1]
 输出: 4
 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
      偷窃到的最高金额 = 1 + 3 = 4 。
 示例 2:
 
 输入: [2,7,9,3,1]
 输出: 12
 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
      偷窃到的最高金额 = 2 + 9 + 1 = 12
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/house-robber
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 解题思路：
 dp 方程 dp[i] = max(dp[i-2]+nums[i], dp[i-1])//要么取中间的，要么取两边的
 
 */


/*
 作者：gpe3DBjDS1
 链接：https://leetcode-cn.com/problems/two-sum/solution/da-jia-jie-she-by-gpe3dbjds1/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

/*
 java 解决方案：
 
 class Solution {
 public int rob(int[] nums) {
 int len = nums.length;
 if(len == 0)
 return 0;
 int[] dp = new int[len + 1];
 dp[0] = 0;
 dp[1] = nums[0];
 for(int i = 2; i <= len; i++) {
 dp[i] = Math.max(dp[i-1], dp[i-2] + nums[i-1]);
 }
 return dp[len];
 }
 }
 
 作者：guanpengchn
 链接：https://leetcode-cn.com/problems/two-sum/solution/hua-jie-suan-fa-198-da-jia-jie-she-by-guanpengchn/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
class SolutionRob {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        nums[2]=nums[0]+nums[2];
        if(nums.size()==3)
            return max(nums[1],nums[2]);
        for(int i=3;i<nums.size();i++)
        {
            nums[i]=max(nums[i-2]+nums[i],nums[i]+nums[i-3]);
        }
        return max(nums[nums.size()-1],nums[nums.size()-2]);
    }
};


/*
 作者：sunshy
 链接：https://leetcode-cn.com/problems/two-sum/solution/die-dai-di-gui-jie-fa-by-sunshy/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 反转一个单链表。
 
 示例:
 
 输入: 1->2->3->4->5->NULL
 输出: 5->4->3->2->1->NULL
 进阶:
 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/reverse-linked-list
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 迭代
 递归
 */
// A: 1 -> 2 -> 3 -> 4 -> 5
// A: 1(head/first) -> 2（target） -> 3 -> 4 -> 5

// B: 2 -> 1 -> 3 -> 4 -> 5
// B: 2(head) -> 1(first) -> 3(target) -> 4 -> 5

// C: 3 -> 2 -> 1 -> 4 -> 5
// D: 4 -> 3 -> 2 -> 1 -> 5

ListNode* reverseList(ListNode* head) {
    if(!head){
        return nullptr;
    }
    ListNode* first = head;//始终指向原链表的首位元素
    ListNode* target = head->next;//始终指向即将要放到当前链表首元素之前的目标元素
    
    //
    while(target != nullptr){
        first->next = target->next; // 3 链接 到 1 上
        ListNode* temp = target->next; //保留
        target->next = head;//   1 链接到 2
        head = target; // 2 放到 链表头
        target = temp; // 移动目标转移到下一个节点
    }
    return head;
}

/*
 翻转一棵二叉树。
 
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

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
 二叉树基本操作
 */

/*
 二叉树题目一：
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
 返回它的最大深度 3
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

/*
 二叉树题目二：
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
    
    return    (l_root->val != r_root->val)   &&
    isMirror(l_root->left,  r_root->right) &&
    isMirror(l_root->right, r_root->left);
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}


/*
 二叉树题目三：
 
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
            vector<int> a;
            int width=Q.size();
            for(int i=0;i<width;i++){
                p=Q.front();
                a.push_back(p->val);//每一层节点的数值
                Q.pop(); //节点释放
                if(p->left) Q.push(p->left);
                if(p->right) Q.push(p->right);
            }
            res.push_back(a);//
        }
        return res;
    }
};


/*
  二叉树题目四： 二叉树展开链表

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
 
 二叉树题目五： 合并二叉树


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

二叉树题目六： 二叉树变成累加树
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

//计算每一个节点的sum 
class Solutionresult {
public:
    int out = 0;
    void result(TreeNode* root, int sum, int num)
    {
        if (root == NULL)
        {
            return;
        }
        if (num + root->val == sum)  // 上一个根节点和左或者右孩子累加
        {
            out++;
        }
        result(root->left, sum, num+root->val);
        result(root->right, sum, num+root->val);
    }

    int pathSum(TreeNode* root, int sum) { //计算本节点和左右子孩子节点的数值
        if (root == NULL)
        {
            return 0;
        }
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        result(root, sum, 0);
        return out;
    }
};

/*
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
    
    
    // v001400
    SolutionSearchRange *searchRanger = new SolutionSearchRange();
    int nums[] = {5,7,7,8,8,10};
    int nums_length = sizeof(nums) / sizeof(nums[0]) ;
    int target = 8;
    int targetRange[] = {-1, -1};
    searchRanger->SolutionSearchRange::searchRange(nums ,nums_length, target, targetRange);
    
    //arr_res = searchRanger->SolutionSearchRange::searchRange(nums ,length(nums), target);
    printf(" %d %d ",targetRange[0],targetRange[1]);
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



//数组 14















