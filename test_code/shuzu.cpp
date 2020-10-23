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

/*

两数之和：
 
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
解决方法：
 两遍hash

*/
//两遍hash
class SolutiontwoSum1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;//建立hash表存放数组元素
        vector<int> b(2,-1);//存放结果
        for(int i=0;i<nums.size();i++)
            a.insert(map<int,int>::value_type(nums[i],i));
        for(int i=0;i<nums.size();i++)
        {
            if(a.count(target-nums[i])>0&&(a[target-nums[i]]!=i))
                //判断是否找到目标元素且目标元素不能是本身
            {
                b[0]=i;
                b[1]=a[target-nums[i]];
                break;
            }
        }
        return b;
    };
};


/*
 ————————————————
 版权声明：本文为CSDN博主「花小姐的成长日记」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
 原文链接：https://blog.csdn.net/weixin_38715903/article/details/80483609
 */
vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> twoSum;
       map<int, int> tmpmap;//键值为nums的值，变量值为nums下标
     
       for (int i = 0; i < nums.size(); ++i) {
               if (tmpmap.count(nums[i]) != 0) {
                       twoSum.push_back(tmpmap[nums[i]]);
                       twoSum.push_back(i);
                       break;
                   }
               tmpmap[target - nums[i]] = i;
        }
       return twoSum;
}



/*
 最优解决
 一遍hash
 在进行迭代并将元素插入到表中的同时，我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素。如果它存在，那我们已经找到了对应解，并立即将其返回
 
 */
class SolutiontwoSum2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapping;
        
        vector<int> result;
        for(int i= 0;i<nums.size();i++){
            int other = target - nums[i];
            if(mapping.find(other) != mapping.end() && mapping[other] < i){
                result.push_back(i+1);
                result.push_back(mapping[other] + 1);
                break;
            }
            mapping[nums[i]] = i;
        }
        return result;
    };
};

class SolutiontwoSum3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;//提供一对一的hash
        vector<int> b(2,-1);//用来承载结果，初始化一个大小为2，值为-1的容器b
        for(int i=0;i<nums.size();i++)
        {
            if(a.count(target-nums[i])>0)
            {
                b[0]=a[target-nums[i]];
                b[1]=i;
                break;
            }
            a[nums[i]]=i;//反过来放入map中，用来获取结果下标
        }
        return b;
    };
};

/*
 整数翻转：
 
 作者：LeetCode
 链接：https://leetcode-cn.com/problems/reverse-integer/solution/zheng-shu-fan-zhuan-by-leetcode/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

class Solution_int {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};






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


class Solutionpermute1 {
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
//        copy(move_iterator(ret_p.begin()),move_iterator(ret_p.end()),back_inserter(ret));
        
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


//两个指针同时移动，原来的数组正常移动，如果移动的数值和前一个不相等，赋值给后面移动的数组；

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int j = 0; j < nums.size(); ++j) {
        if (i == 0 || nums[i-1] != nums[j]){//
            nums[i++] = nums[j];
        }
    }
    return i;
}


/*
 数组题目三 ： 查找
 
 二分法查找适合有序的数组查找
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
    有序的数组，[-1,0,3,5,9,12]  target=9  return 4
 
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
 2. 寻找左侧边界的二分搜索   左闭右开区间
 */
int left_bound(int nums[] ,int length, int target) {
    if (length == 0) return -1;
    int left = 0;
    int right = length; // 注意
    
    while (left < right) { // 注意
        int mid = (left + right) / 2;
        if (nums[mid] == target) {    //[1,2,2,2,3]
            right = mid;
        } else if (nums[mid] < target) { //[1,1,1,2,3]
            left = mid + 1;
        } else if (nums[mid] > target) { //[1,2,3,4,5]
            right = mid; // 注意
        }
    }
    return left;
}

/*
 作者：labuladong
 链接：https://leetcode-cn.com/problems/two-sum/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 
 寻找右侧边界
 */
int right_bound(int nums[] ,int length, int target) {
    if (length == 0) return -1;
    int left = 0;
    int right = length;
    
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) { //[1,2,2,2,3]
            left = mid + 1; // 注意
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {//[1,2,3,4,5]
            right = mid;
        }
    }
    return left - 1; // 注意
}


int search_range(int nums[], int length ,int target , vector<int> &res){
    int left = left_bound(nums,length,target);
    int right = right_bound(nums, length, target);
    res.push_back(left);
    res.push_back(right);
    return 0;
}




