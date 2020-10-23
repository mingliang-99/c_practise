//
//  main.cpp
//  ACM
//
//  Created by mingliang on 16/9/4.
//  Copyright © 2019年 mingliang. All rights reserved.
/************************** 题解 **********************
 字符串题解
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
 字符串经典题目
 
 题目一：
 最长回文字符串

 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 
 示例 1：
 
 输入: "babad"
 输出: "bab"
 注意: "aba" 也是一个有效答案。
 示例 2：
 
 输入: "cbbd"
 输出: "bb"
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-palindromic-substring
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 
 
 方法三：动态规划
 为了改进暴力法，我们首先观察如何避免在验证回文时进行不必要的重复计算。考虑 \textrm{“ababa”}“ababa” 这个示例。如果我们已经知道 \textrm{“bab”}“bab” 是回文，那么很明显，\textrm{“ababa”}“ababa” 一定是回文，因为它的左首字母和右尾字母是相同的。

 如果子串S
 i
 ​    
 …S
 j
 ​    
 是回文子串
 其它情况
 ​    
 
 
 因此，
 
 P(i, j) = ( P(i+1, j-1) \text{ and } S_i == S_j )
 P(i,j)=(P(i+1,j−1) and S
 i
 ​    
 ==S
 j
 ​    
 )
 
 基本示例如下：
 
 P(i, i) = true
 P(i,i)=true
 
 P(i, i+1) = ( S_i == S_{i+1} )
 P(i,i+1)=(Si==Si+1)
 
 这产生了一个直观的动态规划解法，我们首先初始化一字母和二字母的回文，然后找到所有三字母回文，并依此类推
 
 作者：LeetCode
 链接：https://leetcode-cn.com/problems/two-sum/solution/zui-chang-hui-wen-zi-chuan-by-leetcode/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 
 
 */

class SolutionlongestPalindrome {
public:
    string longestPalindrome(string &s) {
        int n=s.length(), begin=0, end=0;
        vector<vector<bool> > dp(n,vector<bool> (n,false));
        for(int j=0; j<n; ++j){
            for(int i=0; i<=j; ++i){
                if((j-i<=1 || dp[i+1][j-1]) && s[i]==s[j])
                    dp[i][j]=true;
                if(dp[i][j] && j-i>end-begin)
                    begin=i, end=j;
            }
        }
        return s.substr(begin,end-begin+1);
    }
};





/*
解决方法：
 
作者：bian-bian-xiong
链接：https://leetcode-cn.com/problems/two-sum/solution/5-zui-chang-hui-wen-zi-chuan-cc-by-bian-bian-xiong/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

//计算以left和right为中心的回文串长度
int expandAroundCenter(string s, int left, int right)
{
    int L = left, R = right;
    while (L >= 0 && R < s.length() && s[L] == s[R])
    {// 计算以left和right为中心的回文串长度
        L--;
        R++;
    }
    return R - L - 1;
}

string longestPalindrome(string s)
{
    if (s.length() < 1)
    {
        return "";
    }
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int len1 = expandAroundCenter(s, i, i);//一个元素为中心
        int len2 = expandAroundCenter(s, i, i + 1);//两个元素为中心
        int len = max(len1, len2);
        if (len > end - start)
        {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end - start + 1);
}







