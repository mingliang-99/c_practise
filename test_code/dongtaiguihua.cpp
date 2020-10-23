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
 不同路径
 */
int uniquePaths(int m, int n) {
    if(m == 0 || n == 0) return 1;
    int ways[m][n] ; //= new int[m][n];
    for(int i = 0; i < m; i++) ways[i][0] = 1;
    for(int i = 0; i < n; i++) ways[0][i] = 1;
    
    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            ways[i][j] = ways[i-1][j] + ways[i][j-1];
    
    return ways[m-1][n-1];
}


/*
 先通过动态规划求出最小路径的值，然后根据dp二维数组倒推所走路径。参考找出最大公共子序列解法
*/

int minsum(vector<vector<int>>a, vector<int>&reg){
    vector<vector<int>>dp(a.size(), vector<int>(a[0].size(), a[0][0]));
    
    for (int i = 1; i < a.size(); i++){
        dp[i][0] = dp[i - 1][0]+a[i][0];
    }
    for (int j = 1; j < a[0].size(); j++){
        dp[0][j] = dp[0][j - 1] + a[0][j];
    }
    for (int i = 1; i < a.size(); i++){
        for (int j = 1; j < a[0].size(); j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }
    /*for (int i = 0; i < dp.size(); i++){
     for (int j = 0; j < dp[0].size(); j++){
     cout << dp[i][j] << " ";
     }
     cout << endl;
     }*/
    
    int i = dp.size() - 1;
    int j = dp[0].size() - 1;
    while (i >= 0 && j >= 0){
        reg.push_back(a[i][j]);
        if (i > 0 && j > 0){
            if (dp[i][j - 1] > dp[i - 1][j]){
                i--;
            }
            else{
                j--;
            }
            continue;
        }
        else if (i == 0){
            j--;
        }
        else{
            i--;
        }
    }
    return dp[a.size()-1][a[0].size()-1];
}



/*
 ---------------------
 作者：zw6161080123
 来源：CSDN
 原文：https://blog.csdn.net/zw6161080123/article/details/80639932
 版权声明：本文为博主原创文章，转载请附上博文链接！
 */

/*
 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 
 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 作者：LeetCode
 链接：https://leetcode-cn.com/problems/climbing-stairs/solution/pa-lou-ti-by-leetcode/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */

int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }
    int first = 1;
    int second = 2;
    for (int i = 3; i <= n; i++) {
        int third = first + second;
        first = second;
        second = third;
    }
    return second;
}




/*

 动态规划的四个要素：
 1.最优子结构
 2.子问题重叠
 3.边界
 4.子问题独立
 5.备忘录
 6.转移方程
 
 动态规划讲解说明：
 使用动态规划特征：
 1. 求一个问题的最优解
 2. 大问题可以分解为子问题，子问题还有重叠的更小的子问题
 3. 整体问题最优解取决于子问题的最优解（状态转移方程）
 4. 从上往下分析问题，从下往上解决问题
 5. 讨论底层的边界问题
 
 动态规划的思路
 1、构造问题所相应的过程。
 2、思考过程的最后一个步骤，看看有哪些选择情况。
 3、找到最后一步的子问题，确保符合“子问题重叠”，把子问题中不同样的地方设置为參数。
 4、使得子问题符合“最优子结构”。
 5、找到边界，考虑边界的各种处理方式。
 6、确保满足“子问题独立”，一般而言，假设我们是在多个子问题中选择一个作为实施方案，而不会同一时候实施多个方案，那么子问题就是独立的。
 7、考虑怎样做备忘录。
 8、分析所需时间是否满足要求。
 9、写出转移方程式
 
 
 
算法实现的说明

    动态规划的主要难点在于理论上的设计，也就是上面4个步骤的确定，一旦设计完成，实现部分就会非常简单。
    使用动态规划求解问题，最重要的就是确定动态规划三要素：

   （1）问题的阶段 （2）每个阶段的状态
   （3）从前一个阶段转化到后一个阶段之间的递推关系。

    递推关系必须是从次小的问题开始到较大的问题之间的转化，从这个角度来说，动态规划往往可以用递归程序来实现，不过因为递推可以充分利用前面保存的子问题的解来减少重复计算，所以对于大规模问题来说，有递归不可比拟的优势，这也是动态规划算法的核心之处。

    确定了动态规划的这三要素，整个求解过程就可以用一个最优决策表来描述，最优决策表是一个二维表，其中行表示决策的阶段，列表示问题状态，表格需要填写的数据一般对应此问题的在某个阶段某个状态下的最优值（如最短路径，最长公共子序列，最大价值等），填表的过程就是根据递推关系，从1行1列开始，以行或者列优先的顺序，依次填写表格，最后根据整个表格的数据通过简单的取舍或者运算求得问题的最优解。

          f(n,m)=max{f(n-1,m), f(n-1,m-w[n])+P(n,m)}

*/