/*

 三数之和
 
 作者：crunch
 链接：https://leetcode-cn.com/problems/3sum/solution/3sum-using-c-by-crunch/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */

class Solution_sum {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> >res;
        sort(nums.begin(),nums.end());
        if(nums.empty() || nums.front()>0 || nums.back()<0)
            return {};
        
        for(int i=0;i<nums.size();i++){
            int fix=nums[i];
            if(fix>0)   break;
            if(i>0 && fix==nums[i-1])    continue;
            //对撞指针
            int l=i+1,r=nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]==-fix  ){
                    if(l==i+1 || r==nums.size()-1){
                        res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                        l++;r--;
                    }
                    else if(nums[l]==nums[l-1])
                        l++;
                    else if(nums[r]==nums[r+1])
                        r--;
                    else{
                        res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                        l++;r--;
                    }
                    
                }
                else if(nums[l]+nums[r]<-fix)
                    l++;
                else
                    r--;
            }
        }
        return res;
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
 回文数：
 
 思路： 将数组 左右两头分开
       每次循环获得最左或者最右数值 然后做比较
       计算好去掉左右数据所需要的div
 作者：MisterBooo
 链接：https://leetcode-cn.com/problems/palindrome-number/solution/dong-hua-hui-wen-shu-de-san-chong-jie-fa-fa-jie-ch/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
