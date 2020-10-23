//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
链表题目集合
 
 ************************* 题解 ***********************/
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
#include<map>
using namespace std;
#define LYTEST  1
 //链表题目集合

/************************** 最小子模块 **********************

 
 ************************* 最小子模块 ***********************/
//Definition for singly-linked list.




//---------------------

struct ListNode {
    int val;
    int num;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*
 两数相加：
 
 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 
 示例：
 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 输出：7 -> 0 -> 8
 原因：342 + 465 = 807
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/add-two-numbers
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        int sum;
        while (l1 || l2){
            sum = 0;
            if (l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        if (carry > 0)
            curr->next = new ListNode(carry);
        return dummyHead->next;
    }
};



//固定位置插入链表节点
/*
 插入指定节点的后面（此例是指定学号的节点）
 */
struct ListNode *insert_node(struct ListNode *head, int num)
{
    struct ListNode *p;
    p=head;       // 指针p指向第一个节点
    int index = 0;
    struct ListNode *s = (struct ListNode*)malloc(sizeof(struct ListNode));    //  待插入的结点s
    if(head==NULL)
    {
        head=s;
        s->next=NULL;  //当链表为空时，新节点作为头结点插入
        return head;
    }
    else
    {
        while(p->next!=NULL)//p指向的结点不是所查找的，并且不是最后一个结点，继续往下找
        {
            p=p->next;
            index++;
            if(index == num){
                /*找到了想要插入的位置*/
                s->next=p->next; //原来链表位置断开，链接到新节点的后面
                p->next=s;//新的节点更新到原来断开链表的尾部
            }
            return head;
        }
        
    }
    
    return head;
}


struct ListNode *delete_node(struct ListNode* head,int num)
{
    struct ListNode *p,*s;
    if(head==NULL) /* 当链表为空时*/
    {
        printf("链表为空");
    }
    s=head; /*指针s指向第一个节点，从表头开始查找*/
    while(num!=s->num&&s->next!=NULL) /*查找的节点不是想要的且还没到达表尾*/
    {
        p=s;s=s->next; /*指针后移*/
    }
    if(num==s->num){ /*找到删除的节点*/
        if(s==head){
            head=s->next; /*当删除的是头结点时*/
        }else{
            p->next=s->next; /*当删除的节点不是头节点时*/
        }
        printf("已经删除：%d\n",num);
        free(s); /*释放删除节点的内存*/
    }
    else printf("%d 表中无此点",num); /*当找不到符合的节点时*/
    return head;
}


/*
作者：ivan_allen
链接：https://leetcode-cn.com/problems/two-sum/solution/148-pai-xu-lian-biao-bottom-to-up-o1-kong-jian-by-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

ListNode* cut(ListNode* head, int n) {
    auto p = head;
    while (--n && p) {
        p = p->next;
    }
    
    if (!p) return nullptr;
    
    auto next = p->next;
    p->next = nullptr;
    return next;
}

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummyHead(0);
    auto p = &dummyHead;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            p = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            p = l2;
            l2 = l2->next;
        }
    }
    p->next = l1 ? l1 : l2;
    return dummyHead.next;
}


/************************** 最小子模块 **********************
 
 
 ************************* 最小子模块 ***********************/







/*
 
 链表题目一： 反转一个单链表。
 
 作者：sunshy
 链接：https://leetcode-cn.com/problems/two-sum/solution/die-dai-di-gui-jie-fa-by-sunshy/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

 //链表反转
 ListNode* ReverseList2(ListNode* head)
 {
     if (head == nullptr){
         return nullptr;
     }
     ListNode* reverseHead = nullptr;
     // 指针1：当前节点
     ListNode* cur = head;
     // 指针2：当前节点的前一个节点
     ListNode* pre = nullptr;
 
     while(cur != nullptr){
         // 指针3：当前节点的后一个节点
         ListNode* next = cur->next;
         if(next == nullptr){
             reverseHead = cur;
         }
         // 将当前节点的后一个节点指向前一个节点
         cur->next = pre; // 1-> null ;
         // 将前一个节点指向当前节点
         pre = cur; // pre = 1;
         // 将当前节点指向后一个节点
         cur = next; // cur = 2;
     }
     return reverseHead;
 }


/*
 链表题目二： 环形链表
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/linked-list-cycle
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 给定一个链表，判断链表中是否有环。
 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
 
  
 示例 1：
 
 输入：head = [3,2,0,-4], pos = 1
 输出：true
 解释：链表中有一个环，其尾部连接到第二个节点。
 
 
 示例 2：
 
 输入：head = [1,2], pos = 0
 输出：true
 解释：链表中有一个环，其尾部连接到第一个节点。
 
 
 示例 3：
 
 输入：head = [1], pos = -1
 输出：false
 解释：链表中没有环。
 

 进阶：
 
 你能用 O(1)（即，常量）内存解决此问题吗？
 
 解决思路：
 
 通过使用具有 不同速度 的快、慢两个指针遍历链表，空间复杂度可以被降低至 O(1)O(1)。慢指针每次移动一步，而快指针每次移动两步。
 
 如果列表中不存在环，最终快指针将会最先到达尾部
 
 java:
 */

class SolutionhasCycle {
public:
    bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
    }
    
};




