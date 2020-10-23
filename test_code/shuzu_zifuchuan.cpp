//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 
 
 
 
 
 
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
using namespace std;


//回溯算法思想 框架
/*
void backtrack(int i,int n,other parameters)
{
    if( i == n)
    {
        //get one answer
        record answer;
        return;
    }
    //下面的意思是求解空间第i个位置上的下一个解
    for(next ans in position i of solution space)
    {
        backtrack(i+1,n,other parameters);
    }
}
*/

//回溯算法最典型的题目：在8×8格的国际象棋上摆放八个皇后，使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列或同一斜线上，问有多少种摆法。


/*
 数组经典题目
 */
int g_number = 0;


void EightQueen()
{
    const int queens = 8;
    int ColumnIndex[queens];
    for(int i = 0; i < queens; ++ i)
        ColumnIndex[i] = i;
    Permutation(ColumnIndex, queens, 0);
}

void Permutation(int ColumnIndex[], int length, int index)
{
    if(index == length){
        if(Check(ColumnIndex, length)){
            ++g_number;
            PrintQueen(ColumnIndex, length);
        }
    }else{
        for(int i = index; i < length; ++ i){
            int temp = ColumnIndex[i];
            ColumnIndex[i] = ColumnIndex[index];
            ColumnIndex[index] = temp;
            Permutation(ColumnIndex, length, index + 1);
            temp = ColumnIndex[index];
            ColumnIndex[index] = ColumnIndex[i];
            ColumnIndex[i] = temp;
        }
    }
}

bool Check(int ColumnIndex[], int length)
{
    for(int i = 0; i < length; ++ i)
    {
        for(int j = i + 1; j < length; ++ j)
        {
            if((i - j == ColumnIndex[i] - ColumnIndex[j])
               || (j - i == ColumnIndex[i] - ColumnIndex[j]))
                return false;
        }
    }
    return true;
}



void PrintQueen(int ColumnIndex[], int length)
{
    printf("Solution %d\n", g_number);
    for(int i = 0; i < length; ++i)
        printf("%d\t", ColumnIndex[i]);
    printf("\n");
    
}


//全排列
/*
 作者：she-wo-qi-shui
 链接：https://leetcode-cn.com/problems/two-sum/solution/hui-su-suan-fa-c-by-she-wo-qi-shui/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums,res,0);
        return res;
    }
    void swap(int &a,int &b)
    {
        int temp;
        temp=a;
        a=b;
        b=temp;
    }
    void backtrack(vector<int> &nums,vector<vector<int>> &res,int i){
        if(i==nums.size())
            res.push_back(nums);
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            backtrack(nums,res,i+1);
            swap(nums[i],nums[j]);
        }
    }
};


/*
先找规律, 1 2 3分别为nums的个数不同的情况.

0 []
1 [1]
2 [1,2] [2, 1]
3 [1,2,3] [1,3,2] [3,2,1], [2,1,3] [3,1,2] [2,3,1]
不难发现规律 3依赖2,2依赖1.

3具体如何依赖2? 分几步:

1. 在2的基础上,每个vec添加元素3;[1,2]=>[1,2,3] [2,1]=>[2,1,3]
2. 再已添加3的基础上，针对每个vec,依次交换a[i]与a[end]的值，得到新的vec,并保存.
for [2,1,3] swap 2,3 => [3,1,2] swap 1,3 =>[2,3,1]
for [1,2,3] swap 1,3 => [3,2,1] swap 2,3 => [1,3,2]
3. 保存所有vec 并返回即可

作者：anribras
链接：https://leetcode-cn.com/problems/two-sum/solution/zhi-guan-qing-xi-de-di-gui-hui-su-si-lu-c-faster-t/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/


class Solutionpermute {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // []
        // [1]
        // [1,2] [2, 1]
        // [1,2,3] [1,3,2] [3,2,1], [2,1,3] [3,1,2] [2,3,1]
        //还是递归 但是vector?
        //先append 3 2 然后分别将3与前面的元素swap得到 2*2
        //vector<vector<int>> val;
        return _permute(nums , nums.size());
    }
    
    void swap(int & a, int & b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    vector<vector<int>> _permute(vector<int>& nums, int level) {
        vector<vector<int>> ret;
        if( level == 0) return ret;
        
        if(level == 1)  {
            ret.push_back(vector<int>{nums[0]});
            return ret;
        }
        
        auto last = _permute(nums, level-1);
        //append  [[1]]
        for(auto v:last) {
            v.push_back(nums[level-1]);
            ret.push_back(v);
        }
        // [[1,2]]
        //swap based on [1,2]
        auto & bk   = ret;
        //[1,2,3]
        vector<vector<int>> ret_p;
        for (auto & v:bk) {
            //[1,2,3]
            //swap 1 3  get [3,2,1]
            //swap 2,3  get [1,3,2]
            //[2,1,3]
            //swap 2 3 => [3,1,2]
            //swap 1 3 => [2,3,1]
            
            for(auto j = 0; j != v.size() -1 ; j ++) {
                auto & tmp = v;
                swap(tmp[j],tmp[tmp.size()-1]);
                ret_p.push_back(tmp);
                swap(tmp[j],tmp[tmp.size()-1]);
            }
            
        }
        //效率提升 move代替copy
        copy(move_iterator(ret_p.begin()),move_iterator(ret_p.end()),back_inserter(ret));
        
        return ret;
    }
};





/*
 经典
 
 数组题目一 ： 投票法
 
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
 
 
 复杂度解析：
 
 
 
 其他解法：
 
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
 
 数组题目二 ： 公共前缀
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-common-prefix
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 编写一个函数来查找字符串数组中的最长公共前缀。
 如果不存在公共前缀，返回空字符串 ""。
 
 示例 1:
 
 输入: ["flower","flow","flight"]
 输出: "fl"
 示例 2:
 
 输入: ["dog","racecar","car"]
 输出: ""
 解释: 输入不存在公共前缀。
 说明:
 
 所有输入只包含小写字母 a-z
 
 水平扫描法：
 
 想象数组的末尾有一个非常短的字符串，使用上述方法依旧会进行 S​S​ 次比较。优化这类情况的一种方法就是水平扫描。我们从前往后枚举字符串的每一列，先比较每个字符串相同列上的字符（即不同字符串相同下标的字符）然后再进行对下一列的比较。
 
 
 
 思路：
 循环一次 找到最短字符串
 从第一个字符串开始对比，如果一样，累加上字符串，若不一样，返回
 
 
 复杂度：  最坏n 个长度为m 的字符串
 
 m  +  m * n
 
 */