/*
作者：zy_dreamer
来源：CSDN
原文：https://blog.csdn.net/zy_dreamer/article/details/9284885
版权声明：本文为博主原创文章，转载请附上博文链接！
*/

//动态题目一 　n 层台阶
// n级台阶，求多少种跳法.cpp : Defines the entry point for the console application.
//
/*
 思路：
 如果只有一级台阶，n=1,很明显只有一种跳法
 如果有两级台阶，n=2，则有两种跳法，一种是跳两下1级，一种是直接跳两级
 那么我们来看看如果有n层台阶，可以怎么跳：
 n层台阶可以是这么够成的
 1.第n层台阶是从第n-1层跳1级上来的
 2.第n层台阶是从第n-2层直接跳2级上来的
 所以可以得到n层的跳法总数是F(n)=F(n-1)+F(n-2)
 */


//备忘录法
#include <iostream>
using namespace std;
int Solve(int n,map<int,int> hash)
{
    int result = 1;
    map<int,int>::iterator iter;
    iter = hash.find(n);
    if(iter->second){
        result = iter->second;
    }else{
        if(n==1){
            hash.insert(make_pair(n,1));
            result = 1;
        }else if(n==2){
            hash.insert(make_pair(n,2));
            result = 2;
        }else{
            result = Solve(n-1,hash)+Solve(n-2,hash);
            hash.insert(n,result);
        }
    }
    return result;
}

//动态规划法
int Solve(int n)
{
    if(n==1){
        return 1;
    }else if(n==2){
        return 2;
    }
    
    int a=1;
    int b=2;
    int temp=3;

    for(int i = 3;i<n;i++){
        temp = a+b;
        a=b;
        b=temp;
    }
    return temp;
}

/*
 动态规划二  国王+ 金矿
 有一个国家发现了5座金矿，每座金矿的黄金储量不同，需要参与挖掘的工人数也不同。参与挖矿工人的总数是10人。每座金矿要么全挖，要么不挖，不能派出一半人挖取一半金矿。要求用程序求解出，要想得到尽可能多的黄金，应该选择挖取哪几座金矿？
 
 
 
 */

int getMostGold(int n, int w , int G[], int P[]){
    return 0;
}

/*
 动态题目二： 数组最大连续子序列和

如arr[] = {6,-1,3,-4,-6,9,2,-2,5}的最大连续子序列和为14。即为：9,2,-2,5

创建一个数组a，长度为原数组长度，不同位置数字a[i]代表0...i上最大连续子序列和，
 a[0]=arr[0]设置一个最大值max，初始值为数组中的第一个数字。
 当进来一个新的数字arr[i+1]时，判断到他前面数字子序列和a[i]+arr[i+1]跟arr[i+1]哪个大，
 前者大就保留前者，后者大就说明前面连续数字加起来都不如后者一个新进来的数字大，前面数字就可以舍弃
 ，从arr[i+1]开始，每次比较完都跟max比较一下，最后的max就是最大值
 */


/*
 动态规划
 */
class Solution_maxSubArray {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        int res = INT_MIN;
        int sum = -1;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum = max(nums[i], sum + nums[i]);
            res = max(sum, res);
        }
        return res;
    }
};