/*
 链表题目三： 删除链表倒数n 个节点
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 
 示例：
 
 给定一个链表: 1->2->3->4->5, 和 n = 2.
 
 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 说明：
 
 给定的 n 保证是有效的。
 
 进阶：
 
 你能尝试使用一趟扫描实现吗？
 
 思路 ：
 1.使用两个指针，第一个指针先移动 n+1 ，第二个指针从头开始移动 ，保持固定间隔
 2.第一个指针移动到最后的节点，第二个指针指向最后一个节点开始倒数第n 个节点。
 3.重新链接第二个指针所应用节点的 next 指针的下下个节点
 
 
 时间复杂度 O(n)
 空间复杂度 O(1)
 
 */


class SolutionremoveNth {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        
        if(!head || !(head -> next))   return NULL;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first = dummy;
        ListNode *second = dummy;
        // Advances first pointer so that the gap between first and second is n nodes apart
        for (int i = 0; i <= n - 1; i++) {
            if(first->next != nullptr){
                first = first->next;
            }else{
                return nullptr;
            }
            
        }
        // Move first to the end, maintaining the gap
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    };
    
};





/*
 链表题目四： 合并两个有序列表
 
 作者：bigcat-4
 链接：https://leetcode-cn.com/problems/two-sum/solution/he-bing-liang-ge-you-xu-lian-biao-guan-fang-cban-b/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 
 合并两个有序列表
 
 思路
 1.如果L1 == NULL 或者 L2 == NULL ，就没有必要合并
 2.判断L1 或者 L2 哪个更小，递归决定给到下一个数值
 3.链表都是NULL 就终止
 
 */


//递归
class SolutionmergeTwoLists {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        else if (l2 == NULL) return l1;
        else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};


//迭代
/*
 作者：abigcat
 链接：https://leetcode-cn.com/problems/two-sum/solution/he-bing-liang-ge-you-xu-lian-biao-guan-fang-cban-b/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
class Solution_mergeTwoLists {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* prehead = new ListNode(-1);
        ListNode* prev = prehead;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 != NULL ? l1 : l2;
        
        return prehead->next;
    }
};




/*
 链表题目五： 链表交换
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表
 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 
 示例:
 
 给定 1->2->3->4, 你应该返回 2->1->4->3.
 
 解决方法，没有理解， 待处理
 https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/hua-jie-suan-fa-24-liang-liang-jiao-huan-lian-biao/
 
 */

/*
使用一个虚拟节点dummy，其next指针指向头节点：ListNode* dummy = new ListNode(0); dummy->next = head;
定义三个ListNode*指针：pre、cur、next
举例说明：1->2->3->4
通过创建虚拟节点dummy，链表为 0->1->2->3->4

初始： pre = dummy(值为0)，cur = head(值为1)， next = cur->next(值为2）：pre(0)->cur(1)->next(2)
                                                       
交换过程：

pre ->next = next; : 0 -> 2
cur ->next = next->next; : 1 -> 3
next->next = cur; : 2 -> 1
更新后的链表为 0->2->1->3->4
更新指针：pre = cur(值为1)，cur = cur->next(值为3)，next = cur->next(值为4)

重复交换过程。。。

终止条件：

cur == NULL 要判断的条件：
cur 不为空时才进行 next = cur->next
交换过程中当next 不为空时才进行 cur ->next = next->next
返回值： dummy->next
 */
                                                       
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
 作者：fly_sky
 链接：https://leetcode-cn.com/problems/two-sum/solution/c-jie-fa-die-dai-xiang-jie-by-fly_sky/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 
 举例说明：1->2->3->4
 通过创建虚拟节点dummy，链表为 0->1->2->3->4
 
 pre ->next = next; : 0 -> 2
 cur ->next = next->next; : 1 -> 3
 next->next = cur; : 2 -> 1
 更新后的链表为 0->2->1->3->4
 更新指针：pre = cur(值为1)，cur = cur->next(值为3)，next = cur->next(值为4)

 */

