//
//  main.cpp
//  hash_shuzu_jiaoji
//
//  Created by mingliang on 2021/1/15.
//

#include <iostream>
#include <vector>

//unordered_set
/*
 题意：给定两个数组，编写一个函数来计算它们的交集
 输入：num1= [1,2,2,1]  num2=[2,2]
 输出：num=[2]
 */
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果
        unordered_set<int> nums_set(nums1.begin(), nums1.end())
        for (int num : nums2) {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
