//
//  main.cpp
//  hash_zimu_yiwei
//
//  Created by mingliang on 2021/1/15.
//

#include <iostream>
#include <string>
/*
 
 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词
 输入 s = "rat"  , t = "car"
 输出 false
 
 输入 s = "agra" , t = "graa"
 输出 true
 
 思路：1.一共26 个字母
      2.找到对应位置如果相同，进行累加/减（src 加 dst 减）
      3.最后比对结果，是否为0
*/

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
                return false;
            }
        }
        // record数组所有元素都为零0，说明字符串s和t是字母异位词
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