class SolutionswapPairs {
public:
   ListNode* swapPairs(ListNode* head) {
       ListNode* dummy = new ListNode(0);
       ListNode* pre = dummy;
       dummy->next = head;
       
       ListNode* cur = head;
       
       while( cur != NULL)
       {
           ListNode* next = cur->next;
           if(next == NULL)
               break;
           
           pre -> next = next;
           cur -> next = next -> next;
           next-> next = cur;
           
           pre = cur;
           cur = cur -> next;
       }
       
       return dummy->next;
       
   }
};
                                                       


/*
 
题目六： 链表排序
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/sort-list
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5

 
 #### 解题思路 ######
 作者：paomiange
 链接：https://leetcode-cn.com/problems/two-sum/solution/148-pai-xu-lian-biao-javajie-fa-gui-bing-pai-xu-by/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 
 
 题目要求排序算法的时间复杂度为 O(n log n) ，空间复杂度为 O(n) ，直接想到 归并排序。
 
 归并排序 是采用分治法的一种排序算法：
 
 分，就是把数列一分二，二分四...最后分成两两一组的最小子集
 治，就是把分开后的子集，一一排序后归并在一起
 最后由局部有序成为全部有序，和数组的归并排序相比，链表多出的一步就是如何找到链表的中点？
 
 利用快慢指针找到链表的中点，利用递归的方式进行分组排序。

 
 /**
 参考如下：
 作者：paomiange
 链接：https://leetcode-cn.com/problems/two-sum/solution/148-pai-xu-lian-biao-javajie-fa-gui-bing-pai-xu-by/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class SolutionsortList {
public:
    ListNode* sortList(ListNode* head) {
        //边界调节 剩余两个节点为止
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        //找到中间节点
        ListNode *mid = findMid(head);
        //右边链表递归操作
        ListNode *right = sortList(mid->next);
        //链表切割
        mid->next = nullptr;
        //左边链表递归操作
        ListNode *left = sortList(head);
        //合并
        return merge(left, right);
    }
    
    /**
     *  快慢指针找出中的节点
     */
    ListNode* findMid(ListNode *node) {
        ListNode *fast = node->next;
        ListNode *slow = node;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    /**
     * 对两组链表进行归并排序
     */
    ListNode* merge(ListNode *l1, ListNode *l2) {
        ListNode* p = new ListNode(0);
        //两个链表都不为null
        while(l1!=NULL && l2!= NULL){
            if(l1->val < l2->val){
                p->next = l1; //l1  链接到p->next
                p = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
 
        }
        //有一个链表为null
        p->next = l1 ? l1 : l2;
        return p->next;
    }
    
};
    
   /*
    作者：gpe3DBjDS1
    链接：https://leetcode-cn.com/problems/two-sum/solution/pai-xu-lian-biao-by-gpe3dbjds1/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    
class Solutionmergesort {
public:
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
    ListNode* mergesort(ListNode* node)
    {
        if(!node || !node->next) return node;
        ListNode *fast=node;//快指针走两步
        ListNode *slow=node;//慢指针走一步
        ListNode *brek=node;//断点
        while(fast && fast->next)
        {
            fast=fast->next->next;
            brek=slow;
            slow=slow->next;
        }
        brek->next=nullptr;
        ListNode *l1=mergesort(node);
        ListNode *l2=mergesort(slow);
        return merge(l1,l2);
    }
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        if(l1->val < l2->val)
        {
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=merge(l2->next,l1);
            return l2;
        }
    }
};


/*
 设置三个指针tail，p，cur；p和tail用于控制外循环的次数，cur用于内循环。
 
 1. 排序开始前遍历一次单链表将tail指向尾结点的指针域，即NULL。cur和p均指向头结点。
 2. 比较cur->data与cur->next->data的大小，若前者大于后者则交换；否则不交换，之后cur指针右移，继续比较cur->data与cur->next->data的大小，直至cur->next==tail。
 3. 一次循环之后，将tail指向cur的位置，即相当于tail前移。将cur重新指向头结点，重复步骤2。
 4. 直至p->next==tail结束整个循环。
   由于需要被冒泡排序的链表不一定十分杂乱无序，有可能经过s少量几次循环后就会有序，不需要经过大量的循环，所以为了减少循环次数，设置一个变量flag，flag初始值为0，若在某一次循环中有元素与元素间的交换，flag变为1，如果没有元素的交换，证明这次循环单链表已经有序，flag不变，依旧为0。没经历一次循环判断flag的大小是否为0，若为0，直接跳出整个循环。
 ---------------------
 作者：zhao_miao
 来源：CSDN
 原文：https://blog.csdn.net/zhao_miao/article/details/81708454
 版权声明：本文为博主原创文章，转载请附上博文链接！
 
 时间复杂度：O(N平方)
 每次需要的循环是 n + (n - 1) + (n -2 ) .... + 1 = n(n-1) / 2 = n^2 ;
 空间复杂度：O（1）
 
 */

// 题目七：冒泡排序
#define DataType int
typedef struct Node{
    DataType data;
    struct Node* next;
}linklist;

void LinkListBubblesort(linklist *head)
{
    linklist *cur = head;
    linklist *tail = head;
    linklist *p = head;
    
    DataType node = 0;
    int length = 0;
    int flag = 0;
    
    //尾结点,tail指向空
    while (tail != NULL)
    {
        tail = tail->next;
    }
    //外循环，循环链表长度-1次
    while (p->next!=tail)
    {
        flag = 0;
        cur = head;
        while (cur->next != tail)
        {
            if (cur->data > cur->next->data)
            {
                //前后交换
                node = cur->data;
                cur->data = cur->next->data;
                cur->next->data = node;
                flag = 1;
            }
            cur = cur->next;
        }
        //尾指针向前移动
        tail = cur;
        //若为1，则证明链表已经有序
        if (flag == 0)
        {
            return;
        }
    }
}

//冒泡法数组实现
/*
int times = 0;
int function(int arr[]) {

    for (var i = 0; i < arr.length - 1; i++) {
        for (var j = i + 1; j < arr.length; j++) {
            if (arr[i] > arr[j]) { //如果前面的数据比后面的大就交换
                var temp = arr[i];//临时缓存
                arr[i] = arr[j];
                arr[j] = temp;
            }
            console.log("第" + (++times) + "次排序后：" + arr);
        }
    }
    return arr;
}
console.log("The result is:" + bubbleSort(arr));
*/
/*
 */

/*
 
题目八：什么是快排

 采用分治策略，一次排序后，将数据划分为两半，一半比某一个数小，另一半比某个数大。
 利用递归，完成对数组的排序
 
快排特点
实现思路
    找到一个支点，两个哨兵p ,q ,取链表第一个当作支点，哨兵p 取第一个元素当作支点，q 继续前行
    ，当遇到 q < p 的时候，做数据交换；

//链表快排
//思想
//时间复杂度
 O（n * logn ）
 最差 O （n ^2 ）
 
//空间复杂度
*/

ListNode* partition(ListNode* start,ListNode* end){
    int num = start->val;
    ListNode* p = start;
    ListNode* q = start->next;
    while(q != end){
        if(q->val < num){
            p = p->next;
            swap(p->val,q->val);
        }
        q = q->next;
    }
    swap(p->val,start->val);
    return p;
}


void quick_sort(ListNode* start,ListNode* end){
    if(start != end){
        ListNode* index = partition(start,end);
        quick_sort(start,index);
        quick_sort(index->next,end);
    }
}


/*
 快排：
（1）左右指针法：
 两个指针，指向数组下标，找一个定值，让其它数与它比较，
 在两个指针相遇之前，左边指针找比这个数大的，右边指针找比这个数小的，交换这两个指针指向的值；
 返回相遇下标值，这样将数据划分为两部分，然后对左半边进行quickSort，对右半边进行quickSort
 。
代码如下：
---------------------
版权声明：本文为CSDN博主「ValDC_Morning」的原创文章，遵循CC 4.0 by-sa版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/ValDC_Morning/article/details/76615752
*/
#include <iostream>
#include <assert.h>
using namespace std;

int PartSort(int *a, int begin, int end)//左右指针法
{
    //int key = GetMid(a, begin, end);//选取数据的优化
    int key = end;
    while (begin < end)
    {
        while (a[begin] <= a[key] && begin<end)
        {
            begin++;
        }
        while (a[end] >= a[key] && begin<end)
        {
            end--;
        }
        if (begin < end)
        {
            swap(a[begin], a[end]);
        }
    }
    
    swap(a[begin], a[key]);
    return begin;
}

void QuickSort(int* a, int start, int end)
{
    assert(a);
    if (start < end){
        int div = PartSort(a, start, end - 1);
        QuickSort(a, start, div);
        QuickSort(a, div + 1, end);
    }
}

int main()
{
    int arr[] = { 3, 6, 8, 1, 7, 9, 5, 2,4 };
    int len = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, len);
    for (int i = 0; i <len; i++)
    {
        printf("%d ", arr[i]);
        
    }
    printf("\n");
    system("pause");
    return 0;
}