class SolutionlongestCommonPrefix {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.empty())    return ans; //输入为空，输出空ans
        int arr = strs.size();
        
        string min = strs[0];
        for(int i = 1; i < arr; ++ i) //找到最短字符串 复杂度为 最短字符串
        {
            if(strs[i].size() < min.size())
                min = strs[i];
        }
        for(int j = 0; j < min.size(); ++ j) //从第一个字符开始对比，若都一样，ans加上该字符，若不一样，返回答案；
        {
            for(int m = 0; m < arr; ++m)
            {
                if(min[j] != strs[m][j])
                    return ans;
            }
            ans = ans + min[j];
        }
        return ans;
    }
};

//class SolutionlongestSec {
//public:
//    string longestSec(vector<string>& strs) {
//        string ans = "";
//        if(strs.empty())    return ans; //输入为空，输出空ans
//        int arr = strs.size();
//
//        string first = strs[0];
//
//        for(int i = 0; i < arr; ++ i) //找到最短字符串 复杂度为 最短字符串
//        {
//           string tmp = strs[i];
//           string min = tmp.substr(i, i+1);
//           if(tmp.compare(min) != 0){
//                ans = ans + min;
//           }
//
//        strcmp(char* a，char* b)
//        }
//
//        return ans;
//    }
//};



/*
 数组题目三 ： 原地删除
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 
 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 
 示例 1:
 给定数组 nums = [1,1,2],
 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
 你不需要考虑数组中超出新长度后面的元素。
 
 
 解决思路：
 
 
 数组完成排序后，我们可以放置两个指针 ii 和 jj，其中 ii 是慢指针，而 jj 是快指针。只要 nums[i] = nums[j]，我们就增加 jj 以跳过重复项。
 
 当我们遇到 nums[j] \neq nums[i]nums[j]=nums[i] 时，跳过重复项的运行已经结束，因此我们必须把它（nums[j]nums[j]）的值复制到 nums[i + 1]nums[i+1]。然后递增 ii，接着我们将再次重复相同的过程，直到 jj 到达数组的末尾为止
 
 */




int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int j = 0; j < nums.size(); ++j) {
        if (i == 0 || nums[i-1] != nums[j]){
            nums[i++] = nums[j];
        }
    }
    return i;
}


/*
 数组题目三 ： 查找
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 你的算法时间复杂度必须是 O(log n) 级别。
 如果数组中不存在目标值，返回 [-1, -1]。
 
 示例 1:
 输入: nums = [5,7,7,8,8,10], target = 8
 输出: [3,4]
 示例 2:
 
 输入: nums = [5,7,7,8,8,10], target = 6
 输出: [-1,-1]
 
 
 思路，二分法查找 左边界，再查找右边界
 */

