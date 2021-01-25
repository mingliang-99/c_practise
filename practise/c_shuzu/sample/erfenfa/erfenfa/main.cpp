#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
//
//  main.cpp
//  erfenfa
//
//  Created by mingliang on 2021/1/11.
//  有序数组，可考虑二分法
/*
 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置
 你可以假设数组中无重复元素。

 示例 1:
 输入: [1,3,5,6], 5
 输出: 2

 示例 2:
 输入: [1,3,5,6], 2
 输出: 1

 示例 3:
 输入: [1,3,5,6], 7
 输出: 4

 示例 4:
 输入: [1,3,5,6], 0
 输出: 0
 */

//移除数组-暴力法
int searchInsert(vector<int>&nums, int target){
    int size = (int)nums.size();
    for (int i = 0;i< size;i++){
        if(nums[i] == target){
            for(int j=i+1;j< size;j++){
                nums[j-1] = nums[j];
            }
            i--;
            size--;
        }
    }
    return size;
}

//移除数组-快慢指针
//1.快指针的索引为数组便利的索引
//2.慢指针的索引为返回值
//3.找到目标的时候进行覆盖
int searchInsert_double_point(vector<int>&nums, int target){
    int size = (int)nums.size();
    int slowIdx = 0;
    for (int i = 0;i< size;i++){
        if(target !=nums[i]){
            nums[slowIdx++] = nums[i];
        }
    }
    return slowIdx;
}

/*
 时间复杂度：O(logn)
 空间复杂度：O(1)
 恒定不变：左闭右闭 【left,right】
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { // 当left==right，区间[left, right]依然有效
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else { // nums[middle] == target
                return middle;
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前  [0, -1]
        // 目标值等于数组中某一个元素  return middle;
        // 目标值插入数组中的位置 [left, right]，return  right + 1
        // 目标值在数组所有元素之后的情况 [left, right]， return right + 1
        return right + 1;
    }
};

/*
 时间复杂度：O(logn)
 空间复杂度：O(1)
 恒定不变：左闭右开 【left,right）
 */
class Solution2 {
public:
    int searchInsert2(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n; // 定义target在左闭右开的区间里，[left, right)  target
        while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle; // target 在左区间，在[left, middle)中
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，在 [middle+1, right)中
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值的情况，直接返回下标
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前 [0,0)
        // 目标值等于数组中某一个元素 return middle
        // 目标值插入数组中的位置 [left, right) ，return right 即可
        // 目标值在数组所有元素之后的情况 [left, right)，return right 即可
        return right;
    }
};

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int test[]={1,3,5,6};
    int target = 2;
//    vector test_vec;
//    test
//    int res = searchInsert(test,target);
//    printf("searchInsert res = %d ",res);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