/*
 左右指针轮流坐坑
 ---------------------
 版权声明：本文为CSDN博主「ValDC_Morning」的原创文章，遵循CC 4.0 by-sa版权协议，转载请附上原文出处链接及本声明。
 原文链接：https://blog.csdn.net/ValDC_Morning/article/details/76615752
 */
int PitSort(int* a, int left, int right)//left和right轮流做坑
{
    int key = a[right];
    while (left < right)
    {
        while (a[left] <= key&&left<right)
        {
            ++left;
        }
        a[right] = a[left];
        while (a[right] >= key&&left < right)
        {
            --right;
        }
        a[left] = a[right];
    }
    a[left] = key;
    return left;
}





//题目九：链表相交叉

//两个单链表交叉只能是Y型，所以可以通过判断最后一个节点是否为同一个节点来判断是否交叉
bool IsCross(Node *head1, Node *head2)
{
    if (!head1 || !head2) {
        return false;
    }
    
    Node *p1 = head1;
    Node *p2 = head2;
    while (p1->next) {
        p1 = p1->next;
    }
    while (p2->next) {
        p2 = p2->next;
    }
    
    return (p1 == p2);
}

//找到交叉点
Node *FindCross(Node *head1, Node *head2)
{
    if (!head1 || !head2) {
        return NULL;
    }
    
    /* 求出两个链表的长度 */
    Node *p1, *p2;
    p1 = head1;
    p2 = head2;
    int len1, len2, len;
    len1 = len2 = 0;
    while (p1) {
        len1++;
        p1 = p1->next;
    }
    while (p2) {
        len2++;
        p2 = p2->next;
    }
    
    /* 将长链表先移动len个结点 */
    int i;
    len = abs(len1 - len2);
    p1 = head1;
    p2 = head2;
    if (len1 > len2) {
        for (i = 0; i < len; ++i) {
            p1 = p1->next;
        }
    } else {
        for (i = 0; i < len; ++i) {
            p2 = p2->next;
        }
    }
    
    /* 遍历 找到第一个相等的结点即为交点 */
    while (!p1) {
        p1 = p1->next;
        p2 = p2->next;
        if (p1 == p2) {
            return p1;
        }
    }
    
    return NULL;
}