/*
 示例: [a, b , c, d , e]
 解答这类题目, 省略不掉遍历, 因此我们先从遍历方式说起
 
 作者：lao-hu-8
 链接：https://leetcode-cn.com/problems/two-sum/solution/xiang-xi-jie-du-dong-tai-gui-hua-de-shi-xian-yi-li/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
// Kadane算法扫描一次整个数列的所有数值，
// 在每一个扫描点计算以该点数值为结束点的子数列的最大和（正数和）。
// 该子数列由两部分组成：以前一个位置为结束点的最大子数列、该位置的数值。
// 因为该算法用到了“最佳子结构”（以每个位置为终点的最大子数列都是基于其前一位置的最大子数列计算得出,
// 该算法可看成动态规划的一个例子。
// 状态转移方程：sum[i] = max{sum[i-1]+a[i],a[i]}
// 其中(sum[i]记录以a[i]为子序列末端的最大序子列连续和)

int maxSubArray2(int nums[]) {
    
    int length = sizeof(nums)/sizeof(nums[0]);
    
    if (!length) {
        return -1;
    };
    // 在每一个扫描点计算以该点数值为结束点的子数列的最大和（正数和）。
    int max_ending_here = nums[0];
    int max_so_far = nums[0];
    
    for (int i = 1; i < length; i ++ ) {
        // 以每个位置为终点的最大子数列 都是基于其前一位置的最大子数列计算得出,
        
        max_ending_here = max( nums[i], max_ending_here + nums[i]);
        max_so_far = max ( max_so_far, max_ending_here);
    };
    
    return max_so_far;
};




static int MaxContinueArraySum(int a[]) {
    int length = 0;
    int n = length=sizeof(a)/sizeof(a[0]);
    int max = a[0];
    int sum = a[0];
    for(int i=1;i<n;i++){
        sum = max(sum+a[i], a[i]);
        if(sum>=max){
            max = sum;
        }
    }
    return max;
}


/*
 题目：
 作者：zw6161080123
 来源：CSDN
 原文：https://blog.csdn.net/zw6161080123/article/details/80639932
 版权声明：本文为博主原创文章，转载请附上博文链接！
 
 两个字符串最大公共子序列
 
 比如字符串1：BDCABA；字符串2：ABCBDAB，则这两个字符串的最长公共子序列长度为4，最长公共子序列是：BCBA
 
 解决方法：
 动态规划解法：
 
 先创建一个解空间即数组，因为给定的是两个字符串即两个一维数组存储的数据，所以要创建一个二维数组，设字符串X有n个值，字符串Y有m个值，需要创建一个m+1*n+1的二维数组，
 二维数组每个位置（i，j）代表当长度为i的X子串与长度为j的Y的子串他们的最长公共子串，之所以要多创建一个是为了将边界值填入进去，
 边界值就是第一行跟第一列，指X长度为0或者Y长度为0时，自然需要填0，其他位置填数字时，
 当这两个位置数字相同，dp[i][j] = dp[i-1][j-1]+1；
 当这两个位置数字不相同时，dp[i][j] = Math.max(dp[i][j-1], dp[i-1][j])。
 最后二维数组最右下角的值就是最大子串
 ---------------------
 */

/*
 ---------------------
 版权声明：本文为CSDN博主「南方以北」的原创文章，遵循CC 4.0 by-sa版权协议，转载请附上原文出处链接及本声明。
 原文链接：https://blog.csdn.net/qq_25800311/article/details/81607168
 算法思路：
 
 1、把两个字符串分别以行和列组成一个二维矩阵。
 2、比较二维矩阵中每个点对应行列字符中否相等，相等的话值设置为1，否则设置为0。
 3、通过查找出值为1的最长对角线就能找到最长公共子串。
 针对于上面的两个字符串我们可以得到的二维矩阵如下：
 
 为了进一步优化算法的效率，我们可以再计算某个二维矩阵的值的时候顺便计算出来当前最长的公共子串的长度，即某个二维矩阵元素的值由record[i][j]=1演变为record[i][j]=1 +record[i-1][j-1]，这样就避免了后续查找对角线长度的操作了。修改后的二维矩阵如下

 
 */
int getLCS(char s1[],char s2[])
{
    int s1_size = (sizeof(s1)/sizeof(s1[0]));
    int s2_size = (sizeof(s2)/sizeof(s2[0]));
    
    int dp[s1_size][s2_size];
    int i,j,max_len=0;

    for(i=0;i<s1_size;i++){
       for(j=0;j<s2_size;j++){
            if(s1[i]==s2[j]){
                if(i>0 && j>0){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=1;
                }
                if(max_len<dp[i][j]){
                    max_len=dp[i][j];
                }
            }
        }
    }
    return max_len;
}
//---------------------
//版权声明：本文为CSDN博主「rs勿忘初心」的原创文章，遵循CC 4.0 by-sa版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/sinat_33718563/article/details/72773088



string getLCS(string str1, string str2) {
    vector<vector<int> > record(str1.length(), vector<int>(str2.length()));
    int maxLen = 0, maxEnd = 0;
    for(int i=0; i<static_cast<int>(str1.length()); ++i)
        for (int j = 0; j < static_cast<int>(str2.length()); ++j) {
            if (str1[i] == str2[j]) {
                if (i == 0 || j == 0) {
                    record[i][j] = 1;
                }
                else {
                    record[i][j] = record[i - 1][j - 1] + 1;
                }
            }
            else {
                record[i][j] = 0;
            }
            
            if (record[i][j] > maxLen) {
                maxLen = record[i][j];
                maxEnd = i; //若记录i,则最后获取LCS时是取str1的子串
            }
        }
    return str1.substr(maxEnd - maxLen + 1, maxLen);
}


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

//动态规划
//https://leetcode-cn.com/problems/coin-change/solution/dong-tai-gui-hua-tao-lu-xiang-jie-by-wei-lai-bu-ke/