/*
 最简单的二分法查找模型
 
 二分法查找最重要的要素和模型
 1.循环执行条件
 2.递进方式
 3.返回值
 ---------------------
 ---------------------
 作者：labuladong
 链接：https://leetcode-cn.com/problems/two-sum/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 
 1. 这个场景是最简单的，肯能也是大家最熟悉的，即搜索一个数，如果存在，返回其索引，否则返回 -1
 
 */

int binarySearch(int nums[] , int length ,int target) {
    int left = 0;
    int right = length - 1; // 注意
    
    while(left <= right) {
        int mid = (right + left) / 2;
        if(nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1; // 注意
        else if (nums[mid] > target)
            right = mid - 1; // 注意
    }
    return -1;
}

/*
 2. 寻找左侧边界的二分搜索
 */
int left_bound(int nums[] ,int length, int target) {
    if (length == 0) return -1;
    int left = 0;
    int right = length; // 注意
    
    while (left < right) { // 注意
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid; // 注意
        }
    }
    return left;
}


class SolutionSearchRange {
public:
    // returns leftmost (or rightmost) index at which `target` should be
    // inserted in sorted array `nums` via binary search.
    int extremeInsertionIndex(int nums[] ,int length, int target, bool left) {
        int lo = 0;
        int hi = length;
        
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            printf("extremeInsertionIndex mid= %d left= %d \n",mid,left);
            if (nums[mid] > target || (left && target == nums[mid])) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }
        
        return lo;
    }
    
    int *searchRange(int nums[] ,int length, int target,int *targetRange) {
        // int targetRange[] = {-1, -1};
        int leftIdx = extremeInsertionIndex(nums, length, target, true);
        printf("searchRange_leftIdx = %d ",leftIdx);
        // assert that `leftIdx` is within the array bounds and that `target`
        // is actually in `nums`.
        if (leftIdx == length || nums[leftIdx] != target) {
            return targetRange;
        }
        targetRange[0] = leftIdx;
        targetRange[1] = extremeInsertionIndex(nums, length, target, false)-1;
        printf("targetRange %d %d \n",targetRange[0],targetRange[1]);
        return targetRange;
        
    }
};

/*
 
 数组题目四 ：  排列组合
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/permutations
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 

 
 给定一个没有重复数字的序列，返回其所有可能的全排列。
 
 示例:
 
 输入: [1,2,3]
 输出:
 [
 [1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,1,2],
 [3,2,1]
 ]
 */

/*
 数组题目四 ：  盛最多水的容器
 双指针
 */


/**
 * Container With Most Water
 * 盛最多水的容器
 */

class SolutionmaxArea {
public:
    int maxArea(vector<int> &height) {
        int maxArea = 0;
        // two pointers scan from two sides to middle
        int left = 0;
        int right = height.size()-1;
        int area;
        while ( left < right ){
            // calculate the area
            area = (right - left) * ( height[left] < height[right] ? height[left] : height[right]);
            // tracking the maxium area
            maxArea = area > maxArea ? area : maxArea;
            // because the area is decided by the shorter edge
            // so we increase the area is to increase the shorter edge
            //
            //     height[left] < height[right] ? left++ : right-- ;
            //
            // However, the above code could cause the unnecessary `area` cacluation
            // We can do some improvement as below:
            if (height[left] < height[right]) {
                do {
                    left++;
                } while (left < right && height[left-1] >= height[left]);
            } else {
                do {
                    right--;
                } while (right > left && height[right+1] >= height[right]);
            }
        }
        
        return maxArea;
    }
};




/*
 字符串经典题目
 */


/*
 v001000
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/valid-parentheses
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 
 题目：给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 
 有效字符串需满足：
 
 左括号必须用相同类型的右括号闭合。
 左括号必须以正确的顺序闭合。
 注意空字符串可被认为是有效字符串。
 
 解决思路：
 一. 判断前括号还是后括号
 
 前括号，压入。
 后括号，判断是否可以pop和是否有匹配的前括号
 二. 此时循环结束，判断栈里是否还有残留
 
 当然，中间的if对比还有可以优化的地方（可以有效减少对比的次数）
 
 
 */

class SolutionisValid {
public:
    bool isValid(string s) {
        if(s=="") return true;
        if(s.length()%2!=0) return false;
        stack<char> ss;
        for(auto i:s) {
            if (i=='{' || i=='('|| i=='[') ss.push(i);
            else {
                if (ss.size() == 0 && (i == ']' || i == '}' || i == ')')) return false;
                else if ((i == '}' && ss.top() != '{') || (i == ']' && ss.top() != '[') || (i == ')' && ss.top() != '(') )
                    return false;
                else
                    ss.pop();
            }
        }
        if (ss.size() != 0 ) return false;
        return true;
    }
};