/*

 作者：hu-er
 链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-c-yu-yan-shi-xian-by-hu-er/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 
 最直接解决方法
 
 */

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL)return NULL;
    struct ListNode *a = headA;
    struct ListNode *b = headB;
    while(a != b){
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }
    return a;
}



/*
LRU Cache具备的操作：
https://www.cnblogs.com/cpselvis/p/6272096.html
 
set(key,value)：
如果key在hashmap中存在，则先重置对应的value值，然后获取对应的节点cur，将cur节点从链表删除，并移动到链表的头部；若果key在hashmap不存在，则新建一个节点，并将节点放到链表的头部。当Cache存满的时候，将链表最后一个节点删除即可。
get(key)：如果key在hashmap中存在，则把对应的节点放到链表头部，并返回对应的value值；如果不存在，则返回-1
*/

struct CacheNode {
    int key;      // 键
    int value;    // 值
    CacheNode *pre, *next;  // 节点的前驱、后继指针
    CacheNode(int k, int v) : key(k), value(v), pre(NULL), next(NULL) {}
};

int LRUCache(int capacity)
{
    int size = capacity;      // 容量
    CacheNode* head = NULL;          // 链表头指针
    CacheNode *tail = NULL;          // 链表尾指针
    return 0;
}

//链表删除
void remove(CacheNode *head,CacheNode *tail,CacheNode *node)
{
    if (node -> pre != NULL){
        node -> pre -> next = node -> next;
    }else{
        head = node -> next;
    }
    
    if (node -> next != NULL){
        node -> next -> pre = node -> pre;
    }else{
        tail = node -> pre;
    }
}
//链表插入头部
void setHead(CacheNode *head,CacheNode *tail,CacheNode *node){
    node -> next = head;
    node -> pre = NULL;
    
    if (head != NULL){
        head -> pre = node;
    }
    head = node;
    if (tail == NULL){
        tail = head;
    }
}
/*
int get(int key)
{
    map<int, CacheNode *>::iterator it = mp.find(key);
    if (it != mp.end())
    {
        CacheNode *node = it -> second;
        remove(node);
        setHead(node);
        return node -> value;
    }
    else
    {
        return -1;
    }
}

void set(int key, int value)
{
    map<int, CacheNode *>::iterator it = mp.find(key);
    if (it != mp.end())
    {
        CacheNode *node = it -> second;
        node -> value = value;
        remove(node);
        setHead(node);
    }
    else
    {
        CacheNode *newNode = new CacheNode(key, value);
        if (mp.size() >= size)
        {
            map<int, CacheNode *>::iterator iter = mp.find(tail -> key);
            remove(tail);
            mp.erase(iter);
        }
        setHead(newNode);
        mp[key] = newNode;
    }
}
*/

