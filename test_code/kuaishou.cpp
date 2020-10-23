//
//  main.cpp
//  ACM
//
//  Created by yangmingliang on 19/07/08.
//  Copyright © 2019年 yangmingliang. All rights reserved.
/************************** 题解 **********************
  动态规划相关
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
#include<math.h>

#include<algorithm>
#include<cmath>
using namespace std;


/*
 一个数组中所有的数都是成对出现的只有一个或者两个数字是单独的，求这个数
 */

//一个数不同
int main()
{
    int arr[] = { 1, 1, 2, 2, 3, 3, 4 };
    int size = sizeof(arr) / sizeof(int);
    int num = 0;
    for (int i = 0; i < size; i++)
    {
        num ^= arr[i];
    }
    printf("%d\n", num);
    system("pause");
    return 0;
}

//两个数不同

void find_num(int *arr, int size)//其实现功能进行函数封装，因为是要返回两个值，C语言                                      //实现故吧这两个值打印出来
{
    int num1 = 0;
    int num2 = 0;
    int end_num = 0;
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        end_num ^= *(arr + i);
    }
    while (!(end_num & 1))
    {
        flag++;
        end_num >>= 1;
    }
    for (int i = 0; i < size; i++)
    {
        int tmp = arr[i] >> flag;
        if (tmp & 1)
        {
            num1 ^= arr[i];
        }
        else
        {
            num2 ^= arr[i];
        }
    }
    printf("num1=%d\nnum2=%d\n", num1, num2);
}
//int main()//验证阶段
//{
//    int arr[] = { 1, 1, 2, 2, 3, 3, 4, 5 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//    find_num(arr,size);
//    system("pause");
//    return 0;
//}






/*
 最小路径和
 

 最优子结构
 子问题重叠
 边界
 状态转移方程
 */

int minPath(vector<vector<int>> &arr, int m, int n){
    
    m = arr.size();
    n = arr[0].size();
    if (m == 0 || n == 0)
        return 0;
    int dp[m][n];
    dp[0][0] = arr[0][0];
    
    for (int i = 1; i < m; i ++) {
        for (int j = 1; j < n; j ++){
            if(i == 0 && j != 0){
                dp[0][j] = dp[0][j - 1] + arr[0][j];
            }
            if(i != 0 && j == 0){
                 dp[i][0] = dp[i - 1][0] + arr[i][0];
            }
            if(i == 0 && j == 0){
                 dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
            }
        }
    }
    return dp[m - 1][n - 1];
}

int minPathSum1(int arr[4][4], int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    int dp[m][n];
    dp[0][0] = arr[0][0];
    for (int i = 1; i < m; i ++)
        dp[i][0] = dp[i - 1][0] + arr[i][0];
    for (int j = 1; j < n; j ++)
        dp[0][j] = dp[0][j - 1] + arr[0][j];
    
    for (int i = 1; i < m; i ++) {
        for (int j = 1; j < n; j ++)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
    }
    
    // print array
    //    for (int i = 0; i < 4; i ++) {
    //        for (int j = 0; j < 4; j ++)
    //            cout<<dp[i][j]<<" ";
    //        cout<<endl;
    //    }
    
    return dp[m - 1][n - 1];
}


/*
 */






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

class LRUCache{
public:
    LRUCache(int capacity){
        maxsize = capacity;      // 容量
        CacheNode* head = NULL;          // 链表头指针
        CacheNode *tail = NULL;          // 链表尾指针
    }
    int get(int key);
    void set(int key, int value);
private:
    void remove(CacheNode *node);
    void setHead(CacheNode *node);
    int maxsize = 0;
    CacheNode* head = NULL;          // 链表头指针
    CacheNode *tail = NULL;          // 链表尾指针
    map<int,CacheNode *> mp;
};

//链表移除
void LRUCache::remove(CacheNode *node)
{
    if (node -> pre != NULL){            // 先节点不为null ,
        node -> pre -> next = node -> next;
    }else{ // 删除节点为头节点
        head = node -> next;
    }
    
    if (node -> next != NULL){ //后节点不为null
        node -> next -> pre = node -> pre;
    }else{//删除尾节点
        tail = node -> pre;
    }
}
//链表插入头部
void LRUCache::setHead(CacheNode *node){
    node -> next = head;  // node 放到head 前面 下一个节点
    node -> pre = NULL;
    
    if (head != NULL){
        head -> pre = node;
    }
    head = node;
    if (tail == NULL){
        tail = head;
    }
}

 int LRUCache::get(int key)
 {
     map<int, CacheNode *>::iterator it = mp.find(key);
     if (it != mp.end()){
         CacheNode *node = it -> second;
         remove(node);
         setHead(node);
         return node -> value;
     }else{
         return -1;
     }
 }
 
void LRUCache::set(int key, int value)
{
 
     map<int, CacheNode *>::iterator it = mp.find(key);
     if (it != mp.end()){
         CacheNode *node = it -> second;
         node -> value = value;
         remove(node);
         setHead(node);
     }else{
         CacheNode *newNode = new CacheNode(key, value);
         if (mp.size() >= maxsize){
             map<int, CacheNode *>::iterator iter = mp.find(tail -> key);
             remove(tail);
             mp.erase(iter);
         }
         setHead(newNode);
         mp[key] = newNode;
     }
}


