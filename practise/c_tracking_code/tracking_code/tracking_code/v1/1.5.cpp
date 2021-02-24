//
//  main.cpp
//  tracking_code
//
//  Created by mingliang on 2021/2/17.
//

#include <iostream>
#include <string>
#include <vector>

using namespace::std;

/*
 4.
 Write a method to decide if two strings are anagrams or not.
 编写一个方法来决定两个字符串是否是字谜
 
 问题陈述：给定两个字符串，请检查两个给定的字符串是否彼此相似 。 字符串的字谜是另一个包含相同字符的字符串，只有字符顺序可以不同。
 For example, "act" and "cat" are anagram of each other.
 例如， “ act”和“ cat”彼此相似
 
 解题思路：初始化两个长度为26的数组，以存储每个字符串中字符的频率
 */


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