/*
 链表删除节点
 ————————————————
 版权声明：本文为CSDN博主「为心而斗」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
 原文链接：https://blog.csdn.net/qq_33575542/article/details/80645449
*/
void DeleteOneNode(ListNode **pHead, ListNode *pNode)
{
    if (pHead == nullptr || pNode != nullptr)
        return;
    
    //不是尾节点
     if (pNode->next != nullptr){
        ListNode *pNext = pNode->next;
        pNode->val = pNext->val;
        pNode->next = pNext->next;
        delete pNext;
        pNext = nullptr;
    }//该链表仅一个节点
    else if (*pHead == pNode){
        delete pNode;
        pHead = nullptr;
        pNode = nullptr;
    }
    //要删除的节点为尾节点
    else{
        ListNode *pTmpNode = *pHead;
        while (pTmpNode->next != pNode){
                pTmpNode = pTmpNode->next;
        }
        pTmpNode->next = nullptr;
        pNode = nullptr;
    }
}


/*

 链表删除重复节点
 ————————————————
 版权声明：本文为CSDN博主「为心而斗」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
 原文链接：https://blog.csdn.net/qq_33575542/article/details/80645449

 */

/*
 struct ListNode {
 int val;
 struct ListNode *next;
 ListNode(int x) :
 val(x), next(NULL) {
 }
 };
 */
class Solution_deleteDuplication {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        // 链表有0个/1个节点，返回第一个节点
        if(pHead==NULL||pHead->next==NULL)
            return pHead;
        else
        {
            // 新建一个头节点，防止第一个结点被删除
            ListNode* newHead=new ListNode(-1);
            newHead->next=pHead;
            
            // 建立索引指针
            ListNode* p=pHead;      // 当前节点
            ListNode* pre=newHead;  // 当前节点的前序节点
            ListNode* next=p->next;    // 当前节点的后序节点
            
            // 从头到尾遍历编标
            while(p!=NULL && p->next!=NULL)
            {
                if(p->val==next->val)//如果当前节点的值和下一个节点的值相等
                {
                    // 循环查找，找到与当前节点不同的节点
                    while(next!=NULL && next->val==p->val)
                    {
                        ListNode* temp=next;
                        next=next->next;
                        
                        // 删除内存中的重复节点
                        delete temp;
                        temp = nullptr;
                        
                    }
                    pre->next=next;
                    p=next;
                }
                else//如果当前节点和下一个节点值不等，则向后移动一位
                {
                    pre=p;
                    p=p->next;
                }
                next=p->next;
            }
            return newHead->next;//返回头结点的下一个节点
        }
    }
};