class Solution_huiwen {
public:
    bool isPalindrome(int x) {
        //边界判断
        if (x < 0) return false;
        int div = 1;
        //
        while (x / div >= 10) div *= 10;
        while (x > 0) {
            int left = x / div;
            int right = x % 10;
            if (left != right) return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
};



/*
 有效括号：
 
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 
 有效字符串需满足：
 
 左括号必须用相同类型的右括号闭合。
 左括号必须以正确的顺序闭合。
 注意空字符串可被认为是有效字符串。
 
 示例 1:
 
 输入: "()"
 输出: true
 示例 2:
 
 输入: "()[]{}"
 输出: true
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/valid-parentheses
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution_stack {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty()&&(s[i]==')'||s[i]=='}'||s[i]==']'))
                return false;    //栈空，遇到右边的括号，直接返回false
            if(s[i]==')'||s[i]=='}'||s[i]==']')  //遇到右边的括号，判断栈顶是否
            {                                 //是对应的左边的括号。
                if(s[i]-st.top()==1||s[i]-st.top()==2)
                    st.pop();   //对应的话，栈顶元素退栈。
                else
                    return false;  //不对应的话，直接返回false。
            }
            else
                st.push(s[i]);   //遇到左边的括号，进栈。
        }
        return st.empty();  //栈空，说明括号都匹配了。
    }
};


/*
 
数组题目五 ：
给定一个未排序的整数数组，找出最长连续序列的长度。
要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 解决方法：
 方法 3：哈希表和线性空间的构造
 想法
 其实我们一开始的暴力解法的思路是正确的，但是需要进行一些优化，才能达到
 O(n)
 O(n) 的时间复杂度。
 
 算法
 
 解决办法：
 如果允许O( nlogn ) ，那么可以线排序，需要复杂度 O(n)
 序列的元素是无序的，要求O(n),所以使用哈希
 unordered_map<int,bool> used;
 记录每个元素是否使用，对每个元素，以该元素为中心，往左右扩展，直到不连续位置，记录最大长度
*/

class SolutionlongestConsecutive {
     int longestConsecutive(const vector<int> &nums) {
        unordered_map<int,bool> used;
         
         for(auto i: nums){
             used[i] = false;
         }
      
         int longest = 0;
         for(auto i: nums){
             used[i] = true;
             
             int length = 0;
             //以元素为中心，往右找
             for(int j = i+1;used.find(j) != used.end();++j){
                 used[j] = true;
                 ++length;
             }
             //以元素为中心，往左找
             for(int j = i-1;used.find(j) != used.end();--j){
                 used[j] = true;
                 ++length;
             }
             longest = max(length,longest);
         }
        
        return longest;
    }
};


/*
 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 
 说明:
 
 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 示例:
 
 输入:
 nums1 = [1,2,3,0,0,0], m = 3
 nums2 = [2,5,6],       n = 3
 
 输出: [1,2,2,3,5,6]
 
 作者：ljj666
 链接：https://leetcode-cn.com/problems/merge-sorted-array/solution/cong-hou-wang-qian-xie-by-ljj666/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int tail = m + n - 1;
    --m,
    --n;
    while (m >= 0 && n >= 0) {
        if (nums1[m] > nums2[n]){
            nums1[tail--] = nums1[m--];
        }else{
            nums1[tail--] = nums2[n--];
            
        }
    }
    while (n >= 0){
        nums1[tail--] = nums2[n--];
    }
}




/*
 滑动窗口伪代码
 */
/*
string funhuadong(){
    string s, t;
    // 在 s 中寻找 t 的「最小覆盖子串」
    int left = 0, right = 0;
    string res = s;
    
    while(right < s.size()) {
        window.add(s[right]);
        right++;
        // 如果符合要求，移动 left 缩小窗口
        while (window 符合要求) {
            // 如果这个窗口的子串更短，则更新结果 res
            res = minLen(res, window);
            window.remove(s[left]);
            left++;
        }
    }
    return res;
}
*/

/*
 
 438. 找到字符串中所有字母异位词
 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
 
 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
 
 说明：
 
 字母异位词指字母相同，但排列不同的字符串。
 不考虑答案输出的顺序。
 示例 1:
 
 输入:
 s: "cbaebabacd" p: "abc"
 
 输出:
 [0, 6]
 
 解释:
 起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
 起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


vector<int> findAnagrams(string s, string t) {
    // 用数组记录答案
    vector<int> res;
    int left = 0, right = 0;
    unordered_map<char, int> needs;
    unordered_map<char, int> window;
    for (char c : t) needs[c]++;
    int match = 0;
    
    while (right < s.size()) {
        char c1 = s[right];
        if (needs.count(c1)) {
            window[c1]++;
            if (window[c1] == needs[c1])
                match++;
        }
        right++;
        
        while (match == needs.size()) {
            // 如果 window 的大小合适
            // 就把起始索引 left 加入结果
            if (right - left == t.size()) {
                res.push_back(left);
            }
            char c2 = s[left];
            if (needs.count(c2)) {//元素是要找的
                window[c2]--;// 缩小范围
                if (window[c2] < needs[c2]) // 不在查找内部，减去
                    match--;
            }
            left++;
        }
    }
    return res;
}

/*
 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 
 示例 1:
 
 输入: "abcabcbb"
 输出: 3
 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


int lengthOfLongestSubstring(string s) {
    int left = 0, right = 0;
    unordered_map<char, int> window;
    int res = 0; // 记录最长长度
    
    while (right < s.size()) {
        char c1 = s[right];
        window[c1]++;//有重复字母就会累加
        right++;
        // 如果 window 中出现重复字符
        // 开始移动 left 缩小窗口
        while (window[c1] > 1) {
            char c2 = s[left];
            window[c2]--;
            left++;
        }
        res = max(res, right - left);
    }
    return res;
}


/*
 作者：she-wo-qi-shui
 链接：https://leetcode-cn.com/problems/two-sum/solution/hui-su-suan-fa-c-by-she-wo-qi-shui/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 全排列解决方法：
 */

class Solutionpermute {
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
    //n代表数组的总数，k代表当前已经递归到第k个数
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
 最大长度子字符串
 
 str=acbcbcef，str2=abcbced，则str和str2的最长公共子串为bcbce，最长公共子串长度为5。
 
 算法思路：
 
 1、把两个字符串分别以行和列组成一个二维矩阵。
 
 2、比较二维矩阵中每个点对应行列字符中否相等，相等的话值设置为1，否则设置为0。
 
 3、通过查找出值为1的最长对角线就能找到最长公共子串
 ---------------------
 版权声明：本文为CSDN博主「南方以北」的原创文章，遵循CC 4.0 by-sa版权协议，转载请附上原文出处链接及本声明。
 原文链接：https://blog.csdn.net/qq_25800311/article/details/81607168
 
 */

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
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

示例:

输入:
[4,3,2,7,8,2,3,1]

输出:
[5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

vector<int> duplicate(vector<int> nums, int length, int *duplication){
    
    vector<int> res;
    if(length <= 0){
        return res;
    }
    //
    for(int i=0;i<nums.size();i++){ //数组内数值不能越界
        if(nums[i] <= 0 || nums[i] > length -1){
            return res;
        }
    }
    
    for(int i = 0;i< nums.size();i++){ //
        while(nums[i] !=i ){
            if(nums[i] == nums[nums[i]]){
                res.push_back(i);
                break;
            }
            int temp = nums[i];
            nums[i] =  nums[temp];
            nums[temp] = temp;
        }
    }
    return res;
}