/*
 链表删除节点
 */
#include <iostream>

/*
 链表清除
 */
void clear(ListNode *pHead)
{
    if(pHead ==nullptr)
        return;
    
    ListNode* head = pHead;
    ListNode* pNext = nullptr;
    while(head!=nullptr)
    {
        pNext = head->next;
        delete head;
        head = pNext;
    }
}
    
bool removeNode(ListNode*& head,ListNode*& node)
{
    if(!node)
        return false;
    if(node->next !=nullptr ){ //节点不在尾部
        ListNode* pNext = node->next;
        node->val = pNext->val;
        node->next = pNext->next; //下一个节点的数值给予上一个节点
        delete pNext;
        pNext = nullptr;
        return true;
    }else if(head == node){//删除节点在头部
        delete node;
        node = nullptr;
        head = nullptr;
        return true;
    }//删除的node在尾部或者不在
    else
    {
        
        ListNode* pCur = head;
        while(pCur->next != node && pCur !=nullptr){
            pCur = pCur->next;
        }
        //删除节点是否在尾部
        if(pCur!=nullptr){
            pCur->next =nullptr;
            delete node;
            node = nullptr;
            return true;
        }
        return false;
    }
    
}

/*
请判断一个链表是否为回文链表。
 
 1.快慢指针找到中间节点
 2.后半部分链表反转；
 3.再做链表遍历，看数值是否相等

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
*/

class Solution_isPalindrome {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;   //空链表表或链表只有一个元素
        ListNode *slow=head,*fast=head;       //快慢指针
        for(; fast&&fast->next ; fast=fast->next->next,slow=slow->next); //快慢指针迭代找中点
        ListNode *cur=slow,*nex=nullptr,*back = nullptr;            //back表示后半链表头指针
        for( ; cur ; nex=cur->next, cur->next=back, back=cur, cur=nex);  //反转后半链表
        for(ListNode* front=head ; front&&back ; front=front->next,back=back->next) //front:前半链表头指针
            if(back->val!=front->val) return false;   //前半链表与后半链表逐元素比较
        return true;
    }
};


/*
 移动零
 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 
 示例:
 
 输入: [0,1,0,3,12]
 输出: [1,3,12,0,0]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/move-zeroes
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */
void moveZeroes(vector<int>& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}




    
//    ListNode():_value(-1),pNext(nullptr){}
//    ListNode(int value):_value(value),pNext(nullptr){}
//    int _value;
//    ListNode * pNext;
//
//};
//ostream& operator <<(ostream&os,ListNode& head)
//{
//    ListNode* node = &head;
//    if(node == nullptr)
//        return os;
//    while(node->pNext!=nullptr)
//    {
//        os<<node->_value<<" ";
//        node = node->pNext;
//    }
//    os<<node->_value;
//    return os;
//}
//
//
//int main()
//{
//    ListNode* number1 = new ListNode(1);
//    ListNode* number2 = new ListNode(2);
//    ListNode* number3 = new ListNode(3);
//    ListNode* number4 = new ListNode(4);
//    number3->pNext = number4;
//
//
//    cout <<"delete number1 in number1 before:"<<*number1<<endl;
//    number1->removeNode(number1);
//    cout <<"delete number1 in number1 after:"<<*number1<<endl;
//
//    number1->removeNode(number2);
//    cout <<"delete number2 in number1 after:"<<*number1<<endl;
//
//    number3->removeNode(number4);
//    cout <<"delete number3 in number1 after:"<<*number3<<endl;
//
//
//    return 0;
//}


/*
 
 题目十：top n
 首先，第一个冒出来的想法是——排序。各种排序算法对数组进行一次sort，然后limit出max的100个即可，时间复杂度为O(nLogN)。
 
 */

/*
 扔鸡蛋
 
 最短路径
 
 最长路径
 
 Lru 缓存
 */























